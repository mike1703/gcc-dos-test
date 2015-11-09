extern void dosmain();

void start() {
    asm (
            // run the program
         "call  dosmain\n"
            // and return back to the OS
         "mov   $0x4C,%%ah\n"
         "int   $0x21\n"
         :
         :
         : "ah"
         );
}
