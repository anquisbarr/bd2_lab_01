#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Matricula{
    string codigo;
    int ciclo;
    float mensualidad;
    string observaciones;

    void printData() {
        cout << "Codigo: " << codigo;
        cout << "\nCiclo: " << ciclo;
        cout << "\nMensualidad: " << mensualidad;
        cout << "\nObservaciones: " << observaciones << endl;
    }
};