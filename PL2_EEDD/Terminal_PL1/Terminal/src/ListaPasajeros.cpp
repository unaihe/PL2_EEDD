#include "ListaPasajeros.h"
#include <iostream>
#include "Persona.h"
#include "NodoListaPasajero.h"

ListaPasajeros::ListaPasajeros() {
    cabeza = nullptr; // Inicializa la cabeza en nullptr, indicando que la lista está vacía.
}

ListaPasajeros::~ListaPasajeros() {
    NodoListaPasajero* temp;
    while (cabeza != nullptr) {
        temp = cabeza;
        cabeza = cabeza->getSiguiente(); // Avanza al siguiente nodo.
        delete temp; // Elimina el nodo actual.
    }
}

void ListaPasajeros::agregarPasajero(Persona p) {
    NodoListaPasajero* nuevoNodo = new NodoListaPasajero(p); // Crea un nuevo nodo con la persona proporcionada.
    nuevoNodo->setSiguiente(cabeza); // El siguiente del nuevo nodo apunta a la cabeza actual de la lista.
    cabeza = nuevoNodo; // El nuevo nodo se convierte en la cabeza de la lista.
}

void ListaPasajeros::eliminarCabeza() {
    if (esVacia()) {
        std::cout << "La lista está vacía. No hay pasajeros para eliminar." << std::endl;
        return;
    }
    NodoListaPasajero* nodoEliminar = cabeza; // Guarda el nodo que se va a eliminar.
    cabeza = cabeza->getSiguiente(); // La cabeza de la lista se mueve al siguiente nodo.
    delete nodoEliminar; // Elimina el nodo que estaba en la cabeza.
}

bool ListaPasajeros::esVacia() {
    return cabeza == nullptr; // Si la cabeza es nullptr, la lista está vacía.
}

void ListaPasajeros::mostrarPasajeros() {
    if (esVacia()) {
        std::cout << "No hay pasajeros en la lista." << std::endl;
        return;
    }
    NodoListaPasajero* temp = cabeza; // Empieza desde la cabeza de la lista.
    while (temp != nullptr) {
        // Muestra el ID de la persona y su tiempo de estancia.
        std::cout << "Pasajero ID: " << temp->getPersona().getId() << std::endl;
        std::cout << "Tiempo de estancia: " << temp->getPersona().getDuracion() << " minutos" << std::endl;
        temp = temp->getSiguiente(); // Avanza al siguiente nodo.
    }
}

NodoListaPasajero* ListaPasajeros::getCabeza() {
    return cabeza; // Devuelve el primer nodo de la lista.
}

