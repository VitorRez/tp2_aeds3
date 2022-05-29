#include <stdio.h>
#include <stdlib.h>

int main(){
    int x, y, i, j, cont, fora;
    scanf("%d %d", &x, &y);
    int** v = (int**)malloc(x*sizeof(int*));
    for(i = 0; i < x; i++){
        v[i] = (int*)malloc(y*sizeof(int));
    }
    cont = 0;
    for(i = 0; i < x; i++){
        for(j = 0; j < y; j++){
            v[i][j] = cont;
            cont++;
        }
    }
    for(i = 0; i < x; i++){
        for(j = 0; j < y; j++){
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
    int** nova = (int**)malloc(x*sizeof(int*));
    for(i = 0; i < x; i++){
        nova[i] = (int*)malloc((y-1)*sizeof(int));
    }
    for(i = 0; i < x; i++){
        scanf("%d", &fora);
        for(j = 0; j < fora; j++){
            nova[i][j] = v[i][j];
        }
        for(j = fora; j < y-1; j++){
            nova[i][j] = v[i][j+1];
        }
    }
    printf("cu\n");
    for(i = 0; i < x; i++){
        free(v[i]);
    }
    y--;
    for(i = 0; i < x; i++){
        for(j = 0; j < y; j++){
            printf("%d ", nova[i][j]);
        }
        printf("\n");
    }
    for(i = 0; i < x; i++){
        free(nova[i]);
    }
    free(v);
}