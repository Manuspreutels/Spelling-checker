#include <stdio.h>
#include <stdlib.h>
#include "gtree.c"


GTree leer_diccionario(char *nombre) {
    FILE *diccionario = fopen(nombre, "r");
    GTree arbolDic = gtree_crear();
    int i = 0;
    unsigned char c;
    unsigned char buffer[255];
    while((c = (unsigned char)fgetc(diccionario)) != EOF) {
        //printf("%c\n", c);
        if (c == '\n') {
            buffer[i] = '\0';
            printf("%s\n", buffer);
            arbolDic = gtree_insertar_string(arbolDic, buffer);
            printf("XDDD");
            i = 0;
        } else {
            buffer[i++] = c;
        }
    }

    return arbolDic;
}


int main() {
    char **listaPalabras = malloc(sizeof(char*)*670000);
    GTree xdd = leer_diccionario("diccionario.txt");
    return 0;
}