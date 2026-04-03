#include "MemoryManager.h"
#include "Log.h"
#include <algorithm>

// it initialized the buffer - passed by the host application - and also initializes the free list and allocated blocks.
MemoryManager::MemoryManager(char * buffer, int num_bytes):
    buffer(buffer), num_bytes(num_bytes), num_used_bytes(0), free_list(), allocated_blocks()
{
    LOG_DEBUG("MemoryManager initialized with buffer at " << (void*)buffer << " of size " << num_bytes);
}

// for compactness - a helper function to compare MemoryBlocks by their pointer address for sorting during coalescing.
// we are not going to condense the used memory - if the demanded memory can not be accomodated as - non-continuous free blocks - then it will return nullptr.
static inline bool ptr_less(const MemoryBlock &a, const MemoryBlock &b) {
    return a.ptr < b.ptr;
}

char* MemoryManager::Alloc(int size)
{
    if (size <= 0) {
        LOG_WARN("Requested allocation size " << size << " is not positive. Returning nullptr.");
        return nullptr;
    }

    // First-fit in free_list if possible. it may be easy to manage the memory from here.
    // if the block matches the size - its simple move on block from free to allocated
    // if it is larger than the size - then split it and compute the new pointer for the free block 
    // readjust the size. 
    // if the block is smaller than the size - then move on to the next block in the free list.
    // if not part of the free list - then w eill look in to the free buffer - if it is available.
    // for the free buffer - it will into allocated buffer. 
    // there is no provision yet to move the memory block - if fragmentation is there and the unused blocks are not adjacent - then it will return nullptr.
    for (size_t i = 0; i < free_list.size(); ++i) {
        MemoryBlock &blk = free_list[i];
        if ((int)blk.mem_size >= size) {
            char* alloc_ptr = blk.ptr;
            if (blk.mem_size == (size_t)size) {
                // exact fit — remove block - from the free list and move it to allocated blocks
                free_list.erase(free_list.begin() + i);
            } else {
                // split: advance start of free block - adjust the size and put the allocated block into allocated blocks
                blk.ptr = blk.ptr + size;
                blk.mem_size = blk.mem_size - size;
            }
            allocated_blocks[alloc_ptr] = (size_t)size;
            LOG_DEBUG("Allocated " << size << " bytes from free_list at " << (void*)alloc_ptr << ". Free blocks: " << free_list.size());
            return alloc_ptr;
        }
    }

    // not found in the free block then bump allocation at end
    if (num_used_bytes + size <= num_bytes) {
        char* alloc_ptr = buffer + num_used_bytes;
        allocated_blocks[alloc_ptr] = (size_t)size;
        num_used_bytes += size;
        LOG_DEBUG("Bump-allocated " << size << " bytes at " << (void*)alloc_ptr << ". Total used: " << num_used_bytes << "/" << num_bytes);
        return alloc_ptr;
    }
    // keep in mind - there might be still enought memory - but non-contiguous - so we can not accomodate the request - this is the fragmentation issue.
    LOG_ERROR("Not enough memory to allocate " << size << " bytes. Used: " << num_used_bytes << "/" << num_bytes);
    return nullptr;
}

void MemoryManager::Free(char* ptr)
{
    auto it = allocated_blocks.find(ptr);
    // there is no such pointer allocated - so we can not free it - this is a no-op but we can log a warning.
    if (it == allocated_blocks.end()) {
        LOG_WARN("Attempted to free unrecognized pointer " << (void*)ptr);
        return;
    }

    size_t freed_size = it->second;
    allocated_blocks.erase(it);

    // Add freed block to free_list
    free_list.push_back({ptr, freed_size});
    LOG_DEBUG("Freed " << freed_size << " bytes at " << (void*)ptr << ". Added to free_list (count=" << free_list.size() << ")");

    // Coalesce adjacent free blocks sort the pointers and then merge adjacent blocks. This is a simple O(n log n) approach to coalescing. 
    // For large free lists, we could optimize this with a more sophisticated data structure, but for simplicity and given the expected use case, this should suffice.
    if (free_list.size() > 1) {
        std::sort(free_list.begin(), free_list.end(), ptr_less);
        std::vector<MemoryBlock> merged;
        merged.reserve(free_list.size());

        MemoryBlock cur = free_list[0];
        for (size_t i = 1; i < free_list.size(); ++i) {
            MemoryBlock &next = free_list[i];
            if (cur.ptr + cur.mem_size == next.ptr) {
                // adjacent, merge
                cur.mem_size += next.mem_size;
            } else {
                merged.push_back(cur);
                cur = next;
            }
        }
        merged.push_back(cur);
        free_list.swap(merged);
        LOG_DEBUG("Coalesced free_list; now has " << free_list.size() << " blocks");
    }

    // Optional: if freed block reaches the tail end, shrink num_used_bytes and reclaim top-most free space.
    // If the last allocated region is freed and corresponds to the high-water mark, we can reduce num_used_bytes.
    // Find if any free block touches the buffer end (buffer + num_used_bytes)
    bool reclaimed = true;
    while (reclaimed) {
        reclaimed = false;
        for (size_t i = 0; i < free_list.size(); ++i) {
            MemoryBlock &blk = free_list[i];
            if (blk.ptr + blk.mem_size == buffer + num_used_bytes) {
                // reclaim tail
                num_used_bytes -= (int)blk.mem_size;
                LOG_DEBUG("Reclaimed tail free block of " << blk.mem_size << " bytes. New used: " << num_used_bytes);
                free_list.erase(free_list.begin() + i);
                reclaimed = true;
                break;
            }
        }
    }
}

