#include <iostream>
using namespace std;

void Descer_max(int Heap_max[],int n,int i);  //Procedimento Descer para uma heap maxima
void Descer_min(int Heap_min[],int n,int i);  //Procedimento Descer para uma heap minima
int Piso(float n); //Retorna o piso de um numero(arredondamento para baixo)
void Exibe(int Heap[],int n);               //Mostra o vetor
void GerarHeap_max(int V[],int n);  //Algoritmo para pegar um vetor e gerar uma heap maxima
void GerarHeap_min(int V[],int n);  //Algoritmo para gerar uma heap minima

int main(){

    //Desejamos nesse algoritmo, dado um vetor qualquer transforma-lo em uma heap maxima ou minima

    int n = 10;
    int V[n] = {10,20,15,30,25,12,27,33,41,50};

    cout << "Vetor inicial" << endl;
    Exibe(V,n);
    GerarHeap_max(V,n);

    return 0;
}

//Este procedimento ira descer o elemento que ficou na raiz para sua posição correta, re-arrumando a heap maxima
void Descer_max(int Heap_max[],int n,int i){
    int j = 2*i+1;       //Posição do Filho esquerdo de i
    int aux;             //Auxiliar para trocar elementos da heap de lugar

    if(j<n){                    //Se o indice do filho esquerdo nao ultrapassar o tamanho do  vetor(ou seja esta na heap)
        if(Heap_max[j+1]>Heap_max[j] && j+1<n){  //Se o filho direito tem mais priodidade
            j = j+1;            //Vamos apontar para ele
        }
        if(Heap_max[i]<Heap_max[j]){    //Se o valor da posição i é menor que seu filho esquerdo(ou direito a depender do if acima)
            aux = Heap_max[i];      //Troca os dois
            Heap_max[i] = Heap_max[j];
            Heap_max[j] = aux;
            Descer_max(Heap_max,n,j);//Chama recursivo na proxima posição
        }
    }
}

void Descer_min(int Heap_min[],int n,int i){//Procedimento Descer para uma heap minima
    int j = 2*i+1;       //Posição do Filho esquerdo de i
    int aux;             //Auxiliar para trocar elementos da heap de lugar

    if(j<n){                    //Se o indice do filho esquerdo NÃO ultrapassar o tamanho do  vetor(ou seja esta na heap)
        if(Heap_min[j+1]<Heap_min[j] && j+1<n){  //Se o filho direito tem menor priodidade
            j = j+1;            //Vamos apontar para ele
        }
        if(Heap_min[i]>Heap_min[j]){    //Se o valor da posição i é maior que seu filho esquerdo(ou direito a depender do if acima)
            aux = Heap_min[i];          //Troca os dois
            Heap_min[i] = Heap_min[j];
            Heap_min[j] = aux;
            Descer_min(Heap_min,n,j);
        }
    }
}

int Piso(float n){
    return int(n);
}

void Exibe(int Heap[],int n){
    for(int i=0;i<n;i++){
        cout << Heap[i] << " ";
    }
    cout << endl;
}

void GerarHeap_max(int V[],int n){

    int i = Piso(n/2)-1;

    for(i;i>=0;i--){
        Descer_max(V,n,i);
    }

    cout << "Heap maxima gerada" << endl;
    Exibe(V,n);

}
