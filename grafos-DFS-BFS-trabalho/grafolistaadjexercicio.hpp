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
    int obterIndiceVertice(string rotuloVertice) {
        //IMPLEMENTAR
        int tam = vertices.size();
        for (int i = 0; i < tam; i++) {
            if (vertices[i] == rotuloVertice){
                return i;
            }
        }
        return -1;
    }

    /**
    * O argumento indicesVerticesVisitados serve para controlar quais
    * vertices j� foram visitados.
    * Lembrando que DFS � uma fun��o recursiva.
    **/
    void dfs(string rotuloVOrigem, bool* indicesVerticesVisitados) {
        int indexOrigem = obterIndiceVertice(rotuloVOrigem);
        if (indicesVerticesVisitados[indexOrigem])
            return;
        indicesVerticesVisitados[indexOrigem] = true;

        vector<pair<int,int>> vizinhos = arestas[indexOrigem];
        
        for (int i=0; i<vizinhos.size(); i++){
            string rotulo = "v" + to_string(vizinhos[i].first + value);
            dfs(rotulo, indicesVerticesVisitados);
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
        value = 0;
        vertices.push_back(rotuloVertice);
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
        if (rotuloVOrigem == NULL)
            return;
        arestas[vertices[rotuloVOrigem],vertices[rotuloVDestino]] = peso
    }

    /**
    * Verifica se v�rtice rotuloVOrigem e v�rtice rotuloVDestino s�o
    * conectados.
    **/
    bool saoConectados(string rotuloVOrigem, string rotuloVDestino) {
        //IMPLEMENTAR
        int prim_ind = obterIndiceVertice(rotuloVOrigem);
        int segun_ind = obterIndiceVertice(rotuloVDestino);
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

            if(!indicesVerticesVisitados[i]){
                dfs(i, indicesVerticesVisitados); //dfs irá alterar a variável global visitado
                //neste ponto podemos descobrir quais vértices
                //foram visitados e mudar o valor de seus rótulos
                cor++;
            }
        }
        return cor;
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
        int indexVOrigem = obterIndiceVertice(rotuloVOrigem);
        bool* visited;
        int* distance;
        visited[indexVOrigem] = true;
        distance[indexVOrigem] = 0;
        queue<int> Fila;
        Fila.push(indexVOrigem);
        while (!Fila.empty()) {
            int s = Fila.front(); Fila.pop();
            // process node s
            for (auto u : vertices[s]) {
                if (!visited[u]){
                    visited[u] = true;
                    distance[u] = distance[s]+1;
                    Fila.push(u);
                }
            }
        }
        return distance;
    }

    vector<string> getVertices() {
        return vertices;
    }

    vector<vector<pair<int, int>>> getArestas() {
        return arestas;
    }
};