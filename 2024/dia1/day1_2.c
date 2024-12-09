#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define N 6

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int modulo(int a, int b) {
    int x = a - b;
        if(x < 0) {
            return -x;
        }
    return x;
}

int puntaje(int* arr1, int* arr2, int tam) {
    int puntaje = 0;
    for (int i = 0; i < tam; i++) {
        int ocurrencias = 0;
        for (int j = 0; j < tam; j++) {
            if (arr1[i] == arr2[j]) {
                ocurrencias++;
            }
        }
        puntaje += arr1[i] * ocurrencias;
    }
    printf("puntaje = %d\n", puntaje);
    return puntaje;
}

int main(void) {
    int i;
    int j;
    int k = 0;
    int col_izq[N];
    int col_der[N];
    int distancia = 0;


    char lines[20];
    FILE *file = fopen("example.txt", "r");
        while(fgets(lines, sizeof(lines), file)) {
            sscanf(lines, "%d  %d", &i, &j);
            col_izq[k] = i;
            col_der[k] = j;
            k++;
        }
        fclose(file);

    qsort(col_izq, N, sizeof(int), compare);
    qsort(col_der, N, sizeof(int), compare);

    for(int l = 0; l < N; l++) {
        distancia += modulo(col_izq[l], col_der[l]);
    }
    printf("distancia = %d\n", distancia);

    puntaje(col_izq, col_der, N);
 
return 0;
}
