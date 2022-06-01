typedef struct pixel{
    int R;
    int G;
    int B;
    int i;
    int e;
    int n;
} pixel;

pixel** criar_matriz(int, int);
pixel** criar_trans(pixel**, int, int);
void preenche_matriz(pixel**, int, int, int*);
void remover(pixel**, int, int, int);
int energiax(pixel**, int, int, int, int);
int energiay(pixel**, int, int, int, int);
void energia(pixel**, int, int);
int menor(pixel**, int, int, int);
void seam(pixel**, int, int);
void carv(pixel**, int, int);
void imprime(pixel**, int, int);
void destroi(pixel**, int);
int* learquivo();
