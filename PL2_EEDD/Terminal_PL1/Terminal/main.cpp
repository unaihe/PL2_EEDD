#include <iostream>
#include "Pilas.h"
#include "NodoPilas.h"
#include "Colas.h"
#include "T4Madrid.h"
using namespace std;
int main()
{

    int n = 0, min;
    T4Madrid t4m = T4Madrid();
    while (n < 11)
    {
        cout << "_______________________________________" << endl;
        cout << "" << endl;
        cout << "--------AEROPUERTO T4 MADRID-----------" << endl;
        cout << "_______________________________________" << endl;
        cout << "" << endl;
        cout << "-¿Qué quieres hacer?" << endl;
        cout << "[1]- Añadir pasajeros." << endl;
        cout << "[2]- Mostrar pila de pasajeros." << endl;
        cout << "[3]- Borrar pila de pasajeros." << endl;
        cout << "[4]- Mostrar datos de los pasajeros en los boxes." << endl;
        cout << "[5]- Pasar tiempo en el aeropuerto." << endl;
        cout << "[6]- Simulación aeropuerto." << endl;
        cout << "[7]- Consultar el box con menos pasajeros." << endl;
        cout << "[8]- Consultar el box más ocupado." << endl;
        cout << "[9]- Consultar el número de boxes operativos." << endl;
        cout << "_______________________________________" << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "- Opción seleccionada: Añadir pasajeros al aeropuerto." << endl;
            t4m.iniciarAeropuerto();
            break;

        case 2:
            cout << "- Opción seleccionada: Mostrar la pila de pasajeros." << endl;
            t4m.mostrarPasajerosPila();
            break;

        case 3:
            cout << "- Opción seleccionada: Borrar todos los pasajeros de la pila." << endl;
            t4m.borrarPila();
            break;


        case 4:
            cout << "- Opción seleccionada: Mostrar datos de los pasajeros en los boxes." << endl;
            t4m.mostrarDatosBox();
            break;

        case 5:
            cout << "- Opción seleccionada: Pasar tiempo en el aeropuerto." << endl;
            cout << "- Introduzca una cantidad de minutos: " << endl;
            cin >> min;
            for (int i = 0; i < min; i++)
            {
                t4m.minuto();
                cout<<" "<<endl;
            }
            break;

        case 6:
            cout << "- Opción seleccionada: Simulación del aeropuerto completa." << endl;
            cout << "- Se va a proceder a la simulación del aeropuerto." << endl;
            t4m.simulacion();
            break;

        case 7:
            cout << "- Opción seleccionada: Consultar el box con menos pasajeros." << endl;
            t4m.consultarBoxMenosOcupado();
            break;

        case 8:
            cout << "- Opción seleccionada: Consultar el box más ocupado." << endl;
            t4m.consultarBoxMasOcupado();
            break;

        case 9:
            cout << "- Opción seleccionada: Consultar el número de boxes operativos." << endl;
            t4m.consultarBoxesOperativos();
            break;

        default:
            cout << "- Opción no válida. Por favor, elige una opción del 1 al 10." << endl;
            break;
        }
    }
    return 0;

}
