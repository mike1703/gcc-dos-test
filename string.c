#include "malloc.h"

int strncpy(char *dest, char *src, unsigned int size)
{
    dest = malloc(size+1);
    for(unsigned int i=0; i<size; i++)
    {
        dest[i] = src[i];
    }
    dest[size] = '$';
    return size;
}
