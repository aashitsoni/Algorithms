#ifndef _MEMORY_MANAGER_H_
#define _MEMORY_MANAGER_H_
#include <cstddef>
#include <vector>
#include <unordered_map>
#include <algorithm>

// A memory block to maintain the pointer and its size. This is used for the free list to manage free blocks of memory.
// a tail end is always available for allocation - so we can keep track of the used bytes and the total bytes to manage the bump allocation.    
typedef struct _MemoryBlock
{
    char* ptr;
    size_t mem_size;
} MemoryBlock;

class MemoryManager {
    
    char* buffer;   
    int num_bytes;
    int num_used_bytes;

    // a list that keeps track of free blocks of memory. I am using the free list to simply recycle 
    // the free blocks and so there is less fragmentation. 
    // I am avoiding memory- move - there can be more design if we need the optimization on the memory.
    // but moving the memory can be costly operation with mem-move or similar functionality unless it
    // is necessary. 
    // There are ways the mem-move can be optimized but this version is kept simple and more manageable. 
    // free_list stores free segments inside the buffer (ptr + size)
    std::vector<MemoryBlock> free_list;

    // an unordered_map for keeping track of allocated blocks. keep in mind - for the first time
    // it will allocate the memory - when the free happens - it moves the pointer and its size to free-list
    // on later on we will try to go through the free-list to see if we can allocate the memory easily - if not 
    // then it will go through the free blocks.
    // the free block is going to be initially empty - it will start moving along when the memory gets allocated.
    // allocated_blocks maps returned pointer -> size (for validation on Free)
    std::unordered_map<char*, size_t> allocated_blocks;

    public:
        // buffer is a large chunk of contiguous memory.
        // num_bytes is the size of the buffer.
        // this is not allocated by the memory memanger - the aggrement is to have this provided by the host
        // application - in our case it will the test - harness code.
        MemoryManager(char * buffer, int num_bytes);

        // Allocate memory of size 'size'. Use malloc() like semantics.
        // not sure why we will use - malloc - the buffer is already allocated for us - this is just a 
        // manager which manages the blocks. - right. 
        char* Alloc(int size);

        // Free up previously allocated memory.  Use free() like semantics.
        // now this will do the free-list management and also help in fragmentation. 
        void Free(char*);
};

#endif
