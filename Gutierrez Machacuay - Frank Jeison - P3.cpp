/*3.Desarrollar un programa en C++ que permita ingresar y almacenar el código, el
nombre, nota 1, nota 2 y nota 3 de un curso. Mostrar el promedio de cada
estudiante y la cantidad de estudiantes desaprobados. Finalmente, ordene los datos
en base de los promedios. Muestre los datos ordenados.*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Estudiante {
    int codigo;
    string nombre;
    double nota1;
    double nota2;
    double nota3;
    double promedio;
};

void calcularPromedio(Estudiante &estudiante) {
    estudiante.promedio = (estudiante.nota1 + estudiante.nota2 + estudiante.nota3) / 3.0;
}

void mostrarEstudiante(const Estudiante &estudiante) {
    cout << "\nCodigo: " << estudiante.codigo << endl;
    cout << "Nombre: " << estudiante.nombre << endl;
    cout << "Nota 1: " << estudiante.nota1 << endl;
    cout << "Nota 2: " << estudiante.nota2 << endl;
    cout << "Nota 3: " << estudiante.nota3 << endl;
    cout << "Promedio: " << estudiante.promedio<< endl;
}

void ordenarPorPromedio(vector<Estudiante> &estudiantes) {
    for (size_t i = 0; i < estudiantes.size(); ++i) {
        for (size_t j = i + 1; j < estudiantes.size(); ++j) {
            if (estudiantes[i].promedio < estudiantes[j].promedio) {
                swap(estudiantes[i], estudiantes[j]);
            }
        }
    }
}

int main() {
    vector<Estudiante> estudiantes;
    int cantidadEstudiantes;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> cantidadEstudiantes;

    for (int i = 0; i < cantidadEstudiantes; ++i) {
        Estudiante estudiante;
        cout << "\nIngrese el codigo del estudiante: ";
        cin >> estudiante.codigo;
        cout << "Ingrese el nombre del estudiante: ";
        cin.ignore(); // Para ignorar el salto de línea pendiente
        getline(cin, estudiante.nombre);
        cout << "Ingrese la nota 1: ";
        cin >> estudiante.nota1;
        cout << "Ingrese la nota 2: ";
        cin >> estudiante.nota2;
        cout << "Ingrese la nota 3: ";
        cin >> estudiante.nota3;

        calcularPromedio(estudiante);
        estudiantes.push_back(estudiante);
    }

    int cantidadDesaprobados = 0;

    for (size_t i = 0; i < estudiantes.size(); ++i) {
        mostrarEstudiante(estudiantes[i]);
        if (estudiantes[i].promedio < 10.5) {
            cantidadDesaprobados++;
        }
    }

    cout << "\nCantidad de estudiantes desaprobados: " << cantidadDesaprobados << endl;

    // Ordenar los estudiantes por promedio de mayor a menor sin usar std::sort
    ordenarPorPromedio(estudiantes);

    cout << "\n\nEstudiantes ordenados por promedio:" << endl;
    for (size_t i = 0; i < estudiantes.size(); ++i) {
        mostrarEstudiante(estudiantes[i]);
    }

    return 0;
}

