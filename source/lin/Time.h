#define TAM 35 

typedef struct T{

    char nome[TAM];
    char estado[TAM];
    
}Time;

Time* criarTime();
int editaTime(Time *t);
int imprimeTime(Time *t);