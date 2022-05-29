typedef struct pixel{
    int R;
    int G;
    int B;
    int i;
    int e;
} pixel;

pixel** cria_matriz(int, int);
pixel** cria_transposta(pixel**, int, int);
void remove(pixel**, pixel**, int, int, int);
void preenche_matriz(pixel**, FILE*, int, int);
int energiax(pixel**, int, int, int, int);
int energiay(pixel**, int, int, int, int);
void energia(pixel**, int, int);
int menor(pixel**, int, int);
void seam(pixel**, int, int);
void carv(pixel**, int, int);
void destroi(pixel**, int);