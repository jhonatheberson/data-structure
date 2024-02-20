#include<iostream>
using namespace std;

typedef struct p{
	char chave; // chave (conteúdo armazenado)
	struct p *prox; // ponteiro para o próximo elemento

} Pilha;



void empilha(Pilha *topoP, char x, int &ind){
    ind++;
    Pilha *novoNo = new Pilha();
    if(ind == 0){
        novoNo->prox = NULL;
    }else{
        novoNo->prox = topoP->prox;
    }
    topoP->prox = novoNo;
    novoNo->chave = x;
}
char desempilha(Pilha *topoP, int &ind){
    if(ind >= 0){
        ind--;
        char value;
        No *aux = topoP->prox;
        topoP->prox = aux->prox;
        value = aux->chave;
        delete aux;
        return value;
    }else{
        cout<<"Pilha estah vazia"<<endl;
    }
}

void mostra(No *topoP){
    No *aux = topoP->prox;
    while(aux!=NULL){
        cout<<aux->chave<<" ";
        aux = aux->prox;
    }
    cout<<endl;
}

void verificaPalindromo(No *topoP, char vet[], int &ind, int k){
    char value;
    for(int i = 0; i<k; i++){
        value = desempilha(topoP, ind);
        if(value != vet[i]) break;
    }
    if(ind == -1) cout<<"Eh palindrimo!!!"<<endl;
    else cout<<"Nao eh palindrimo!!!"<<endl;
}

int main(){
    int k = 6;
    char vet[k] = {'1','2','3','3','2','1'};
    int ind = -1;
    No *topoP = new No ();
    for (int i = 0; i<k; i++){
        empilha(topoP, vet[i], ind);
    }
    mostra(topoP);
    verificaPalindromo(topoP, vet, ind, k);
}
