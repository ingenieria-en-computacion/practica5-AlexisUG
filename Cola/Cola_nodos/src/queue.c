#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue* queue_create() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (q != NULL) {
        q->head = NULL;
        q->tail = NULL;
    } else {
        printf("Error: No se pudo asignar memoria para la cola.\n");
    }
    return q;
}


void queue_enqueue(Queue* q, Data d) {
    if (q == NULL) {
        printf("Error: La cola no está inicializada.\n");
        return;
    }
    Node *n = new_node(d);
    if (n != NULL) {
        if (q->tail != NULL) {
            q->tail->next = n;
        }
        q->tail = n;
        if (q->head == NULL) {
            q->head = n;
        }
    } else {
        printf("Error: No se pudo insertar el elemento.\n");
    }
}

Data queue_dequeue(Queue* q) {
    if (q == NULL || q->head == NULL) {
        printf("Error: La cola está vacía o no está inicializada.\n");
        return -1;
    }
    Node *temp = q->head;
    Data value = temp->data;
    q->head = temp->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }
    delete_node(temp);
    return value;
}

bool queue_is_empty(Queue* q) {
    return q == NULL || q->head == NULL;
}

Data queue_front(Queue* q) {
    if (q == NULL || q->head == NULL) {
        printf("Error: La cola está vacía o no está inicializada.\n");
        return -1;
    }
    return q->head->data;
}

void queue_empty(Queue* q) {
    if (q == NULL) {
        printf("Error: La cola no está inicializada.\n");
        return;
    }
    while (q->head != NULL) {
        queue_dequeue(q);
    }
}

void queue_delete(Queue* q) {
    if (q == NULL) {
        return;
    }
    queue_empty(q);
    free(q);
}
