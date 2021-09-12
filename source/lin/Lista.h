#include "Time.h"
#include <stdbool.h>

typedef struct L tipoNo;
typedef struct D Descritor;

int criarListaVazia(Descritor **D);
int removeLista(Descritor **D);
int removeGrupo(Descritor **D);
int limpaGrupo(Descritor **grupo);
tipoNo* criaNo();
int recuperaMID(Descritor *D);
int removeNo(Descritor *D);
int insereNaOrdem(Descritor *D, tipoNo *novoNo);
int editaNo(Descritor *D);
int imprimeLista(Descritor *D);
int insereOrdenado(Descritor *D);
bool existe(int *vetor, int tam, int n);
tipoNo* selecionaNo(Descritor *D, int n);
tipoNo* selecionaNoId(Descritor *D, int id);
int imprimirGrupos(Descritor *D, Descritor *A, Descritor *B);
int sortearGrupos(Descritor *D, Descritor *grupoA, Descritor *grupoB);