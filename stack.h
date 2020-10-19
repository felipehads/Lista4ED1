#ifndef STACK_H
#define STACK_H

typedef struct _stack_ Stack;

Stack * stkCreate(int maxItens);
int stkPush(Stack *s, void * item);
void * stkPop(Stack *s);
void * stkDestroy(Stack *s);

#endif
