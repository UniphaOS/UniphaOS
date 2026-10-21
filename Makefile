CC = gcc
AS = nasm
CFLAGS = -ffreestanding -fno-stack-protector -mno-red-zone -mgeneral-regs-only -Wall -Wextra -Isrc -c
LDFLAGS = -T linker.ld -nostdlib -Wl,-z,max-page-size=0x1000

OBJS = src/boot.o src/main.o src/gdt.o src/idt.o src/isr.o

all: kernel.efi

kernel.efi: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

%.o: %.asm
	$(AS) -f elf64 -o $@ $<

clean:
	rm -f src/*.o kernel.efi