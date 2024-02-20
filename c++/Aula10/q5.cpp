#include<iostream>
using namespace std;

void troca(float &a, float &b){
    float aux = a;
    a = b;
    b = aux;
}

void descer(int i, int n, float vet_quantia[], float vet_peso[]){
    int j = 2*i+1; //recebe o filho esquerdo
    if(j<n){
        if(j<n-1){
            if(vet_quantia[j+1]>vet_quantia[j]){
                j++;
            }
        }
        if(vet_quantia[i]<vet_quantia[j]){
            troca(vet_quantia[i],vet_quantia[j]);
            troca(vet_peso[i], vet_peso[j]);
            descer(j, n, vet_quantia, vet_peso);
        }
    }
}

void arranjar(int n, float vet_quantia[], float vet_peso[]){
    for(int i = (n-1)/2; i>=0; i--) descer(i, n, vet_quantia, vet_peso);
}

void remocao(int &n, float H1[], float H2[]){
    if(n>0){
        float elemento1 = H1[0];
        float elemento2 = H2[0];
        H1[0] = H1[n-1];
        H2[0] = H2[n-1];
        n--;
        descer(0, n, H1, H2);
    }else cout<<"\nHeap vazia";
}

void func(int n, float W, float vet_quantia[], float vet_peso[]){
    float soma_quantia = 0, soma_peso = 0, aux;
    float numerador = 0, denominador = 0;
    while(1){
        arranjar(n, vet_quantia, vet_peso);
        aux = soma_peso + vet_peso[0];
        //cout<<"\naux: "<<aux;
        //Se, a barra que esta sendo retirada do topo da heap nao exceder o peso
        //contamos ela inteira
        if(aux < W){
            soma_quantia += vet_quantia[0];
            soma_peso += vet_peso[0];
            remocao(n, vet_quantia, vet_peso);
            if(aux == W){
                break;
            }
        }
        else if(aux > W){ //senao fracionamos
            float resto = W - soma_peso;
            numerador = resto;
            denominador = vet_peso[0];
            float fracao = (numerador/denominador);
            fracao = fracao*vet_quantia[0];
            soma_quantia += fracao;
            break;
        }
    }
    cout<<"\nPeso das barras inteiras "<<soma_peso<<" e da fracionada "<<numerador<<"/"<<denominador;
    cout<<"\nQuantidade total em reais: "<<soma_quantia;

}

int main(){
    int n = 4, W = 72.0;
    float vet_quantia[n] = {60.0,100.0,120.0,75.00};
    float vet_peso[n] = {10.0,20.0,30.0,15.0};
    func(n,W,vet_quantia,vet_peso);
}
