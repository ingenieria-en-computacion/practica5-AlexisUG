#include "queue.h"
#include <stdio.h>

Queue queue_create() {
    Queue q;
    q.head = -1;
    q.tail = -1;
    q.len = 0;
    return q;
}

void queue_enqueue(Queue* q, Data d) {
    if (q == NULL) {
        printf("Error: La cola no está inicializada.\n");
        return;
    }
    if (q->len == TAM) {
        printf("Error: La cola está llena.\n");
        return;
    }
    if (q->head == -1) {
        q->head = 0;
    }
    q->tail = (q->tail + 1) % TAM;
    q->datos[q->tail] = d;
    q->len++;
}

Data queue_dequeue(Queue* q) {
    if (q == NULL || queue_is_empty(q)) {
        printf("Error: La cola está vacía o no está inicializada.\n");
        return -1;
    }
    Data value = q->datos[q->head];
    if (q->head == q->tail) {
        q->head = -1;
        q->tail = -1;
    } else {
        q->head = (q->head + 1) % TAM;
    }
    q->len--;
    return value;
}

bool queue_is_empty(Queue* q) {
    return q == NULL || q->len == 0;
}

Data queue_front(Queue* q) {
    if (q == NULL || queue_is_empty(q)) {
        printf("Error: La cola está vacía o no está inicializada.\n");
        return -1;
    }
    return q->datos[q->head];
}

void queue_empty(Queue* q) {
    if (q == NULL) {
        printf("Error: La cola no está inicializada.\n");
        return;
    }
    q->head = -1;
    q->tail = -1;
    q->len = 0;
}