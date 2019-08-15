//Código abaixo foi um desafio proposto, onde o objeto é simular o fucionamento de um
//Gerenciador de Tarefas aplicando o método de Pilhas Estáticas.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>


#define tamanho 5

struct p_pilha 
{
	int dado[tamanho];
	int ini;
	int fim;
};

struct p_nome
{
	char nome[35];
};

struct p_nome nome_processo[tamanho];
struct p_pilha pilha;
int cod = 0;

void menu_op();
void exibir();
void inserir_pilha();
void remover_um();
void remover_tudo();

int main()
{
	setlocale(LC_ALL, "Portuguese");
	pilha.fim = 0;
	pilha.ini = 0;

	int sair = 1;
	int escolha;
	
	while (sair == 1)
	{
		system("cls");
		exibir();
		menu_op();
		scanf("%d", &escolha);
		fflush(stdin);
		
		switch (escolha)
		{
			case 1:
				inserir_pilha();
			break;
			
			case 2:
				remover_um();
			break;
			
			case 3:
				remover_tudo();
			break;
			
			case 0:
				sair = 0;
			break;
			
			default:
				printf("ERRO! Opção inválida");
				system("pause");
		}
	}
	return(0);
}

void menu_op()
{
	printf("===============================\n");
	printf("Escolha uma das opções abaixo: \n");
	printf("===============================\n");
	printf("|1 para inserir na pilha      |\n");
	printf("|2 para remover um elemento   |\n");
	printf("|3 para esvaziar a pilha      |\n");
	printf("|0 para sair                  |\n");
	printf("===============================\n");
}

void exibir()
{
	printf("-----------------------------\n");
	printf("   GERENCIADOR DE TAREFAS   |\n");
	printf("-----------------------------\n");
	printf("PID| Nome_Processo           |\n");
	printf("-----------------------------\n");
	int i;
	for(i = 0; i < tamanho; i++)
	{
		printf(" %d| %s \n", pilha.dado[i], nome_processo[i]);
	}
	printf("\n");
}

void inserir_pilha()
{
	system("cls");
	if(pilha.fim == tamanho)
	{
		printf("ERRO! A PILHA ESTÁ CHEIA");
	}
	else
	{
		printf("Digite o nome do processo: \n");
		gets(nome_processo[pilha.fim].nome);
		fflush(stdin);
		cod = cod + 00013;
		pilha.dado[pilha.fim] = cod;
		pilha.fim ++;
	}
}

void remover_um()
{
	if(pilha.ini == pilha.fim)
	{
		printf("Erro! pilha vazia\n");
		system("pause");
	}
	else
	{
		strcpy(nome_processo[pilha.fim - 1].nome, "");
		pilha.dado[pilha.fim - 1] = 0;
		pilha.fim --;
	}
}

void remover_tudo()
{
	int o;
	for(o = 0; o < tamanho; o++)
	{
		if(pilha.fim == pilha.ini)
		{
			break;
		}
		else
		{
		strcpy(nome_processo[pilha.fim - 1].nome, "");
		pilha.dado[pilha.fim - 1] = 0;
		pilha.fim --;
		}
	}
}
