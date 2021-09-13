#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct AlumnoP3{
    string Nombre;
    string Apellidos;
    string Carrera;
    float mensualidad;

    friend ostream& operator<<(ostream& os, const AlumnoP3& a3) {
        os  << endl << "Nombre: " << a3.Nombre
            << endl << "Apellidos: " << a3.Apellidos
            << endl << "Carrera: " << a3.Carrera
            << endl << "Mensualidad: " << a3.mensualidad << endl;
        return os;
    }
};