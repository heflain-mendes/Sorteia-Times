#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "sys.h"
#include "Lista.h"

int main(){

    Descritor *Time;
    Descritor *grupoA; 
    Descritor *grupoB;
    int a = 1;

    int op;
    int err;

    /*inicializar listas*/
    criarListaVazia(&Time);
    criarListaVazia(&grupoA);
    criarListaVazia(&grupoB);
    
    setlocale(LC_ALL,"portuguese");

    while(1){

        limpaTela();

        printf("----------------MENU------------------\n");
        printf("1 - Cadastrar time\n");
        printf("2 - Editar time\n");
        printf("3 - Remover time\n");
        printf("4 - Imprimir times\n");
        printf("5 - Sortear grupos\n");
        printf("6 - Imprimir grupos\n");
        printf("7 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);
       
        switch (op){

        case 1:
            /* cadastrar time*/
            limpaTela();

            if(insereOrdenado(Time) == -1){

                printf("Este time já está na lista!");
            }else{
                printf("Time cadastrado com sucesso!");
                a = 1;
            }
            pause();
            break;
        case 2:
            /* editar time*/
            limpaTela();
            err = editaNo(Time);
            if(err != 0){

                if(err == -1){

                    printf("Identificador não encontrado!");

                }else{

                    printf("Este time já está na lista!");
                }

            }else{

                printf("Time editado com sucesso!");
            }
            pause();
            break;
        case 3:
            /* remover time*/
            limpaTela();
            if(removeNo(Time) == -1){

                printf("Identificador não encontrado!");

            }else{

                printf("Time removido!");
                a = 1;
            }
            pause();
            break;
        case 4:
            /* imprimir times*/
            limpaTela();
            if(imprimeLista(Time) == -1){

                printf("Lista vazia!");

            }
            pause();
            break;
        case 5:
            /* sortear grupos*/
            limpaTela();
            
            if(sortearGrupos(Time, grupoA, grupoB) == -1){

                printf("Quantidade de times insuficiente para formar grupos!");
                a = 1;
            }else{
                a = 0;
            }
            pause();
            break;
        case 6:
            /* imprimir grupos*/
            limpaTela();
            if(a == 0){
                if(imprimirGrupos(Time, grupoA, grupoB) == -1){

                    printf("Grupos não formados!");

                }
            }else{   
                printf("Grupos invalidos!!!\nPor favor, sorteie os grupos novamente\n");
            }
            pause();
            break;
        case 7:
            /*sair*/
            limpaTela();
            removeLista(&Time);
            removeGrupo(&grupoA);
            removeGrupo(&grupoB);
            printf("Saindo...\n");
            exit(0);
        default:
            /*opcao invalida*/
            limpaTela();
            printf("Opção invalida!\n");
            pause();
            break;
        }

    }

    return 0;

}
