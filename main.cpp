#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "P1/p1.cpp"
#include "P2/p2.cpp"
#include "P3/p3.cpp"
#include "P4/p4.cpp"

using namespace std;

int main() {
    cout << "-------------------------P1-------------------------\n";
    FixedRecordP1 P1("datos1");
    P1.Test();

    cout << "-------------------------P2-------------------------\n";
    FixedRecordP2 P2("fichero1");
    P2.Test();
    
    cout << "-------------------------P3-------------------------\n";
    VariableRecord P3("datos2");
    P3.Test();

    cout << "-------------------------P4-------------------------\n";
    VariableRecordP4 P4("fichero2", "metadata");
    P4.Test();
    return 0;
}