# UniphaOS

A minimalist 64-bit operating system built from scratch for x86_64 architecture using UEFI.

## Prerequisites

You need a Linux environment (such as WSL2/Ubuntu) with the following tools installed:

```bash
sudo apt update
sudo apt install -y build-essential gcc-multilib nasm qemu-system-x86 ovmf git
```

## Directory Structure

```text
.
├── src/
│   ├── boot.c      # UEFI Bootloader
│   └── main.c      # Kernel Entry Point
├── .gitignore      # Git ignore list
├── LICENSE         # MIT license
├── Makefile        # Build and emulation scripts
└── README.md       # Project document
```

## How to Build and Run

### 1. Build the OS image
```bash
make
```

### 2. Run in QEMU Emulator
```bash
make run
```

### 3. Clean build files
```bash
make clean
```

## License
This project is licensed under the MIT License.
