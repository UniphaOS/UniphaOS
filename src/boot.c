#include <stdint.h>
#include <stddef.h>

typedef uint64_t UINTN;
typedef uint16_t CHAR16;
typedef void *EFI_HANDLE;

struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

typedef UINTN (*EFI_TEXT_STRING)(
    struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
    CHAR16 *String
);

typedef struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
    void *dummy;
    EFI_TEXT_STRING OutputString;
} EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

typedef struct {
    char dummy[24];
    EFI_HANDLE ConsoleOutHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *ConOut;
} EFI_SYSTEM_TABLE;

extern void kernel_main(void);

UINTN efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
    SystemTable->ConOut->OutputString(SystemTable->ConOut, (CHAR16*)L"Booting UniphaOS...\r\n");
    
    kernel_main();
    
    while (1);
    return 0;
}
