#include "dqueue.h"

dqueue *init_queue(int size) {
    dqueue *queue = (dqueue *) malloc(sizeof(dqueue) * size);
    return queue;
}

void push(dqueue *head, void *item) {
    if (head == NULL) {
        head = item;
    } else {
        void *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = item;
    }
}

void *pop(dqueue queue) {

}
