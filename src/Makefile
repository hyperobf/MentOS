OBJECTS = IO/io.o IO/framebuffer.o IO/serial.o kmain.o loader.o
CC = i686-elf-gcc
CFLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra -c
LDFLAGS = -T link.ld -melf_i386
AS = nasm
ASFLAGS = -f elf

all: kernel.elf

kernel.elf: $(OBJECTS)
		ld $(LDFLAGS) $(OBJECTS) -o ../build/kernel.elf
		rm *.o IO/*.o

%.o: %.c
		$(CC) $(CFLAGS) $< -o $@

%.o: %.asm
		$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -rf *.o IO/*.o ../build/kernel.elf
