#include <iostream>
#include <string>

#include "MySQLConexion.h"
#include "MySQLModel.h"
#include "EloquentORM.h"

using namespace std;

class Consola {
public:
    static void color(int c) {
        system(("color " + to_string(c)).c_str());
    }
};

class Libros {
public:
    void menu() {
        cout << "\n=== GESTION DE LIBROS ===\n";
    }
};

class Usuarios {
public:
    void menu() {
        cout << "\n=== GESTION DE USUARIOS ===\n";
    }
};

class Prestamos {
public:
    void menu() {
        cout << "\n=== GESTION DE PRESTAMOS ===\n";
    }
};

class SistemaBiblioteca {
private:
    Libros* libros;
    Usuarios* usuarios;
    Prestamos* prestamos;

public:
    SistemaBiblioteca() {
        libros = new Libros();
        usuarios = new Usuarios();
        prestamos = new Prestamos();
    }

    ~SistemaBiblioteca() {
        delete libros;
        delete usuarios;
        delete prestamos;
    }

    void menuPrincipal() {
        int opcion;

        do {
            cout << "\n===== SISTEMA BIBLIOTECA =====\n";
            cout << "1. Gestionar libros\n";
            cout << "2. Gestionar usuarios\n";
            cout << "3. Gestionar prestamos\n";
            cout << "4. Salir\n";
            cout << "Seleccione una opcion: ";
            cin >> opcion;

            switch(opcion) {
                case 1:
                    libros->menu();
                    break;

                case 2:
                    usuarios->menu();
                    break;

                case 3:
                    prestamos->menu();
                    break;

                case 4:
                    cout << "\nSaliendo del sistema...\n";
                    break;

                default:
                    cout << "\nOpcion invalida.\n";
            }

        } while(opcion != 4);
    }
};

int main() {

    cout << "Conexion exitosa a MySQL\n";

    SistemaBiblioteca sistema;
    sistema.menuPrincipal();

    return 0;
}