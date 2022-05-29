#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int TipoValorVertice;
typedef int TipoPeso;

typedef struct TipoItem {
TipoValorVertice Vertice;
int r;
int g;
int b;
TipoPeso Peso;
} TipoItem;

typedef struct TipoCelula *TipoApontador;

struct TipoCelula {
    TipoItem Item;
    TipoApontador Prox;
} TipoCelula;

typedef struct TipoLista {
    TipoApontador Primeiro , Ultimo;
} TipoLista;

typedef struct TipoGrafo {
    TipoLista Adj[MAXNUMVERTICES + 1];
    TipoValorVertice NumVertices;
    short NumArestas;
} TipoGrafo;

grafo FazGVazio();
void InsereVertice();
void RemoveVertice();
void InsereAresta();
void RemoveAresta();



