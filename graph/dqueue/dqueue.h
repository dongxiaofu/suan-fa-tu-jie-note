#include <stdlib.h>

typedef struct queue {
    struct queue *head;
    struct queue *next;
    void *value;
} dqueue;

dqueue *init_queue(int size);

void push(dqueue *head, void *item);

void *pop(dqueue *queue);