#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;


typedef struct s{
    int chave;
	string rotuloVOrigem;
	struct s *prox;
} No;

typedef struct Fila {

	int capacidade;
	float *dados;
	int primeiro;
	int ultimo;
	int nItens;

}Nof;

bool marca[6];

class GrafoListaAdj {
private:
    vector<string> vertices;

    //first � o indice do vertice, second � o peso (caso o grafo seja ponderado)
    vector<vector<pair<int, int>>> arestas;

    /**
    * A principio nao temos nenhuma ordenacao usando os rotulos.
    * Portanto, usaremos busca linear.
    **/
    int obterIndiceVertice(string rotuloVertice) {
        //IMPLEMENTAR
        for (int i = 0; i < vector->maxNumVertices; i++) {
        if (vector->rotuloVertices[i] == NULL)
            continue;
        if (strcmp(vector->rotuloVertices[i], rotuloVertice) == 0)
            return i;
    }

    return -1;
    }

    /**
    * O argumento indicesVerticesVisitados serve para controlar quais
    * vertices j� foram visitados.
    * Lembrando que DFS � uma fun��o recursiva.
    **/
    void dfs(string rotuloVOrigem, bool* indicesVerticesVisitados, No *lista[6]) {
        marca[rotuloVOrigem] = 1;
        No *pt = lista[rotuloVOrigem]->prox;
        while(pt != NULL){
            if(marca[pt->rotuloVOrigem] != 1){
                marca[pt->rotuloVOrigem] = 1;
                cout<<"Marcou aresta: "<<pt->rotuloVOrigem<<endl;
                printMarca();
                dfs(pt->rotuloVOrigem, pt->indicesVerticesVisitados, lista);
            }
        pt = pt->prox;
        }
    }
public:
    /**
    * Lembrem-se:
    *       1) nao podemos inserir vertices com mesmo rotulo
    *       2) toda vez que inserirmos um novo v�rtice, precisaremos
    *          inserir um vetor para representar as conex�es daquele
    *          v�rtice na lista de adjac�ncias
    **/
    void inserirVertice(string rotuloVertice) {
        while(pt->prox != NULL){
            pt = pt->prox;
        }
        No *prox = new No();
        prox->chave = chave;
        prox->rotuloVertice = rotuloVertice;
        pt->prox = prox;
    }

    /**
    * Sempre que o grafo for n�o ponderado, adicionaremos o peso 1,
    * por conveni�ncia.
    **/
    void inserirArestaDirecionada(string rotuloVOrigem, string rotuloVDestino) {
        inserirArestaDirecionada(rotuloVOrigem, rotuloVDestino, 1);
    }

    void inserirArestaNaoDirecionada(string rotuloVOrigem, string rotuloVDestino) {
        inserirArestaDirecionada(rotuloVOrigem, rotuloVDestino, 1);
        inserirArestaDirecionada(rotuloVDestino, rotuloVOrigem, 1);
    }

    void inserirArestaNaoDirecionada(string rotuloVOrigem, string rotuloVDestino, int peso) {
        inserirArestaDirecionada(rotuloVOrigem, rotuloVDestino, peso);
        inserirArestaDirecionada(rotuloVDestino, rotuloVOrigem, peso);
    }

    /**
    * Inserir uma aresta entre rotuloVOrigem e rotuloVDestino com o peso
    * especificado.
    **/
    void inserirArestaDirecionada(string rotuloVOrigem, string rotuloVDestino, int peso) {
        //IMPLEMENTAR
    }

    /**
    * Verifica se v�rtice rotuloVOrigem e v�rtice rotuloVDestino s�o
    * conectados.
    **/
    bool saoConectados(string rotuloVOrigem, string rotuloVDestino) {
        //IMPLEMENTAR
        int prim_ind = obterIndiceVertice(vector,rotuloVOrigem);
        int segun_ind = obterIndiceVertice(vector,rotuloVDestino);

        if(prim_ind!=-1 && segun_ind!=-1){
            return true;
        }else{
            return false;
        }
    }

    /**
    * Verifica se h� algum caminho entre v�rtice rotuloVOrigem e 
    * v�rtice rotuloVDestino.
    * A melhor forma de fazer isto � reusando a fun��o dfs.
    **/
    bool haCaminho(string rotuloVOrigem, string rotuloVDestino) {
        //IMPLEMENTAR
    }

    /**
    * Muda os r�tulos do v�rtices dos diferentes componentes para
    * cor1, cor2, etc.
    * Procura componentes partindo do v�rtice v0 ou v1, em ordem
    * crescente. As cores tamb�m s�o atribu�das nessa mesma ordem.
    * Retorna a quantidade de componentes.
    * A melhor forma de fazer isto � reusando a fun��o dfs.
    **/
    int colorir() {
        int cor = 1;
        for(int i = 0; i < vertices.size(); i++){
            if(!visitado[i]){
                dfs(i); //dfs irá alterar a variável global visitado
                //neste ponto podemos descobrir quais vértices
                //foram visitados e mudar o valor de seus rótulos
                cor++;
            }
        }
        return cor;
    }

    void inserir(struct Fila *f, int v) {

        if(f->ultimo == f->capacidade-1)
            f->ultimo = -1;

        f->ultimo++;
        f->dados[f->ultimo] = v;
        f->nItens++;

    }

    int remover(struct Fila *f ) {
        int temp = f->dados[f->primeiro++];
        if(f->primeiro == f->capacidade)
            f->primeiro = 0;
        f->nItens--;
        return temp;
    }

    int estaVazia( struct Fila *f ) {
        return (f->nItens==0);
    }

    void printMarca(){
        for(int i = 0; i<6; i++){
            cout<<marca[i]<<" ";
        }
        cout<<endl;
    }

    /**
    * Usa a abordagem de navega��o BFS para listar as dist�ncias
    * entre o v�rtice rotuloVOrigem e cada um dos demais v�rtices.
    * A fun��o BFS consegue listar a menor dist�ncia entre um v�rtice
    * e os demais se o grafo for N�O-PONDERADO.
    * Retorna um vetor de inteiros com a quantidade de arestas 
    * (dist�ncia) e o v�rtice rotuloVOrigem e cada um dos demais v�rtices.
    * N�o � uma fun��o recursiva. 
    * � necess�rio utilizar a ED fila.
    **/
    int* bfs(string rotuloVOrigem, No *lista[6], Nof *fila) {
        printMarca();
        cout<<"MARCOU "<<rotuloVOrigem<<endl;
        marca[rotuloVOrigem] = 1;
        inserir(fila, rotuloVOrigem);
        while(!estaVazia(fila)){
            int rotuloVOrigem_fila = remover(fila);
            No *pt = lista[rotuloVOrigem_fila];
            while(pt!= NULL){
                if(marca[pt->rotuloVOrigem] != 1){
                    marca[pt->rotuloVOrigem] = 1;
                    inserir(fila, pt->rotuloVOrigem);
                    printMarca();
                    cout<<"MARCOU "<<pt->rotuloVOrigem<<endl;
                }
                pt = pt->prox;
            }
        }
    }

    vector<string> getVertices() {
        return vertices;
    }

    vector<vector<pair<int, int>>> getArestas() {
        return arestas;
    }
};