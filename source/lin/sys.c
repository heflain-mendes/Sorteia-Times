#include <stdio.h>
#include <stdlib.h>

/*
Arquivo para padronizar as ações de pausar e limpar 
a tela, assim o programa vai funcionar tanto no linux quanto no windows
*/

void pause(){

    setbuf(stdin, NULL);
    printf("\nPressione enter para continuar...\n");
    getchar();

}

void limpaTela(){

    system("clear || cls");

}