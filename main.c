#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char Guser[10];
char Gsenha[10];
char Gra[8];

typedef struct aux{
	char ra[8];
	char sigla[8];
	char sem[2];
	char nota[3];
	char falta[3];
}ax;


int realizar_matricula();
char * codigo_prereq(char codigo[8]);
int carrega_disciplina(char disc[8]);
char * prerequisitos (char codigo[8]);
void nome_prered_disc(char disc[8]);
int cadastra_aluno();
int login_sistema();
int confere_login(char login[10], char senha[10]);
int alterar_nota();
int cred_disc(char disc[8]);


int cred_disc(char disc[8])
{
    FILE * fp = fopen("Disciplinas.txt", "r");
    char nome_disc[40];
    char codigo_disc[8];
    char dados[100];
    char cred_disc[3];
    int found = 0;
    int cred_discint;
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
					cred_discint = atoi(cred_disc);
                    return cred_discint;
                 }
            }
            fclose(fp);
   }
}

int alterar_nota(){
	char ra[8],cod_disc[8],falta[3],nota[3],disc[8],dados[100];
	int cont=0,cont2=0,cont3=0;
	char * token;
	ax* a;
	FILE * fp = fopen("AlunosDisciplinas.txt","r");


	 if (fp == NULL)
        {
            printf("    Erro ao abrir o arquivo.");
            exit(EXIT_FAILURE);
        }
		while(!feof(fp))
		{
			fgets(dados,101,fp);
			cont2++;
			printf("%d\n", cont2);
		}
		fclose(fp);
		   //ax a [cont2];
		a = malloc (cont2*sizeof(ax));
	    fp = fopen("AlunosDisciplinas.txt","r");

		 while(!feof(fp))
                 {
                    fgets(dados, 101, fp);
					printf("%s",dados);
                    token = strtok(dados, ",");
                    strcpy(a[cont3].ra, token);



                        cont = 0;


						while(token != NULL)//RA, COD DISC, SEMEST, NOT, FALTA
                        {
                            token = strtok(NULL,",");
                            if (cont == 0){
							strcpy (a[cont3].sigla, token);
							cont3--;
							}
                            if (cont == 1){ strcpy (a[cont3].sem, token); cont3--;}
                            if (cont == 2){ strcpy (a[cont3].nota, token); cont3--;}
                            if (cont == 3) strcpy (a[cont3].falta, token);
                            cont++;
                            cont3++;

						}

			}


						printf("Digite o codigo da disciplina ");
						scanf("%s",disc);
						printf("Digite a nota para alterar ");
						scanf("%s",nota);
						printf("Digite a falta para alterar ");
						scanf("%s",falta);




					for(cont=0;cont<cont2;cont++){
						if(((strcmp(Gra,a[cont].ra))==0)&&((strcmp(disc,a[cont].sigla)==0))){
							strcpy(a[cont].nota,nota);
							strcpy(a[cont].falta,falta);

						}


					}


					fclose(fp);
					fp= fopen("AlunosDisciplinas.txt","w");


					for(cont=0;cont<cont2;cont++){
						fprintf(fp,"%s,%s,%s,%s,%s\n",a[cont].ra,a[cont].sigla,a[cont].sem,a[cont].nota,a[cont].falta);

					}
					fclose(fp);

					printf("Nota alterada\n");

}
int realizar_matricula()
{
        FILE *fp;
        char semestre[2];
        char dados[100], ra[8], disc[8], arq_sem[2], nota[4], falta[3], * codigo_prereqq[8], notalixo[3];
        char cod_disc[8], nota1[] = "0", falta1[] = "0";
        char *token;
        char *token1;
        char * teste[100];
        int cont = 0, found = 0, contcred=0;

        system("cls");
        printf("    __________________________________________________________________ \n");
        printf("   |                 Menu de realizacao de matricula                  |\n");
        printf("   |                                                                  |\n");
        printf("   |           Para voltar ao menu anterior, digite XX000.            |\n");
        printf("   |__________________________________________________________________|\n");

        if (fp == NULL)
        {
            printf("    Erro ao abrir o arquivo.");
            exit(EXIT_FAILURE);
        }

        else
        {
            printf("    Para sair, digite XX000\n");
            printf("    Digite o semestre: ");
            scanf("%s", semestre);

            if(strcmp(semestre,"XX000") == 0)
             {
                 return 0;
             }

            while(strcmp(cod_disc, "XX000")!= 0)
            {
   		 	 	 fp = fopen("AlunosDisciplinas.txt","r");
            	
                 printf("Digite o codigo da disciplina: ");
                 scanf("%s", cod_disc);

                 strcpy(codigo_prereqq, codigo_prereq(cod_disc));


                 while(!feof(fp))
                 {
                 	cont = 0;
                    fgets(dados, 101, fp);

                    token = strtok(dados, ",");
                    strcpy(ra, token);

					if (strcmp(ra, Gra) == 0)
                    {
                        while(token != NULL)//RA, COD DISC, SEMEST, NOT, FALTA
                        {
                            token = strtok(NULL,",");
                            if (cont == 0) strcpy (disc, token);
                            if (cont == 1) strcpy (arq_sem, token);
                            if (cont == 2)
							{
								strcpy (nota, token);
								strcpy(notalixo, nota);
							}
                            if (cont == 3)
							{
								   strcpy (falta, token);
								   token1 = strtok(falta,"\n");
								   strcpy(falta, token1);
							}
                            cont++;
                        }
                        if (strcmp(codigo_prereqq,"um") == 0)
                 	{
								  strcpy(codigo_prereqq, disc);
								  strcpy(notalixo,"6");
								  strcpy(falta,"75");
					}


                        if (strcmp(codigo_prereqq, disc)== 0)
                        {
      	                    int notaint = atoi(notalixo);
                        	int faltaint = atoi(falta);
	        				contcred += cred_disc(cod_disc);
	        				
                        	if ((notaint>=6) && (faltaint>=75))
							{
								if (contcred <= 32)
								{
								FILE * fp2 = fopen("AlunosDisciplinas.txt","a");
	                            found++;

	                            fprintf(fp2,"\n%s,%s,%s,%s,%s",ra,cod_disc,semestre,nota1,falta1);
	                 	        fclose(fp2);
								}
	                        	else
								{
									return 3;
								}
							}
							else
							{
								printf("Nota menor que 6 ou presenca menor que 75%\n");
								return 3;
							}
						}


						}
					
   				 }
					fclose(fp);
                 if (found == 0)
                 {
                     printf("Essa disciplina ainda nao pode ser cursada por voce. Verifique se voce ja concluiu o pre requisito para essa disciplina.\n");
                 }
            }
            return 0;
        }
}


