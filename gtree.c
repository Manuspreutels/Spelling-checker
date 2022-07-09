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
    GTree tmp = root;
    for(; *str != '\0'; str++){
        if(tmp->hijos[*str -65] == NULL) {
            tmp->hijos[*str-65] = gtree_crear();
        }
        tmp = tmp->hijos[*str-65];
    }
    tmp->final = 1;
    return root;
}


int gtree_buscar(GTree root, char *str) {
    GTree tmp = root;
    for(; (unsigned char) *str != '\0'; str++){
        if(tmp->hijos[*str -65] == NULL) {
            return 0;
        }
        tmp = tmp->hijos[*str -65];
    }
    return tmp->final;
}

void print_gtree(GTree root, unsigned char* prefix, int length){ 
    unsigned char nuevoPrefix[length+2];
    memcpy(nuevoPrefix, prefix, length);
    nuevoPrefix[length+1] = 0;

    if(root->final) {
        printf("PALABRA:   %s\n", prefix);

    }
    for(int i = 0; i < CARACTERES_ACEPTADOS; i++) {
        if(root->hijos[i] != NULL) {
            nuevoPrefix[length] = i+65;
            print_gtree(root->hijos[i], nuevoPrefix, length+1);
        }
    }


}

void print_gtree_rec(GTree root) {
    if (root == NULL) {
        printf("Arbol vacio\n");
        return;
    }
    print_gtree(root, NULL, 0);
}

//int main() {
//  GTree arbol = gtree_crear();
//  arbol = gtree_insertar_string(arbol, "HOLA");
//  printf("BBBBB BB %d", EOF);
//  return 0;
//}