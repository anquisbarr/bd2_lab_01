#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "p1.cpp"
#include "p2.cpp"
#include "p3.cpp"
#include "p4.cpp"

using namespace std;

int main() {
    std::cout << "Hello World!\n";
    cout << "-------------------------P1-------------------------\n";
    FixedRecordP1 P1("datos1");
    P1.Test();

    cout << "-------------------------P2-------------------------\n";
    FixedRecordP2 P2("fichero1");
    P2.Test();
    
    cout << "-------------------------P3-------------------------\n";
    VariableRecord VR("datos2");
    VR.Test();
    
    cout << "-------------------------P4-------------------------\n";
    // FixedRecordP4 P4("fichero2");
    // P4.Test();
    cout << "PROFE, NO NOS SALIÓ ESTA PREGUNTA, PERDONE" << endl;

    return 0;
}