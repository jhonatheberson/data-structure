#include <iostream>
using namespace std;

/*estrutura que representa um elemento da lista*/
typedef struct s{
	char chave; // chave (conteúdo armazenado)
	struct s *next; // ponteiro para o próximo elemento

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
	}
	return cabeca;
}

// busca em lista SIMPLESMENTE encadeada com cabeça
// recebe a cabeça da lista, um ponteito para ponteiro para o ant, um ponteito para ponteiro para o  pont, a chave a ser buscada x.
// retorna o ponteiro para o elemento encontrado
// pont é o ponteiro para o elemento encontrado
// ant é o ponteiro para o anterior ao pont
// Se o elemento nao for encontrado, entao retorna um ponteiro para onde o elemento "v",
// onde "v" possui a menor chave maior que x (ou seja, x deveria estar imediatamente antes de "v")
// complexidade O(n), onde n é a quantidade de elemento da lista
void busca(No *cabeca, No **ant, No **pont, char x){
	*ant = cabeca; // ant agora aponta pra cabeça e isso se reflete fora da funçao
	*pont = NULL;
	No *aux = cabeca->next;
	while (aux!=cabeca){
			*ant = aux; // ant agora aponta pra aux e isso se reflete fora da funçao
			aux = aux->next;
			if(aux->chave==x){
				*pont = aux;
                aux = cabeca;
			}
    }
}


void busca2(No *cabeca, No **ant, No **pont, int x){
	*ant = cabeca; // ant agora aponta pra cabeça e isso se reflete fora da funçao
	*pont = NULL;
	No *aux = cabeca->next;
	while (aux!=cabeca){
		if (aux->chave > x){
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

// Insere um novoValor na lista
// recebe o no cabeça e o novoValor
// Nao permite elementos com chave repetidas
// Exercício: modificar esta implementaçao para permitir elementos repetidos =)
void insert(No *cabeca, char novoValor){
	No *ant=NULL, *pont=NULL;
	busca(cabeca, &ant, &pont, novoValor); // ATENCAO:  &ant, &pont
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

void insert2(No *cabeca2, char novoValor){
	No *ant=NULL, *pont=NULL;
	busca2(cabeca2, &ant, &pont, novoValor); // ATENCAO:  &ant, &pont
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

// Imprime a lista da cabeça até o último elemento (ordem crescente)
void printDireto(No *cabeca){
	No *aux = cabeca->next;
	while (aux!=cabeca){
		cout<<aux->chave<<" ";
		aux = aux->next;
	}
	cout<<endl;
}
void funcao(No *cabeca, No *cabeca2){
    No *aux = cabeca->next;
    char aux_chave;
    while(aux!=cabeca){
        aux_chave = (char)aux->chave;
        if(aux_chave < 'A' || aux_chave > 'Z'){
            insert2(cabeca2,aux_chave);
        }else{
            cout<<aux_chave<<" ";
        }
        aux = aux->next;
    }
}
int main(){
	cout<<"Simulando ListaEncadeada"<<endl;
	No *cabeca = criarCabeca();
	No *cabeca2 = criarCabeca();
	if (cabeca!=NULL){
		insert(cabeca, 'A');
		insert(cabeca, '1');
		insert(cabeca, 'E');
		insert(cabeca, '5');
		insert(cabeca, 'T');
		insert(cabeca, '7');
		insert(cabeca, 'W');
		insert(cabeca, '8');
		insert(cabeca, 'G');
		cout<<"Ordem direta: ";
		printDireto(cabeca);
		funcao(cabeca, cabeca2);
		printDireto(cabeca2);

	}
	return 0;
}

