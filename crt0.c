extern void dosmain();

char startup_message[] = "Hello World Programm:\n\r$";

void start() {
    asm (".code16gcc\n"
            // print the startup message
         "mov   $0x09, %%ah\n"
         "int   $0x21\n"
            // run the program
         "call  dosmain\n"
            // and return back to the OS
         "mov   $0x4C,%%ah\n"
         "int   $0x21\n"
         :
         : "d"(startup_message)
         : "ah"
         );
}
