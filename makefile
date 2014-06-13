CC = i686-elf-gcc
LD = i686-elf-gcc
ASM = nasm

CFLAGS = -ffreestanding -O2 -Wall -Wextra -fno-exceptions

INCLUDE = ./include

os42.iso: os42.bin iso/boot/grub/grub.cfg
	cp os42.bin iso/boot/os42.bin
	grub2-mkrescue -o os42.iso iso

os42.bin: bootstrap.o \
		kernel.o \
		lib/stdio.o \
		lib/stdlib.o \
		lib/vga.o \
		lib/io.o
	$(LD) -T linker.ld -o os42.bin -ffreestanding -O2 -nostdlib \
		bootstrap.o \
		kernel.o \
		lib/stdio.o \
		lib/stdlib.o \
		lib/vga.o \
		lib/io.o \
		-lgcc -Ldir

bootstrap.o: bootstrap.asm
	$(ASM) -f elf -o bootstrap.o bootstrap.asm

kernel.o: kernel.c
	$(CC) -c kernel.c -o kernel.o -I $(INCLUDE) $(CFLAGS)
	
lib/stdio.o: src/stdio.c
	$(CC) -c src/stdio.c -o lib/stdio.o -I $(INCLUDE) $(CFLAGS)
	
lib/stdlib.o: src/stdlib.c
	$(CC) -c src/stdlib.c -o lib/stdlib.o -I $(INCLUDE) $(CFLAGS)
	
lib/vga.o: src/vga.c
	$(CC) -c src/vga.c -o lib/vga.o -I $(INCLUDE) $(CFLAGS)

lib/io.o: src/io.c
	$(CC) -c src/io.c -o lib/io.o -I $(INCLUDE) $(CFLAGS)
