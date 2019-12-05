#include <iostream>
using namespace std;

typedef struct no{
    struct no *pont_d;
    struct no *pont_e;
    int chave;
} No;

No *arvore(){
    No *raiz = new No();
    if(raiz != NULL){
        raiz->chave = NULL;
    }
    return raiz;
}

void busca(No **pt_raiz, int x, int f){
    if(pt_raiz == NULL){

        if((*pt_raiz)->chave == x){
            f = 1;
        }

        else{
            if(x<(*pt_raiz)->chave){
                if((*pt_raiz)->pont_e == NULL){
                    f = 2;
                }
                else{
                    (*pt_raiz) = (*pt_raiz)->pont_e;
                    busca(pt_raiz, x, f);
                }
            }
            else{
                if((*pt_raiz)->pont_d == NULL){
                    f = 3;
                }
                else{
                    (*pt_raiz) = (*pt_raiz)->pont_d;
                    busca(pt_raiz, x, f);
                }
            }
        }
    }
}

void inserir(No *pt_raiz, int x, int f){
    busca(&pt_raiz, x, f);
    if(f == 1){ //ELEMENTO JÁ EXISTE
        cout << "O elemento existe na arvore." << endl;
    }
    else{
        No *novo = new No();
        novo->chave = x;
        novo->pont_d = NULL;
        novo->pont_e = NULL;
        if(f == 0){
            pt_raiz = novo;
        }
        else if(f == 2){
            pt_raiz->pont_e = novo;
        }
        else if(f == 3){
            pt_raiz->pont_d = novo;
        }
    }
}

void remover(No *pt_raiz, int x, int f){
    busca(&pt_raiz, x, f);
    if(f == 1){

    }
    else{

    }
}

int main(){
    No *raiz = arvore();
    return 0;
}
