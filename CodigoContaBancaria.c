#include <stdio.h>
#include <stdlib.h>

    struct Client{
    char name[256];
    int cpf;
};typedef struct Client clientes;

    struct Account {
    int acc_id;
    struct Client clientes;
    float balance;
};typedef struct Account accounts;

int main(){
   system("color 1F");
   accounts acc1;
   int opc;
   float dep,saq;
   acc1.balance=0;
   printf("| CADASTRO FATEC BANK |\n\n");
   printf("Digite seu nome: ");
    scanf("%[^\n]s", acc1.clientes.name);
   printf("\nDigite seu CPF: ");
    scanf("%d",&acc1.clientes.cpf);
   printf("\nDigite o numero da conta: ");
    scanf("%d",&acc1.acc_id);
    system("cls");
    do{
    system("cls");
   printf("| FATEC BANK |\n\nOla,%s\n\nSeu Saldo Atual: R$ %2.f\n\n",acc1.clientes.name,acc1.balance);
   printf("1. Deposito\n2. Saque\n3. Sair\n\n\nDigite a opcao desejada: ");
    FILE*pointer = fopen("clientlist.txt","a+");
   if(pointer==NULL){
    printf("ERRO, IMPOSSIVEL LOCALIZAR O ARQUIVO!");
   }
   else{
    fprintf(pointer, "Nome do cliente:%s\nCPF:%d\nConta:%d",acc1.clientes.name,acc1.clientes.cpf,acc1.acc_id);
   }
   fclose(pointer);
    scanf("%d",&opc);
    switch(opc){

    case 1:
        system("cls");
        printf("| DEPOSITO |\n\nDigite a quantidade que deseja depositar: ");
        scanf("%f",&dep);
        if(dep<0){
            printf("\n\7ERRO, O Valor a ser depositado deve ser maior que R$ 0.00\n");
            system("Pause");

        }else{
            acc1.balance+=dep;
            printf("\nDeposito realizado com sucesso!\n");
            system("Pause");
        }
        break;
    case 2:
        system("cls");
        printf("| SAQUE |\n\nDigite a quantidade que deseja sacar: ");
        scanf("%f",&saq);
        if(saq>acc1.balance){
            printf("\n\7ERRO, Valor digitado indisponivel para saque!\n");
            system("Pause");

        }else{
            acc1.balance-=saq;
            printf("\nSaque realizado com sucesso!\n");
            system("Pause");
        }
        break;
    case 3:
        exit(1);
    default:
        printf("\n\7Opcao invalida!\n");

    }}while(opc!=3);
}

