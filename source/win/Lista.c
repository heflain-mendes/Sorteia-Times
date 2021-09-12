#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Lista.h"

struct L{

    Time *info;
    int identificador;
    struct L *proximo;
    struct L *anterior;

};

struct D{

    int qtd;
    int mId;
    tipoNo *inicio;
    
};

int criarListaVazia(Descritor **D){

    *D = (Descritor*) malloc(sizeof(Descritor));

    if (*D != NULL){

        (*D)->qtd = 0;
        (*D)->mId = 0;
        (*D)->inicio = NULL;
        
        return 0;

    }else{

        printf("\nerro ao criar descritor\n");
        exit(1);

    }

}

int removeLista(Descritor **D){

    tipoNo *anterior;
    tipoNo *atual;

    if((*D)->qtd != 0){

        anterior = (*D)->inicio;
        atual = anterior->proximo;

        while (atual != NULL){

            free(anterior->info);
            free(anterior);

            anterior = atual;
            atual = atual->proximo;

        }

        free(anterior->info);
        free(anterior);

        free(*D);

    }

    return 0;

}

int removeGrupo(Descritor **D){

    tipoNo *anterior;
    tipoNo *atual;

    if((*D)->qtd != 0){

        anterior = (*D)->inicio;
        atual = anterior->proximo;

        while (atual != NULL){
            free(anterior);

            anterior = atual;
            atual = atual->proximo;

        }

        free(anterior);

        free(*D);

    }

    return 0;

}

int limpaGrupo(Descritor **grupo){

    tipoNo *aux, *aux2;
    aux = (*grupo)->inicio;

    while(aux != NULL){

        aux2 = aux->proximo;
        free(aux);
        aux = aux2;

    }

    (*grupo)->inicio = NULL;
    (*grupo)->qtd = 0;

    return 0;

}

tipoNo* criaNo(){

    tipoNo *novoNo;

    novoNo = (tipoNo*) malloc(sizeof(tipoNo));

    if(novoNo != NULL){

        novoNo->anterior = NULL;
        novoNo->proximo = NULL;
        novoNo->identificador = 0;

        return novoNo;

    }else{

        printf("\nerro ao criar novo no\n");
        exit(1);
        
    }

}

int recuperaMID(Descritor *D){

    tipoNo *atual;
    int MID = 0;

    atual = D->inicio;

    while(atual != NULL){

        if(MID < atual->identificador){

            MID = atual->identificador;

        }

        atual = atual->proximo;

    }

    return MID;

}

int removeNo(Descritor *D){

    int a;
    printf("Digite o numero do identificador do time a ser removido: ");
    scanf("%d", &a);

    tipoNo *atual;
    atual = selecionaNoId(D, a);

    if(atual != NULL){

        if (atual->anterior == NULL){//caso seja o primeiro no da lista
    
            D->inicio = atual->proximo;

            if (atual->proximo != NULL){

                atual->proximo->anterior = NULL;

            }

        }else{

            if (atual->proximo != NULL){//caso seja algum n? do meio da lista
            
                atual->anterior->proximo =  atual->proximo;
                atual->proximo->anterior = atual->anterior;

            }else{//caso seja o n? do fim da lista

                atual->anterior->proximo = NULL;

            }

        }

        a = atual->identificador;

        free(atual->info);
        free(atual);

        D->qtd--;

        if(D->mId == a){

            D->mId = recuperaMID(D);

        }

        return 0;

    }

    return -1;

}

int insereNaOrdem(Descritor *D, tipoNo *novoNo){

    tipoNo *atual;
    int resCom;//resultado da compara??o

    atual = D->inicio;

    if(novoNo->identificador == 0){

        novoNo->identificador = ++(D->mId);

    }

    D->qtd++;

    if (D->inicio == NULL){/*lista est? vazia*/

        D->inicio = novoNo;
        return 0;

    }else{
        
        while (atual != NULL){

            resCom = strcmp(novoNo->info->nome, atual->info->nome);

            if (resCom < 0){

                if(atual->anterior != NULL){

                    atual->anterior->proximo = novoNo;

                }else{

                    D->inicio = novoNo;

                }

                novoNo->anterior = atual->anterior;
                novoNo->proximo = atual;
                atual->anterior = novoNo;

                return 0;
                
            }else{

                if (resCom == 0){

                    D->qtd--;
                    D->mId = recuperaMID(D);
                    return -1;

                }else{

                    if(atual->proximo == NULL){

                        novoNo->anterior = atual;
                        atual->proximo = novoNo;

                        return 0;

                    }

                }

            }

            atual = atual->proximo;

        }

    }

    return 0;

}

int editaNo(Descritor *D){

    int a;
    Time *bkp;
    tipoNo *novoNo;

    printf("Digite o numero do identificador do time a ser alterado: ");
    scanf("%d", &a);

    tipoNo *atual;
    atual = selecionaNoId(D, a);

    if(atual != NULL){

        bkp = (Time*) malloc(sizeof(Time));

        strcpy(bkp->nome, atual->info->nome);
        strcpy(bkp->estado, atual->info->estado);

        novoNo = criaNo();
        novoNo->info = bkp;
        novoNo->identificador = atual->identificador;

        a = editaTime(atual->info);

        if(a == 1){

            if (atual->anterior == NULL){//caso seja o primeiro no da lista

                D->inicio = atual->proximo;

                if (atual->proximo != NULL){

                    atual->proximo->anterior = NULL;

                }

            }else{

                if (atual->proximo != NULL){//caso seja algum n? do meio da lista

                    atual->anterior->proximo =  atual->proximo;
                    atual->proximo->anterior = atual->anterior;

                }else{//caso seja o n? do fim da lista

                    atual->anterior->proximo = NULL;

                }

            }

            D->qtd--;

            if(insereNaOrdem(D, atual) == 0){

                free(bkp);
                free(novoNo);
                return 0;//time editado

            }else{

                insereNaOrdem(D, novoNo);
                return -2;//time j? cadastrado

            }

        }

    }else{

        return -1;//id n?o encontrado

    }

    return 0;//usuario n?o fez altera??es

}

