#include <switch.h>
#include <stdio.h>

static void print_status(void) {
    printf("\x1b[2J");
    printf("Minecraft-NX - Bootstrap v0.1\n");
    printf("============================\n\n");
    printf("[OK] Horizon/libnx iniciou\n");
    printf("[OK] CPU: AArch64 (Nintendo Switch)\n");
    printf("[OK] SD: sdmc:/\n");
    printf("[--] JVM 21: proxima etapa\n");
    printf("[--] LWJGL/GLFW: aguardando JVM\n");
    printf("[--] Minecraft: aguardando runtime\n\n");
    printf("Objetivo desta build:\n");
    printf("validar o NRO nativo antes de integrar a JVM.\n\n");
    printf("PLUS: sair\n");
}

int main(int argc, char **argv) {
    consoleInit(NULL);
    padConfigureInput(1, HidNpadStyleSet_NpadStandard);
    PadState pad;
    padInitializeDefault(&pad);

    print_status();

    while (appletMainLoop()) {
        padUpdate(&pad);
        u64 kDown = padGetButtonsDown(&pad);
        if (kDown & HidNpadButton_Plus) break;
        consoleUpdate(NULL);
    }

    consoleExit(NULL);
    return 0;
}
