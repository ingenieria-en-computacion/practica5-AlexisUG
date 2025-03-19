#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue queue_create(int len) {
    Queue q;
    q.data = (Data*)malloc(len * sizeof(Data));
    if (q.data == NULL) {
        printf("Error: No se pudo asignar memoria para la cola.\n");
        q.head = -1;
        q.tail = -1;
        q.len = 0;
    } else {
        q.head = 0;
        q.tail = -1;
        q.len = len;
    }
    return q;
}

void queue_enqueue(Queue* q, Data d) {
    if (q == NULL || q->data == NULL) {
        printf("Error: La cola no está inicializada.\n");
        return;
    }
    if ((q->tail + 1) % q->len == q->head) {
        printf("Error: La cola está llena.\n");
        return;
    }
    q->tail = (q->tail + 1) % q->len;
    q->data[q->tail] = d;
}

Data queue_dequeue(Queue* q) {
    if (q == NULL || q->data == NULL || queue_is_empty(q)) {
        printf("Error: La cola está vacía o no está inicializada.\n");
        return -1;
    }
    Data value = q->data[q->head];
    if (q->head == q->tail) {
        q->head = 0;
        q->tail = -1;
    } else {
        q->head = (q->head + 1) % q->len;
    }
    return value;
}

bool queue_is_empty(Queue* q) {
    return q == NULL || q->tail == -1;
}

Data queue_front(Queue* q) {
    if (q == NULL || q->data == NULL || queue_is_empty(q)) {
        printf("Error: La cola está vacía o no está inicializada.\n");
        return -1;
    }
    return q->data[q->head];
}

void queue_empty(Queue* q) {
    if (q == NULL || q->data == NULL) {
        printf("Error: La cola no está inicializada.\n");
        return;
    }
    q->head = 0;
    q->tail = -1;
}

void queue_delete(Queue* q) {
    if (q == NULL || q->data == NULL) {
        return;
    }
    free(q->data);
    q->data = NULL;
    q->head = 0;
    q->tail = -1;
    q->len = 0;
}