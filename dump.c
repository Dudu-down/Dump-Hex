#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include "dump.h"

uint8_t lineBuffer[MAX_LINE_LENGHT];

/*
int dump(FILE *r) {
    int ch;
    long count = 0;
    size_t bufferPass[MAX_LINE_LENGHT];

    while((ch = fgetc(r)) != EOF) {
        if (count % MAX_LINE_LENGHT == 0) {
            printf("%08lX  | ", count);
        }

        printf("%02X ", ch);
        wbuffer(MAX_LINE_LENGHT, ch, count);
        count++;
            /*resto de uma operação modular é indice
        if (count % MAX_LINE_LENGHT == 8) {
            printf("  ");
        }
        if (count % MAX_LINE_LENGHT == 0) {
            printf("|\n");
        }
    }
    if (count % MAX_LINE_LENGHT != 0) {
        printf("\n");
    }


    return 0;
}*/

int formatterLine(uint8_t line[MAX_LINE_LENGHT], unsigned long *count) {
    

    for (int i = 0; i < 16; i++) {
        if (*count % MAX_LINE_LENGHT == 0) {
            printf("%08lX |", *count);
        }
        printf("%02X ", line[i]);
        *count += 1;

        if (*count % MAX_LINE_LENGHT == 8) {
            printf(" ");
        }

        if (*count % MAX_LINE_LENGHT == 0) {
            printf(" |\n");
        }
    }
    return 0;
}

int wbuffer (uint8_t line[MAX_LINE_LENGHT]) {
    for(int i = 0; i < 16; i++){
        lineBuffer[i] = line[i];
    }
    return 0;
}

int lcompare (uint8_t line[MAX_LINE_LENGHT]) {
    for(int i = 0; i < MAX_LINE_LENGHT; i++) {
        if(line[i] != lineBuffer[i]) {
            return 1;
        }
    }
    return 0;
}
