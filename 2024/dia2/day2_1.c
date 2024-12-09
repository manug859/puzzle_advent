#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 1000
#define MAX_NUMS 100

bool descenso(int a[], int tam) {
    bool res = true;
    for(int i = 0; i < tam - 1; i++) {
        res = res && (a[i] > a[i+1]);
    }
    return res;
}

bool ascenso(int a[], int tam) {
    bool res = true;
    for(int i = 0; i < tam - 1; i++) {
        res = res && (a[i] < a[i+1]);
    }
    return res;
}

bool diff(int a[], int tam) {
    bool res = true;
    for(int i = 0; i < tam - 1; i++) {
        res = res && (1 <= abs(a[i] - a[i+1]) && abs(a[i] - a[i+1]) <= 3);
    }
    return res;
}

bool es_segura(int a[], int tam) {
    bool res;
    return res = diff(a, tam) && (ascenso(a, tam) || descenso(a, tam));
}

int main(void) {
    char lines[N];
    int arrays[N][MAX_NUMS];  // Almacena hasta 30 líneas, cada una con hasta MAX_NUMS números
    int sizes[20];            // Almacena el tamaño de cada arreglo
    int lineCount = 0;

    FILE *file = fopen("test_day2.txt", "r");
    if (!file) {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Leer cada línea del archivo
    while (fgets(lines, sizeof(lines), file) && lineCount < N) {
        int numCount = 0;
        char *token = strtok(lines, " ");
        
        // Procesar cada número de la línea
        while (token && numCount < MAX_NUMS) {
            arrays[lineCount][numCount] = atoi(token);  // Convertir token a entero
            numCount++;
            token = strtok(NULL, " ");
        }
        
        sizes[lineCount] = numCount;  // Guardar el tamaño del array
        lineCount++;
    }
    fclose(file);
    
    int seguras = 0;
    for (int i = 0; i < lineCount; i++) {
        if (es_segura(arrays[i], sizes[i])) {
            seguras++;
        }
    }
    printf("Arreglos seguros: %d\n", seguras);
    return 0;
}
