#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "AlumnoP2.h"

using namespace std;

class FixedRecordP2{
    string name;
    int n = 0;

    void stringtochar(char arr[], string palabra, int n) {
        for (int i=0; i<n; i++) {
            if (i<palabra.size())
                arr[i] = palabra[i];
            else
                arr[i] = ' ';
        }
    }

public:
    explicit FixedRecordP2(string _nombre) : name(_nombre){}

    vector<AlumnoP2> load() {
        ifstream file;
        file.open(name + ".dat", ios::binary);
        vector<AlumnoP2> v;
        int i = 0;
        ifstream inFile;
            inFile.open(name + ".dat", ios::binary);
        int c = n;
        while (n--) {
            AlumnoP2 record;
            inFile.seekg(i++ * sizeof(record), ios::beg);
            inFile.read((char*) &record, sizeof(record));
            
            cout << "Codigo: ";
            for (int i=0; i<5; i++)
                cout << record.codigo[i];
            cout << endl << "Nombre: ";
            for (int i=0; i<11; i++)
                cout << record.nombre[i];
            cout << endl << "Apellidos: ";
            for (int i=0; i<20; i++)
                cout << record.apellidos[i];
            cout << endl << "Carrera: ";
            for (int i=0; i<15; i++)
                cout << record.carrera[i];
            cout << endl << "Ciclo: " << record.ciclo;
            cout << endl << "Mensualidad: " << record.mensualidad << endl;
            cout << endl;

            v.push_back(record);
        }
        inFile.close();
	    return v;
    }

    
    friend ostream &operator<< (ostream & stream, const AlumnoP2 record) {
        stream.write((char*) &record, sizeof(record));
        return stream;
    }
    

    void add(AlumnoP2 record) {
        ofstream inFile;
        inFile.open(name + ".dat", ios::app | ios::binary);
        inFile.write((char*) &record, sizeof(record));
        inFile.close();
        n++;
    }

    AlumnoP2 readRecord(int pos) {
        ifstream inFile;
        AlumnoP2 record;
        inFile.open(name + ".dat", ios::binary);
        inFile.seekg(pos * sizeof(record), ios::beg);
        inFile.read((char*) &record, sizeof(record));
        inFile.close();
        return record;
    }

    bool mydelete(int pos) {
        load()[pos];
        return true;
    }

    void Test() {
        AlumnoP2 a2a{};
        string codigo = "22315";
        stringtochar(a2a.codigo, codigo, 5);

        string nombre = "Alonso";
        stringtochar(a2a.nombre, nombre, 11);

        string apellidos = "Mondragon Aliaga";
        stringtochar(a2a.apellidos, apellidos, 20);

        string carrera = "Medicina";
        stringtochar(a2a.carrera, carrera, 15);

        a2a.ciclo = int(3);
        a2a.mensualidad = double(100.3);

        AlumnoP2 a2b{};
        codigo = "4412";
        stringtochar(a2b.codigo, codigo, 5);

        nombre = "Juan";
        stringtochar(a2b.nombre, nombre, 11);

        apellidos = "Martinez Mendoza";
        stringtochar(a2b.apellidos, apellidos, 20);

        carrera = "Arquitectura";
        stringtochar(a2b.carrera, carrera, 15);

        a2b.ciclo = int(5);
        a2b.mensualidad = double(200.5);

        AlumnoP2 a2c{};
        codigo = "11";
        stringtochar(a2c.codigo, codigo, 5);

        nombre = "Lucho";
        stringtochar(a2c.nombre, nombre, 11);

        apellidos = "Saco Largo";
        stringtochar(a2c.apellidos, apellidos, 20);

        carrera = "Programacion";
        stringtochar(a2c.carrera, carrera, 15);

        a2c.ciclo = int(9);
        a2c.mensualidad = double(150.25);

        add(a2a);
        add(a2b);
        add(a2c);

        cout << "* Probando load & readRecord: *\n";
        load();
        cout << "\n* Imprimiendo alumno pos 2: *\n";
        AlumnoP2 p = readRecord(2);
        cout << "Codigo: ";
            for (int i=0; i<5; i++)
                cout << p.codigo[i];
            cout << endl << "Nombre: ";
            for (int i=0; i<11; i++)
                cout << p.nombre[i];
            cout << endl << "Apellidos: ";
            for (int i=0; i<20; i++)
                cout << p.apellidos[i];
            cout << endl << "Carrera: ";
            for (int i=0; i<15; i++)
                cout << p.carrera[i];
            cout << endl << "Ciclo: " << p.ciclo;
            cout << endl << "Mensualidad: " << p.mensualidad << endl;
            cout << endl;
    }
};
