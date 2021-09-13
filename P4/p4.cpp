#include "Matricula.h"

class VariableRecordP4{
    string name;
    string meta_name;
public:
    explicit VariableRecordP4(string _nombre, string _meta_nombre) : name(_nombre), meta_name(_meta_nombre){}

    vector<Matricula> load() {
        vector<Matricula> v;
        ifstream inFile;
        inFile.open(name + ".dat", ios::binary);
        Matricula temp;
        while (read(inFile, temp))
        {
            v.push_back(temp);
        }
        inFile.close();
        return v;
    }

    bool read(ifstream &s, Matricula &reg)
    {
        s.read((char *) &reg.ciclo, sizeof(reg.ciclo));
        if (s.fail()) return false;
        s.read((char *) &reg.mensualidad, sizeof(reg.mensualidad));
        reg.codigo = readStr(s);
        reg.observaciones = readStr(s);
        return true;
    }

    string readStr(ifstream &strm) {
        int len;
        strm.read((char *) &len, sizeof(len));
        char *buffer = new char[len + 1];
        strm.read(buffer, len);
        buffer[len] = '\0';
        string result = buffer;
        delete buffer;
        return result;
    }

    void add(Matricula record) {
        ofstream inFile;
        inFile.open(name + ".dat", ios::binary | ios::app);
        long begin = fileSize();
        write(inFile, record);
        inFile.close();
        inFile.open(meta_name + ".dat", ios::binary | ios::app);
        inFile.write((char*) &begin, sizeof(begin));
        inFile.close();
    }

    void write(ofstream &stream, Matricula &r) {
        stream.write((char *) &r.ciclo, sizeof(r.ciclo));
        stream.write((char *) &r.mensualidad, sizeof(r.mensualidad));
        writeString(stream, r.codigo);
        writeString(stream, r.observaciones);
    }

    void writeString(ofstream &stream, string str) {
        int len = str.size();
        stream.write((char *) &len, sizeof(len));
        stream.write(str.c_str(), len);
    }

    streampos fileSize(){
        ifstream inFile(name + ".dat", ios::binary);
        streampos size = 0;
        size = inFile.tellg();
        inFile.seekg(0, std::ios::end);
        size = inFile.tellg() - size;
        inFile.close();
        return size;
    }

    Matricula readRecordP4(int pos) {
        ifstream inFile;
        Matricula record;
        long metadataPos;

        inFile.open(meta_name + ".dat", ios::binary);
        inFile.seekg(pos*sizeof(metadataPos));
        inFile.read((char *) &metadataPos, sizeof(metadataPos));
        inFile.close();

        inFile.open(name + ".dat", ios::binary);
        inFile.seekg(metadataPos);
        read(inFile, record);
        inFile.close();
        
        return record;
    }

    void Test() {
        auto v = load();
        for (auto x : v)
        {
            x.printData();
        }
        cout << "Añadiendo registros al archivo:" << endl;
        Matricula M{};
        M.codigo = "0012";
        M.ciclo = 7;
        M.mensualidad = 3205.23;
        M.observaciones = "prueba";
        add(M);
        M.printData();
        cout << endl;

        Matricula O{};
        O.codigo = "0002";
        O.ciclo = 3;
        O.mensualidad = 1480.70;
        O.observaciones = "qwerty";
        add(O);
        O.printData();
        cout << endl;

        Matricula P{};
        P.codigo = "0003";
        P.ciclo = 7;
        P.mensualidad = 2700.15;
        P.observaciones = "123456789";
        add(P);
        P.printData();
        cout << endl;
        
	    v = load();
        auto a = readRecordP4(v.size()-1);
        a.printData();
    }
};