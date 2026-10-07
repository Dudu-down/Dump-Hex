#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include "dump.h"

/*Reescrever e comentar todo codigo, reemplementar e analisar melhor logica de quebra de linhas e offset.
isso é uma matriz. tentar trabalkhar mais com os numeros em si que ta uma bagunça danada*/



int main (int argc, char *argv[]) {
    if(argc < 2) {
                                                        /*fprintf usar arguimento a mais como sdin,stdou, etc para separar msg*/
        fprintf(stderr, "uso: %s arquivo\n", argv[0]); /*aqui usa-se uma conveção unix para declarar erro de chamada "uso: como se usa"*/
        return 1;
    }

    FILE *r = fopen(argv[1], "rb");     /*rb - readBytes*/
    if (!r) {                            /*!r abreviação de r == NULL*/
        perror("fopen");                /*perror pinta a msg padrao de erro da função chamada > fopen*/          
        return 1;
    }

    uint8_t line[MAX_LINE_LENGHT];
    size_t n;
    unsigned long count = 0;
    int suprimindo = 0;
    int primeira = 1;
    
    while ((n = fread(line, 1, sizeof line, r)) > 0) {

        if (!primeira && n == MAX_LINE_LENGHT && lcompare(line) == 0) {
            if(!suprimindo){
                printf("*\n");
                count += n;
                suprimindo = 1;
            }
        } else {
            formatterLine(line, &count);
            wbuffer(line);
            suprimindo = 0;
            }
        primeira = 0;
    }

    fclose(r);
    return 0;
}

