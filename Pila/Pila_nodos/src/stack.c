#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack *stack_create() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if (s != NULL) {
        s->top = NULL;
    } else {
        printf("Error: No se pudo asignar memoria para la pila.\n");
    }
    return s;
}

void stack_push(Stack* s, Data d) {
    if (s == NULL) {
        printf("Error: La pila no está inicializada.\n");
        return;
    }
    Node *n = new_node(d);
    if (n != NULL) {
        n->next = s->top;
        s->top = n;
    } else {
        printf("Error: No se pudo insertar el elemento.\n");
    }
}

Data stack_pop(Stack* s) {
    if (s == NULL || s->top == NULL) {
        printf("Error: La pila está vacía o no está inicializada.\n");
        return -1; // Valor de error
    }
    Node *temp = s->top;
    Data value = temp->data;
    s->top = temp->next;
    delete_node(temp);
    return value;
}

int stack_is_empty(Stack* s) {
    if (s == NULL) {
        printf("Error: La pila no está inicializada.\n");
        return -1;
    }
    return s->top == NULL;
}

void stack_empty(Stack* s) {
    if (s == NULL) {
        printf("Error: La pila no está inicializada.\n");
        return;
    }
    while (s->top != NULL) {
        stack_pop(s);
    }
}

void stack_delete(Stack *s) {
    if (s == NULL) {
        return;
    }
    stack_empty(s);
    free(s);
}

void stack_print(Stack *s) {
    if (s == NULL || s->top == NULL) {
        printf("La pila está vacía o no está inicializada.\n");
        return;
    }
    printf("Elementos en la pila:\n");
    Node *current = s->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}