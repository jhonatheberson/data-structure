#ifndef GRAFOMATADJEXERCICIO_H
#define GRAFOMATADJEXERCICIO_H

typedef struct GrafoMatrizAdj {
    int** arestas;
    char** rotuloVertices;
    int verticesInseridos;
    int maxNumVertices;
} Grafo;


//Aloca a matriz de adjacencias
static int **iniciaMatriz( int r, int c, int val);
// //Inicia um grafo com numero de vertices V
Grafo* iniciaGrafo(int maxNumVertices, bool ponderado);


// void insereConexao(Grafo *G, char* rotuloVOrigem, char* rotuloVDestino, char peso);


void printGrafo(Grafo *G);




/**
 * Se o grafo for ponderado, inicializamos cada posicao da matriz com INT_MAX.
 * Se o grafo for não ponderado, inicializamos cada posicao da matriz com 0.
 **/
struct GrafoMatrizAdj* inicializar(int numVertices, bool ponderado);



/**
 * A principio nao temos nenhuma ordenacao usando os rotulos.
 * Portanto, usaremos busca linear
 **/
int obterIndiceVertice(struct GrafoMatrizAdj* grafo, char* rotuloVertice);


/**
 * Se o grafo for ponderado, usamos a variavel peso para especificar o peso da aresta.
 * Se o grafo for não ponderado, passaremos o valor 1 para a variavel peso, de modo que represente existência da aresta.
 * Se um dos rotulos dos vertices nao existir, simplesmente nao faremos nada.
 **/
void inserirAresta(struct GrafoMatrizAdj* grafo, char* rotuloVOrigem, char* rotuloVDestino, int peso);

/**
 * Usamos a variavel grafo->verticesInseridos para controlar a quantidade de vertices que ja foi inserido no grafo.
 * Logo, ela pode/deve ser usada para especificar em qual posicao o vertice a ser inserido sera alocado.
 **/

void inserirVertice(struct GrafoMatrizAdj* grafo, char* rotuloVertice);

/**
 * Tomar cuidado com as diferenças semânticas entre haver conexão entre dois vertices em um grafo ponderado,
 * e haver conexão entre dois vertices em um grafo nao-ponderado.
 **/
bool saoConectados(struct GrafoMatrizAdj* grafo, char* rotuloVOrigem, char* rotuloVDestino);

#endif /* GRAFOMATADJEXERCICIO_H */