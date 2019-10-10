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

No * busca(No *cabeca, string x, int flag){
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
        if (flag == 0){
            return aux->next;
        }else{
            return cabeca->next;
        }
    }
}



void insert(No *cabeca, string novoVaor, int flag){
	No *resulBusca = busca(cabeca, novoVaor, flag);
	if(flag == 0){
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
        }else {
		cout<<"Elemento "<<novoVaor<<" ja se encontra na lista"<<endl;
        }
    }else{
        if (resulBusca == cabeca || resulBusca->chave != novoVaor){
            No *anterior = resulBusca->prev;
            No *novoNo = new No();
            if (novoNo!=NULL){
                novoNo->chave = novoVaor;
                novoNo->prev = cabeca;
                novoNo->next = resulBusca;
                anterior->next = novoNo;
                resulBusca->prev = novoNo;
            }
        }else {
		cout<<"Elemento "<<novoVaor<<" ja se encontra na lista"<<endl;
        }
    }
}


void remove(No *cabeca, int flag){
	//No *resulBusca = busca(cabeca, valor, flag);
	//if (resulBusca!=cabeca && resulBusca->chave==valor){ // o elemento deve estar na lista
    if(cabeca->next!= NULL){
		No * ant = cabeca->prev;
		No * prox = cabeca->next;
		if(flag == 0){
            cabeca->next = prox->next;
            (prox->next)->prev = cabeca;
            delete prox; // IMPORTANTE NAO ESQUECER
		}else{
            (ant->prev)->next = (ant->next);
            cabeca->prev = ant->prev;
            delete ant; // IMPORTANTE NAO ESQUECER
        }

	} else {
		cout<<"Lista vazia"<<endl;
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

int main(){
    No *cabeca = criarCabeca();
	if (cabeca!=NULL){
		insert(cabeca, "Massao",0);
		insert(cabeca, "Lucas",0);
		insert(cabeca, "Joao",1);
		insert(cabeca, "Felipe",0);
		insert(cabeca, "Breno",1);
		insert(cabeca, "Mauricio",0);
		cout<<"Ordem direta: ";
		printDireto(cabeca);
		remove(cabeca,0);
        cout<<"Ordem direta: ";
		printDireto(cabeca);
        remove(cabeca,1);
        cout<<"Ordem direta: ";
		printDireto(cabeca);
    }
}

