int imprimeLista(Descritor *D){

    tipoNo *atual;

    atual = D->inicio;

    if(atual != NULL){

        printf(" ______________________________________________________________________________\n");
        printf("|  ID  |               TIME                |               ESTADO              |\n");
        printf("|______|___________________________________|___________________________________|\n");

        while(atual != NULL){

            printf("|%-6d|",atual->identificador);
            imprimeTime(atual->info);
            printf("\n");

            atual = atual->proximo;
            

        }

        printf("|______|___________________________________|___________________________________|\n");

        return 0;

    }else{

        return -1;

    }

}

int insereOrdenado(Descritor *D){

    tipoNo *novoNo;

    novoNo = criaNo();

    novoNo->info = criarTime();

    if(insereNaOrdem(D, novoNo) == -1){//nome j? existe na lista

        free(novoNo);
        return -1;

    }else{

        return 0;

    }
    
}

bool existe(int *vetor, int tam, int n){

    for(int i = 0; i < tam; i++){

        if(vetor[i] == n){

            return true;

        }

    }    

    return false;

}

tipoNo* selecionaNo(Descritor *D, int n){/*o primeiro no e o no 0*/

    tipoNo *retorno;
    int cont = -1;
    retorno = D->inicio;

    while(retorno != NULL){

        cont++;

        if(cont == n){

            return retorno;

        }

        retorno = retorno->proximo;

    }

    return NULL;

}

tipoNo* selecionaNoId(Descritor *D, int id){/*busca no pelo identificador*/

    tipoNo *retorno;
    retorno = D->inicio;

    while(retorno != NULL){

        if(retorno->identificador == id){

            return retorno;

        }

        retorno = retorno->proximo;

    }

    return NULL;

}

int imprimirGrupos(Descritor *D, Descritor *A, Descritor *B){

    tipoNo *atA, *atB, *no;
    atA = A->inicio;
    atB = B->inicio;

    if(atA != NULL){

        printf(" _________________________________GRUPO A__________________________________________________________________GRUPO B________________________________\n");
        printf("|               TIME                |               ESTADO              | |               TIME                |               ESTADO              |\n");
        printf("|___________________________________|___________________________________| |___________________________________|___________________________________|\n");

        while(atA != NULL){

            no = selecionaNoId(D, atA->identificador);

            printf("|");

            if(no != NULL){

                imprimeTime(no->info);

            }else{

                printf("%-35s|%-35s|", "N?o encontrado", "");

            }

            printf("X|");

            no = selecionaNoId(D, atB->identificador);

            if(no != NULL){

                imprimeTime(no->info);

            }else{

                printf("%-35s|%-35s|", "N?o encontrado", "");

            }
            
            printf("\n");

            atA = atA->proximo;
            atB = atB->proximo;

        }

        printf("|___________________________________|___________________________________| |___________________________________|___________________________________|\n");

        return 0;

    }else{

        return -1;

    }
}

int sortearGrupos(Descritor *D, Descritor *grupoA, Descritor *grupoB){

    int n;
    tipoNo *auxA, *auxB;
    
    if(D->qtd % 2 == 0 || D->qtd == 0){//lista origem precisa ser par e diferente de 0

        if(grupoA->inicio != NULL){

            limpaGrupo(&grupoA);

        }

        if(grupoB->inicio != NULL){

            limpaGrupo(&grupoB);

        }

        int nums[D->qtd];

        for(int i = 0; i < D->qtd; i++){//colocar numeros aleatorios no vetor

            n = rand() % D->qtd;

            while(existe(nums, i, n)){

                n = rand() % D->qtd;

            }

            nums[i] = n;

        }

        for(int i = 0; i < D->qtd; i++){//colocar elementos nos grupos de acordo com os numeros aleatorios do vetor

            auxA = grupoA->inicio;
            auxB = grupoB->inicio;

            if(auxA == NULL && auxB == NULL){

                auxA = criaNo();
                auxA->identificador = selecionaNo(D, nums[i])->identificador;
                grupoA->inicio = auxA;

                auxB = criaNo();
                auxB->identificador = selecionaNo(D, nums[i+1])->identificador;
                grupoB->inicio = auxB;

            }else{

                while(auxA->proximo != NULL){

                    auxA = auxA->proximo;

                }

                auxA->proximo = criaNo();
                auxA->proximo->identificador = selecionaNo(D, nums[i])->identificador;
                auxA->proximo->anterior = auxA;

                while(auxB->proximo != NULL){

                    auxB = auxB->proximo;

                }

                auxB->proximo = criaNo();
                auxB->proximo->identificador = selecionaNo(D, nums[i+1])->identificador;
                auxB->proximo->anterior = auxB;

            }

            grupoA->qtd++;
            grupoB->qtd++;
            i++;

        }

        imprimirGrupos(D, grupoA, grupoB);

        return 0;

    }else{

        return -1;

    }
}