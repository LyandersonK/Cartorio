#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca resp�nsavel por cuidar dos strings

int registro() //fun��o responsavel por cadastrar os usu�rio no sistema
{
   setlocale(LC_ALL, "Portuguese");
	
	//inicio da cria��o de vari�veis/string
	char arquivo[40];
     char cpf[40];
      char nome[40];
       char sobrenome[40];
        char cargo[40];
        //fim da cria��o de vari�veis/string
        
          printf("Digite o CPF a ser cadastrado:"); //coletando informa��es do usu�rio
           scanf("%s", cpf); //%s refere-se a salvar uma string
           
           strcpy(arquivo, cpf); //responsav�l por copiar os valores dos strings
           
            FILE *file; //cria o arquivo
            file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
            fprintf(file,cpf); //salvo o valor da var�avel
            fclose(file); //fecha aquivo
           
            file = fopen(arquivo, "a"); // acessando arquivo e atualizando "a"
            fprintf(file,",");
            fclose(file);
           
            printf("Digite o nome a ser cadastrado:");
            scanf("%s",nome);
            
            file = fopen(arquivo, "a");
            fprintf(file,nome);
            fclose(file);
            
            file = fopen(arquivo, "a");
            fprintf(file,",");
            fclose(file);
            
            printf("Digite o sobrenome ser cadastrado:");
            scanf("%s",sobrenome);
          
            file = fopen(arquivo, "a");
            fprintf(file,sobrenome);
            fclose(file);
          
            file = fopen(arquivo, "a");
            fprintf(file,",");
            fclose(file);
           
            printf("Digite o cargo a ser cadastrado:");
            scanf("%s",cargo);
           
            file = fopen(arquivo, "a");
            fprintf(file,cargo);
            fclose(file);
            
            file = fopen(arquivo, "a");
            fprintf(file,",");
            fclose(file);
           
        system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo idioma
	
	//inicio da cria��o de vari�veis/string
    char cpf[40];
     char conteudo[200];
	 //fim da cria��o de vari�veis/string
	 
	printf("digite o CPF a ser consultado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abri o arquivo, n�o localizado!.\n");
	}        
	
	while(fgets(conteudo, 200, file) !=NULL) //buscando conte�do dentro da file com limite de 200 caracteres 
	{
		printf("\nEssas s�o as informac�es do usuario:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	
	char cpf[40]; //cria��o de vari�vel/string
	
	printf("Digite o CPF do usu�rio que deseja deletar:\n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("O CPF digitado n�o pertence a um usu�rio cadastrado.\n\n");
	}
	else
	{
		remove(cpf);
		printf("Usu�rio deletado com sucesso!\n\n");
	}
	
	
	system("pause");
}

int main()
{
	int opcao = 0;
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo idioma
	
	 
	    printf("### Cartorio da EBAC ### \n\n"); //inicio
	    printf("Selecione a op��o desejada do menu:\n\n"); //Inico do Menu
	    printf("\t1 - Registrar Nomes\n");
	    printf("\t2 - Consultar Nomes\n"); //Menu
       	printf("\t3 - Deletar Nomes\n\n");
	    printf("Op��o:"); //Fim do Menu
	
	    scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
    	system("cls"); //responsavel por limpar a tela
    	
    	switch(opcao) //respostas das escolhas
    	{
    		case 1:
    		    registro(); //chamada de fun��es
    		break;
    		
    		case 2:
    			 consulta(); //chamada de fun��es
	        break;
	        
	        case 3:
	        	deletar(); //chamada de fun��es
        	break;
        	
        	
        	default:
        		printf("Est� op��o n�o est� disponivel!\n");
        	system("pause");
        	break;
        	//fim da sele��o
        
		}

        
    }
}
