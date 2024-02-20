#include<iostream>
using namespace std;

typedef struct a{
struct a* prox;
struct a* ant;
int chave;
}No;

No* criar_cabeca(){
    No* cabeca= new No();
    if(cabeca!= NULL){
    cabeca->ant = cabeca;
    cabeca->prox = cabeca;
    cabeca->chave = NULL;
    }
    return cabeca;
}

No* busca(No* cabeca, int ch){

        No* aux = new No();
        aux = cabeca->prox;
        while(aux->prox!=NULL){
            if(aux->chave == ch){
                return aux;
            }
            aux = aux->prox;
        }
        return NULL;
}

void inserir(No* cabeca, int ch){
   /* No* novo = new No();
    if(cabeca->prox == cabeca){
        cabeca->prox = novo;
        novo->ant = cabeca;
        cabeca->ant = novo;
        novo->prox = cabeca;
    }
    else{
        No* i = busca(cabeca, ch);
        if(i != NULL){
            cout << "elemento ja existe";
            return;
        }
        else{
            No* ultimo = cabeca->ant;
            ultimo->prox = novo;
            novo->prox = cabeca;
            novo->ant= ultimo;
            cabeca->ant = novo;
        }
    }*/
}

void unir(No* cabeca1, No* cabeca2){
    No *ultimo = cabeca1->ant;
    ultimo->prox = cabeca2->prox;
    cabeca2->ant = cabeca1;
}

void printDireto2(No *cabeca){
    No *aux = cabeca->prox;
    while(aux!=cabeca){
        cout << aux->chave << " ";
        aux = aux->prox;
    }
}

int main(){

    No *cabeca1 = criar_cabeca();
    No *cabeca2 = criar_cabeca();

    inserir(cabeca1, 1);
    cout << "Inseriu o primeiro" << endl;
    inserir(cabeca1, 2);
    cout << "Inseriu o segundo" << endl;
    inserir(cabeca2, 3);
    inserir(cabeca2, 4);
    unir(cabeca1, cabeca2);
    printDireto2(cabeca1);
    return 0;
}

