//
// Created by jhonat e klyfton 
//

#include "grafomatadjexercicio.hpp"

#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>



struct GrafoMatrizAdj* inicializar(int numVertices, bool ponderado) {
    struct GrafoMatrizAdj* Mat_pond;
    Mat_pond = (struct GrafoMatrizAdj*) malloc(sizeof(struct GrafoMatrizAdj));
    Mat_pond->arestas = (int**) malloc(numVertices * sizeof(int*)); 
    Mat_pond->rotuloVertices = (char**) malloc(numVertices * (sizeof(char*))); 
    Mat_pond->verticesInseridos = 0;
    Mat_pond->maxNumVertices = numVertices;

    for (int i = 0; i < numVertices; i++) { 
        Mat_pond->rotuloVertices[i] = (char*) malloc(numVertices * (sizeof(char)));
        Mat_pond->arestas[i] = (int*) malloc(numVertices * sizeof(int));
    }

    if (ponderado==true) {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                Mat_pond->arestas[i][j] = INT_MAX;
            }
        }
    }
    else {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                Mat_pond->arestas[i][j] = 0;
            }
        }
    }

    return Mat_pond;
}
/**
 * A principio nao temos nenhuma ordenacao usando os rotulos.
 * Portanto, usaremos busca linear
 **/
int obterIndiceVertice(GrafoMatrizAdj *grafo, char *rotuloVertice) {
    

    for (int i = 0; i < grafo->maxNumVertices; i++) {
        if (grafo->rotuloVertices[i] == NULL)
            continue;
        if (strcmp(grafo->rotuloVertices[i], rotuloVertice) == 0)
            return i;
    }

    return -1;
}

/**
 * Usamos a variavel grafo->verticesInseridos para controlar a quantidade de vertices que ja foi inserido no grafo.
 * Logo, ela pode/deve ser usada para especificar em qual posicao o vertice a ser inserido sera alocado.
 **/
void inserirVertice(GrafoMatrizAdj *grafo, char *rotuloVertice) {
    if (rotuloVertice == NULL)
        return;

    grafo->rotuloVertices[grafo->verticesInseridos] = rotuloVertice;
    grafo->verticesInseridos++;

}

/**
 * Se o grafo for ponderado, usamos a variavel peso para especificar o peso da aresta.
 * Se o grafo for não ponderado, passaremos o valor 1 para a variavel peso, de modo que represente existência da aresta.
 * Se um dos rotulos dos vertices nao existir, simplesmente nao faremos nada.
 **/

void inserirAresta(GrafoMatrizAdj *grafo, char *rotuloVOrigem, char *rotuloVDestino, int peso) {

    if (rotuloVOrigem == NULL || rotuloVDestino == NULL)
        return;

    peso = grafo->ponderado ? 1 : peso;


    int origem = obterIndiceVertice(grafo, rotuloVOrigem);
    int destino  = obterIndiceVertice(grafo, rotuloVDestino);


    grafo->arestas[destino][origem] = peso;
    grafo->arestas[origem][destino] = peso;


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