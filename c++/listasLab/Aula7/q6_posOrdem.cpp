#include<iostream>
using namespace std;

typedef struct s{
	int chave;
	int m_no;
	struct s *right;
	struct s *left;
} No;

typedef struct p{
	No *chaveP; // chave (conte�do armazenado)
	int m;
	struct p *prox; // ponteiro para o pr�ximo elemento

} Pilha;

void empilha(Pilha *topoP, No *x, int &ind, int m_aux){
    ind++;
    //cout<<"\nind: "<<ind<<endl;
    Pilha *novoNo = new Pilha();
    if(ind == 0){
        novoNo->prox = NULL;
        topoP->prox = novoNo;
        novoNo->chaveP = x;
        novoNo->m = m_aux;
    }else{
        novoNo->prox = topoP->prox;
        topoP->prox = novoNo;
        novoNo->chaveP = x;
        novoNo->m = m_aux;
    }
    cout<<endl;
    cout<<x->chave<<" com m = "<<m_aux;
}
void desempilha(Pilha *topoP, int &ind, No **noRetirado){
    if(ind >= 0){
        ind--;
        Pilha *aux = topoP->prox;
        topoP->prox = aux->prox;
        *noRetirado = aux->chaveP;
        delete aux;
    }else{
        cout<<"Pilha estah vazia"<<endl;
    }
}

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

int pos_ordem_iterativa(No *pt, Pilha *topoP, int &ind){
    bool sobe;
    int aux;
    while(1){
        while(pt != NULL){
            empilha(topoP, pt, ind, 1);
            pt->m_no = 1;
            pt = pt->left;
        }
        sobe = true;
        while(sobe == true && topoP->prox != NULL){
            No *noRetirado = NULL;
            desempilha(topoP, ind, &noRetirado);
            cout<<"\ndesempilhou: "<<noRetirado->chave<<endl;
            pt = noRetirado;
            aux = pt->m_no;
            switch(aux){
                case 1:
                    empilha(topoP, pt, ind, 2);
                    pt->m_no = 2;
                    pt = pt->right;
                    sobe = false;
                case 2:
                    cout<<endl;
                    if(pt->chave != NULL)cout<<"exibindo: "<<pt->chave<<endl;
            }
        }
        if(topoP->prox == NULL){
            cout<<"break"<<endl;
            break;
        }
    }
}
int main(){
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
	//posOrdem(raiz);
    int ind = -1;
    int t = 3;
    Pilha *topoP = new Pilha ();
    pos_ordem_iterativa(raiz, topoP, ind);

}
