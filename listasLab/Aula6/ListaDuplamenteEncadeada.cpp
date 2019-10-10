#include <iostream>
using namespace std;

/*
========================================================================================================

Copyright Islame Felipe da Costa Fernandes (2019)
Compilar: g++ ListaDuplamenteEncadeada.cpp -o ListaDuplamenteEncadeada
Executar: ./ListaDuplamenteEncadeada

Este código foi implementado para a disciplina DCA0214.1 ESTRUTURAS DE DADOS - LABORATÓRIO
Com vistas a elucidar as dúvidas dos alunos quanto à manipulação
de ponteiros em listas duplamente encadeadas.

Esta implmentaçao mantém uma lista circular duplamente encadeada com cabeça
cujos elementos devem ser mantidos em ordem crescente

Os demais tipos de listas encadeadas podem ser FACILMENTE implementadas
de modo direto e análogo a essa implementação. Deixo-os como exercício para vocês! =)

========================================================================================================
*/


/*estrutura que representa um elemento da lista*/
typedef struct s{
	int chave; // chave (conteúdo armazenado)
	struct s *next; // ponteiro para o próximo elemento
	struct s *prev; // ponteiro para o elemento anterior
} No;


/*
Aloca o cabeça e retorna seu ponteiro .
Dada a alocaçao do nó cabeça, temos, pois, a uma lista vazia
*/
No *criarCabeca(){
	No *cabeca = new No (); // alocaçao
	if (cabeca!=NULL){ // apenas pra verificar se a alocaçao foi bem sucedida
		cabeca->chave = -1; // Somente pra dizer que o conteudo da cebça é desprezível
		cabeca->next = cabeca; // lista vazia
		cabeca->prev = cabeca; // lista vazia
	}
	return cabeca;
}

// busca em lista duplamente encadeada com cabeça
// recebe a chave a ser buscada x, bem como a cabeça da lista
// retorna o ponteiro para o elemento encontrado
// Se o elemento nao for encontrado, entao retorna um ponteiro para onde o elemento "v",
// onde "v" possui a menor chave maior que x (ou seja, x deveria estar imediatamente antes de "v")
// complexidade O(n), onde n é a quantidade de elemento da lista
No * busca(No *cabeca, int x){
	No *ultimo = cabeca->prev; // pega o ultimo elemento da lista
	if (x<=ultimo->chave){
		No *aux = cabeca->next;
		while (aux->chave <x) aux = aux->next;
		return aux;
	} else return cabeca;
}


// Insere um novoValor na lista
// recebe o no cabeça e o novoValor
// Nao permite elementos com chave repetidas
// Exercício: modificar esta implementaçao para permitir elementos repetidos =)
void insert(No *cabeca, int novoVaor){
	No *resulBusca = busca(cabeca, novoVaor);
	if (resulBusca == cabeca || resulBusca->chave != novoVaor){
		No *anterior = resulBusca->prev;
		No *novoNo = new No();
		if (novoNo!=NULL){
			novoNo->chave = novoVaor;
			novoNo->prev = anterior;
			novoNo->next = resulBusca;
			anterior->next = novoNo;
			resulBusca->prev = novoNo;
		}
	} else {
		cout<<"Elemento "<<novoVaor<<" ja se encontra na lista"<<endl;
	}
}


void remove(No *cabeca, int valor){
	No *resulBusca = busca(cabeca, valor);
	if (resulBusca!=cabeca && resulBusca->chave==valor){ // o elemento deve estar na lista
		No * ant = resulBusca->prev;
		No * prox = resulBusca->next;
		ant->next = prox;
		prox->prev = ant;
		delete resulBusca; // IMPORTANTE NAO ESQUECER
	} else {
		cout<<"Elemento "<<valor<<" nao se encontra na lista"<<endl;
	}
}


// Imprime a lista da cabeça até o último elemento (ordem crescente)
void printDireto(No *cabeca){
	No *aux = cabeca->next;
	while (aux!=cabeca){
		cout<<aux->chave<<" ";
		aux = aux->next;
	}
	cout<<endl;
}

// Imprime a lista do último elemento até a cabeça (ordem decrescente)
void printInverso(No *cabeca){
	No *aux = cabeca->prev;
	while (aux!=cabeca){
		cout<<aux->chave<<" ";
		aux = aux->prev;
	}
	cout<<endl;
}

int main(){
	No *cabeca = criarCabeca();
	if (cabeca!=NULL){
		insert(cabeca, 10);
		insert(cabeca, 100);
		insert(cabeca, 7);
		insert(cabeca, 30);
		insert(cabeca, 2);
		insert(cabeca, 7);
		insert(cabeca, 11);
		insert(cabeca, 101);
		insert(cabeca, 2);
		cout<<"Ordem direta: ";
		printDireto(cabeca);
		cout<<"Ordem inversa: ";
		printInverso(cabeca);
		remove(cabeca, 30);
		cout<<"Ordem direta depois da remocao de 30: "<<endl;
		printDireto(cabeca);
		remove(cabeca, 30);
		remove(cabeca, 101);
		cout<<"Ordem direta depois da remocao de 101: "<<endl;
		printDireto(cabeca);
		remove(cabeca, 2);
		cout<<"Ordem direta depois da remocao de 2: "<<endl;
		printDireto(cabeca);
		cout<<"Insere o 30 novamente:"<<endl;
		insert(cabeca, 30);
		printDireto(cabeca);
	}
	return 0;
}
