#include<iostream>
using namespace std;

typedef struct s{
	int chave;
	int altura;
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

int getAltura(No *raiz){
	if (raiz!=NULL){
			int left = getAltura(raiz->left);  // chamada recursiva para a esqueda
			int right = getAltura(raiz->right); // chamada recursiva para a direita
			if (left>right){
                raiz->altura = left + 1;
                return left + 1; // soma +1 na altura (sobe o nível)
			}else{
                raiz->altura = right + 1;
                return right +1;
			}
	}
	return 0;
}

void posOrdem(No *pt){
    if(pt->left != NULL){
        posOrdem(pt->left);
    }
    if(pt->right != NULL){
        posOrdem(pt->right);
    }
    cout<<pt->chave<<" ";
}

int main(){
    No *raiz = NULL; // NO raiz inicialmente nulo
    int numero_nos = 0, cont = 0;
	insert(30, &raiz);
	insert(20, &raiz);
    insert(40, &raiz);
	insert(25, &raiz);
	insert(18, &raiz);
	insert(19, &raiz);
	insert(38, &raiz);
	insert(47, &raiz);
	insert(43, &raiz);
    posOrdem(raiz);
    cout<<endl;
    int altura1 = getAltura(raiz->left);
    int altura2 = getAltura(raiz->right);
    if(abs(altura1 - altura2) <= 1){
        cout<<"Eh arvore AVL";
    }else{
        cout<<"Nao eh arvore AVL";
    }
    cout<<"\n\naltura esquerda: "<<((raiz->left)->left)->altura<<endl;
}



