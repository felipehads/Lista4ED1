#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.c"
#include "stack.h"

int main(){
    char str[100], *aux;
    Stack *stk;
    int checkPush, strSize,stkSize, i = 0;

    //RECEBENDO OS VALORES DA STRING
    printf("Digite a string:");
    fgets(str,100,stdin);

    strSize = strlen(str)-1;

    //CHECANDO SE A STRING TEM APENAS UM CARACTERE, NESSE CASO É PALÍNDROMO
    if(strSize == 1){
        printf("E palíndromo!");
        return TRUE;
    }

    stkSize = strSize/2;

    //ALOCANDO UMA PILHA COM A METADE DO TAMANHO DA STRING, QUE É O TAMANHO NECESSÁRIO PARA SE COMPARAR A PILHA COM O RESTO DA STRING E CHECAR SE É PALÍNDROMO.
    stk = stkCreate(stkSize);

    //CHECANDO A ALOCAÇÃO DA PILHA
    if(stk != NULL){
        //RODANDO A STRING SÓ ATÉ A METADE
        while (i < stkSize){
            checkPush = 0;
            aux = (char *)malloc(sizeof(char));
            //CHECANDO A ALOCAÇÃOD A VARIÁVEL AUXILIAR
            if (aux != NULL){
                //PREENCHENDO UMA PILHA DE TAMANHO DA METADE DA STRING PARA COMPARAR COM O RESTO DA STRING
                *aux = str[i];
                checkPush = stkPush(stk, aux);
            }
            //CHECANDO SE A PILHA FOI PREENCHIDA CORRETAMENTE
            if (checkPush == 0){
                printf("Algum push nao foi efetuado!");
                exit(0);
            }
            i++;
        }

        //SE A STRING ORIGINAL TIVER TAMANHO ÍMPAR, É NECESSÁRIO PULAR A POSIÇÃO DO MEIO, JÁ QUE ELA NÃO VAI SER COMPARADA
        if (strSize%2 != 0){
            i = stkSize +1;
        } else {
            i = stkSize;
        }

        //COMPARANDO OS VALORES COLOCADOS NA PILHA COM O RESTO DOS VALORES DA STRING
        while (i < strSize){
            //UTILIZANDO O MÉTODO POP PARA CHECAR OS VALORES DE FORMA INVERSA
            aux = (char *)stkPop(stk);
            if(*aux != str[i]){
                printf("Nao e palindromo");
                return FALSE;
            }
            i++;
        }
        printf("A string e palindromo!");
        return TRUE;
    }
}