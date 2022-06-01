#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "matriz.h"

int* learquivo(){
    FILE* in = fopen("in.ppm", "r");
    int cont, x, y, inutil, i;
    int* v;
    char linha[2000];
    char *token;
    cont = 0;
    fscanf(in, "%*[^\n]\n");
    while(cont <= 2){
        fgets(linha, 2000, in);
        if(linha[0] != '#'){
            token = strtok(linha, " ");
            while(token != NULL){
                if(cont == 0) x = atoi(token);
                if(cont == 1) y = atoi(token);
                if(cont == 2) inutil = atoi(token);
                cont++;
                token = strtok(NULL, " ");
            }
        }
    }
    v = (int*)malloc(((3*x*y)+2)*sizeof(int));
    i = 2;
    v[0] = x;
    v[1] = y;
    while(i < 3*x*y){
        fgets(linha, 2000, in);
        if(linha[0] != '#'){
            token = strtok(linha, " ");
            while(token != NULL){
                v[i] = atoi(token);
                i++;
                token = strtok(NULL, " ");
            }
        }
    }
    return v;
}

pixel** criar_matriz(int x, int y){
    int i;
    pixel** p = (pixel**)malloc(y*sizeof(pixel*));
    for(i = 0; i < y; i++){
        p[i] = (pixel*)malloc(x*sizeof(pixel));
    }
    return p;
}

pixel** criar_trans(pixel** p, int x, int y){
    int i, j;
    pixel** trans = criar_matriz(y, x);
    for(i = 0; i < x; i++){
        for(j = 0; j < y; j++){
            trans[i][j] = p[j][i];
        }
    }
    return trans;
}

void preenche_matriz(pixel** p, int x, int y, int* v){
    int i, j, k, cont; 
    cont = 2;
    for(i = 0; i < y; i++){
        for(j = 0; j < x; j++){
            for(k = 0; k < 3; k++){
                switch(k){
                    case 0:
                        p[i][j].R = v[cont];
                        cont++;
                        break;
                    case 1:
                        p[i][j].G = v[cont];
                        cont++;
                        break;
                    case 2:
                        p[i][j].B = v[cont];
                        cont++;
                }
            }
            p[i][j].i = 0.3*p[i][j].R + 0.59*p[i][j].G + 0.11*p[i][j].B;
        }
    }
}

void remover(pixel** p, int x, int y, int fora){
    int j;
    for(j = fora; j < x-1; j++){
        p[y][j] = p[y][j+1];
    }
    p[y][x-1].e = (-1);
}

int energiax(pixel **p, int x, int y, int maxx, int maxy){
    int e;
    if(x == 0 && y == 0){
        e = p[x][y].i*(-1) + p[x][y].i*(-2) + p[x][y+1].i*(-1) + p[x+1][y].i + p[x+1][y].i*2 + p[x+1][y+1].i;
        return e;
    }
    if(x == 0 && y == maxy){
        e = p[x][y-1].i*(-1) + p[x][y].i*(-2) + p[x][y].i*(-1) + p[x+1][y-1].i + p[x+1][y].i*2 + p[x+1][y].i;
        return e; 
    }
    if(x == maxx && y == 0){
        e = p[x-1][y].i*(-1) + p[x][y].i + p[x-1][y].i*(-2) + p[x][y].i*2 + p[x-1][y+1].i*(-1) + p[x][y+1].i;
        return e;
    }
    if(x == maxx && y == maxy){
        e = p[x-1][y-1].i*(-1) + p[x][y-1].i + p[x-1][y].i*(-2) + p[x][y].i*2 + p[x-1][y].i*(-1) + p[x][y].i;
        return e;
    }
    if(x == 0 && y > 0 && y < maxy){
        e = p[x][y-1].i*(-1) + p[x+1][y-1].i + p[x][y].i*(-2) + p[x+1][y].i*2 + p[x][y+1].i*(-1) + p[x+1][y+1].i;
        return e;
    }
    if(x == maxx && y > 0 && y < maxy){
        e = p[x-1][y-1].i*(-1) + p[x][y-1].i + p[x-1][y].i*(-2) + p[x][y].i*2 + p[x-1][y+1].i*(-1) + p[x][y+1].i;
        return e; 
    }
    if(y == 0 && x > 0 && x < maxx){
        e = p[x-1][y].i*(-1) + p[x+1][y].i + p[x-1][y].i*(-2) + p[x+1][y].i*2 + p[x-1][y+1].i*(-1) + p[x+1][y+1].i;
        return e;
    }
    if(y == maxy && x > 0 && x < maxx){
        e = p[x-1][y-1].i*(-1) + p[x+1][y-1].i + p[x-1][y].i*(-2) + p[x+1][y].i*2 + p[x-1][y].i*(-1) + p[x+1][y].i;
        return e;
    }
    e = p[x-1][y-1].i*(-1) + p[x+1][y-1].i + p[x-1][y].i*(-2) + p[x+1][y].i*2 + p[x-1][y+1].i*(-1) + p[x+1][y+1].i;
    return e;
}

