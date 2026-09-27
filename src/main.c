#define VIDEO_MEM ((unsigned short *)0xB8000)
#define SCREEN_SIZE (80 * 25)

void kernel_main(void) {
    unsigned short *vram = VIDEO_MEM;
    
    /* Fill screen with blue background */
    for (int i = 0; i < SCREEN_SIZE; i++) {
        vram[i] = (unsigned short)(0x1000 | ' ');
    }

    /* Halt CPU */
    while (1) {
        __asm__ __volatile__("hlt");
    }
}
