#include<iostream>
#define maximo 100
using namespace std;

void troca(int &a, int &b){
    int aux = a;
    a = b;
    b = aux;
}

void subir(int i, int H[], int n){
    int j =  (i-1)/2; //j <- pai(i)
    if(j > 0){
        if(H[i]>H[j]){
            troca(H[i],H[j]);
            subir(j, H, n);
        }
    }
}

void descer(int i, int H[], int n){
    int j = 2*i+1; //recebe o filho esquerdo
    if(j<n){
        if(j<n-1){
            if(H[j+1]>H[j]){
                j++;
            }
        }
        if(H[i]<H[j]){
            troca(H[i],H[j]);
            descer(j, H, n);
        }
    }
}

void arranjar(int n, int H[]){
    for(int i = (n-1)/2; i>=0; i--) descer(i, H, n);
}

void remocao(int &n, int H[]){
    if(n>0){
        int elemento = H[0];
        H[0] = H[n-1];
        n--;
        descer(0, H, n);
    }else cout<<"\nHeap vazia";
}

int main(){
    int n = 10;
    int v_sobe[maximo] = {14,8,10,4,7,9,3,2,1,13};
    int v_desce[maximo] = {1,14,10,8,7,9,3,2,4};
    int v_aleatorio[maximo] = {7,5,12,4,8,9,3,14,1,15};
    int v_remocao[maximo] = {16,14,10,8,7,9,3,2,4,1};
    subir(n-1, v_sobe, n);
    cout<<"Procedimento de subida: ";
    for (int k = 0; k<n; k++) cout<<v_sobe[k]<<" ";
    descer(0, v_desce, n);
    cout<<"\nProcedimento de descida: ";
    for (int k = 0; k<n-1; k++) cout<<v_desce[k]<<" ";
    arranjar(n, v_aleatorio);
    cout<<"\nProcedimento de construcao: ";
    for (int k = 0; k<n; k++) cout<<v_aleatorio[k]<<" ";
    remocao(n, v_remocao);
    cout<<"\nProcedimento de remocao: ";
    for (int k = 0; k<n; k++) cout<<v_remocao[k]<<" ";
}
