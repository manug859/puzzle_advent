#include <stdio.h>
#include <string.h>

int piedra = 1;
int papel = 2;
int tijera = 3;

#define A piedra
#define X piedra
#define B papel
#define Y papel
#define C tijera
#define Z tijera

int partida (char mano_c, char mano_p) {
    int puntaje = 0;
    if (mano_c == 'A' && mano_p == 'X') {
        puntaje = 4;
    }
    else if (mano_c == 'A' && mano_p == 'Y') {
        puntaje = 8;
    }
    else if (mano_c == 'A' && mano_p == 'Z') {
        puntaje = 3;
    }


    else if (mano_c == 'B' && mano_p == 'X') {
        puntaje = 1;
    }
    else if (mano_c == 'B' && mano_p == 'Y') {
        puntaje = 5;
    }
    else if (mano_c == 'B' && mano_p == 'Z') {
        puntaje = 9;
    }


    else if (mano_c == 'C' && mano_p == 'X') {
        puntaje = 7;
    }
    else if (mano_c == 'C' && mano_p == 'Y') {
        puntaje = 2;
    }
    else if (mano_c == 'C' && mano_p == 'Z') {
        puntaje = 6;
    }
    return puntaje;
}

int main(void) {
     FILE *archivo = fopen("test2.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    int puntaje_final = 0;
    char linea[10]; // Buffer para leer cada línea (ajustar según longitud)
    while (fgets(linea, sizeof(linea), archivo)) {
        char dato1, dato2;
        sscanf(linea, "%c %c", &dato1, &dato2); // Leer los dos caracteres
        puntaje_final = partida(dato1, dato2) + puntaje_final;
    }
    fclose(archivo);
    printf("puntaje_final : %d ", puntaje_final);

   return 0;
}