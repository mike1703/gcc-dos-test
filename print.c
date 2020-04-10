#include "dosapi.h"
#include "string.h"

// expects $ terminated string to give raw to the API
void print(char *string)
{
    dos_09h(string);
};

// does not expect $ terminated string
void print2(char *string, unsigned int size)
{
    char* foo;
    strncpy(foo, string, size);
    print(foo);
}
