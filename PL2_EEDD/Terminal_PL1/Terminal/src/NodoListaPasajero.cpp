#include "NodoListaPasajero.h"
#include "Persona.h"

NodoListaPasajero::NodoListaPasajero() : siguiente(nullptr) {

}

NodoListaPasajero::NodoListaPasajero(const Persona& persona) : persona(persona), siguiente(nullptr) {

}

NodoListaPasajero::~NodoListaPasajero() {

}

Persona& NodoListaPasajero::getPersona() {

    return persona;
}

NodoListaPasajero* NodoListaPasajero::getSiguiente() {

    return siguiente;
}

void NodoListaPasajero::setSiguiente(NodoListaPasajero* siguienteNodo) {

    siguiente = siguienteNodo;
}
