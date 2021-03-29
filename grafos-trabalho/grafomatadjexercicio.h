#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <iostream>
#define vert int
using namespace std;
#include <string.h>

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
  G->maxNumVertices = maxNumVertices;
  G->verticesInseridos = 0;
  if (ponderado == 'true'){
    G->arestas = iniciaMatriz( maxNumVertices, maxNumVertices, 0);
  }else{
    G->arestas = iniciaMatriz( maxNumVertices, maxNumVertices, INT_MAX);
  }
  return G;
}

void insereConexao(Grafo *G, vert rotuloVOrigem, vert rotuloVDestino, char peso) {
   if (G->arestas[rotuloVOrigem][rotuloVDestino] == 0 || G->arestas[rotuloVOrigem][rotuloVDestino] ==INT_MAX) {
      G->arestas[rotuloVOrigem][rotuloVDestino] = peso;
      G->verticesInseridos++;
   }
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

typedef struct GrafoMatrizAdj {
    int** arestas;
    char** rotuloVertices;
    int verticesInseridos;
    int maxNumVertices;
} Grafo;

// //Inicia a struct grafo
// typedef struct s {
//    int v;
//    int a;
//    int **adj;
// } Grafo;


// int main(){
//     Grafo *G = iniciaGrafo(10);
//     insereConexao(G, 3, 5);
//     printGrafo(G);
// }

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
    int obterIndiceVertice(struct GrafoMatrizAdj* grafo, char* rotuloVertice) {
    for(int i = 0; i < grafo->maxNumVertices; i++){
        if(strcmp(grafo->rotuloVertices[i],rotuloVertice)==0){
           return i;
        }
    }
    return -1;
}

}

/**
 * Se o grafo for ponderado, usamos a variavel peso para especificar o peso da aresta.
 * Se o grafo for não ponderado, passaremos o valor 1 para a variavel peso, de modo que represente existência da aresta.
 * Se um dos rotulos dos vertices nao existir, simplesmente nao faremos nada.
 **/
void inserirAresta(struct GrafoMatrizAdj* grafo, char* rotuloVOrigem, char* rotuloVDestino, int peso) {
  insereConexao(grafo, rotuloVOrigem, rotuloVDestino, peso);
}

/**
 * Usamos a variavel grafo->verticesInseridos para controlar a quantidade de vertices que ja foi inserido no grafo.
 * Logo, ela pode/deve ser usada para especificar em qual posicao o vertice a ser inserido sera alocado.
 **/
void inserirVertice(struct GrafoMatrizAdj* grafo, char* rotuloVertice) {
  grafo->arestas[rotuloVertice+1][rotuloVertice+1] = 0;
  grafo->v = v+1;
}

/**
 * Tomar cuidado com as diferenças semânticas entre haver conexão entre dois vertices em um grafo ponderado,
 * e haver conexão entre dois vertices em um grafo nao-ponderado.
 **/
bool saoConectados(struct GrafoMatrizAdj* grafo, char* rotuloVOrigem, char* rotuloVDestino) {
///klyfton você faz esse
}