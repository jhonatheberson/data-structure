#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <iostream>
#define vert int
using namespace std;
#include <string.h>
#include "grafomatadjexercicio.hpp"

// typedef struct GrafoMatrizAdj {
//     int** arestas;
//     char** rotuloVertices;
//     int verticesInseridos;
//     int maxNumVertices;
// } Grafo;


//Aloca a matriz de adjacencias
static int **iniciaMatriz( int r, int c, int val) {
   int **m = new int *[r];
   for (vert i = 0; i < r; i++)
      m[i] = new int [c];
   for (vert i = 0; i < r; i++)
      for (vert j = 0; j < c; ++j)
         m[i][j] = val;
   return m;
}

// //Inicia um grafo com numero de vertices V
Grafo* iniciaGrafo(int maxNumVertices, bool ponderado) {
  Grafo *G = new Grafo();
  bool True = true;
  G->maxNumVertices = maxNumVertices;
  G->verticesInseridos = 0;
  if (ponderado == True){
    G->arestas = iniciaMatriz( maxNumVertices, maxNumVertices, 0);
  }else{
    G->arestas = iniciaMatriz( maxNumVertices, maxNumVertices, INT_MAX);
  }
  return G;
}

void printGrafo(Grafo *G) {
   for (vert maxNumVertices = 0; maxNumVertices < G->maxNumVertices; ++maxNumVertices) {
      cout<<"Vertice "<<maxNumVertices<<": Se conecta com: ";
      for (vert w = 0; w < G->maxNumVertices; ++w)
         if (G->arestas[maxNumVertices][w] == 1)
            cout<<w;
      cout<<endl;
   }
}

/**
 * Se o grafo for ponderado, inicializamos cada posicao da matriz com INT_MAX.
 * Se o grafo for não ponderado, inicializamos cada posicao da matriz com 0.
 **/
struct GrafoMatrizAdj* inicializar(int numVertices, bool ponderado) {
  Grafo *G = iniciaGrafo(numVertices, ponderado);
  return G;
}



/**
 * A principio nao temos nenhuma ordenacao usando os rotulos.
 * Portanto, usaremos busca linear
 **/
int obterIndiceVertice(struct GrafoMatrizAdj* grafo, char* rotuloVertice) {
    for(int i = 0; i < grafo->maxNumVertices; i++){
        if(strcmp(grafo->rotuloVertices[i],rotuloVertice)==0){
           return i;
        }
    }
    return -1;
}

/**
 * Se o grafo for ponderado, usamos a variavel peso para especificar o peso da aresta.
 * Se o grafo for não ponderado, passaremos o valor 1 para a variavel peso, de modo que represente existência da aresta.
 * Se um dos rotulos dos vertices nao existir, simplesmente nao faremos nada.
 **/
// void inserirAresta(struct GrafoMatrizAdj* grafo, char* rotuloVOrigem, char* rotuloVDestino, int peso) {
//   if (grafo->arestas[rotuloVOrigem][rotuloVDestino] == 0 || grafo->arestas[rotuloVOrigem][rotuloVDestino] ==INT_MAX) {
//       grafo->arestas[rotuloVOrigem][rotuloVDestino] = peso;
//       grafo->verticesInseridos++;
//    }
// }

void inserirAresta(struct GrafoMatrizAdj* grafo, char* rotuloVOrigem, char* rotuloVDestino, int peso) {
    int prim_ind = obterIndiceVertice(grafo,rotuloVOrigem);
    int segun_ind = obterIndiceVertice(grafo,rotuloVDestino);

    if(prim_ind!=-1 && segun_ind!=-1){
        grafo->arestas[prim_ind][segun_ind] = peso;
    }
}


/**
 * Usamos a variavel grafo->verticesInseridos para controlar a quantidade de vertices que ja foi inserido no grafo.
 * Logo, ela pode/deve ser usada para especificar em qual posicao o vertice a ser inserido sera alocado.
 **/

void inserirVertice(struct GrafoMatrizAdj* grafo, char* rotuloVertice) {
    grafo->rotuloVertices[grafo->verticesInseridos] = rotuloVertice;
    grafo->verticesInseridos = grafo->verticesInseridos+1;
}

/**
 * Tomar cuidado com as diferenças semânticas entre haver conexão entre dois vertices em um grafo ponderado,
 * e haver conexão entre dois vertices em um grafo nao-ponderado.
 **/
bool saoConectados(struct GrafoMatrizAdj* grafo, char* rotuloVOrigem, char* rotuloVDestino) {
 int prim_ind = obterIndiceVertice(grafo,rotuloVOrigem);
    int segun_ind = obterIndiceVertice(grafo,rotuloVDestino);

    if(prim_ind!=-1 && segun_ind!=-1){
        return true;
    }else{
        return false;
    }
}