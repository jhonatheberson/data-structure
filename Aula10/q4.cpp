#include<iostream>
#define maximo 100
using namespace std;

void troca(int &a, int &b){
    int aux = a;
    a = b;
    b = aux;
}

void descer(int i, int H[], int n, int vet_indice[]){
    int j = 2*i+1; //recebe o filho esquerdo
    if(j<n){
        if(j<n-1){
            if(H[j+1]>H[j]){
                j++;
            }
        }
        if(H[i]<H[j]){
            troca(H[i],H[j]);
            troca(vet_indice[i], vet_indice[j]);
            descer(j, H, n, vet_indice);
        }
    }
}

void arranjar(int n, int H[], int vet_indice[]){
    for(int i = (n-1)/2; i>=0; i--) descer(i, H, n, vet_indice);
}

void func(int n, int k, int x, int vetor[]){
    int v_dif[n];
    for(int i =0; i<n; i++) {
        v_dif[i] = abs(vetor[i] - x);
    }
    int v_indice[k];
    for(int j = 0; j<k; j++){
        v_indice[j] = j;
    }
    arranjar(k, v_dif, v_indice);
    for(int i = k; i< n; i++){
        if(v_dif[0] > v_dif[i]){
            v_dif[0] = v_dif[i];
            v_indice[0] = i;
            arranjar(k, v_dif, v_indice);
        }
    }
    cout<<"Menores discatancias: ";
    for(int j =0; j<k; j++){
        cout<<v_dif[j]<<" ";
    }
    cout<<"\nOs "<<k<<" valores mais proximos de "<<x<<" sao: ";
    for(int j =0; j<k; j++){
        cout<<vetor[v_indice[j]]<<" ";
    }
}

int main(){
    int n = 6, k = 2, x = 11;
    int vetor[n] = {10,2,14,4,7,6};
    func(n,k,x,vetor);
}
