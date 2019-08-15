//Aqui é implementado uma simples lista dinâmica usando toda estrutura de ponteiros necessários para sua criação 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct no {
 	int dado;
 	struct no *proximo;
};

typedef no *ptr_no;
ptr_no lista;
int op;


void menu_mostrar();
void menu_selecionar(int op);
void lista_inserir(ptr_no lista);
void lista_remover(ptr_no lista);
void lista_mostrar(ptr_no lista);

main() {
 	
 	srand(time(NULL));
 	op = 1;
 
 	lista = (ptr_no) malloc(sizeof(no));
 	lista->dado = 0;
 	lista->proximo = NULL;
 
 while (op !=0){
 		system("cls");
 		menu_mostrar();
 		scanf("%d", &op);
 		menu_selecionar(op);
 	}
 	system("Pause");
 	return(0);
}

void menu_mostrar(){
 	lista_mostrar(lista);
 	printf("\n\nEscolha uma das opcoes:\n");
 	printf("1 - Inserir no final da Lista\n");
 	printf("2 - Remover um item da Lista\n");
 	printf("0 - Sair\n\n");
}


void menu_selecionar(int op){
 	switch (op){
 		case 1:
 			lista_inserir(lista);
 		break;
 		case 2:
 			lista_remover(lista);
 		break;
	 }
}

void lista_inserir(ptr_no lista){
 	while(lista->proximo != NULL){
 		lista = lista->proximo;
 	}
 	lista->proximo = (ptr_no) malloc(sizeof(no));
 	lista = lista->proximo;
 	lista->dado = rand()%100;
 	lista->proximo = NULL;
}

void lista_remover(ptr_no lista){
 	int dado;
 	ptr_no atual;
 	atual = (ptr_no) malloc(sizeof(no));
 	printf("\n\nEscolha uma dos itens:\n");
 	scanf("%d", &dado);
 	while((lista->dado != dado) ){
		if (lista->proximo == NULL){
 			break;
 	}
 	atual = lista;
 	lista = lista->proximo;
 	}
 	if (lista->dado == dado){
 		atual->proximo = lista->proximo;
	}
}


void lista_mostrar(ptr_no lista){
 	system("cls");
 	while(1) {
 		printf("%d, ", lista->dado);
 		if (lista->proximo == NULL){
 			break;
 		}
 		lista = lista->proximo;
 	}
}

void lista_mostrar_2(ptr_no lista){
 	system("cls");
 	while(lista->proximo != NULL) {
 		printf("%d, ", lista->dado);
 		lista = lista->proximo;
 	}
 	printf("%d, ", lista->dado);
}
