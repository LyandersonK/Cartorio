#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca respónsavel por cuidar dos strings

int registro() //função responsavel por cadastrar os usuário no sistema
{
   setlocale(LC_ALL, "Portuguese");
	
	//inicio da criação de variáveis/string
	char arquivo[40];
     char cpf[40];
      char nome[40];
       char sobrenome[40];
        char cargo[40];
        //fim da criação de variáveis/string
        
          printf("Digite o CPF a ser cadastrado:"); //coletando informações do usuário
           scanf("%s", cpf); //%s refere-se a salvar uma string
           
           strcpy(arquivo, cpf); //responsavél por copiar os valores dos strings
           
            FILE *file; //cria o arquivo
            file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
            fprintf(file,cpf); //salvo o valor da varíavel
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
	
	//inicio da criação de variáveis/string
    char cpf[40];
     char conteudo[200];
	 //fim da criação de variáveis/string
	 
	printf("digite o CPF a ser consultado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abri o arquivo, não localizado!.\n");
	}        
	
	while(fgets(conteudo, 200, file) !=NULL) //buscando conteúdo dentro da file com limite de 200 caracteres 
	{
		printf("\nEssas são as informacões do usuario:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	
	char cpf[40]; //criação de variável/string
	
	printf("Digite o CPF do usuário que deseja deletar:\n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("O CPF digitado não pertence a um usuário cadastrado.\n\n");
	}
	else
	{
		remove(cpf);
		printf("Usuário deletado com sucesso!\n\n");
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
	    printf("Selecione a opção desejada do menu:\n\n"); //Inico do Menu
	    printf("\t1 - Registrar Nomes\n");
	    printf("\t2 - Consultar Nomes\n"); //Menu
       	printf("\t3 - Deletar Nomes\n\n");
	    printf("Opção:"); //Fim do Menu
	
	    scanf("%d", &opcao); //armazenando a escolha do usuário
	
    	system("cls"); //responsavel por limpar a tela
    	
    	switch(opcao) //respostas das escolhas
    	{
    		case 1:
    		    registro(); //chamada de funções
    		break;
    		
    		case 2:
    			 consulta(); //chamada de funções
	        break;
	        
	        case 3:
	        	deletar(); //chamada de funções
        	break;
        	
        	
        	default:
        		printf("Está opção não está disponivel!\n");
        	system("pause");
        	break;
        	//fim da seleção
        
		}

        
    }
}
