#include<iostream>

using namespace std;

void verifica_heap(int v[], int n){
    int maior = v[0], menor = v[0];
    for(int i = 1; i<n; i++){
        if(maior<v[i]){
            maior = v[i];
        }
        if(menor > v[i]){
            menor = v[i];
        }
    }
    if(maior == v[0]) cout<<"Eh uma heap maxima!!!";
    else if( menor == v[0]) cout<<"Eh uma heap minima!!!";
    else cout<<"Nao eh nenhuma das possibilidades";

}

int main(){
    int n = 10;
    int vMin[n] = {1,2,7,4,3,14,9,16,8,10};
    int vMax[n] = {16,14,10,8,7,9,3,2,4,1};
    verifica_heap(vMax, n);
}
