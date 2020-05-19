#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0

typedef char *ElementType;

typedef char STATUS;

typedef struct Node {
    char *data;
    struct Node *next;
} Node, *QueuePtr;

typedef struct {
    QueuePtr front, rear;
} LinkQueue;

STATUS enter_queue(LinkQueue *queue, char *e);

char *de_queue(LinkQueue *queue);