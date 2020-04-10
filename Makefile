CFLAGS=-std=gnu99 -O1 -m16 -march=i386 -ffreestanding -nostdlib
LDFLAGS=-Wl,--nmagic,--script=com.ld
GCC=/usr/bin/gcc

all: hello.com

hello.com: main.o print.o crt0.o dosapi.o string.o malloc.o
	${GCC} ${CFLAGS} -o hello.com ${LDFLAGS} dosapi.o malloc.o string.o print.o main.o

crt0.o: crt0.c
	${GCC} ${CFLAGS} -o crt0.o -c crt0.c

main.o: main.c
	${GCC} ${CFLAGS} -o main.o -c main.c

print.o: print.h print.c
	${GCC} ${CFLAGS} -o print.o -c print.c

dosapi.o: dosapi.c
	${GCC} ${CFLAGS} -o dosapi.o -c dosapi.c

malloc.o: malloc.c
	${GCC} ${CFLAGS} -o malloc.o -c malloc.c

string.o: string.c malloc.h
	${GCC} ${CFLAGS} -o string.o -c string.c

clean:
	rm -f *.o hello.com
