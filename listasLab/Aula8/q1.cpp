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

void posOrdem(No *pt){
    if(pt->left != NULL){
        posOrdem(pt->left);
    }
    if(pt->right != NULL){
        posOrdem(pt->right);
    }
    cout<<pt->chave<<" ";
}


void busca_menor(No *raiz, int &menor){
    if(raiz->chave < menor){
        menor = raiz->chave;
    }
    if (raiz->left !=NULL) busca_menor(raiz->left, menor);
	if (raiz->right !=NULL) busca_menor(raiz->right, menor);
}

void busca_maior(No *raiz, int &maior){
    if(raiz->chave > maior){
        maior = raiz->chave;
    }
    if (raiz->left !=NULL) busca_maior(raiz->left, maior);
	if (raiz->right !=NULL) busca_maior(raiz->right, maior);
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
	int maior = raiz->chave, menor = raiz->chave;
    posOrdem(raiz);
    busca_maior(raiz, maior);
    busca_menor(raiz, menor);
    cout<<"\nMaior chave: "<<maior<<endl;
    cout<<"Menor chave: "<<menor<<endl;
}
