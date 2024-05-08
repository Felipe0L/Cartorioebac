#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" vem do write que significa escrever
	fprintf(file,"CPF: ");
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" é utilizado para atualizar o arquivo
	fprintf(file,"\n");//Foi inserido a quebra de linha no arquivo
	fclose(file);//Comando para fechar o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//Coletando informação do usuário
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");//Abrindo o arquivo para atualiza-lo
	fprintf(file,"Nome: ");// Inserindo no arquivo o texto
	fclose(file);//Fechando o arquivo
	
	file = fopen(arquivo, "a");//Abrindo o arquivo para atualiza-lo
	fprintf(file,nome);// Inserindo no arquivo o nome digitado pelo usuário
	fclose(file);//Fechando o arquivo
	
	file = fopen(arquivo, "a");//Abrindo o arquivo para atualiza-lo
	fprintf(file,"\n");//Inserindo a quebra de linha no arquivo
	fclose(file);//Fechando o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//Coletando informação do usuário
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");//Abrindo o arquivo para atualiza-lo
	fprintf(file,"Sobrenome: ");//Inserindo o texto no arquivo
	fclose(file);//Fechando o arquivo
	
	file = fopen(arquivo, "a");//Abrindo o arquivo para atualiza-lo
	fprintf(file,sobrenome);// Inserindo no arquivo o sobrenome digitado pelo usuário
	fclose(file);//Fechando o arquivo
	
	file = fopen(arquivo, "a");//Abrindo o arquivo para atualiza-lo
	fprintf(file,"\n");//Inserindo a quebra de linha no arquivo
	fclose(file);//Fechando o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//Coletando informação do usuário
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");//Abrindo o arquivo para atualiza-lo
	fprintf(file,"Cargo: ");//Inserindo o texto no arquivo
	fclose(file);//Fechand o arquivo
	
	file = fopen(arquivo, "a");//Abrindo o arquivo para atualiza-lo
	fprintf(file,cargo);//Inserindo no arquivo o cargo digitado pelo usuário
	fclose(file);//Fechando o arquivo
		
	system("pause");
	
}//Fim da função registro

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	//Inicio da criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//Fim da criação de variáveis/string
	
	printf("Digite o CPF a ser consultado: ");//Coletando informação do usuário
	scanf("%s", cpf);
	
	FILE *file;//Comando para abrir arquivo
	file = fopen(cpf,"r");//Utilizado para abrir um arquivo e o "r" para ler
	
	if (file == NULL)//Condicional para informar o usuário
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//Mostra o conteúdo do arquivo para o usuário
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);//Fechando o arquivo
	
	system("pause");
}

int deletar()
{
	char cpf[40];//Variável/string
	
	printf("Digite o CPF do usuário a ser deletado: ");//Coleta de informação do usuário
	scanf("%s",cpf);
	
	remove(cpf);//Comando da biblioteca de arquivos para deletar 
	
	FILE *file;//Comando para abrir arquivo
	file = fopen(cpf, "r");//Comando para abrir arquivo e o "r" para ler
	
	if(file == NULL)//Condição para se o arquivo não existir retornar a mensagem ao usuário
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
}


int main()
{
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");//Responsável por limpar a tela
		
		setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n");//Inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nome\n");
		printf("\t2 - Consultar nome\n");
		printf("\t3 - Deletar  nome\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: ");//Fim do menu
	
		scanf("%d", &opcao);//Armazenando a escolha do usuário
	
		system("cls");
		
		switch(opcao)//Inicio da seleção do menu
		{
			case 1:
				registro();//chamada de funções
				break;
				
			case 2:
				consulta();//chamada de funções
				break;
				
			case 3:
				deletar();//chamada de funções
				break;
				
			case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
				
			default:
				printf("Essa opção não está disponível.\n\n");//Se nenhuma das opções anteriores for selecionada exibe a mensagem
				system("pause");
				break;
				
		}//Fim da seleção
	
	}
	printf("Esse software é de livre uso dos alunos\n");
}