char *  codigo_prereq(char codigo[8])
{
	FILE * fp = fopen("Prerequisitos.txt", "r");
	char dados[100], um[]="um";
	char codigo_disc[8];
	char code_prereq[8];
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
                        if (i == 0) strcpy(code_prereq, token);
                        i++;
                    }

                    token = strtok(code_prereq, "\n");
                    strcpy(code_prereq, token);
                    return code_prereq;
                 }
             }
            }
            if (found == 0)
            {
                return um;
            }
            fclose(fp);
   }

int carrega_disciplina(char disc[8])
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

char * prerequisitos (char codigo[8]) {
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

            }
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
               strcpy(Gra, ra);
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
         printf("  |   4 - Alterar Notas                                              |\n");
		 printf("  |   5 - Deslogar                                                   |\n");
         printf("  |   6 - Sair                                                       |\n");
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
            	int erro = 1;
                erro = realizar_matricula();
                if (erro == 0)
				{
					printf("Transacao efetuada com sucesso! \n");
				}
                else if(erro == 1)
				{
					printf ("Transacao nao efetuada! \n");	
				}
				else if (erro == 3)
				{
					printf("Creditos excedidos, voce foi matriculado em todas as outras disciplinas exceto a ultima.\n");
				}
                printf("\n\n\n");
                system("pause");
                system("cls");
                break;
            }
        case 4:
			{
                system("cls");
                 printf("    __________________________________________________________________ \n");
                 printf("   |                	Alteracao de Notas                             |\n");
                 printf("   |__________________________________________________________________|\n");
                alterar_nota();
                system("cls");
                break;
            }






        case 5:
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
        case 6:
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
