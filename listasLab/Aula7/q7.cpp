#include <iostream>
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
					*pt_retorno = raiz->left; // essa linha � importante porque a busca,
					// caso nao encontre o n� desejado, precisa retornar o elemento que seria pai do elemento procurado.
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
		No *novo_no = new No(); // cria novo n�
		novo_no->chave = x; // atribui a chave
		novo_no->left = NULL; // novo n� inicialmente � folha
		novo_no->right = NULL;
		if (f==0) *raiz = novo_no; // o unico caso em que o ponteiro da raiz � modificado
		else {
			if (f==2) pt_retorno->left = novo_no; // o novo n� eh filho esquerdo
			else pt_retorno->right = novo_no; // idem
		}
	}
}
void posOrdem(No *pt, int &cont){
    if(pt->left != NULL){
        posOrdem(pt->left,cont);
    }
    if(pt->right != NULL){
        posOrdem(pt->right,cont);
    }
    cout<<pt->chave<<" ";
    if(pt->left == NULL && pt->right == NULL) cont++;
}

int main(int argc, char const *argv[]){
	No *raiz = NULL; // NO raiz inicialmente nulo
	insert(30, &raiz);
	insert(20, &raiz);
    insert(40, &raiz);
	insert(18, &raiz);
	insert(25, &raiz);
	insert(19, &raiz);
	insert(47, &raiz);
	insert(38, &raiz);
	insert(43, &raiz);
	insert(50, &raiz);
	int cont = 0;
	posOrdem(raiz, cont);
	cout<<"\nNumero de folhas: "<<cont;

}
