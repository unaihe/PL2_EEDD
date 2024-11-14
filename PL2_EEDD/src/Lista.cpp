#include "Lista.h"
#include <iostream>
#include "Box.h"
#include "NodoLista.h"

Lista::Lista()
{
    //ctor
    cabeza=nullptr;
}

Lista::~Lista()
{
    //dtor
}

void Lista::agregarBox(Box b) {
    NodoLista* nuevoNodo = new NodoLista(b);
    nuevoNodo->setSiguiente(cabeza);
    cabeza = nuevoNodo;
}

void Lista::eliminarCabeza() {
    if (esVacia()) {
        std::cout << "La lista está vacía. No hay Boxes para eliminar." << std::endl;
        return;
    }
    NodoLista* nodoEliminar = cabeza;
    cabeza = cabeza->getSiguiente();
    delete nodoEliminar;
}

void Lista::eliminarEspecifico(Box b) {
    NodoLista* actual = cabeza;
    NodoLista* anterior = nullptr;

    while (actual != nullptr) {
        if (actual->getBox().getId() == b.getId()) {
            if (anterior == nullptr) {
                cabeza = actual->getSiguiente();
            } else {
                anterior->setSiguiente(actual->getSiguiente());
            }
            delete actual;
            std::cout << "Box " << b.getId() << " eliminado.\n";
            return;
        }
        anterior = actual;
        actual = actual->getSiguiente();
    }
    std::cout << "Box no encontrado.\n";
}




bool Lista::esVacia() {
    return cabeza == nullptr;
}

Box Lista::boxMenosPasajeros() {
    if (esVacia()) {
        std::cerr << "La lista está vacía, no se puede encontrar un box." << std::endl;
    }

    NodoLista* temp = cabeza;
    Box boxMenor = temp->getBox();
    temp = temp->getSiguiente();
    while (temp != nullptr) {
        if (temp->getBox().numeroPasajeros() < boxMenor.numeroPasajeros()) {
            boxMenor = temp->getBox();
        }
        temp = temp->getSiguiente();
    }

    return boxMenor;
}
Box Lista::boxMasOcupado() {
    if (esVacia()) {
        std::cerr << "La lista está vacía, no se puede encontrar un box." << std::endl;
        return Box(-1);
    }

    NodoLista* temp = cabeza;
    Box boxMayor = temp->getBox();
    temp = temp->getSiguiente();

    while (temp != nullptr) {
        if (temp->getBox().numeroPasajeros() > boxMayor.numeroPasajeros()) {
            boxMayor = temp->getBox();
        }
        temp = temp->getSiguiente();
    }

    return boxMayor;
}

void Lista::eliminarVacios() {
    NodoLista* actual = cabeza;
    NodoLista* anterior = nullptr;

    while (actual != nullptr) {
        if (actual->getBox().esta_libre()) {

            if (anterior == nullptr) {

                cabeza = actual->getSiguiente();
                delete actual;
                actual = cabeza;
            } else {
                anterior->setSiguiente(actual->getSiguiente());
                delete actual;
                actual = anterior->getSiguiente();
            }
            std::cout << "Box vacío eliminado.\n";
        } else {
            anterior = actual;
            actual = actual->getSiguiente();
        }
    }
}

int Lista::numeroBoxes() {
    int contador = 0;
    NodoLista* actual = cabeza;
    while (actual != nullptr) {
        contador++;
        actual = actual->getSiguiente();
    }

    return contador;
}

NodoLista* Lista::getCabeza() {
        return cabeza;
}


 bool Lista::hayPasajerosAtendidos() {
        NodoLista* temp = cabeza;
        while (temp != nullptr) {

            if (temp->getBox().hayPasajerosAtendidos()) {
                return true;
            }
            temp = temp->getSiguiente();
        }
        return false;
    }
;
void Lista::mostrarEstadoBox() {
    if (esVacia()) {
        std::cout << "No hay boxes en la lista." << std::endl;
        return;
    }

    NodoLista* temp = cabeza;
    while (temp != nullptr) {
        Box boxActual = temp->getBox();


        std::cout << "Box ID: " << boxActual.getId() << std::endl;


        if (boxActual.esta_libre()) {
            std::cout << "Estado: Libre" << std::endl;
        } else {
            std::cout << "Estado: Ocupado" << std::endl;
            std::cout << "Pasajero atendido (ID): " << boxActual.getPasajero().getId() << std::endl;
            std::cout << "Tiempo restante de atención: " << boxActual.getTiempoRestante() << " minutos" << std::endl;
        }


        std::cout << "Pasajeros en espera: ";
        if (boxActual.getColaPasajeros().es_vacia()) {
            std::cout << "Ninguno" << std::endl;
        } else {
            boxActual.getColaPasajeros().mostrarCola();
        }

        std::cout << "------------------------" << std::endl;

        temp = temp->getSiguiente();
    }
}
