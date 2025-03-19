#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack stack_create(int len) {
    Stack stack;
    stack.data = (Data*)malloc(len * sizeof(Data));
    if (stack.data == NULL) {
        printf("Error: No se pudo asignar memoria para la pila.\n");
    }
    stack.top = -1;
    return stack;
}

void stack_push(Stack* s, Data d) {
    if (s->data == NULL) {
        printf("Error: La pila no está inicializada.\n");
        return;
    }
    s->data[++(s->top)] = d;
}

Data stack_pop(Stack* s) {
    if (s->top == -1 || s->data == NULL) {
        printf("Error: La pila está vacía o no está inicializada.\n");
        return -1;
    }
    return s->data[(s->top)--];
}

int stack_is_empty(Stack* s) {
    if (s == NULL || s->data == NULL) {
        printf("Error: La pila no está inicializada.\n");
        return -1;
    }
    return s->top == -1;
}

void stack_empty(Stack* s) {
    if (s != NULL && s->data != NULL) {
        s->top = -1;
    } else {
        printf("Error: La pila no está inicializada.\n");
    }
}

void stack_delete(Stack* s) {
    if (s != NULL && s->data != NULL) {
        free(s->data);
        s->data = NULL;
        s->top = -1;
    }
}

void stack_print(Stack* s) {
    if (s == NULL || s->data == NULL || stack_is_empty(s)) {
        printf("La pila está vacía o no está inicializada.\n");
        return;
    }
    printf("Elementos en la pila:\n");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}