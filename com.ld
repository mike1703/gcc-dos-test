OUTPUT_FORMAT(binary)
STARTUP(crt0.o)
SECTIONS
{
    . = 0x0100;
    .text :
    {
        *(.text);
    }
    .data :
    {
        *(.data);
        *(.bss);
        *(.rodata);
    }
    _heap = ALIGN(4);
}
