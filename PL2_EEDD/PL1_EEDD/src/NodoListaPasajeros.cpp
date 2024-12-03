#include "NodoListaPasajeros.h"
#include "Pasajero.h"

NodoListaPasajeros::NodoListaPasajeros()
{
    //ctor
    siguiente=nullptr;
}
NodoListaPasajeros::NodoListaPasajeros(Pasajero p)
{
    //ctor
    pasajero=p;
    siguiente=nullptr;
}

NodoListaPasajeros::~NodoListaPasajeros()
{
    //dtor
}

Pasajero& NodoListaPasajeros::getPasajero() {
    return pasajero;
}

NodoListaPasajeros* NodoListaPasajeros::getSiguiente() {
    return siguiente;
}

void NodoListaPasajeros::setSiguiente(NodoListaPasajeros* siguienteNodo) {
    siguiente = siguienteNodo;
}
