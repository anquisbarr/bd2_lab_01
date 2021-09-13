#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Matricula.h"

using namespace std;

class FixedRecordP4{
    string name;
    int n = 0;
    vector<string> split(string line, string separator) {
        vector<string> words;
        string word;
        for (auto i=0; i<line.size(); i++) {
            string comp;
            int j=i;
            if (j < line.size()-1) {
                for (auto x : separator) {
                    comp += line[j++];
                }
            }
            
            
            if (comp != separator)
                word += line[i];
            else {
                words.push_back(word);
                word = "";
            }
        }
        words.push_back(word);
        return words;
    }
public:
    explicit FixedRecordP4(string _nombre) : name(_nombre){}

    vector<Matricula> load() {
        fstream file;
        file.open(name + ".txt");
        string texto;

        vector<Matricula> v;

        bool key = true;
        int j = n;
        while (n--) {
            if (key) {
                key = false;
                continue;
            }
        }
        return v;
    }

    void add(Matricula record) {
        ofstream inFile;
        string cadena = to_string(sizeof(record.codigo)) + ":" + record.codigo +
                        to_string(sizeof(record.ciclo)) + ":" + to_string(record.ciclo) +
                        to_string(sizeof(record.mensualidad)) + ":" + to_string(record.mensualidad) +
                        to_string(sizeof(record.observaciones)) + ":" + record.observaciones;
        cout << cadena << endl;
        inFile.open(name + ".dat", ios::app | ios::binary);
        inFile.write((char*) &cadena, sizeof(cadena));
        inFile.close();
        n++;
    }

    Matricula readRecordP4(int pos) {
        Matricula record;
        
        return record;
    }

    void Test() {
        Matricula m1{};
        m1.ciclo = 1;
        m1.codigo = "abc";
        m1.mensualidad = 19.6;
        m1.observaciones = "atwq";

        Matricula m2{};
        m2.ciclo = 3;
        m2.codigo = "abcde";
        m2.mensualidad = 20;
        m2.observaciones = "fugian";

        Matricula m = readRecordP4(1);
        cout << "ciclo: " << m.ciclo;
    }
};