int energiay(pixel **p, int x, int y, int maxx, int maxy){
    int e;
    if(x == 0 && y == 0){
        e = p[x][y].i*(-1) + p[x][y+1].i*1 + p[x][y].i*(-2) + p[x][y+1].i*2 + p[x+1][y].i*(-1) + p[x+1][y+1].i*1;
        return e;
    }
    if(x == 0 && y == maxy){
        e = p[x][y-1].i*(-1) + p[x][y].i*1 + p[x][y-1].i*(-2) + p[x][y].i*2 + p[x+1][y-1].i*(-1) + p[x+1][y].i*1;
        return e;
    }
    if(x == maxx && y == 0){
        e = p[x-1][y].i*(-1) + p[x-1][y+1].i*1 + p[x][y].i*(-2) + p[x][y+1].i*2 + p[x][y].i*(-1) + p[x][y+1].i*1;
        return e;
    }
    if(x == maxx && y == maxy){
        e = p[x-1][y-1].i*(-1) + p[x-1][y].i*1 + p[x][y-1].i*(-2) + p[x][y].i*2 + p[x][y-1].i*(-1) + p[x][y].i*1;
        return e;
    }
    if(x == 0 && y > 0 && y < maxy){
        e = p[x][y-1].i*(-1) + p[x][y+1].i*1 + p[x][y-1].i*(-2) + p[x][y+1].i*2 + p[x+1][y-1].i*(-1) + p[x+1][y+1].i*1;
        return e;
    }
    if(x == maxx && y > 0 && y < maxy){
        e = p[x-1][y-1].i*(-1) + p[x-1][y+1].i*1 + p[x][y-1].i*(-2) + p[x][y+1].i*2 + p[x][y-1].i*(-1) + p[x][y+1].i*1;
        return e;
    }
    if(y == 0 && x > 0 && x < maxx){
        e = p[x-1][y].i*(-1) + p[x-1][y+1].i*1 + p[x][y].i*(-2) + p[x][y+1].i*2 + p[x+1][y].i*(-1) + p[x+1][y+1].i*1;
        return e;
    }
    if(y == maxy && x > 0 && x < maxx){
        e = p[x-1][y-1].i*(-1) + p[x-1][y].i*1 + p[x][y-1].i*(-2) + p[x][y].i*2 + p[x+1][y-1].i*(-1) + p[x+1][y].i*1;
        return e;
    }
    e = p[x-1][y-1].i*(-1) + p[x-1][y+1].i*1 + p[x][y-1].i*(-2) + p[x][y+1].i*2 + p[x+1][y-1].i*(-1) + p[x+1][y+1].i*1;
    return e;
}

void energia(pixel** p, int maxx, int maxy){
    int i, j, ex, ey, e;
    for(i = 0; i < maxy; i++){
        for(j = 0; j < maxx; j++){
            ex = energiax(p, j, i, maxx-1, maxy-1);
            ey = energiay(p, j, i, maxx-1, maxy-1);
            e = (ex*ex + ey*ey);
            p[i][j].e = sqrt(e);
        }
    }
}

int menor(pixel** p, int i, int j, int maxx){
    int jmin;
    if(j == 0){
        if(p[i][j].e < p[i][j+1].e){
            jmin = j;
            return jmin;
        }else{
            jmin = j+1;
            return jmin;
        }
    }
    if(j == maxx-1){
        if(p[i][j].e < p[i][j-1].e){
            jmin = j;
            return jmin;
        }else{
            jmin = j-1;
            return jmin;
        }
    }
    int m = p[i][j-1].e;
    jmin = j-1;
    for(int k = j; k <= j+1; k++){
        if(p[i][k].e < m){
            m = p[i][k].e;
            jmin = k;
        }
    }
    return jmin;
}

void seam(pixel** p, int maxx, int maxy){
    int i, j, m;
    for(i = maxy-2; i >= 0; i--){
        for(j = 0; j < maxx; j++){
            m = menor(p, i+1, j, maxx);
            p[i][j].e = p[i][j].e + p[i+1][m].e;
        }
    }
}

void carv(pixel** p, int maxx, int maxy){
    int i, j, jmin;
    int min = p[0][0].e;
    jmin = 0;
    for(j = 1; j < maxx; j++){
        if(p[0][j].e < min){
            min = p[0][j].e;
            jmin = j;
        }
    }
    for(i = 0; i < maxy; i++){
        j = jmin;
        if(i < maxy-1) jmin = menor(p, i+1, jmin, maxx);
        remover(p, maxx, i, j);
    }
}

void imprime(pixel** img, int maxx, int maxy){
    int i, j, k;
    for(i = 0; i < maxy; i++){
        for(j = 0; j < maxx; j++){
            if(img[i][j].e == -1) break;
            for(k = 0; k < 3; k++){
                switch(k ){
                    case 0:
                        printf("%d ", img[i][j].R);
                        break;
                    case 1:
                        printf("%d ", img[i][j].G);
                        break;
                    case 2:
                        printf("%d ", img[i][j].B);
                        break;
                }
            }
        }
        printf("\n");
    }
}

void destroi(pixel** p, int y){
    int i;
    for(i = 0; i < y; i++){
        free(p[i]);
    }
    free(p);
}