#include "dqueue.h"

STATUS enter_queue(LinkQueue *queue, char *e) {
    QueuePtr s = (QueuePtr) malloc(sizeof(Node));
    if (!s) {
        return ERROR;
    }
    s->data = e;
    s->next = NULL;
    queue->rear->next = s;
    queue->rear = s;
    return OK;
}

char *de_queue(LinkQueue *queue) {
    if (queue->front == queue->rear) {
        return ERROR;
    }
    QueuePtr p;
    p = queue->front->next;
    queue->front->next = p->next;
    char *e = (char *) malloc(sizeof(char) * 1024);
    strcpy(e, p->data);
//    e = p->data;
    if (queue->rear == p) {
        queue->front = queue->rear;
    }
    return e;
}
