#include <stdio.h>
#include <stdlib.h>>
#include <string.h>


typedef struct Aluno
{
    int ra;
    char nome[40];
    char user[40];
    char pass[40];
}aluno;


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
     printf("-------- Bem vindo ao Sistema Academico --------\n\n");
     printf("                 Menu inicial\n");
     login_sistema();
     system("cls");

     printf("Logado com sucesso!\n");
}
