#ifndef STACK_H
#define STACK_H

#define TRUE 1
#define FALSE 0


typedef struct _stack_ Stack;

Stack *stkCreate(int max);
int stkPush(Stack *s, void * item);
void *stkPop(Stack *s);
void *stkDestroy(Stack *s);

#endif
