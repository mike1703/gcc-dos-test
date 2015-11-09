void print(char *string)
{
    asm (
         "mov  $0x09, %%ah\n"
         "int  $0x21\n"
         :
         : "d"(string)
         : "ah"
         );
};
