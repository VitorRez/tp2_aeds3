#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pixel{
    int R;
    int G;
    int B;
    int i;
    int e;
} pixel;

int energiax(pixel **p, int x, int y, int maxx, int maxy){
    int e;
    if(x == 0 && y == 0){
        e = p[x][y].i*(-1) + p[x+1][y].i*(-1) + p[x][y].i*(-2) + p[x+1][y].i*2 + p[x][y+1].i*(-1) + p[x+1][y+1]*1;
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
        e = p[x-1][y].i*(-1) + p[x+1][y]*1 + p[x-1][y].i*(-2) + p[x+1][y]*2 + p[x-1][y+1]*(-1) + p[x+1][y+1]*1;
        return e;
    }
    if(y == maxy){
        e = p[x-1][y].i*(-1) + p[x+1][y]*1 + p[x-1][y].i*(-2) + p[x+1][y]*2 + p[x-1][y+1]*(-1) + p[x+1][y+1]*1;
        return e;
    }
    e = p[x-1][y-1].i*(-1) + p[x+1][y-1].i*1 + p[x-1][y].i*(-2) + p[x+1][y]*2 + p[x-1][y+1]*(-1) + p[x+1][y+1]*1;
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

void energia(pixel** p, int x, int y, int maxx, int maxy){
    int i, j, ex, ey;
    for(i = 0; i < maxx; i++){
        for(j = 0; j < maxy; j++){
            ex = energiax(p, i, j, maxx, maxy);
            ey = energiay(p, i, j, maxx, maxy);
            //p[i][j].e = sqrt(ex*ex + ey*ey);
        }
    }
}

int main(){
    FILE *in = fopen("in.PPM", "r");
    int i, j, k, x, y;
    char p3[3];
    fgets(p3, 3, in);
    printf("%s\n", p3);
    fscanf(in, "%d", &x);
    fscanf(in, "%d", &y);
    pixel** img = (pixel**)malloc(x*sizeof(pixel*));
    for(i = 0; i < x; i++){
        img[i] = (pixel*)malloc(y*sizeof(pixel));
    }
    for(i = 0; i < x; i++){
        for(j = 0; j < y; j++){
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
    printf("%d %d\n", x, y);
    for(i = 0; i < x; i++){
        for(j = 0; j < y; j++){
            for(k = 0; k < 3; k++){
                switch(k){
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

/*int main(){
    char p3[2];
    char linha[1000];
    char *token;
    int i, j, k, l, m, n;
    int x[9];
    pixel img[3][3];
    FILE *in = fopen("in.PPM", "r");
    fgets(p3, 3, in);
    printf("%s", p3);
    i = 0;
    while(){
        fgets(linha, 1000, in);
        if(linha[0] != '#'){
            token = strtok(linha, " ");
            while(token){
                x[i] = atoi(token);
                token = strtok(NULL, " ");
            }
        }
    }
    n = x[0];
    m = x[1];
    l = 2;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            for(k = 0; k < 3; k++){
                if(k == 0) img[i][j].R = x[l];
                if(k == 1) img[i][j].G = x[l];
                if(k == 2) img[i][j].B = x[l];
                l++;
            }
        }
    }
}*/