#include <stdio.h>
#include "dqueue.h"

int main()
{
    Node node = {"a", NULL};
    Node node1 = {"b", &node};
    Node node2 = {"c",&node1};
    Node node3 = {"delete",&node2};

    LinkQueue *queue;// = (LinkQueue *)malloc(sizeof(LinkQueue));
//    queue->front=(QueuePtr)malloc(sizeof(QueuePtr));
    if(!queue){
        return 1;
    }
    queue->front->next=&node3;
    queue->rear=&node;

    enter_queue(queue,"789");

//    char *e = (char *)malloc(sizeof(char)*1024);
    char *e = de_queue(queue);
    printf("e->data = %s\n",e);

    printf("%s\n", "hello,world");
    return 0;
}