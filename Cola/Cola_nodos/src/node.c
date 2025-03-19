#include "node.h"
#include <stdlib.h>
#include <stdio.h>

Node *new_node(Data d) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (n != NULL) {
        n->data = d;
        n->next = NULL;
    } else {
        printf("Error: No se pudo asignar memoria para el nodo.\n");
    }
    return n;
}

void delete_node(Node* n) {
    if (n != NULL && n->next == NULL) {
        free(n);
    } else if (n != NULL) {
        printf("Error: Solo se pueden eliminar nodos que no estén enlazados.\n");
    }
}

void print_node(Node* n) {
    if (n != NULL) {
        printf("Nodo: data = %d\n", n->data);
    } else {
        printf("El nodo es inválido o NULL.\n");
    }
}