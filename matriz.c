#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

pixel** cria_matriz(int x, int y){
    int i;
    pixel** img = (pixel**)malloc(y*sizeof(pixel*));
    for(i = 0; i < y; i++){
        img[i] = (pixel*)malloc(x*sizeof(pixel*));
    }
    return img;
}

pixel** cria_transposta(pixel** img, int x, int y){
    if(img[0][0] == NULL) return NULL;
    int i, j;
    pixel** trans = (pixel**)malloc(x*sizeof(pixel*));
    for(i = 0; i < x; i++){
        trans[i] = (pixel*)malloc(y*sizeof(pixel));
    }
    for(i = 0; i < x; i++){
        for(j = 0; j < y; j++){
            trans[i][j] = img[j][i];
        }
    }
    return trans;
}

void remove(pixel** p, pixel** nova, int x, int y, int fora){
    int j;
    for(j = 0; j < fora; j++){
        nova[y][j] = p[y][j];
    }
    for(j = fora; j < x-1; j++){
        nova[y][j] = p[y][j+1];
    }
}

void preenche_matriz(pixel** img, FILE* in, int x, int y){
    int i, j, k;
    for(i = 0; i < y; i++){
        for(j = 0; j < x; j++){
            for(k = 0; k < 3; k++){
                switch(k){
                    case 0:
                        fscanf(in, "%d", &img[i][j].R);
                        break;
                    case 1:
                        fscanf(in, "%d", &img[i][j].G);
                        break;
                    case 2:
                        fscanf(in, "%d", &img[i][j].B);
                }
            }
            img[i][j].i = 0.3*img[i][j].R + 0.59*img[i][j].G + 0.11*img[i][j].B;
        }
    }
}

int energiax(pixel **p, int x, int y, int maxx, int maxy){
    int e;
    if(x == 0 && y == 0){
        e = p[x][y].i*(-1) + p[x+1][y].i*1 + p[x][y].i*(-2) + p[x+1][y].i*2 + p[x][y+1].i*(-1) + p[x+1][y+1].i*1;
        return e;
    }
    if(x == 0 && y == maxy){
        e = p[x][y-1].i*(-1) + p[x+1][y-1].i*1 + p[x][y].i*(-2) + p[x+1][y].i*2 + p[x][y].i*(-1) + p[x+1][y].i*1;
        return e; 
    }
    if(x == maxx && y == 0){
        e = p[x-1][y].i*(-1) + p[x][y].i*1 + p[x-1][y].i*(-2) + p[x][y].i*2 + p[x-1][y+1].i*(-1) + p[x][y+1].i*1;
        return e;
    }
    if(x == maxx && y == maxy){
        e = p[x-1][y-1].i*(-1) + p[x][y-1].i*1 + p[x-1][y].i*(-2) + p[x][y].i*2 + p[x-1][y].i*(-1) + p[x][y].i*1;
        return e;
    }
    if(x == 0){
        e = p[x][y-1].i*(-1) + p[x+1][y-1].i*1 + p[x][y].i*(-2) + p[x+1][y].i*2 + p[x][y+1].i*(-1) + p[x][y+1].i*1;
        return e;
    }
    if(x == maxx){
        e = p[x-1][y-1].i*(-1) + p[x][y-1].i*1 + p[x-1][y].i*(-2) + p[x][y].i*2 + p[x-1][y+1].i*(-1) + p[x][y+1].i*1;
        return e; 
    }
    if(y == 0){
        e = p[x-1][y].i*(-1) + p[x+1][y].i*1 + p[x-1][y].i*(-2) + p[x+1][y].i*2 + p[x-1][y+1].i*(-1) + p[x+1][y+1].i*1;
        return e;
    }
    if(y == maxy){
        e = p[x-1][y].i*(-1) + p[x+1][y].i*1 + p[x-1][y].i*(-2) + p[x+1][y].i*2 + p[x-1][y+1].i*(-1) + p[x+1][y+1].i*1;
        return e;
    }
    e = p[x-1][y-1].i*(-1) + p[x+1][y-1].i*1 + p[x-1][y].i*(-2) + p[x+1][y].i*2 + p[x-1][y+1].i*(-1) + p[x+1][y+1].i*1;
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
    if(x == 0){
        e = p[x][y-1].i*(-1) + p[x][y+1].i*1 + p[x][y-1].i*(-2) + p[x][y+1].i*2 + p[x+1][y-1].i*(-1) + p[x+1][y+1].i*1;
        return e;
    }
    if(x == maxx){
        e = p[x-1][y-1].i*(-1) + p[x-1][y+1].i*1 + p[x][y-1].i*(-2) + p[x][y+1].i*2 + p[x][y-1].i*(-1) + p[x][y+1].i*1;
        return e;
    }
    if(y == 0){
        e = p[x-1][y].i*(-1) + p[x-1][y+1].i*1 + p[x][y].i*(-2) + p[x][y+1].i*2 + p[x+1][y].i*(-1) + p[x+1][y+1].i*1;
        return e;
    }
    if(y == maxy){
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

int menor(pixel** p, int i, int j){
    int menor = p[i][j-1].e
    int jmin = j-1;
    for(int k = j; k <= j-1; k++){
        if(p[i][k] < menor){
            menor = p[i][k];
            jmin = k;
        }
    }
    return jmin;
}

void seam(pixel** p, int maxx, int maxy){
    int i, j;
    for(i = maxy-2; i >= 0; i--){
        for(j = 0; j < maxx; j++){
            if(j == 0){
                p[i][j].e = p[i][j].e + min(p[i+1][j].e, p[i+1][j+1].e, p[i+1][j+1].e);
            }
            if(j == maxx-1){
                p[i][j].e = p[i][j].e + min(p[i+1][j-1].e, p[i+1][j].e, p[i+1][j].e);
            }
            if(j > 0 && j < maxx-1){
                p[i][j].e = p[i][j].e + min(p[i+1][j-1].e, p[i+1][j].e, p[i+1][j+1].e);
            }
        }
    }
}

void carv(pixel** p, int maxx, int maxy){
    int i, j, jmin;
    int menor = p[0][0].e;
    jmin = 0;
    for(j = 1; j < maxx; j++){
        if(p[0][j].e < menor){
            menor = p[0][j].e;
            jmin = j;
        }
    }
    for(i = 0; i < maxy-1; i++){
        j = jmin;
        if(jmin == 0){
            if(p[i+1][jmin].e < p[i+1][jmin + 1].e) jmin++;
        }
        if(jmin == maxx-1){
            if(p[i+1][jmin - 1].e < p[i+1][jmin].e) jmin--;
        }
        if(jmin > 0 && < maxx-1){
            jmin = menor(img, i+1, jmin);
        }
        //retira p[i][j]
    }
}