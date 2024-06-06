/*1.Hacer un programa que alimente solo con números entre 1 y 10 dos matrices una
de 2 x 3 y la otra de 3 x 2, buscar aquellos números de la primera matriz que sean
mayores a 5 y convertirlos a 1, y buscar aquellos números que sean menores a 6
de la segunda matriz y convertirlos a 0. (imprimir la primera matriz y la
modificada)*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void imprimirMatriz(int matriz[][3], int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void imprimirMatriz(int matriz[][2], int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    srand(time(0));

    int matriz1[2][3];
    int matriz2[3][2];

    // Alimentar matrices con números aleatorios entre 1 y 10
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            matriz1[i][j] = rand() % 10 + 1;
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            matriz2[i][j] = rand() % 10 + 1;
        }
    }

    // Imprimir matrices originales
    cout << "Matriz 1 original:" << endl;
    imprimirMatriz(matriz1, 2, 3);

    cout << "Matriz 2 original:" << endl;
    imprimirMatriz(matriz2, 3, 2);

    // Modificar matriz1: números mayores a 5 se convierten en 1
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (matriz1[i][j] > 5) {
                matriz1[i][j] = 1;
            }
        }
    }

    // Modificar matriz2: números menores a 6 se convierten en 0
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (matriz2[i][j] < 6) {
                matriz2[i][j] = 0;
            }
        }
    }

    // Imprimir matrices modificadas
    cout << "Matriz 1 modificada:" << endl;
    imprimirMatriz(matriz1, 2, 3);

    cout << "Matriz 2 modificada:" << endl;
    imprimirMatriz(matriz2, 3, 2);

    return 0;
}
