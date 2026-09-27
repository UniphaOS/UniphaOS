CC = x86_64-w64-mingw32-gcc
CFLAGS = -Wall -Wextra -ffreestanding -nostdlib -fno-stack-protector

TARGET = boot.efi
SRCS = src/boot.c src/main.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -shared -e EfiMain -o $(TARGET) $(SRCS)

run: $(TARGET)
	qemu-system-x86_64 -bios /usr/share/ovmf/OVMF.fd -drive format=raw,file=fat:rw:.

clean:
	rm -f $(TARGET)
