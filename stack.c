#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct _stack {
    int maxItens;
    int top;
    void **itens;
} Stack;

Stack *stkCreate(int maxItens){
    Stack *s;
    if(maxItens > 0){
        s = (Stack *)malloc(sizeof(Stack));
        if(s != NULL){
            s->itens = (void **)malloc(sizeof(void *)*maxItens);
            if(s->itens != NULL){
                s->maxItens = maxItens;
                s->top = -1;
                return s;
            }
        }
    }
    return NULL;
};

int stkPush(Stack *s, void * item){
    if(s != NULL){
        if(s->itens != NULL){
            if(s->top < s->maxItens-1){
                s->top++;
                s->itens[s->top]=item;
                return TRUE;
            }
        }
    }
    return FALSE;
};


void * stkPop(Stack *s){
    void * aux;
    if(s != NULL){
        if(s->itens != NULL){
            if((s->top >= 0){
                aux = s->itens[s->top];
                s->top--;
                return aux;
            }
        }
    }
    return NULL;
};

void * stkDestroy(Stack *s){
    if(s != NULL){
        if(s->itens != NULL){
            if(s->top < 0){
                free(s->itens);
                free(s);
                return TRUE;
            }
        }
    }
    return FALSE;
};
