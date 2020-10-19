#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.c"
#include "stack.h"


int main(){
    char str[100], *aux;
    Stack * stk;

    //RECEBENDO OS VALORES DA STRING
    printf("Digite a string:");
    fgets(str,100,stdin);

    //COLOCANDO NA VARIÁVEL strSize O VALOR DO TAMANHO DA STRING PREENCHIDA
    int strSize = strlen(str)-1;
    int i = 0;

    //O PROCESSO SÓ SERÁ FEITO SE O TAMANHO DA STRING FOR ÍMPAR E SE FOR MAIOR QUE 1
    if(strSize %2 != 0 && strSize >= 1){

        //STACK CRIADA E ARMAZENADA NA VARIÁVEL stk NO TAMANHO DEFINIDO ANTERIOMENTE
        stk = stkCreate(strSize);

        //CHECANDO A ALOCAÇÃO DA VARIÁVEL stk
        if (stk != NULL){
            while (i < strSize){
                int checkPush = 0;
                //ALOCANDO UMA VARIÁVEL AUXILIAR PARA COLETAR OS VALORES DA STRING
                aux = (char *)malloc(sizeof(char));
                //COLETANDO OS VALORES DA STRING PASSADA E JOGANDO PARA DENTRO DA PILHA
                if(aux != NULL){
                    *aux = str[i];
                    checkPush = stkPush(stk, aux);
                }
                //CHECANDO SE O PUSH FOI REALIZADO CORRETAMENTE
                if (checkPush == 0){
                    printf("Algum push nao foi efetuado!");
                    return FALSE;
                }
                //SE O VALOR ENCONTRADO FOI O C
                if(*aux == 'C'){
                    i++;
                    //TIRAR O C DE DENTRO DO PILHA, POIS ELE NÃO SERÁ COMPARADO
                    stkPop(stk);
                    //COMPARAR OS VALORES QUE ESTÃO DENTRO DA PILHA (VALORES ANTES DO C), COM OS VALORES QUE AINDA RESTAM NA STRING (VALORES APÓS O C)
                    while(i < strSize){
                        if(str[i] == 'A' || str[i] == 'B'){
                            aux = (char *)stkPop(stk);
                            if(*aux != str[i]){
                                printf("A string nao tem formato xCy --");
                                return FALSE;
                            } else {
                                i++;
                            }
                        } else {
                            printf("Digite apenas 'A', 'B' ou 'C'!");
                            break;
                        }
                    }
                    printf("A string tem formato xCy!");
                    return TRUE;
                }
                i++;
            }
        }
        printf("Stk nao alocado!");
        return FALSE;
    } else{
        printf("A string nao tem formato xCy");
        return FALSE;
    }

}
