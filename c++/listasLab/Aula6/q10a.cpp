#include <iostream>
#include <cmath>
using namespace std;

typedef struct s{
	int chave; // chave (conte�do armazenado)
	struct s *next; // ponteiro para o pr�ximo elemento

} No;

No *criarCabeca(){
	No *cabeca = new No (); // aloca�ao
	if (cabeca!=NULL){ // apenas pra verificar se a aloca�ao foi bem sucedida
		cabeca->chave = -1; // Somente pra dizer que o conteudo da ceb�a � desprez�vel
		cabeca->next = NULL; // lista vazia
	}
	return cabeca;
}

void busca(No *cabeca, No **ant, No **pont, int x){
	*ant = cabeca; // ant agora aponta pra cabe�a e isso se reflete fora da fun�ao
	*pont = NULL;
	No *aux = cabeca->next;
	while (aux!=NULL){
        *ant = aux; // ant agora aponta pra aux e isso se reflete fora da fun�ao
        aux = aux->next;
    }
}


void insert(No *cabeca, int novoValor){
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


// Imprime a lista da cabe�a at� o �ltimo elemento (ordem crescente)
void printDireto(No *cabeca){
	No *aux = cabeca->next;
	while (aux!=cabeca){
		cout<<aux->chave<<" ";
		aux = aux->next;
	}
	cout<<endl;
}

float polinomio(No *pont, float x, int k){
    float total = 0, c = 0;
    No *aux = pont->next;
    for(int i = k-1; i>=0; i--){
        c = aux->chave;
        total = total + c*pow(x,k);
        aux = aux->next;
    }
    return total;
}

int main(){
	No *P = criarCabeca();
	No *Q = criarCabeca();
    insert(P,1);
    insert(P,3);
    insert(P,-2);
    insert(Q,-2);
    insert(Q,11);
    insert(Q,1);
    float rP = polinomio(P, 1, 3);
    float rQ = polinomio(Q, 1, 3);
    cout<<"P(x)+Q(x) = "<<(rP+rQ)<<endl;
    cout<<"P(x)*Q(x) = "<<(rP*rQ)<<endl;
}

