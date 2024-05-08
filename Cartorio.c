#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//Inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" vem do write que significa escrever
	fprintf(file,"CPF: ");
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" � utilizado para atualizar o arquivo
	fprintf(file,"\n");//Foi inserido a quebra de linha no arquivo
	fclose(file);//Comando para fechar o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//Coletando informa��o do usu�rio
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");//Abrindo o arquivo para atualiza-lo
	fprintf(file,"Nome: ");// Inserindo no arquivo o texto
	fclose(file);//Fechando o arquivo
	
	file = fopen(arquivo, "a");//Abrindo o arquivo para atualiza-lo
	fprintf(file,nome);// Inserindo no arquivo o nome digitado pelo usu�rio
	fclose(file);//Fechando o arquivo
	
	file = fopen(arquivo, "a");//Abrindo o arquivo para atualiza-lo
	fprintf(file,"\n");//Inserindo a quebra de linha no arquivo
	fclose(file);//Fechando o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//Coletando informa��o do usu�rio
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");//Abrindo o arquivo para atualiza-lo
	fprintf(file,"Sobrenome: ");//Inserindo o texto no arquivo
	fclose(file);//Fechando o arquivo
	
	file = fopen(arquivo, "a");//Abrindo o arquivo para atualiza-lo
	fprintf(file,sobrenome);// Inserindo no arquivo o sobrenome digitado pelo usu�rio
	fclose(file);//Fechando o arquivo
	
	file = fopen(arquivo, "a");//Abrindo o arquivo para atualiza-lo
	fprintf(file,"\n");//Inserindo a quebra de linha no arquivo
	fclose(file);//Fechando o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//Coletando informa��o do usu�rio
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");//Abrindo o arquivo para atualiza-lo
	fprintf(file,"Cargo: ");//Inserindo o texto no arquivo
	fclose(file);//Fechand o arquivo
	
	file = fopen(arquivo, "a");//Abrindo o arquivo para atualiza-lo
	fprintf(file,cargo);//Inserindo no arquivo o cargo digitado pelo usu�rio
	fclose(file);//Fechando o arquivo
		
	system("pause");
	
}//Fim da fun��o registro

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	//Inicio da cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//Fim da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: ");//Coletando informa��o do usu�rio
	scanf("%s", cpf);
	
	FILE *file;//Comando para abrir arquivo
	file = fopen(cpf,"r");//Utilizado para abrir um arquivo e o "r" para ler
	
	if (file == NULL)//Condicional para informar o usu�rio
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//Mostra o conte�do do arquivo para o usu�rio
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);//Fechando o arquivo
	
	system("pause");
}

int deletar()
{
	char cpf[40];//Vari�vel/string
	
	printf("Digite o CPF do usu�rio a ser deletado: ");//Coleta de informa��o do usu�rio
	scanf("%s",cpf);
	
	remove(cpf);//Comando da biblioteca de arquivos para deletar 
	
	FILE *file;//Comando para abrir arquivo
	file = fopen(cpf, "r");//Comando para abrir arquivo e o "r" para ler
	
	if(file == NULL)//Condi��o para se o arquivo n�o existir retornar a mensagem ao usu�rio
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
}


int main()
{
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");//Respons�vel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n");//Inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nome\n");
		printf("\t2 - Consultar nome\n");
		printf("\t3 - Deletar  nome\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: ");//Fim do menu
	
		scanf("%d", &opcao);//Armazenando a escolha do usu�rio
	
		system("cls");
		
		switch(opcao)//Inicio da sele��o do menu
		{
			case 1:
				registro();//chamada de fun��es
				break;
				
			case 2:
				consulta();//chamada de fun��es
				break;
				
			case 3:
				deletar();//chamada de fun��es
				break;
				
			case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
				
			default:
				printf("Essa op��o n�o est� dispon�vel.\n\n");//Se nenhuma das op��es anteriores for selecionada exibe a mensagem
				system("pause");
				break;
				
		}//Fim da sele��o
	
	}
	printf("Esse software � de livre uso dos alunos\n");
}
