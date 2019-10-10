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

int mostraElemento(No *Matriz, int i, int j, int k){
    if(j ==2){
        return 0;
    }else{
        cout<<"entrou"<<endl;
        No *aux = Matriz;
        for(int t = 0; t<(i+j+k);t++){
            aux = aux->next;
        }
        return(aux->chave);
    }
}

void somaMatriz(No *Ma, No *Mb, No *Mc, int n, int m, int k){
    No *auxA = Ma->next;
    No *auxB = Mb->next;
    No *auxC = Mc;
    int soma = 0;
    for(int t =0; t<(n+m+k); t++){
        soma = (auxA->chave) + (auxB->chave);
        insert(auxC, soma);
        auxA = auxA->next;
        auxB = auxB->next;
    }
    printDireto(auxC);
}

int main(){
	No *MatrizA = criarCabeca();
	No *MatrizB = criarCabeca();
	No *MatrizC = criarCabeca();
    //Matriz A
    insert(MatrizA,1);
    insert(MatrizA,0);
    insert(MatrizA,0);
    insert(MatrizA,4);
    insert(MatrizA,0);
    insert(MatrizA,0);
    insert(MatrizA,1);
    insert(MatrizA,0);
    insert(MatrizA,0);
    insert(MatrizA,2);
    insert(MatrizA,0);
    insert(MatrizA,3);
    insert(MatrizA,0);
    //Matriz B
    insert(MatrizB,1);
    insert(MatrizB,3);
    insert(MatrizB,0);
    insert(MatrizB,0);
    insert(MatrizB,0);
    insert(MatrizB,0);
    insert(MatrizB,1);
    insert(MatrizB,0);
    insert(MatrizB,0);
    insert(MatrizB,2);
    insert(MatrizB,0);
    insert(MatrizB,0);
    insert(MatrizB,10);
    int i = 3, j = 4, k = 5, n = 4, m =4;
    int respota = mostraElemento(MatrizA, i, j, k);
    cout<<respota<<endl;
    somaMatriz(MatrizA, MatrizB, MatrizC, n, m, k);
}

