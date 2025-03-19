#include "stack.h"
#include <stdio.h>

Stack stack_create() {
    Stack stack;
    stack.top = -1;
    return stack;
}

void stack_push(Stack* s, Data d) {
    if (s->top < TAM - 1) {
        s->data[++(s->top)] = d;
    } else {
        printf("Error: La pila está llena.\n");
    }
}

Data stack_pop(Stack* s) {
    if (s->top >= 0) {
        return s->data[(s->top)--];
    } else {
        printf("Error: La pila está vacía.\n");
        return -1;
    }
}

int stack_is_empty(Stack* s) {
    if (!s) {
        return -1;
    }
    return s->top == -1;
}

void stack_empty(Stack* s) {
    if (s) {
        s->top = -1;
    }
}

void stack_print(Stack *s) {
    if (!s || stack_is_empty(s)) {
        printf("La pila está vacía o es inválida.\n");
    } else {
        printf("Elementos en la pila:\n");
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->data[i]);
        }
        printf("\n");
    }
}
