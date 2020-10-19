#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct _queue_ {
    int front;
    int rear;
    int maxItens;
    void **qItems;
}Queue;

int qDestroy(Queue *q){
    if(q != NULL){
        if(q -> front <= q->rear){
            free(q->qItems);
            free(q);
            return TRUE;
        }
    }
    return FALSE;
}