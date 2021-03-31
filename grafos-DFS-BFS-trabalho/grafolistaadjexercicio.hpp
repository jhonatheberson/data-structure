#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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
    }

    /**
    * O argumento indicesVerticesVisitados serve para controlar quais
    * vertices j� foram visitados.
    * Lembrando que DFS � uma fun��o recursiva.
    **/
    void dfs(string rotuloVOrigem, bool* indicesVerticesVisitados) {
        //IMPLEMENTAR
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
        //IMPLEMENTAR
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
        //IMPLEMENTAR
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
    int* bfs(string rotuloVOrigem) {
        //IMPLEMENTAR
    }

    vector<string> getVertices() {
        return vertices;
    }

    vector<vector<pair<int, int>>> getArestas() {
        return arestas;
    }
};