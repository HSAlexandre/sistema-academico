#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char Guser[10];
char Gsenha[10];


int realizar_matricula()
{
        int semestre;

        system("cls");
        printf("    __________________________________________________________________ \n");
        printf("   |                 Menu de realizacao de matricula                  |\n");
        printf("   |                                                                  |\n");
        printf("   |             Para voltar ao menu anterior, digite 00.             |\n");
        printf("   |__________________________________________________________________|\n");

        printf("    Digite o semestre: ");
        scanf("%d", &semestre);

        switch(semestre)
        {
            case 00: return 0;
        }



/*
        Digite o semestre: 2
        Digite a disciplina: SI200
        Digite a disciplina: AA100
        Digite a disciplina: XX000
        Transação efetuada com sucesso

*/
}

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
      printf("    Erro ao abrir o arquivo.\n");
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
                    printf("\n    Nome: %s\n", nome_disc);
                    printf("    Quantidade de Creditos: %s", cred_disc);
                    prerequisitos(codigo_disc);
                    return 0;
                 }
            }
            if (found == 0)
            {
                printf("\n    Codigo nao encontrado!\n\n");
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
      printf("    Erro ao abrir o arquivo.\n");
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
                	i = 0;
                	while( token != NULL )
                    {
                        token = strtok(NULL, ",");
                        if (i == 0) strcpy(codigo_prereq, token);
                        i++;
                    }

                    token = strtok(codigo_prereq, "\n");
                    strcpy(codigo_prereq, token);

                    printf("    Pre Requisito: %s - ", codigo_prereq);
                    nome_prered_disc(codigo_prereq);
                 }
             }
            }
            if (found == 0)
            {
                printf("    Sem pre requisito.\n\n");
                return 1;
            }
            else return 0;
            fclose(fp);
   }


   void nome_prered_disc(char disc[8])
{
    FILE * fp = fopen("Disciplinas.txt", "r");
    char nome_disc[40];
    char codigo_disc[8];
    char dados[100];
    char cred_disc[3];
    int found = 0;
    int i = 0;
    char *token;
    char *token2;

    token2 = strtok(disc, "\n");
    strcpy(disc, token2);

    //Check para verificar se o arquivo foi aberto com sucesso
    if (fp == NULL)
   {
      printf("    Erro ao abrir o arquivo.\n");
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
                        i++;
                    }
                    printf("%s\n", nome_disc);
                 }
            }
            fclose(fp);
   }
}

int cadastra_aluno(){
    system("cls");
     printf("    __________________________________________________________________ \n");
     printf("   |                    Menu Cadastro de Alunos                       |\n");
     printf("   |                                                                  |\n");
     printf("   |__________________________________________________________________|\n");
	char lixo[10];
    FILE *fp = fopen("alunos.txt","a");

     if (fp == NULL)
   {
      printf("    Erro ao abrir o arquivo.\n");
      exit(EXIT_FAILURE);
   }

    int ra=0;
    char nome[40], user[10], pass[10];

    printf("\n    Digite o RA do Aluno: ");
    scanf("%d",&ra);

    printf("    Digite o Nome do Aluno: ");
    gets(lixo);
	fgets(nome,41,stdin);
	strtok(nome,"\n");

    printf("    Digite o login: ");
    scanf("%s",user);

    printf("    Digite a senha: ");
    scanf("%s",pass);


    fprintf(fp, "\n");
    fprintf(fp,"%d,%s,%s,%s",ra,nome,user,pass);
    printf("    Usuario cadastrado.\n");
}

