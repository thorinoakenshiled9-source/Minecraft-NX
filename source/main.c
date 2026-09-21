#include <switch.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    consoleInit(NULL);

    printf("Minecraft-NX - libnx test\n\n");
    printf("Hello from Nintendo Switch!\n");
    printf("Se esta tela apareceu, o NRO funciona.\n\n");
    printf("Pressione + para sair.\n");

    PadState pad;
    padConfigureInput(1, HidNpadStyleSet_NpadStandard);
    padInitializeDefault(&pad);

    while (appletMainLoop())
    {
        padUpdate(&pad);

        u64 kDown = padGetButtonsDown(&pad);

        if (kDown & HidNpadButton_Plus)
            break;

        consoleUpdate(NULL);
    }

    consoleExit(NULL);
    return 0;
}
