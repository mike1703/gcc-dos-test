#include "print.h"
#include "dosapi.h"
#include "malloc.h"

int dosmain(void)
{
    print("Hello World!$");
    print2("Hi there!", 9);
    return 0;
}

