section .text
    global gdt_flush
    global idt_load
    global isr0

gdt_flush:
    lgdt [rdi]
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    ret

idt_load:
    lidt [rdi]
    ret

isr0:
    cli
.hang:
    hlt
    jmp .hang
