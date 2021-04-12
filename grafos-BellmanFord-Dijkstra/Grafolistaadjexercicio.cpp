//
// Created by jhonat e klyfton 
//

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
#include "Grafolistaadjexercicio.hpp"

#define POS_INF 1000000000
#define NEG_INF -1000000000

GrafoListaAdj::GrafoListaAdj(){
    int value = 0;
    vector<string> vertices; //lista de vertices
    vector<vector<pair<int, int>>> arestas; //arestas
}
/**
* A principio nao temos nenhuma ordenacao usando os rotulos.
* Portanto, usaremos busca linear.
**/
int GrafoListaAdj::obterIndiceVertice(string rotuloVertice) {
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i].compare(rotuloVertice) == 0) {
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
void GrafoListaAdj::dfs(string rotuloVOrigem, bool* indicesVerticesVisitados) {
        int ind_Origem = GrafoListaAdj::obterIndiceVertice(rotuloVOrigem);
        if (indicesVerticesVisitados[ind_Origem]) {
            return;
        }
        indicesVerticesVisitados[ind_Origem] = true;

        vector<pair<int,int>> vizinhos = arestas[ind_Origem];
        for (int i = 0; i < vizinhos.size(); i++) {
            int indice = vizinhos[i].first;
            GrafoListaAdj::dfs(vertices[indice],indicesVerticesVisitados);
        }
    }
/**
* Lembrem-se:
*       1) nao podemos inserir vertices com mesmo rotulo
*       2) toda vez que inserirmos um novo v�rtice, precisaremos
*          inserir um vetor para representar as conex�es daquele
*          v�rtice na lista de adjac�ncias
**/
void GrafoListaAdj::inserirVertice(string rotuloVertice) {
        int verifica_vertice = 1;
        for(int i = 0; i < vertices.size(); i++) {
            verifica_vertice = rotuloVertice.compare(vertices[i]);
            if(verifica_vertice == 0){
                break;
            }
        }
        if(verifica_vertice != 0){
            vertices.push_back(rotuloVertice);
            arestas.push_back(*new vector<pair<int, int>>);
        }
    }


/**
* Sempre que o grafo for n�o ponderado, adicionaremos o peso 1,
* por conveni�ncia.
**/
void GrafoListaAdj::inserirArestaDirecionada(string rotuloVOrigem, string rotuloVDestino) {
    GrafoListaAdj::inserirArestaDirecionada(rotuloVOrigem, rotuloVDestino, 1);
}

void GrafoListaAdj::inserirArestaNaoDirecionada(string rotuloVOrigem, string rotuloVDestino) {
    GrafoListaAdj::inserirArestaDirecionada(rotuloVOrigem, rotuloVDestino, 1);
    GrafoListaAdj::inserirArestaDirecionada(rotuloVDestino, rotuloVOrigem, 1);
}

void GrafoListaAdj::inserirArestaNaoDirecionada(string rotuloVOrigem, string rotuloVDestino, int peso) {
    inserirArestaDirecionada(rotuloVOrigem, rotuloVDestino, peso);
    inserirArestaDirecionada(rotuloVDestino, rotuloVOrigem, peso);
}

/**
* Inserir uma aresta entre rotuloVOrigem e rotuloVDestino com o peso
* especificado.
**/
void GrafoListaAdj::inserirArestaDirecionada(string rotuloVOrigem, string rotuloVDestino, int peso) {
    // arestas[vertices[rotuloVOrigem],vertices[rotuloVDestino]] = peso
    int ind_Origem = GrafoListaAdj::obterIndiceVertice(rotuloVOrigem);
    int ind_Destino = GrafoListaAdj::obterIndiceVertice(rotuloVDestino);
    arestas[ind_Origem].push_back(make_pair(ind_Destino,peso));
}


/**
* Verifica se v�rtice rotuloVOrigem e v�rtice rotuloVDestino s�o
* conectados.
**/
bool GrafoListaAdj::saoConectados(string rotuloVOrigem, string rotuloVDestino) {
    int ind_Origem = GrafoListaAdj::obterIndiceVertice(rotuloVOrigem);
    int ind_Destino = GrafoListaAdj::obterIndiceVertice(rotuloVDestino);
    for (int i = 0; i < arestas[ind_Origem].size(); i++) {
        if (arestas[ind_Origem][i].first == ind_Destino) {
            return true;
        }
    }
    return false;
}

/**
* Verifica se h� algum caminho entre v�rtice rotuloVOrigem e 
* v�rtice rotuloVDestino.
* A melhor forma de fazer isto � reusando a fun��o dfs.
**/

    //
bool GrafoListaAdj::haCaminho(string rotuloVOrigem, string rotuloVDestino) {
    bool* indiceVerticesVisitados = new bool[vertices.size()];
        int ind_Origem = GrafoListaAdj::obterIndiceVertice(rotuloVOrigem);
        int ind_Destino = GrafoListaAdj::obterIndiceVertice(rotuloVDestino);
        for (int i = 0; i < vertices.size(); i++) {
            indiceVerticesVisitados[i] = false;
        }
        dfs(rotuloVOrigem,indiceVerticesVisitados);
        indiceVerticesVisitados[ind_Origem] = GrafoListaAdj::saoConectados(rotuloVOrigem, rotuloVOrigem);
        if (indiceVerticesVisitados[ind_Destino]) {
                return true;
        }
        return false;
    }

/**
* Muda os r�tulos do v�rtices dos diferentes componentes para
* cor1, cor2, etc.
* Procura componentes partindo do v�rtice v0 ou v1, em ordem
* crescente. As cores tamb�m s�o atribu�das nessa mesma ordem.
* Retorna a quantidade de componentes.
* A melhor forma de fazer isto � reusando a fun��o dfs.
**/
int GrafoListaAdj::colorir() {
    int cor = 0;
    bool* coloridos_antes = new bool[vertices.size()];
    bool* indicesVerticesVisitados = new bool[vertices.size()];
    for (int i = 0; i < vertices.size(); i++) {
        indicesVerticesVisitados[i] = false;
        coloridos_antes[i] = false;
    }
    for(int i = 0; i < vertices.size(); i++){
        if(!indicesVerticesVisitados[i]){
            dfs(vertices[i], coloridos_antes);
            for (int j = 0; j < vertices.size(); j++)
            {
                if (coloridos_antes[j]) {
                    indicesVerticesVisitados[j] = true;
                    vertices[j] = to_string(cor);
                }
                coloridos_antes[j] = false;
            }
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
int* GrafoListaAdj::bfs(string rotuloVOrigem) {
        int ind_Origem = GrafoListaAdj::obterIndiceVertice(rotuloVOrigem);
        bool* indicesVerticesVisitados = new bool[vertices.size()];
        int* distancia = new int[vertices.size()];
        for (int i = 0; i < vertices.size(); i++) {
            indicesVerticesVisitados[i] = false;
            distancia[i] = 0;
        }
        queue<int> q;
        vector<int> vizinhos;

        indicesVerticesVisitados[ind_Origem] = true;
        distancia[ind_Origem] = 0;
        q.push(ind_Origem);
        while (!q.empty()) {
            int s = q.front(); 
            q.pop();
            vizinhos.clear();
            for (int i = 0; i < vertices.size(); i++) {
                if (GrafoListaAdj::saoConectados(vertices[s], vertices[i])) {
                    vizinhos.push_back(i);
                }
            }
            for (auto i : vizinhos) {
                if (!indicesVerticesVisitados[i]) {
                    indicesVerticesVisitados[i] = true;
                    distancia[i] = distancia[s] + 1;
                    q.push(i);
                }
            }
        }
        return distancia;
    }

vector<string> GrafoListaAdj::getVertices() {
    return vertices;
}

vector<vector<pair<int, int>>> GrafoListaAdj::getArestas() {
    return arestas;
}
