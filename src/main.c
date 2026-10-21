#include <stdint.h>
#include "io.h"
#include "gdt.h"
#include "idt.h"

#define VGA_MEM ((volatile uint16_t*)0xB8000)
#define VGA_COLS 80
#define VGA_ROWS 25
#define VGA_COLOR 0x1F

static void clear_screen(void) {
    for (int i = 0; i < VGA_COLS * VGA_ROWS; i++) {
        VGA_MEM[i] = (uint16_t)(VGA_COLOR << 8 | ' ');
    }
}

static void print_string(const char *str) {
    int i = 0;
    while (str[i]) {
        VGA_MEM[i] = (uint16_t)(VGA_COLOR << 8 | str[i]);
        i++;
    }
}

void kernel_main(void) {
    clear_screen();
    
    init_gdt();
    init_idt();
    
    print_string("UniphaOS Kernel Initialized");
    
    sti();
    while (1) {
        hlt();
    }
}
