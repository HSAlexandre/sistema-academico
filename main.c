#include <stdio.h>
#include <stdlib.h>>
#include <string.h>

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
                    printf("Quantidade de Creditos: %s\n", cred_disc);
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
        printf("\nUsuario ou Senha inválidos.\n\n");
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
    //Declaração das variáveis
    int op = 0;
    char disc[8];

     printf("-------- Bem vindo ao Sistema Academico --------\n\n");
     printf("                 Menu inicial\n");
     login_sistema();
     system("cls");

     printf("Logado com sucesso!\n");
     sleep(1);
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
             //Danilel tá fazendo esse
             //break;
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
