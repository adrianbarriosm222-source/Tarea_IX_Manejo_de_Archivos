#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Prototipos de funciones
void mostrarMenu();
void guardarUsuario();
void mostrarUsuarios();

int main() {
    int opcion;

    do {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // limpiar buffer

        switch(opcion) {
            case 1:
                guardarUsuario();
                break;
            case 2:
                mostrarUsuarios();
                break;
            case 3:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }

    } while(opcion != 3);

    return 0;
}

// Función para mostrar el menú
void mostrarMenu() {
    cout << "\n===== MENU =====\n";
    cout << "1. Guardar usuario\n";
    cout << "2. Mostrar usuarios\n";
    cout << "3. Salir\n";
}

// Función para guardar usuario en archivo
void guardarUsuario() {
    string nombre, posicion;
    int edad;

    ofstream archivo("usuarios.txt", ios::app);

    if (!archivo) {
        cout << "Error al abrir el archivo.\n";
        return;
    }

    cout << "Ingrese nombre completo: ";
    getline(cin, nombre);

    cout << "Ingrese posicion en la empresa: ";
    getline(cin, posicion);

    cout << "Ingrese edad: ";
    cin >> edad;
    cin.ignore();

    // Guardar en formato CSV
    archivo << nombre << "," << posicion << "," << edad << endl;

    archivo.close();

    cout << "Usuario guardado correctamente.\n";
}

// Función para mostrar usuarios
void mostrarUsuarios() {
    ifstream archivo("usuarios.txt");
    string linea;

    if (!archivo) {
        cout << "No se pudo abrir el archivo o no existe.\n";
        return;
    }

    cout << "\n=== LISTA DE USUARIOS ===\n";

    while (getline(archivo, linea)) {
        cout << linea << endl;
    }
    cout <<"Rodrigo Adrian Barrios Monterroso" ;

    archivo.close();
}