#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <Windows.h>

const uintptr_t healthAddress      = 0x00722084;
const uintptr_t mpt57BulletAddress = 0x007220D8;
const uintptr_t mpt57AmmoAddress   = 0x007220B4;
const uintptr_t mk77BulletAddress  = 0x007220C4;
const uintptr_t mk77AmmoAddress    = 0x007220A0;
const uintptr_t shieldAddress      = 0x00722088;
const uintptr_t bombAddress        = 0x007220DC;

int health, mpt57_bullet, mpt57_ammo, mk77bullet, mk77ammo, shield, bomb;

int main(void) {
    printf("-- Assault Cube Memory Read --\n");

    HWND gameWindowScreen = FindWindow(NULL, "AssaultCube");

    if (gameWindowScreen == NULL) {
        printf("[-] Game Window not found!\n");
        return 1; 
    }
    printf("[*] Game Window Found\n");

    DWORD processID = 0;
    GetWindowThreadProcessId(gameWindowScreen, &processID);
    if (processID == 0) {
        printf("[-] Process ID not found!\n");
        return 1;
    }
    printf("[*] Process ID found: %lu\n", processID);

    HANDLE allowProcess = OpenProcess(PROCESS_VM_READ, FALSE, processID);
    if (allowProcess == NULL) {
        printf("[-] Failed to open process!\n");
        return 1;
    }

    while (1) {
        system("cls"); 

        ReadProcessMemory(allowProcess, (LPCVOID)healthAddress, &health, sizeof(health), NULL);
        ReadProcessMemory(allowProcess, (LPCVOID)mpt57BulletAddress, &mpt57_bullet, sizeof(mpt57_bullet), NULL);
        ReadProcessMemory(allowProcess, (LPCVOID)mpt57AmmoAddress, &mpt57_ammo, sizeof(mpt57_ammo), NULL);
        ReadProcessMemory(allowProcess, (LPCVOID)mk77BulletAddress, &mk77bullet, sizeof(mk77bullet), NULL);
        ReadProcessMemory(allowProcess, (LPCVOID)mk77AmmoAddress, &mk77ammo, sizeof(mk77ammo), NULL);
        ReadProcessMemory(allowProcess, (LPCVOID)shieldAddress, &shield, sizeof(shield), NULL);
        ReadProcessMemory(allowProcess, (LPCVOID)bombAddress, &bomb, sizeof(bomb), NULL);

        printf("--- Assault Cube Memory Read ---\n\n");
        printf("Health        : %d\n", health);
        printf("Shield        : %d\n", shield);
        printf("Mpt-57 Bullet : %d\n", mpt57_bullet);
        printf("Mpt-57 Ammo   : %d\n", mpt57_ammo);
        printf("Mk-77 Bullet  : %d\n", mk77bullet);
        printf("Mk-77 Ammo    : %d\n", mk77ammo);
        printf("Bomb          : %d\n", bomb);

        Sleep(100);
    }

    CloseHandle(allowProcess);
    return 0;
}