CFLAGS=-std=gnu99 -O1 -m32 -march=i386 -ffreestanding -nostdlib
LDFLAGS=-Wl,--nmagic,--script=com.ld
GCC=/usr/bin/gcc

all: hello.com

hello.com: main.o print.o crt0.o
	${GCC} ${CFLAGS} -o hello.com ${LDFLAGS} main.o print.o

crt0.o: crt0.c
	${GCC} ${CFLAGS} -o crt0.o -c crt0.c

main.o: main.c
	${GCC} ${CFLAGS} -o main.o -c main.c

print.o: print.h print.c
	${GCC} ${CFLAGS} -o print.o -c print.c

clean:
	rm -f *.o hello.com
