#include <stdio.h> //biblioteca de cominuca��o com o usuario 
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o 
#include <string.h> //biblioteca responsavel por cuidar das strings
		
int registro() //fun��o respons�vel por cadastrar os usuarios no sistema 
{
	char arquivo[40]; //criando uma string
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF que gostaria de cadastrar: "); //coletando informa��es dos usuarios 
	scanf("%s", cpf); // %S refere-se a uma string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string 

  	FILE *file; // criando o arquivo
	file = fopen(arquivo, "w"); // criar o arquivo - w significa escrever
	fprintf(file,cpf); // salvar o valor da variavel
	fclose(file); // fechar o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");

}

int consulta()
{
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF que deseja consultar: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir esse aquivo!. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	
	}

	system("pause");
}

int deletar()
{
	char cpf[40];
		
	printf("Digite o CPF que deseja excluir: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O us�ario n�o se encontra no sistema!. \n");
		system("pause");
	}
	
}


	
int main()
	{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls");

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
		printf("*** Cartorio da EBAC ***\n\n"); //inicio 
		printf("Escolha a op��o desejada no menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do sistema\n");
		printf("Op��o: ");//fim do menu
				
		scanf("%d", &opcao); //armazenando a escolha do usu
		
		system("cls"); // respons�vel por limpar a tela
	
		switch(opcao) //inicio da sele��o
		{
			case 1:
			registro(); //chamada de fun��o
			break;
			
			case 2:
			consulta();
			break;
		
			case 3:
			deletar();
			break;
			
			case 4: 
			printf("Obrigado por utilizar o sistema! \n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;
			
			
		} //fim da sele��o
			
	}	
}
