#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define N 1000

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

int main(void) {
    int i;
    int j;
    int k = 0;
    int l_row[N];
    int r_row[N];
    int distancia = 0;


    char lines[20];
    FILE *file = fopen("input1_2024.txt", "r");
        while(fgets(lines, sizeof(lines), file)) {
            sscanf(lines, "%d  %d", &i, &j);
            l_row[k] = i;
            r_row[k] = j;
            k++;
        }
        fclose(file);

    qsort(l_row, N, sizeof(int), compare);
    qsort(r_row, N, sizeof(int), compare);

    for(int l = 0; l < N; l++) {
        distancia += modulo(l_row[l], r_row[l]);
    }
        printf("distancia = %d\n", distancia);
 
return 0;
}
