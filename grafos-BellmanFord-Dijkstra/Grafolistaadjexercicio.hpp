#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
#define POS_INF 1000000000
#define NEG_INF -1000000000
class GrafoListaAdj {
private:
    int value;
    vector<string> vertices; //lista de vertices
    //first � o indice do vertice, second � o peso (caso o grafo seja ponderado)
    vector<vector<pair<int, int>>> arestas; //arestas
    /**
    * A principio nao temos nenhuma ordenacao usando os rotulos.
    * Portanto, usaremos busca linear.
    **/
    int obterIndiceVertice(string rotuloVertice);
    /**
    * O argumento indicesVerticesVisitados serve para controlar quais
    * vertices j� foram visitados.
    * Lembrando que DFS � uma fun��o recursiva.
    **/
    void dfs(string rotuloVOrigem, bool* indicesVerticesVisitados);
public:
    GrafoListaAdj(); //Construtores (sobrecarregado)
    
    /**
    * Lembrem-se:
    *       1) nao podemos inserir vertices com mesmo rotulo
    *       2) toda vez que inserirmos um novo v�rtice, precisaremos
    *          inserir um vetor para representar as conex�es daquele
    *          v�rtice na lista de adjac�ncias
    **/
    void inserirVertice(string rotuloVertice);
    /**
    * Sempre que o grafo for n�o ponderado, adicionaremos o peso 1,
    * por conveni�ncia.
    **/
    void inserirArestaDirecionada(string rotuloVOrigem, string rotuloVDestino);
    void inserirArestaNaoDirecionada(string rotuloVOrigem, string rotuloVDestino);
    void inserirArestaNaoDirecionada(string rotuloVOrigem, string rotuloVDestino, int peso);
    /**
    * Inserir uma aresta entre rotuloVOrigem e rotuloVDestino com o peso
    * especificado.
    **/
    void inserirArestaDirecionada(string rotuloVOrigem, string rotuloVDestino, int peso);
    /**
    * Verifica se v�rtice rotuloVOrigem e v�rtice rotuloVDestino s�o
    * conectados.
    **/
    bool saoConectados(string rotuloVOrigem, string rotuloVDestino);
    /**
    * Verifica se h� algum caminho entre v�rtice rotuloVOrigem e 
    * v�rtice rotuloVDestino.
    * A melhor forma de fazer isto � reusando a fun��o dfs.
    **/
    //
    bool haCaminho(string rotuloVOrigem, string rotuloVDestino);
    /**
    * Muda os r�tulos do v�rtices dos diferentes componentes para
    * cor1, cor2, etc.
    * Procura componentes partindo do v�rtice v0 ou v1, em ordem
    * crescente. As cores tamb�m s�o atribu�das nessa mesma ordem.
    * Retorna a quantidade de componentes.
    * A melhor forma de fazer isto � reusando a fun��o dfs.
    **/
    int colorir();
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
    int* bfs(string rotuloVOrigem);
    /**
    * Usamos o BellmanFord para encontrar menor caminho
    * em grafos com arestas com pesos negativos.
    * O BellmanFord consegue detectar ciclos negativos
    * e atribuir o valor NEG_INF (constante definida nesse arquivo)
    * aos vértices que pertençam ao ciclo.
    * POS_INF deve ser atribuído aos vértices inalcançáveis.
    * O aspecto negativo é sua complexidade de tempo: O(V*E).
    * Isto acontece pois, como possui arestas negativas, cada vértice 
    * do grafo precisa ser processado V vezes.   
    * Pseudo-código: https://github.com/eduardolfalcao/edii/blob/master/conteudos/Grafos.md#bellman-ford
    **/
    int* bellmanFord(string rotuloVOrigem);

    /**
    * Usamos o Dijkstra para encontrar menor caminho
    * em grafos sem arestas com pesos negativos.
    * O Dijkstra retorna respostas incorretas caso o grafo
    * possua arestas negativas, e portanto não consegue
    * detectar ciclos negativos. Este é o aspecto negativo.
    * POS_INF deve ser atribuído aos vértices inalcançáveis.
    * O aspecto positivo é sua complexidade de tempo: O(V+E).
    * Isto acontece pois, como o grafo não possui arestas negativas, 
    * cada vértice do grafo precisa ser processado apenas 1 vez.
    * Pseudo-código: https://github.com/eduardolfalcao/edii/blob/master/conteudos/Grafos.md#dijkstra
    * Ilustração: https://docs.google.com/drawings/d/1NmkJPHpcg8uVcDZ24FQiYs3uHR5n-rdm1AZwD74WiMY/edit?usp=sharing
    **/
    int* dijkstra(string rotuloVOrigem);

    vector<string> getVertices();

    vector<vector<pair<int, int>>> getArestas();
};