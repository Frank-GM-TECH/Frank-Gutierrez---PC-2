/*2.Desarrollar un programa en C++ que gestione los datos de empleados,
diferenciando entre empleados contratados y nombrados. El programa debe
solicitar al usuario el nombre, tipo de empleado (C-contratado o N-nombrado) y
sueldo básico de cada empleado, calcular sus deducciones de AFP (8%) y seguro
(5%) del sueldo, aplicar una bonificación según el tipo de empleado (C=8% O
N= 12% al sueldo básico), y determinar el sueldo neto. Finalmente, debe mostrar
los detalles de cada empleado y proporcionar un resumen consolidado de la
cantidad de empleados y el total acumulado de sueldos netos para ambos tipos
de empleados.*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Empleado {
    string nombre;
    char tipo; // 'C' para contratado, 'N' para nombrado
    double sueldoBasico;
    double reduccionAFP;
    double reduccionSeguro;
    double bonificacion;
    double sueldoNeto;
};

void calcularDetallesEmpleado(Empleado &empleado) {
    // Calcular reducciones
    empleado.reduccionAFP = empleado.sueldoBasico * 0.08;
    empleado.reduccionSeguro = empleado.sueldoBasico * 0.05;

    // Calcular bonificación
    if (empleado.tipo == 'C') {
        empleado.bonificacion = empleado.sueldoBasico * 0.08;
    } else if (empleado.tipo == 'N') {
        empleado.bonificacion = empleado.sueldoBasico * 0.12;
    }

    // Calcular sueldo neto
    empleado.sueldoNeto = empleado.sueldoBasico - empleado.reduccionAFP - empleado.reduccionSeguro + empleado.bonificacion;
}

void mostrarDetallesEmpleado(const Empleado &empleado) {
    cout << "\nNombre: " << empleado.nombre << endl;
    cout << "Tipo de empleado: " << (empleado.tipo == 'C' ? "Contratado" : "Nombrado") << endl;
    cout << "Sueldo basico: " << empleado.sueldoBasico << endl;
    cout << "Reduccion AFP: " << empleado.reduccionAFP << endl;
    cout << "Reduccion seguro: " << empleado.reduccionSeguro << endl;
    cout << "Bonificacion: " << empleado.bonificacion << endl;
    cout << "Sueldo neto: " << empleado.sueldoNeto << endl;
}

int main() {
    vector<Empleado> empleados;
    int cantidadEmpleados;
    cout << "Ingrese la cantidad de empleados: ";
    cin >> cantidadEmpleados;

    for (int i = 0; i < cantidadEmpleados; ++i) {
        Empleado empleado;
        cout << "\nIngrese el nombre del empleado: ";
        cin >> empleado.nombre;
        cout << "Ingrese el tipo de empleado (C para contratado, N para nombrado): ";
        cin >> empleado.tipo;
        cout << "Ingrese el sueldo basico del empleado: ";
        cin >> empleado.sueldoBasico;

        calcularDetallesEmpleado(empleado);
        empleados.push_back(empleado);
    }

    int cantidadContratados = 0, cantidadNombrados = 0;
    double totalSueldosContratados = 0, totalSueldosNombrados = 0;

    for (size_t i = 0; i < empleados.size(); ++i) {
        mostrarDetallesEmpleado(empleados[i]);
        if (empleados[i].tipo == 'C') {
            cantidadContratados++;
            totalSueldosContratados += empleados[i].sueldoNeto;
        } else if (empleados[i].tipo == 'N') {
            cantidadNombrados++;
            totalSueldosNombrados += empleados[i].sueldoNeto;
        }
    }

    cout << "\nResumen consolidado:" << endl;
    cout << "Cantidad de empleados contratados: " << cantidadContratados << endl;
    cout << "Total sueldos netos empleados contratados: " << totalSueldosContratados << endl;
    cout << "Cantidad de empleados nombrados: " << cantidadNombrados << endl;
    cout << "Total sueldos netos empleados nombrados: " << totalSueldosNombrados << endl;

    return 0;
}
