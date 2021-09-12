#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Time.h"

Time* criarTime(){

    int a;
    Time *t = (Time*) malloc(sizeof(Time));
   
    setbuf(stdin, NULL);
    printf("Digite o nome do time: ");
    fgets(t->nome, TAM, stdin);
    a = strlen(t->nome)-1;

    t->nome[a] = '\0'; /* removendo o \n que fica ao usar o fgets*/

    printf("Digite o estado do time: ");
    fgets(t->estado, TAM, stdin);
    a = strlen(t->estado)-1;
    t->estado[a] = '\0';

    return t;
    
}

int editaTime(Time *t){

    char aux, buffer;
    int retorno = 0;
    int a;

    setbuf(stdin, NULL);
    printf("o nome atual do time ? %s e sua seu estado ? %s\n", t->nome, t->estado);

    printf("deseja trocar o nome do time[S/N]: ");
    scanf("%c", &aux);
    scanf("%c", &buffer);
    

    if (aux == 'S' || aux == 's'){

        printf("Digite o novo nome do time: ");
        fgets(t->nome, TAM, stdin);
        a = strlen(t->nome);
        a--;
        t->nome[a] = '\0'; /* removendo o \n que fica ao usar o fgets*/
        retorno = 1;

    }

    printf("deseja trocar o nome do estado do time[S/N]: ");
    scanf("%c", &aux);
    scanf("%c", &buffer);
    
    if (aux == 'S' || aux == 's'){

        printf("Digite o novo nome do estado do time: ");
        fgets(t->estado, TAM, stdin);
         a = strlen(t->estado);
        a--;
        t->estado[a] = '\0';
        retorno = retorno == 1 ? 1 : 0;

    }
    
    return retorno; //se retorna 1 foi editado
}

int imprimeTime(Time *t){
    
    if (t == NULL){

        return -1;

    }else{

        printf("%-35s|%-35s|",t->nome, t->estado);
        return 0;

    }
    
}


