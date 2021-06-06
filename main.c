#include <stdio.h>
#include <stdlib.h>



    struct Aluno{
        char nome[256];
        int num_alu;
        char respostas[51];

    }; typedef struct Aluno alunos;

int main()
{
    system("color 1F");
    int op,corretas,por;
    do{
    system("cls");
    alunos aluno;
    char gabarito[51]={'a','b','c','d','e','e','d','c','b','a','a','b','c','d','e','e','d','c','b','a','a','b','c','d','e','e','d','c','b','a','a','b','c','d','e','e','d','c','b','a','a','b','c','d','e','e','d','c','b','a','\0'};
    printf("| VESTIBULAR FATEC |\n\n\n1. Comecar Prova\n2. Sair\n\nDigite uma opcao: ");
    scanf("%d",&op);
    fflush(stdin);
    system("cls");
    switch(op){

  case 1:
    corretas=0;
    printf("Digite seu nome: ");
    scanf("%[^\n]s",&aluno.nome);
    fflush(stdin);
    printf("\nDigite o numero da matricula: ");
    scanf("%d",&aluno.num_alu);
    fflush(stdin);
    system("cls");

        for(int i=0;i<50;i++){
        printf("| VESTIBULAR FATEC |\n\n");
        printf("Questao %d \nDigite a resposta: ",i+1);
        scanf("%c",&aluno.respostas[i]);
        if(aluno.respostas[i]!='a'&& aluno.respostas[i]!='b' && aluno.respostas[i]!='c' && aluno.respostas[i]!='d'&& aluno.respostas[i]!='e'){
            printf("\n\7ERRO, A resposta digitada nao deve ser diferente de (a,b,c,d,e)\n\n");
            i-=1;
        system("pause");
        }
        fflush(stdin);
        system("cls");
        }
        for(int j=0;j<50;j++){
                if (aluno.respostas[j]==gabarito[j]){
                    corretas+=1;
                }}
        por=corretas*0.50;
        printf("| VESTIBULAR FATEC |\n\n");
        printf("Numero da Matricula: %d\n\nQuestoes Corretas: %d\n\n",aluno.num_alu,corretas,por);

        FILE*pointer = fopen("aluno.txt","a+");
    if(pointer==NULL){
    printf("ERRO, IMPOSSIVEL LOCALIZAR O ARQUIVO!");
    }
    else{
    fprintf(pointer, "%s  %d  %d\n",aluno.nome,aluno.num_alu,corretas);
   }
    fclose(pointer);

    system("pause");

    break;

  case 2:
    exit(1);




    }






    }while(op!=2);
}
