#include <switch.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    consoleInit(NULL);

    printf("\x1b[2J");
    printf("Minecraft-NX - Diagnostic v0.2\n");
    printf("==============================\n\n");

    printf("[OK] NRO iniciou\n");
    printf("[OK] libnx iniciou\n");
    printf("[OK] consoleInit iniciou\n\n");

    printf("Teste minimo: sem HID, JVM, LWJGL ou Minecraft.\n");
    printf("Se voce ve esta tela, o bootstrap basico funciona.\n\n");

    printf("Use HOME para voltar ao menu quando terminar.\n");

    while (appletMainLoop())
    {
        consoleUpdate(NULL);
    }

    consoleExit(NULL);
    return 0;
}
