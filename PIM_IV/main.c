#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define TAM 50

char login[15] = "teste";
char login_dig[15];
char senha[15] = "teste";
char senha_dig[15];
int login_efetuado = 0;
char nome[TAM];
char cpf[TAM];
char telefone[TAM];
char email[TAM];
int datadiag[TAM];
char comorbidade[TAM];
int n;
int opcao;
int opcao2;
int idade[4];
int ano_atual[4];

void cadastro();

void teladelogin();

struct endereco{
char rua[30];
char numero[4];
char bairro[30];
char cidade[30];
char estado[2];
int cep[10];
}end;

struct nascimento{
int dia[2];
int mes[2];
int ano[4];
}nasc;

void teladelogin(){

    printf("\n\n\tBem Vindo(a) ao Programa de Cadastro de Pacientes\n");

    while(!login_efetuado){
    printf("\n\n\tDigite o Login: ");
    gets(login_dig);

    printf("\n\tDigite a Senha: ");
    gets(senha_dig);

    if (strcmp(login, login_dig) == 0 && strcmp(senha, senha_dig) == 0){
        printf("\n\n\tLogin Efetuado com Sucesso!\n\n");
        login_efetuado = 1;
    }
    else
        printf("\n\n\tLogin ou Senha Incorretos, Por favor Insira Novamente!\n\n");
}
}
int main(void)
{
    teladelogin();
    cadastro();
    strcpy(ano_atual,"2021");
    idade[4] = ano_atual[4]-nasc.ano[4];
    FILE *risco;
    risco = fopen("sec_saude.xlsx","ab");
    fprintf(risco,"%s\n",idade);
    fprintf(risco,"%s\n",end.cep);
    fclose(risco);
}
void cadastro(){
    FILE *ponteiro;
    ponteiro = fopen("arquivo.txt", "ab");
    printf("\n\tBem Vindo ao Doutor(a),Digite as Informacoes do Paciente nos Campos Abaixo\n\n\n");
    do{
    for (n=0 ; n<16 ; n++)
        {
     if(n == 0){
        printf("\tNome do Paciente: ");
            gets(nome);
            fprintf(ponteiro, "\n%s\n",nome);
        n++;
     }
     if(n == 1){
        printf("\n\tCPF do Paciente: ");
            gets(cpf);
            fprintf(ponteiro, "%s\n",cpf);
        n++;
     }
     if(n == 2){
        printf("\n\tTelefone do Paciente: ");
            gets(telefone);
            fprintf(ponteiro, "%s\n",telefone);
        n++;
     }
     if(n == 3){
        printf("\n\tEndereco do Paciente\n");
            printf("\n\t  Rua: ");
            gets(end.rua);
            fprintf(ponteiro, "%s ",end.rua);
        n++;
     }
     if(n == 4){
        printf("\n\t  Numero da Casa: ");
            gets(end.numero);
            fprintf(ponteiro, "%s, ",end.numero);
        n++;
     }
     if(n == 5){
        printf("\n\t  Bairro: ");
            gets(end.bairro);
            fprintf(ponteiro, "%s, ",end.bairro);
        n++;
     }
     if(n == 6){
        printf("\n\t  Cidade: ");
            gets(end.cidade);
            fprintf(ponteiro, "%s ",end.cidade);
        n++;
     }
     if(n == 7){
        printf("\n\t  Estado: ");
            gets(end.estado);
            fprintf(ponteiro, "%s, ",end.estado);
        n++;
     }
     if(n == 8){
        printf("\n\t  CEP: ");
            gets(end.cep);
            fprintf(ponteiro, "%s\n",end.cep);
        n++;
     }
     if(n == 9){
        printf("\n\tData de Nascimento do Paciente:\n");
            printf("\n\t  Dia: ");
            gets(nasc.dia);
            fprintf(ponteiro, "%s/",nasc.dia);
        n++;
     }
     if(n == 10){
        printf("\n\t  Mes: ");
            gets(nasc.mes);
            fprintf(ponteiro, "%s/",nasc.mes);
     }
     if(n == 11){
        printf("\n\t  Ano: ");
            gets(nasc.ano);
            fprintf(ponteiro, "%s\n",nasc.ano);
     }
     if(n == 12){
        printf("\n\tEmail do Paciente:");
            gets(email);
            fprintf(ponteiro, "%s\n",email);
        n++;
     }
     if(n == 13){
        printf("\n\tData do Diagnostico do Paciente: ");
            gets(datadiag);
            fprintf(ponteiro, "%s\n",datadiag);
        n++;
     }
     if(n == 14){
        printf("\n\tEle(a) tem alguma Comorbidade?\n");
          printf("\n\tSe sim Digite 1, Se nao Digite qualquer tecla: ");
            scanf("%d",&opcao);
            if(opcao==1){
            printf("\n\tQual o nome da dela: ");
            scanf("%s",comorbidade);
            fprintf(ponteiro, "%s\n",comorbidade);}
        n++;
     }
     if(n == 15){
         puts ("\n\n\tPaciente Cadastrado com Sucesso!");
         n++;
     }
     if(n == 16){
         printf("\n\n\tDeseja continuar?, Se sim digite 1, Se nao Digite qualquer tecla: ");
         scanf("%d",&opcao2);
         n++;
     }
     fclose(ponteiro);
    }
    }while(opcao2==1);
}

