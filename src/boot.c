typedef unsigned long long UINTN;
typedef short CHAR16;
typedef void *EFI_HANDLE;

struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

typedef unsigned long long (*EFI_TEXT_STRING)(
    struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, 
    CHAR16 *String
);

typedef struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
    void *dummy;
    EFI_TEXT_STRING OutputString;
} EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

typedef struct {
    char dummy;
    EFI_HANDLE ConsoleOutHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *ConOut;
} EFI_SYSTEM_TABLE;

extern void kernel_main(void);

/* UEFI Entry Point */
unsigned long long EfiMain(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
    SystemTable->ConOut->OutputString(SystemTable->ConOut, (CHAR16 *)L"Booting UniphaOS...\r\n");
    
    kernel_main();

    while (1);
    return 0;
}
