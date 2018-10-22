#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Aluno
{
    int ra;
    char nome[40];
    char user[40];
    char pass[40];
}aluno;

carrega_disciplina(char disc[8])
{
    FILE * fp = fopen("Disciplinas.txt", "r");
    char nome_disc[40];
    char codigo_disc[8];
    char dados[100];
    char cred_disc[3];
    int found = 0;
    int i = 0;
    char *token;

    //Check para verificar se o arquivo foi aberto com sucesso
    if (fp == NULL)
   {
      printf("Erro ao abrir o arquivo.\n");
      exit(EXIT_FAILURE);
   }

      else
    {

         while(!feof(fp))
            {
                fgets(dados, 101, fp);

                //Separando a string
                token = strtok(dados, ",");
                strcpy(codigo_disc,token);

                if (strcmp(codigo_disc, disc) == 0)
                {
                    found++;
                    while( token != NULL )
                    {
                        token = strtok(NULL, ",");
                        if (i == 0) strcpy(nome_disc, token);
                        if (i == 1) strcpy(cred_disc, token);
                        i++;
                    }
                    printf("Nome: %s\n", nome_disc);
                    printf("Quantidade de Creditos: %s", cred_disc);
                    prerequisitos(codigo_disc);
                    return 0;
                 }
            }
            if (found == 0)
            {
                printf("\nCodigo nao encontrado!\n\n");
                return 1;
            }
            else return 0;
            fclose(fp);
   }
}

void prerequisitos (char codigo[8]) {
	FILE * fp = fopen("Prerequisitos.txt", "r");
	char dados[100];
	char codigo_disc[8];
	char codigo_prereq[8];
	int found = 0;
	char *token;
	int i = 0;
	
	if (fp == NULL)
   {
      printf("Erro ao abrir o arquivo.\n");
      exit(EXIT_FAILURE);
   }
   else {
   	while(!feof(fp))
            {
                fgets(dados, 101, fp);
                token = strtok(dados, ",");
                strcpy(codigo_disc,token);
                
                if (strcmp(codigo_disc, codigo) == 0)
                {
                	found++;
                	while( token != NULL )
                    {
                        token = strtok(NULL, ",");
                        if (i == 0) strcpy(codigo_prereq, token);
                        i++;
                    }
                    printf("Pre Requisito: %s\n", codigo_prereq);

                    return 0;
                 }
             }
                
            }
            if (found == 0)
            {
                printf("\nCodigo nao encontrado!\n\n");
                return 1;
            }
            else return 0;
            fclose(fp);
   	
   }


int cadastra_aluno(){
    printf("---------------Menu Cadastro de Alunos-------------\n\n");

    FILE *fp = fopen("alunos.txt","a");
     if (fp == NULL)
   {
      printf("Erro ao abrir o arquivo.\n");
      exit(EXIT_FAILURE);
   }

    int ra=0;
    char nome[40], user[10], pass[10];
    printf("Digite o RA do Aluno:\n");
    scanf("%d",&ra);
    printf("Digite o Nome do Aluno:\n");
    scanf("%s",nome);
    printf("Digite o login:\n");
    scanf("%s",user);
    printf("Digite a senha: \n");
    scanf("%s",pass);

    fprintf(fp,"%d %s %s %s\n",ra,nome,user,pass);
    printf("Usuario cadastrado");




}

int confere_login(char login[10], char senha[10]){
	FILE *fp = fopen("alunos.txt","r");
    int ra;
    char nome[40], user[10], pass[10];
    int found = 0;

	 if (fp == NULL)
   {
      printf("Erro ao abrir o arquivo.\n");
      exit(EXIT_FAILURE);
   }

    else
    {
         while(fscanf(fp, "%d %s %s %s", &ra, nome, user, pass)!= EOF)
            {
            if ( (strcmp(user, login) == 0) && (strcmp(pass, senha) == 0))
                {
                found++;
                }
            }
    }
     if (found == 0)
        {
        printf("\nUsuario/Senha incorretos!\n\n");
        return 1;
        }
        else return 0;
        fclose(fp);
    }

int login_sistema()
{
    char user[10];
    char pass[10];
    int erro = 1;

    while (erro == 1)
        {
        printf("Usuario: ");
        scanf("%s", &user);

        printf("Senha: ");
        scanf("%s", &pass);

        erro = confere_login(user, pass);
        }

    return 0;
}



int main()
{
	int op = 0;
    char disc[8];
	
     printf("-------- Bem vindo ao Sistema Academico --------\n\n");
     printf("                 Menu inicial\n");
     login_sistema();
     system("cls");

     printf("Logado com sucesso!\n");
     //sleep(1);
     system("cls");

     while (op == 0)
     {
         printf("Menu de opcoes: \n\n");
         printf("1 - Cadastro de Alunos\n2 - Consulta de Disciplinas\n");
         printf("Opcao escolhida: ");
         scanf("%d", &op);

      switch(op)
      {
        case 1:
            {
             cadastra_aluno();
             break;
            }
        case 2:
            {
            	
                int erro = 1;
                system("cls");
                printf("Consultas de disciplinas: \n\n");
                while (erro == 1)
                {
                    printf("Digite o codigo da disciplina: ");
                    scanf("%s", disc);
                    int i;
                    for(i=0;i<strlen(disc);i++)
                    {
                        disc[i]=toupper(disc[i]);
                    }
                    erro = carrega_disciplina(disc);
                }
                 break;
                
            }
        }
     }

}
