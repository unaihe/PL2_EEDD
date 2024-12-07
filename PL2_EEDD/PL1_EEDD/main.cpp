#include <iostream>
#include "Pasajero.h"
#include "Pila.h"
#include "Aeropuerto.h"
using namespace std;


int main(){


    Aeropuerto aeropuerto=Aeropuerto();
    void mostrarMenu();
    int opcion;

        do {
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                aeropuerto.crearPila();
                break;
            }
            case 2: {
                aeropuerto.mostrarPila();
                break;
            }
            case 3: {
                aeropuerto.borrarPila();
                break;
            }
            case 4: {
                aeropuerto.simularMinutos();
                break;
            }
            case 5: {aeropuerto.mostrarEstadoBoxes();

                break;
            }
            case 6: {
                aeropuerto.mostrarColaMasYMenosLlena();
                break;
            }
            case 7: {
                aeropuerto.simularTiempo();
                break;
            }
            case 8:{
                aeropuerto.agregarPasajeroArbol();
                break;
            }
            case 9:{
                aeropuerto.mostrarArbol();
                break;
            }
            case 10:{
                aeropuerto.mostrarPasajerosPais();
                break;
            }
            case 11:{
                aeropuerto.paisesOrdenados();
                break;
            }
            case 12:{
                aeropuerto.masMenos();
                break;
            }
            case 13:{
                aeropuerto.tiempoMedioPais();
                break;
            }
            case 14:{
                aeropuerto.tiempoMedioPaises();
                break;
            }
            case 15: {
                std::cout << "Saliendo del programa...\n";
                break;
            }

            default: {
                std::cout << "Opción no válida. Intente de nuevo.\n";
            }
        }
    } while (opcion != 15);

    return 0;
}


    void mostrarMenu() {
    std::cout << "\n--- Menú ---\n";
    std::cout << "1. Crear la pila de pasajeros\n";
    std::cout << "2. Mostrar los pasajeros en la pila\n";
    std::cout << "3. Borrar la pila de pasajeros\n";
    std::cout << "4. Simular el paso de N minutos\n";
    std::cout << "5. Mostrar el estado de los boxes\n";
    std::cout << "6. Consultar el box con mas y menos cola\n";
    std::cout << "7. Simular el control de aduanas completo\n";
    std::cout << "8. Introducir pasajero al arbol por pantalla\n";
    std::cout << "9. Ver datos del árbol\n";
    std::cout << "10. Buscar por país\n";
    std::cout << "11. Mostrar paises ordenados\n";
    std::cout << "12. Mayor número de pasajeros y menor por país\n";
    std::cout << "13. Media de tiempo por país\n";
    std::cout << "14. Media de tiempo paises\n";
    std::cout << "15. Salir\n";
    std::cout << "Seleccione una opción: ";
}
