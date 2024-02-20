#include<iostream>
#define maximo 100
using namespace std;

void troca(int &a, int &b){
    int aux = a;
    a = b;
    b = aux;
}

void descer(int i, int H[], int n){
    int j = 2*i+1; //recebe o filho esquerdo
    if(j<=n){
        if(j<n)
            if(H[j+1]>H[j]) j++;
        if(H[i]<H[j]){
            troca(H[i],H[j]);
            descer(j, H, n);
        }
    }
}
void arranjar(int n, int H[]){
    for(int i = (n-1)/2; i>=0; i--) descer(i, H, n);
}
void heap_sort(int n, int H[]){
    arranjar(n, H);
    int m = n-1; //temos que subtrair 1, pois os algoritmos vao trabalhar com o indice do vetor, variando de 0 a n-1
    while(m>0){
        troca(H[0], H[m]);
        m--;
        descer(0,H,m);
    }
}
int main(){
    int n = 10;
    int v[maximo] = {7,5,12,4,8,9,3,14,1,15};
    cout<<"Vetor desordenado: ";
    for (int k = 0; k<n; k++) cout<<v[k]<<" ";
    heap_sort(n, v);
    cout<<"\nOrdenacao com heap sort: ";
    for (int k = 0; k<n; k++) cout<<v[k]<<" ";
}

