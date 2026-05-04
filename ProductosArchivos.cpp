#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream archivo("ventas.txt");

    if (!archivo.is_open()) {
        cout << "Error: No se puede abrir el archivo." << endl;
        return 1;
    }

    string producto;
    double precio;
    int cantidad;

    double totalGeneral = 0;
    double mayorVenta = 0;
    string productoMayor = "";

    while (archivo >> producto >> precio >> cantidad) {
        double subtotal = precio * cantidad;
        totalGeneral += subtotal;

        cout << "Producto: " << producto << " | Subtotal: $" << subtotal << endl;

        if (subtotal > mayorVenta) {
            mayorVenta = subtotal;
            productoMayor = producto;
        }
    }

    archivo.close();

    cout << "------------------------" << endl;
    cout << "Total general: $" << totalGeneral << endl;
    cout << "Mayor venta: " << productoMayor << " ($" << mayorVenta << ")" << endl;

    return 0;
}