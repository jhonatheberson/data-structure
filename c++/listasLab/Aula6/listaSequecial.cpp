#include<iostream>
using namespace std;

#define MAX1 100


int busca(int S[], int n, int x){
    for(int i =0; i<n; i++){
        if(S[i]>=x){
            return i;
        }
    }
    return n;
}
void inserir(int S[], int &n, int x){
    if(n < MAX1){
        int i = busca(S, n, x);
        if(S[i] != x){
            int j = n-1;
            while(j>= i){
                S[j+1] = S[j];
                j--;
            }
            S[i] = x;
            n++;
        }else{
            cout<<"Livro duplicado\n";
        }
    }
}

void remover(int S[], int &n, int x){
    if(n!=0){
        int i = busca(S,n,x);
        if(S[i] == x){
            for(int j = i;j<n;j++){
                S[j] = S[j+1];
            }
            n--;
        }else{
            cout<<"Livro nao se encontra na lista";
        }
    }
}

void mostra(int S[], int n){
    for(int i = 0;i<n;i++){
        cout<<S[i]<<" ";
    }
}

int main(){
   int x = 18;
   int n = 13;
   int S[MAX1] = {1,3,5,7,9,12,15,23,27,33,41,82,95};
   mostra(S, n);
   inserir(S, n, x);
   cout<<"\n\n";
   mostra(S, n);
   inserir(S, n, 30);
   cout<<"\n\n";
   mostra(S, n);
   inserir(S, n, 130);
   cout<<"\n\n";
   mostra(S, n);
   remover(S, n, 15);
   cout<<"\n\n";
   mostra(S, n);

}
