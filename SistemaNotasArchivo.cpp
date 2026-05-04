#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream archivo("estudiantes.txt");
    string nombre;
    double n1, n2, n3, promedio;
    int total = 0, aprobados = 0;
    double suma = 0;

    if (!archivo.is_open()) {
        cout << "Error: no se puede abrir el archivo." << endl;
        return 1;
    }

    while (archivo >> nombre >> n1 >> n2 >> n3) {
        promedio = (n1 + n2 + n3) / 3.0;
        cout << "Nombre: " << nombre << endl;
        cout << "Promedio: " << promedio << endl;
        if (promedio >= 9) {
            cout << "Estado: Excelente" << endl;
            aprobados++;
        } else if (promedio >= 7) {
            cout << "Estado: Bueno" << endl;
            aprobados++;
        } else {
            cout << "Estado: Reprobado" << endl;
        }
        suma += promedio;
        total++;
        cout << "----------------------" << endl;
    }

    archivo.close();
    cout << "Total estudiantes: " << total << endl;
    cout << "Total aprobados: " << aprobados << endl;
    cout << "Promedio general: " << suma / total << endl;

    return 0;
}