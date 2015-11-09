/* #include "print.h" */

char second_msg[] = "and this is the second line!\n\r$";

void print2(char *string)
{
    asm (
         "mov  $0x09, %%ah\n"
         "int  $0x21\n"
         :
         : "d"(string)
         : "ah"
         );
};

int dosmain(void)
{
    asm (
         "mov   $0x09, %%ah\n"
         "int   $0x21\n"
         :
         : "d"(second_msg)
         : "ah"
         );
    print2(second_msg);
    return 0;
}

