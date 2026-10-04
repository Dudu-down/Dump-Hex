#include<stdio.h>
#include<stdlib.h>
#include "dump.h"




int dump(FILE *r) {
    int ch;
    long count = 0;

    while((ch = fgetc(r)) != EOF) {
        if (count % MAX_LINE_LENGHT == 0) {
            printf("%08lX  | ", count);
        }

        printf("%02X ", ch);
        count++;

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
}

