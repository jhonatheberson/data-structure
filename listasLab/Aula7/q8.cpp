#include<iostream>
using namespace std;


typedef struct s{
	int chave;
	struct s *right;
	struct s *left;
} No;

typedef struct f{
	No *chave; // chave (conteúdo armazenado)
	struct f *next; // ponteiro para o próximo elemento

} Fila;

No *criarCabeca(){
	No *cabeca = new No (); // alocaçao
	if (cabeca!=NULL){ // apenas pra verificar se a alocaçao foi bem sucedida
		cabeca->chave = -1; // Somente pra dizer que o conteudo da cebça é desprezível
		cabeca->next = cabeca; // lista vazia
	}
	return cabeca;
}

void busca(No *cabeca, No **ant, No **pont, int x){
	*ant = cabeca; // ant agora aponta pra cabeça e isso se reflete fora da funçao
	*pont = NULL;
	No *aux = cabeca->next;
	while (aux!=cabeca){
		if (aux->chave < x){
			*ant = aux; // ant agora aponta pra aux e isso se reflete fora da funçao
			aux = aux->next;
		} else{
			if(aux->chave==x){
				*pont = aux;
			}
            aux = cabeca;
		}
	}
}

void insert(No *cabeca, int novoValor){
	No *pont=NULL;
	if (pont==NULL){
		No *novoNo = new No();
		if (novoNo!=NULL){
			novoNo->chave = novoValor;
			novoNo->next = ant->next;
			ant->next = novoNo;
		}
	} else {
		cout<<"Elemento "<<novoValor<<" ja se encontra na lista"<<endl;
	}
}


void printDireto(No *cabeca){
	No *aux = cabeca->next;
	while (aux!=cabeca){
		cout<<aux->chave<<" ";
		aux = aux->next;
	}
	cout<<endl;
}


void remove(No *cabeca, int valor){
	No *ant=NULL, *pont=NULL;
	busca(cabeca, &ant, &pont, valor); // ATENCAO:  &ant, &pont
	if (pont!=NULL){ // o elemento deve estar na lista
		ant->next = pont->next;
		delete pont; // IMPORTANTE NAO ESQUECER
	} else {
		cout<<"Elemento "<<valor<<" nao se encontra na lista"<<endl;
	}
}

void percuso_nivel(Fila *fila, No *pt){
    fila->next = pt;
    Fila *aux = fila->next;
    while(aux != NULL){
        aux = remove()

    }
}

int main(){
    Fila *cabeca = criarCabeca();
    No *raiz = NULL; // NO raiz inicialmente nulo
	insert(30, &raiz);
	insert(20, &raiz);
    insert(40, &raiz);
	insert(18, &raiz);
	insert(25, &raiz);
	insert(19, &raiz);
	insert(47, &raiz);
	insert(38, &raiz);
	insert(43, &raiz);
	//posOrdem(raiz);
}
