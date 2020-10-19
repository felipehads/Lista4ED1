#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct _stack {
    int maxItens;
    int top;
    void **itens;
} Stack;

Stack *stkCreate(int maxItens){

};

int stkPush(Stack *s, void * item){

};


void * stkPop(Stack *s){

};

void * stkDestroy(Stack *s){
    
};