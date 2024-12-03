#include "ListaPasajeros.h"
#include <iostream>
#include "Pasajero.h"
#include "NodoListaPasajeros.h"


ListaPasajeros::ListaPasajeros() {
    cabeza = nullptr;
}


ListaPasajeros::~ListaPasajeros() {
    NodoListaPasajeros* temp;
    while (cabeza != nullptr) {
        temp = cabeza;
        cabeza = cabeza->getSiguiente();
        delete temp;
    }
}


void ListaPasajeros::agregarPasajero(Pasajero p) {
    NodoListaPasajeros* nuevoNodo = new NodoListaPasajeros(p);
    nuevoNodo->setSiguiente(cabeza);
    cabeza = nuevoNodo;
}


void ListaPasajeros::eliminarCabeza() {
    if (esVacia()) {
        std::cout << "La lista está vacía. No hay pasajeros para eliminar." << std::endl;
        return;
    }
    NodoListaPasajeros* nodoEliminar = cabeza;
    cabeza = cabeza->getSiguiente();
    delete nodoEliminar;
}


bool ListaPasajeros::esVacia() {
    return cabeza == nullptr;
}


void ListaPasajeros::mostrarPasajeros() {
    if (esVacia()) {
        std::cout << "No hay pasajeros en la lista." << std::endl;
        return;
    }

    NodoListaPasajeros* temp = cabeza;
    while (temp != nullptr) {
        std::cout << "Pasajero ID: " << temp->getPasajero().getId() << std::endl;
        std::cout << "Tiempo de estancia: " << temp->getPasajero().getTiempoFinal() << " minutos" << std::endl;
        temp = temp->getSiguiente();
    }
}


NodoListaPasajeros* ListaPasajeros::getCabeza() {
    return cabeza;
}
