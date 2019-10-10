#include<iostream>
using namespace std;

typedef struct s{
	int chave;
	struct s *right;
	struct s *left;
} No;

void buscaABB_recursiva(No *raiz, No **pt_retorno, int x, int &f){
	if (raiz!=NULL){
		if (raiz->chave == x){
			*pt_retorno = raiz; // pt_retorno agora aponta apra o elemento encontrado
			f = 1;
		} else {
			if (x < raiz->chave ){
				if (raiz->left == NULL) f=2; // volta na recursao.
				else {
					*pt_retorno = raiz->left; // essa linha é importante porque a busca,
					// caso nao encontre o nó desejado, precisa retornar o elemento que seria pai do elemento procurado.
					buscaABB_recursiva(raiz->left,pt_retorno, x, f); // Chama recursivamente para a esquerda
				}
			} else{
				if (raiz->right == NULL) f=3; // volta na recursao.
				else {
					*pt_retorno = raiz->right; // idem
					buscaABB_recursiva(raiz->right,pt_retorno, x, f);// chama recursivamente para a direita
				}
			}
		}
	}

}


void insert(int x, No **raiz){
	int f=0;
	No *pt_retorno = *raiz;
	buscaABB_recursiva(*raiz, &pt_retorno, x, f); // NOTEM NOTEM NOTEM NOTEM NOTEM NOTEM NOTEM o &pt_retorno e o *raiz
	if (f==1) cout<<"Elemento "<< x <<" ja existe"<<endl;
	else {
		No *novo_no = new No(); // cria novo nó
		novo_no->chave = x; // atribui a chave
		novo_no->left = NULL; // novo nó inicialmente é folha
		novo_no->right = NULL;
		if (f==0) *raiz = novo_no; // o unico caso em que o ponteiro da raiz é modificado
		else {
			if (f==2) pt_retorno->left = novo_no; // o novo nó eh filho esquerdo
			else pt_retorno->right = novo_no; // idem
		}
	}
}

void busca_ant(No *pt, int &aux, int k){
    if(pt->left != NULL) busca_ant(pt->left, aux, k);
    if(pt->chave < k){
        aux = pt->chave;
    }
    if(pt->right != NULL && (pt->right)->chave < k) busca_ant(pt->right, aux, k);
}

int busca_suc(No *pt, int k){
    if(pt->left != NULL) return busca_suc(pt->left, k);
    if(pt->chave > k) return pt->chave;
    if(pt->right != NULL) return busca_suc(pt->right, k);
}



int main(){
    No *raiz = NULL; // NO raiz inicialmente nulo
	insert(30, &raiz);
	insert(20, &raiz);
	insert(40, &raiz);
	insert(25, &raiz);
	insert(21, &raiz);
	insert(47, &raiz);
	insert(38, &raiz);
	insert(23, &raiz);
	insert(43, &raiz);
	int aux1 = NULL, aux2 = NULL, k = 47;
    busca_ant(raiz, aux1, k);
    aux2 = busca_suc(raiz, k);
    cout<<"\nChave: "<<k<<endl;
    cout<<"Antecessor: "<<aux1<<endl;
    cout<<"Sucessor: "<<aux2<<endl;
}

