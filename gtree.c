#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gtree.h"


GTree gtree_crear() {
    GTree nuevoTree = malloc(sizeof(GNode));
    for(int i = 0; i < CARACTERES_ACEPTADOS; i++) {
        nuevoTree->hijos[i] = NULL;
    }

    nuevoTree->final = 0;
    return nuevoTree;
}

GTree gtree_insertar_string(GTree root, unsigned char* str) {

    printf("%s   AAA", str);
    GTree tmp = root;
    for(; (unsigned char) *str != '\0'; str++){
        if(tmp->hijos[*str] == NULL) {
            tmp->hijos[*str] = gtree_crear();
        }
        tmp = tmp->hijos[*str];
    }
    tmp->final = 1;
    return root;
}


int gtree_buscar(GTree root, char *str) {
    GTree tmp = root;
    for(; (unsigned char) *str != '\0'; str++){
        if(tmp->hijos[*str] == NULL) {
            return 0;
        }
        tmp = tmp->hijos[*str];
    }
    return tmp->final;
}

/*int main() {
    GTree arbol = gtree_crear();
    arbol = gtree_insertar_string(arbol, "HOLA");
    printf("%d", arbol->hijos[(unsigned char) 'H'] != NULL);
    return 0;
}*/