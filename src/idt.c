#include "idt.h"
#include "io.h"

static struct idt_entry idt[256];
static struct idt_ptr idtp;

extern void idt_load(uint64_t);
extern void isr0();

static void set_idt_gate(int n, uint64_t handler) {
    idt[n].base_lo = (handler & 0xFFFF);
    idt[n].sel = 0x08;
    idt[n].always0 = 0;
    idt[n].flags = 0x8E;
    idt[n].base_hi = (handler >> 16) & 0xFFFF;
}

void init_idt(void) {
    idtp.limit = (sizeof(struct idt_entry) * 256) - 1;
    idtp.base = (uint64_t)&idt;

    for (int i = 0; i < 256; i++) {
        set_idt_gate(i, (uint64_t)isr0);
    }

    idt_load((uint64_t)&idtp);
}
