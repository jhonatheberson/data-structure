#include <iostream>
#define MAX1 100
using namespace std;

void preencher(int V[MAX1], int n);
void preencher(int V[MAX1], int n){

    for(int i = 0;i<n;i++){
        cout << "Informe o valor do vetor na posicao " << i << ":" <<endl;
        cin >> V[i];
    }

}

void mostrar(int V[MAX1], int n);
void mostrar(int V[MAX1], int n){
    for(int i = 0;i<n;i++){
        cout << V[i] << " ";
    }
    cout << endl;
}

void ordena(int A[MAX1], int m);
void ordena(int A[MAX1], int m){
    int aux;
    //O QUE ESSE ALGORITMO FAZ É SEMPRE JOGAR O MAIOR NUMERO PARA A ULTIMA POSICAO!!
    for(int i = 0;i<m;i++){
        for(int j = 0;j<m;j++){
        if(A[j] > A[j+1]){
            aux = A[j];
            A[j]= A[j+1];
            A[j+1] = aux;
            }
        }
    }

}

void intercala(int A[MAX1], int m, int B[MAX1], int n, int C[2*MAX1], int &k);
void intercala(int A[MAX1], int m, int B[MAX1], int n, int C[2*MAX1], int &k){

    bool existe;
    int cont = 0;

    for(int i = 0;i<m;i++){
        for(int j=0;j<k;j++){

        }
    }

    /*ordena(C, cont);*/
    mostrar(C, cont);

}

int main(){
    int m, n, z;
    cout << "Informe o tamanho do vetor A:" << endl;
    cin >> m;
    cout << "Informe o tamanho do vetor B:" << endl;
    cin >> n;

    z = m+n;

    int A[m];
    int B[n];
    int C[z];
    preencher(A, m);
    preencher(B, n);
    ordena(A, m);
    ordena(B, n);
    mostrar(A,m);
    mostrar(B,n);

    intercala(A, m, B, n, C, z);
    return 0;
}

