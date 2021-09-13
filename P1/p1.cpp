#include "AlumnoP1.h"

void stringtochar(char arr[], string palabra, int n) {
    for (int i=0; i<n; i++) {
        if (i<palabra.size())
            arr[i] = palabra[i];
        else
            arr[i] = ' ';
    }
}

class FixedRecordP1{
    string nombre;
public:
    explicit FixedRecordP1(string _nombre) : nombre(_nombre){}
    
    vector<AlumnoP1> load() {
        fstream file;
        file.open(nombre + ".txt");

        string texto;

        vector<AlumnoP1> v;

        while (getline (file, texto)) {
            AlumnoP1 alumno{};
            for (int i=0; i<5; i++)
                alumno.codigo[i] = texto[i];

            for (int i=5; i<16; i++)
                alumno.nombre[i-5] = texto[i];

            for (int i=16; i<36; i++)
                alumno.apellidos[i-16] = texto[i];

            for (int i=36; i<51; i++)
                alumno.carrera[i-36] = texto[i];

            v.push_back(alumno);
        }

        file.close();

        return v;
    }

    void add(AlumnoP1 record) {
        string palabra;

        for (char i : record.codigo)
            palabra += i;
        string code = palabra;
        palabra = "";

        for (char i : record.nombre)
            palabra += i;
        string name = palabra;
        palabra = "";

        for (char apellido : record.apellidos)
            palabra += apellido;
        string last_name = palabra;
        palabra = "";
        
        for (char i : record.carrera)
            palabra += i;
        string career = palabra;

        string cadena = code + name + last_name + career + "\n";
        ofstream file;
        file.open(nombre + ".txt", ios::app);
        file << cadena;
        file.close();
    }

    AlumnoP1 readRecord(int pos) {
        vector<AlumnoP1> temp = load();
        return temp[pos];
    }

    void Test() {
        FixedRecordP1 fr(nombre);

        AlumnoP1 a{};
        string codigo = "22315";
        stringtochar(a.codigo, codigo, 5);

        string nombre = "Alonso";
        stringtochar(a.nombre, nombre, 11);

        string apellidos = "Mondragon Aliaga";
        stringtochar(a.apellidos, apellidos, 20);

        string carrera = "Medicina";
        stringtochar(a.carrera, carrera, 15);

        fr.add(a);

        AlumnoP1 pruebaA1 = fr.readRecord(2);
        cout << "* Imprimiendo alumno pos 2: *" << endl;
        cout << pruebaA1;
    }
};