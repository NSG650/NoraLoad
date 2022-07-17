#include <types.h>

VOID BpPuts(CHAR* String) {
    STATIC ULONG PosX = 0;
    STATIC ULONG PosY = 0;

    while (*String) {
        switch (*String) {
            case '\n':
                PosY++;
                PosX = 0;
                break;
            case '\r':
                PosX = 0;
                break;
            default:
                ((USHORT*)0xB8000)[PosX + PosY * 80] = *String | 0x1F00;
                PosX++;
                break;
        }
        String++;
    }
}

VOID BdEntry(VOID) {
    BpPuts("Hello from NoraLoad!\n");
    for (;;)
        ;
}