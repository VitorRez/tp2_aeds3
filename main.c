#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "matriz.h"

int main(){
    int x, y, i, j;
    int* v = learquivo();
    x = v[0];
    y = v[1];
    pixel** img = criar_matriz(x, y);
    preenche_matriz(img, x, y, v);
    imprime(img, x, y);
    pixel** trans = criar_trans(img, x, y);
    imprime(trans, y, x);
    energia(img, x, y);
    seam(img, x, y);
    carv(img, x, y);
    imprime(img, x, y);
    destroi(img, y);
    destroi(trans, x);
}