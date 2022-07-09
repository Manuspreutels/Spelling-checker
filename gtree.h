#ifndef __GTREE_H__
#define __GTREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CARACTERES_ACEPTADOS 57

typedef struct _GNode {
    struct _GNode *hijos[CARACTERES_ACEPTADOS];
    int final;
} GNode;

typedef GNode *GTree;


GTree gtree_crear();

GTree gtree_insertar_string(GTree root, unsigned char* str);



#endif // __GTREE_H__