int confere_login(char login[10], char senha[10]){
	FILE *fp = fopen("alunos.txt","r");
    char ra[10], nome[40], user[10], pass[10], dados_login[70];
    int found = 0;
    int cont = 0;
    char *token_login;
    char *token_senha;

	 if (fp == NULL)
   {
      printf("    Erro ao abrir o arquivo.\n");
      exit(EXIT_FAILURE);
   }

   while(!feof(fp))
   {
       fgets(dados_login, 71, fp);

       token_login = strtok(dados_login, ",");
       strcpy(ra, token_login);

       while(token_login != NULL )
       {
           token_login = strtok(NULL, ",");
           cont = 0;

           if (cont == 0) strcpy(nome, token_login);
           cont++;
           token_login = strtok(NULL, ",");
           if (cont == 1) strcpy(user, token_login);
           cont++;
           token_login = strtok(NULL, ",");
           if (cont == 2) strcpy(pass, token_login);
           token_login = strtok(NULL, ",");
           token_senha = strtok(pass, "\n");
           strcpy(pass, token_senha);

           if ((strcmp(user, login) == 0) && (strcmp(pass, senha) == 0) )
           {
               found++;
           }
       }
   }
        if (found == 0)
            {
            printf("\n    Usuario/Senha incorretos!\n\n");
            return 1;
            }
        return 0;
        fclose(fp);
    }

int login_sistema()
{
    char user[10], pass[10];
    int erro = 1;

    while (erro == 1)
        {
        printf("    Usuario: ");
        scanf("%s", user);

        printf("    Senha: ");
        scanf("%s", pass);

        erro = confere_login(user, pass);
        strcpy(Guser,user);
        strcpy(Gsenha,pass);
        }

    return 0;
}



int main()
{
	int op = 8;
	char op1[10];
    char disc[8];

     printf("    __________________________________________________________________ \n");
     printf("   |                Bem vindo ao Sistema Academico                    |\n");
     printf("   |                                                                  |\n");
     printf("   |                         Menu inicial                             |\n");
     printf("   |__________________________________________________________________|\n");
     login_sistema();
     system("cls");

     printf("    Logado com sucesso!\n");
     //sleep(1);
     system("cls");

     while (1)
     {
         system("cls");
         printf("   __________________________________________________________________ \n");
         printf("  |                                                                  |\n");
         printf("  |   Menu de opcoes:                                                |\n");
         printf("  |                                                                  |\n");
         printf("  |   1 - Cadastro de Alunos                                         |\n");
         printf("  |   2 - Consulta de Disciplinas                                    |\n");
         printf("  |   3 - Realizar matricula                                         |\n");
         printf("  |   4 - Deslogar                                                   |\n");
         printf("  |   5 - Sair                                                       |\n");
         printf("  |__________________________________________________________________|\n\n");
         printf("    Opcao escolhida: ");
         scanf("%s", op1);
         op = atoi(op1);

      switch(op)
      {
        case 1:
            {
             cadastra_aluno();
             printf("\n\n\n");
             system("pause");
             system("cls");
             break;
            }
        case 2:
            {
                int erro = 1;
                system("cls");
                printf("    __________________________________________________________________\n");
                printf("   |                  Consultas de disciplinas:                       |\n");
                printf("   |__________________________________________________________________|\n");
                while (erro == 1)
                {
                    printf("\n    Digite o codigo da disciplina: ");
                    scanf("%s", disc);
                    int i;
                    for(i=0;i<strlen(disc);i++)
                    {
                        disc[i]=toupper(disc[i]);
                    }
                    erro = carrega_disciplina(disc);
                }
                printf("\n\n\n");
                system("pause");
                system("cls");
                break;
            }

        case 3:
            {
                realizar_matricula();
                printf("\n\n\n");
                system("pause");
                system("cls");
                break;
            }

        case 4:
            {
                system("cls");
                 printf("    __________________________________________________________________ \n");
                 printf("   |                Bem vindo ao Sistema Academico                    |\n");
                 printf("   |                                                                  |\n");
                 printf("   |                         Menu inicial                             |\n");
                 printf("   |__________________________________________________________________|\n");
                login_sistema();
                system("cls");
                break;
            }
        case 5:
            {
              system("cls");
              printf("   __________________________________________________________________ \n");
              printf("  |                                                                  |\n");
              printf("  |              Obrigado por utilizar nosso sistema! :)             |\n");
              printf("  |                                                                  |\n");
              printf("  |__________________________________________________________________|\n");
              exit(1);
            }
        }
    }
}
