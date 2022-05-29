#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

int min(int a, int b, int c){
    int m;
    if(a <= b){
        if(a <= c){
            m = a;
            return m;
        }else{
            m = c;
            return m;
        }
    }else{
        if(b <= c){
            m = b;
            return m;
        }else{
            m = c;
            return m;
        }
    }
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

void carv(pixel** p, int maxx, int maxy)(
    int i, j, jmin;
    int menor = p[0][0].e;
    for(j = 1; j < maxx; j++){
        if(menor > p[0][j].e){
            menor = p[0][j].e;
            jmin = j;
        }
    }
    for(i = 0; i < maxy-1; i++){
        printf("%d ", p[0][jmin].e);
        if(jmin == 0){
            if(p[i+1][jmin].e >= p[i+1][jmin + 1].e){
                jmin++;
            }
        }
        if(jmin == maxx-1){
            if(p[i+1][jmin].e >= p[i+1][jmin - 1].e){
                jmin--;
            }
        }
        if(jmin > 0 && jmin < maxx-1){
            menor = p[i+1][jmin-1];
            for(j = jmin; j <= jmin+1; j++){
                if(menor > p[i+1][j].e){
                    menor = p[i+1][j].e;
                    jmin = j;
                }
            }
        }
    }
)

int main(){
    FILE *in = fopen("in.ppm", "r");
    int i, j, k, x, y;
    long int cont = 1;
    char p3[3];
    fgets(p3, 3, in);
    printf("%s\n", p3);
    fscanf(in, "%d", &x);
    fscanf(in, "%d", &y);
    pixel** img = (pixel**)malloc(y*sizeof(pixel*));
    for(i = 0; i < y; i++){
        img[i] = (pixel*)malloc(x*sizeof(pixel));
    }
    pixel** tran = (pixel**)malloc(x*sizeof(pixel*));
    for(i = 0; i < x; i++){
        tran[i] = (pixel*)malloc(y*sizeof(pixel));
    }

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

    energia(img, x, y);
    for(i = 0; i < x; i++){
        for(j = 0; j < y; j++){
            tran[i][j] = img[j][i];
        }
    }

    for(i = 0; i < y; i++){
        for(j = 0; j < x; j++){
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
            cont++;
        }
        printf("\n");
    }

    for(i = 0; i < y; i++){
        for(j = 0; j < x; j++){
            printf("%d ", img[i][j].i);
        }
        printf("\n");
    }

    for(i = 0; i < y; i++){
        for(j = 0; j < x; j++){
            printf("%d ", img[i][j].e);
        }
        printf("\n");
    }

    seam(img, x, y);

    for(i = 0; i < y; i++){
        for(j = 0; j < x; j++){
            printf("%d ", img[i][j].e);
        }
        printf("\n");
    }


    for(i = 0; i < y; i++){
        free(img[i]);
    }
    free(img);
    for(i = 0; i < x; i++){
        free(tran[i]);
    }
    free(tran);
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