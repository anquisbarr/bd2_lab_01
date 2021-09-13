#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct AlumnoP1{
    char codigo[5];
    char nombre[11];
    char apellidos[20];
    char carrera[15];

    friend ostream& operator<<(ostream& os, const AlumnoP1& a1) {
        os << "Codigo: ";
        for (int i=0; i<5; i++)
            os << a1.codigo[i];
        os << endl << "Nombre: ";
        for (int i=0; i<11; i++)
            os << a1.nombre[i];
        os << endl << "Apellidos: ";
        for (int i=0; i<20; i++)
            os << a1.apellidos[i];
        os << endl << "Carrera: ";
        for (int i=0; i<15; i++)
            os << a1.carrera[i];
        os << endl;
        return os;
    }
};