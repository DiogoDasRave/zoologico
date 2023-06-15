#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //bliblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> // biblitoteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //fun��o responsavel por cadastrar os usu�rios no sistemna
{
	//inicio cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo,cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "W" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel 
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para atualiza��o
	fprintf(file,","); //colocando "," para dar espa�o
	fclose(file); //fecho do arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando nome do usu�rio a ser cadastrado
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para cadastro 
	fprintf(file,nome); //salvando o nome a ser cadastrado
	fclose(file); //fecho do arquivo
	
	file = fopen(arquivo, "a"); //abrindo arquivo para atualiza��o
	fprintf(file,","); //colando "," para dar espa�o
	fclose(file); //fecho do arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando sobrenome do usu�rio a ser cadastrado
	scanf("%s",sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abrindo arquivo para cadastro
	fprintf(file,sobrenome); //salvando o sobrenome a ser cadastrado
	fclose(file); //fecho do arquivo
	
	file = fopen(arquivo, "a"); //abrindo o arquivo
	fprintf(file,","); //colocando ","
	fclose(file); //fechando arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando cargo a ser cadastrado
	scanf("%s",cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abrindo arquivo para cadastro
	fprintf(file,cargo); //salvando o cargo
	fclose(file); //fecho do arquivo
	
	system("pause"); //pause para o usu�rio consseguir usar a fun��o
	
}

int consulta() //fun��o responsavel para consulta de usu�rio
{
	  setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	  
	  
	 //inicio cria��o de variaveis/string
	char cpf[40];
	char conteudo[200];
	//fim da cria��o de variaveis/string
	
	printf("Digita o CPF a ser consultado: "); //coleta de cpf a ser consultado
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; // busca de arquivo
	file = fopen(cpf,"r"); // "r" serve para ler oque esta no arquivo
	
	if(file == NULL) //compara��o caso o cpf nao esteja no arquivo
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n"); //menssagem para o cpf nao localizado
	}
	
	while(fgets(conteudo, 200, file)!= NULL) // comendo para mostrar o conteudo do arquivo
	{
		printf("\nEssas s�o as informa��es do usu�rio"); //mostrando ao usu�rio as informa��es
		printf("%s", conteudo); //conteudo do arquivo puchado
		printf("\n\n"); //espa�o
	}
	
	system("pause"); //pausa do sistema
	
	
}

int deletar() //fun��o deletrar
{
	//inicio da cria��o de variaveis/strings
	char cpf[40]; 
	
	//fim da cria��o de variaveis/strings
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //coletando informa��o do cpf a ser deletado
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf); //comando de delet 
	
	FILE *file; //busca de arquivo
	file = fopen(cpf,"r"); // "r" serve para ler oque esta no arquivo
	{
		printf("O usu�rio foi deletado com sucesso.\n"); //inform��o de delet de usu�rio
	}
	
	if(file == NULL) //compara��o caso o cpf nao esteja no arquivo
	{
		printf("O usu�rio n�o se encontra no sistema!.\n"); //usu�rio nao encontrado no sistema
		system("pause"); //pausa do sistema
	}
}



int main()
{
	int opcao=0; //Definindo a linguagem
	int laco=1;
	
	for(laco=1;laco=1;) //responsavel pelo programa voltar ao menu de sele��o
	{
	
        system("cls"); //responsavel por limpar a tela

		   setlocale(LC_ALL, "Portuguese");
     
   
     printf("###Zoologico da Mabel### \n\n"); //inicio do menu
     printf("Escolha a op��o desejada do menu:\n\n");
     printf("\t1 - registrar nomes\n");
     printf("\t2 - consultar nomes\n");
     printf("\t3 - deletar nomes\n\n");
	 printf("op��o: "); //fim do menu
     
     scanf("%d", &opcao); //armazenando a escolha do usu�rio

        system("cls"); //responsavel por limpar a tela
        
        switch(opcao) //inicio da sele��o do menu
        {
        	case 1:
        	registro(); //chamada de fun��es
       	    break; //fim da sele��o registro
       	    
       	    case 2:
       	    consulta(); //chamada da fun��o consulta
     	    break; //fim da sele��o consulta
     	    
     	    case 3:
     	    deletar(); //chamada da fun��o deletar
	        break; //fim da sele��o de deletar
     	    
	        
	        default:
	        printf("Essa op��o n�o est� disponivel!\n");
            system("pause");
            break;
		} //Fim da sele��o
    }
	
	
}
    
