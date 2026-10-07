# My-Hexdump

Clone do `hexdump -C` em C, feito para aprendizado (surgiu dos estudos de emulação, ROM e parser).

## Requisitos
- GCC instalado

## Instalação
```bash
git clone https://github.com/Dudu-down/Dump-Hex.git
cd Dump-Hex/src
gcc -Wall -Wextra main.c dump.c -o Dump-Hex
```

## Uso
```bash
./Dump-Hex caminho/do/arquivo
```

## Exemplo de saída
```
00000000  |7f 45 4c 46 01 01 01 00  00 00 00 00 00 00 00 00  |
*
```
