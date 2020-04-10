// AH 01h
char dos_01h()
{
    char c;
    asm (
            "mov    $0x01, %%ah\n"
            "int    $0x21\n"
            : "=al"(c)
            :
            :
            );
    return c;
};

// AH 09h
void dos_09h(char* output)
{
    asm (
            "mov    $0x09, %%ah\n"
            "int    $0x21\n"
            :
            : "d"(output)
            :
            );

}
