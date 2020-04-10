#include <stdbool.h>
// this comes from the linker script
extern char _heap;

static char *heap_ptr = &_heap;

struct heaplist {
    bool free;
    struct heaplist *next;
};

static struct heaplist heap_head = {true, (struct heaplist*)(&_heap + sizeof(struct heaplist) + 1)};

void *malloc(unsigned int size)
{
    struct heaplist *current_heap = &heap_head;

    void *mem = 0;

    while(current_heap = (current_heap->next))
    {
        // go to next part
        current_heap = current_heap->next;
        if(current_heap->free)
        {
            // TODO: reserve memory and return with mem
            // mem = 
        }
    }

    // fetch the current stack_ptr by reading register ESP
    char *stack_ptr;
    asm (
            "mov    %%esp, %0\n"
            : "=rm"(stack_ptr)
            :
            :
            );
    heap_ptr+=size;

    return mem;
}
