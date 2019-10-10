#include<iostream>
using namespace std;

typedef struct s{
	char chave; // chave (conteúdo armazenado)
	struct s *prox; // ponteiro para o próximo elemento

} No;



void empilha(No *topoP, char x, int &ind){
    ind++;
    No *novoNo = new No();
    if(ind == 0){
        novoNo->prox = NULL;
    }else{
        novoNo->prox = topoP->prox;
    }
    topoP->prox = novoNo;
    novoNo->chave = x;
}
char desempilha(No *topoP, int &ind){
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

void polesaReversa(No *topoP, char v[], int k, int &ind){
    for(int i=0; i<k; i++){
        if(v[i] >= 'A' && v[i] <= 'Z'){
            cout<<v[i];
        }else{
            if(v[i] == '*' || v[i] == '/' || v[i] == '+' || v[i] == '-'){
                empilha(topoP, v[i], ind);
            }else{
                if(v[i] == ')'){
                    char value = desempilha(topoP, ind);
                    cout<<value;
                }
            }
        }
    }
}

int main(){
    int k = 13;
    char v[k] = {'(','(','A','*','B',')','-','(','C','/','D',')',')'};
    int ind = -1;
    No *topoP = new No ();
    polesaReversa(topoP, v, k, ind);
}





