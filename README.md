# Minecraft-NX bootstrap v0.1

Primeiro protótipo nativo para Nintendo Switch/Atmosphère.

## O que esta versão faz
- Compila como homebrew AArch64 usando devkitA64 + libnx.
- Inicializa o console do Horizon.
- Inicializa controles.
- Mostra o estado do bootstrap.
- PLUS encerra o aplicativo.

Ela ainda NÃO contém Java, LWJGL ou Minecraft. Isso é proposital: primeiro validamos
a base NRO em hardware real.

## Compilar
Requer devkitPro com devkitA64/libnx.

```sh
cd Minecraft-NX
make
```

Saída esperada:

`Minecraft-NX.nro`

Copie para:

`sd:/switch/Minecraft-NX/Minecraft-NX.nro`

Execute pelo Homebrew Menu. Para ter memória suficiente nas etapas futuras, prefira
abrir o hbmenu em modo application (não applet).

## Próxima etapa
Criar a camada `jvm/` e testar uma JVM ARM64/JNI mínima. O alvo inicial será executar
um HelloWorld Java antes de integrar LWJGL/GLFW ou o launcher do Minecraft.

## Referências de arquitetura
O projeto usa a estrutura convencional de homebrew libnx/devkitA64. O MojoLauncher
será usado como referência para o pipeline de Minecraft/JVM/LWJGL, não como APK
diretamente convertido.

## Compilar pelo GitHub Actions (inclusive pelo celular)

1. Crie um repositório no GitHub.
2. Envie **o conteúdo desta pasta** para a raiz do repositório. O `Makefile` precisa
   aparecer na página inicial do repositório; não deixe tudo dentro de uma pasta extra.
3. Abra a aba **Actions**.
4. Selecione **Build Minecraft-NX**.
5. Toque em **Run workflow**.
6. Quando terminar, abra a execução e baixe o artifact **Minecraft-NX-nro**.
7. Extraia o ZIP do artifact. Dentro estará `Minecraft-NX.nro`.
8. No microSD, crie `switch/Minecraft-NX/` e coloque o NRO lá.

Também ocorre uma compilação automática quando houver push para `main` ou `master`.
