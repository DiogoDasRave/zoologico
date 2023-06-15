#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //bliblioteca de alocação de espaço em memória 
#include <locale.h> // biblitoteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //função responsavel por cadastrar os usuários no sistemna
{
	//inicio criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo,cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "W" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel 
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para atualização
	fprintf(file,","); //colocando "," para dar espaço
	fclose(file); //fecho do arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando nome do usuário a ser cadastrado
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para cadastro 
	fprintf(file,nome); //salvando o nome a ser cadastrado
	fclose(file); //fecho do arquivo
	
	file = fopen(arquivo, "a"); //abrindo arquivo para atualização
	fprintf(file,","); //colando "," para dar espaço
	fclose(file); //fecho do arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando sobrenome do usuário a ser cadastrado
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
	
	system("pause"); //pause para o usuário consseguir usar a função
	
}

int consulta() //função responsavel para consulta de usuário
{
	  setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	  
	  
	 //inicio criação de variaveis/string
	char cpf[40];
	char conteudo[200];
	//fim da criação de variaveis/string
	
	printf("Digita o CPF a ser consultado: "); //coleta de cpf a ser consultado
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; // busca de arquivo
	file = fopen(cpf,"r"); // "r" serve para ler oque esta no arquivo
	
	if(file == NULL) //comparação caso o cpf nao esteja no arquivo
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n"); //menssagem para o cpf nao localizado
	}
	
	while(fgets(conteudo, 200, file)!= NULL) // comendo para mostrar o conteudo do arquivo
	{
		printf("\nEssas são as informações do usuário"); //mostrando ao usuário as informações
		printf("%s", conteudo); //conteudo do arquivo puchado
		printf("\n\n"); //espaço
	}
	
	system("pause"); //pausa do sistema
	
	
}

int deletar() //função deletrar
{
	//inicio da criação de variaveis/strings
	char cpf[40]; 
	
	//fim da criação de variaveis/strings
	
	printf("Digite o CPF do usuário a ser deletado: "); //coletando informação do cpf a ser deletado
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf); //comando de delet 
	
	FILE *file; //busca de arquivo
	file = fopen(cpf,"r"); // "r" serve para ler oque esta no arquivo
	{
		printf("O usuário foi deletado com sucesso.\n"); //informção de delet de usuário
	}
	
	if(file == NULL) //comparação caso o cpf nao esteja no arquivo
	{
		printf("O usuário não se encontra no sistema!.\n"); //usuário nao encontrado no sistema
		system("pause"); //pausa do sistema
	}
}



int main()
{
	int opcao=0; //Definindo a linguagem
	int laco=1;
	
	for(laco=1;laco=1;) //responsavel pelo programa voltar ao menu de seleção
	{
	
        system("cls"); //responsavel por limpar a tela

		   setlocale(LC_ALL, "Portuguese");
     
   
     printf("###Zoologico da Mabel### \n\n"); //inicio do menu
     printf("Escolha a opção desejada do menu:\n\n");
     printf("\t1 - registrar nomes\n");
     printf("\t2 - consultar nomes\n");
     printf("\t3 - deletar nomes\n\n");
	 printf("opção: "); //fim do menu
     
     scanf("%d", &opcao); //armazenando a escolha do usuário

        system("cls"); //responsavel por limpar a tela
        
        switch(opcao) //inicio da seleção do menu
        {
        	case 1:
        	registro(); //chamada de funções
       	    break; //fim da seleção registro
       	    
       	    case 2:
       	    consulta(); //chamada da função consulta
     	    break; //fim da seleção consulta
     	    
     	    case 3:
     	    deletar(); //chamada da função deletar
	        break; //fim da seleção de deletar
     	    
	        
	        default:
	        printf("Essa opção não está disponivel!\n");
            system("pause");
            break;
		} //Fim da seleção
    }
	
	
}
    
