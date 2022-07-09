#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gtree.h"


GTree leer_diccionario(char *nombre) {
    FILE *diccionario = fopen(nombre, "r");
    if (diccionario == NULL) {
        printf("Diccionario no encontrado.");
        exit(1);
    }
    GTree arbolDic = gtree_crear();
    
    int i = 0;
    unsigned char c;
    unsigned char buffer[255];
    while((c = fgetc(diccionario)) != (unsigned char) EOF) {
        if (c == '\n') {
            buffer[i] = '\0';
            arbolDic = gtree_insertar_string(arbolDic, buffer);
            i = 0;
        } else {
            buffer[i++] = c;
        }
    }
    fclose(diccionario);
    buffer[i] = '\0';
    arbolDic = gtree_insertar_string(arbolDic, buffer);
    return arbolDic;
}

int main() {
    GTree xdd = leer_diccionario("diccionario.txt");
    
    return 0;
}