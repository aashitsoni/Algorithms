Hello Sean, 

A MemoryManager class is designed to implement a basic functionality of memory management. It takes char* and size in its construction. It has basically two important
datastrucutre 

1. allocated_block - which is a unorder_map of char* to its size. 
2. free_list - which a vector of type MemoryBlock - manages pointer and its size.

There are some other book-keeping items - which is num_bytes, num_used_bytes and buffer - that basically is used in Alloc() and Free() to manage the operations.

When allocation happens - it looks at the free list - if the free list is empty - it allocates from the buffer. it keeps going on and populating underder_map of
pointers. Which will be used later on when someone calls free - what it does is moves the pointer and the size into struct and populates free_list.

If the free_list is non-empty - then the allocation looks at the free list and see if any block can be used. If the block is exact match - it is removed from 
the free list and num_used_bytes is bumped up. If there is bigger block in free-list it is split into the smaller one - the modified block is kept back and the
allocated one is accounted for the allocation and used bytes. If the block is not available - it goes to the tail - of the buffer and see if there is space - if it
does not find enough buffer - it bails out and non-allocation.

When free() is called - it only not do a free-list population but also tries to see if there are any contiguous block available which can be merged for the bigger
block. - once that is done - at the end it checks if the block can be reclaimed meaning if we can move the free block - which is at the end of the free buffer - and
take out the from free-list so that tail will be managed easily into allocation buffer.

Keep in mind - there is no mem-mmove done to optimization the fragmentation in this - ony free-list, merge is implemeted to manage the fragmentation.

Also it does not have thread-safety - but it can be easily added using the mutext for the alloc and free - it can be separate or it can be one - depending on the
usage on the library to provide the thread-safetly - mainly where the need to access the allocated-block and free-list - those mutext can be used. We can 
acquire and release these mutex as it desires in the implementation of the alloc and free api.

the future - expansion can consider multiple things.
it can have - blocks of list - if the memory manager has to be more sophisticated - like 64, 128, 264, 512, 1024, 2048, 4096 bytes. We can keep these memory as a 
part of separate pool - and always allocated the blocks from these list - 
One thing it can help is avoid bigger fragmentation - always allocated memory - using rounded numbers - anything between 1-64 will get 64 minimum and then go on. 
Or it can be divided in to similar fashion for bigger bytes - like more than 512 - we do the rounding and for rest it will be as needed - because book-keeping or
waste on the roudning is going to be more.

We can also probably provision mem-move - to condense the memory - if there are more fragments - we can always checks - book keep how many are in the free-list
and if the free list - becomes more than certain percentage of the memory - than we can sweep the memory and allign it one after anotherone so that the fragmentation
can be avoided.

I have tried to keep it as shared object lib - and have tests - harness into cpp files - mainly my objective was to design on minimal MemoryManagement and then build
on top of it.

I think major consideration i would have is to have 2**n implemetation - to avoid fragmentation - and probably have buffers allocated for each sets and provide Alloc
and free based of this set - rather than implementing mem-move to have optimization on memory.

Also - one can implement a gurard rails - in the memory management - like multiple frees or memory corruptions - those will be very important addition to the memory
management - we can call it SafeMemoryManager - which has a way to lock the memory - and if someone else tries to modify - it can assert or log it. We have used in
the past 8 byte signatures to stamp the start and end - if on the operations we see the sign - changed we can flag the process - or provided debug.

Also it can track the non-free - or mutiple freee - so that user - gets to know what is happening with the memory leaks. If the memory is not freed - it can log
the amount and more details of the free - many time alloc and free - can take inbuild - strings as an identifier and that can be as well used.

Threading can be a simple addition - i didn't wanted to do it - as i thoguth it may not be so essential for today - but overall - if we have thread-safe alloc
and free - we will also add - test case to verify the same - there might be some timeout - or watchdog added in the test programs to detect the locks. if any.
This will aid our customer use-cases better. 

I have used logging - cout as my own purpose - it can be easily replaced with system-wide logging. 


I might have missed few things - i apologize for the same. There are many things one can do - i really appreciate the excercise and opptunity
- Aashit Soni

