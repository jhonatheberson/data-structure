#include <iostream>
using namespace std;

void SelectionSort(int vetor[100], int n) {
    for (int indice = 0; indice < n; ++indice) {
        int indiceMenor = indice;
        for (int indiceSeguinte = indice+1; indiceSeguinte < n; ++indiceSeguinte) {
            if (vetor[indiceSeguinte] < vetor[indiceMenor]) {
                indiceMenor = indiceSeguinte;
            }
        }
        int aux = vetor[indice];
        vetor[indice] = vetor[indiceMenor];
        vetor[indiceMenor] = aux;
    }

    for(int i = 0;i<n;i++){
        cout << vetor[i] << " ";
    }
}

int main(){
     int n;
    cout << "Informe o tamanho do vetor:" << endl;
    cin >> n;

    int v[n];

    for(int i = 0;i<n;i++){
        cin >> v[i];
    }

    SelectionSort(v, n);

    return 0;
}


