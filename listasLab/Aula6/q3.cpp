#include<iostream>
using namespace std;

typedef struct s{
	string chave; // chave (conteúdo armazenado)
	struct s *next; // ponteiro para o próximo elemento
	struct s *prev; // ponteiro para o elemento anterior
} No;


No *criarCabeca(){
	No *cabeca = new No (); // alocaçao
	if (cabeca!=NULL){ // apenas pra verificar se a alocaçao foi bem sucedida
		cabeca->chave = -1; // Somente pra dizer que o conteudo da cebça é desprezível
		cabeca->next = cabeca; // lista vazia
		cabeca->prev = cabeca; // lista vazia
	}
	return cabeca;
}

No * busca(No *cabeca, string x){
	No * ultimo = cabeca->prev; // pega o ultimo elemento da lista
	No *aux = cabeca->next;
    while (aux->chave != x){
        aux = aux->next;
        if(aux == ultimo){
            break;
        }
    }
    if(aux->chave == x){
        return aux;
    }else{
        return aux->next;
    }
}



void insert(No *cabeca, string novoVaor){
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


void remove(No *cabeca, string valor){
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

void printDireto(No *cabeca){
	No *aux = cabeca->next;
	while (aux!=cabeca){
		cout<<aux->chave<<" ";
		aux = aux->next;
	}
	cout<<endl;
}

string func(No *cabeca, int n, int m){
    No *aux;
    while(n>=2){
        aux = cabeca;
        for(int k = 0; k<m; k++){
            aux = aux->next;
            if(aux == cabeca) aux = aux->next;
        }
        cout<<" sai - "<<aux->chave<<endl;
        remove(cabeca, aux->chave);
        n--;
    }
    aux = cabeca->next;
    return((aux->chave));
}

int main(){
    No *cabeca = criarCabeca();
    int n =6, m = 5;
	if (cabeca!=NULL){
		insert(cabeca, "Massao");
		insert(cabeca, "Lucas");
		insert(cabeca, "Joao");
		insert(cabeca, "Felipe");
		insert(cabeca, "Breno");
		insert(cabeca, "Mauricio");
		cout<<"Ordem direta: ";
		printDireto(cabeca);
		cout<<func(cabeca, n, m)<<endl;
		cout<<"Ordem direta: ";
		printDireto(cabeca);
    }
}

















