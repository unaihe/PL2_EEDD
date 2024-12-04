#ifndef NODOLISTAPASAJERO_H
#define NODOLISTAPASAJERO_H

#include "Persona.h"

class NodoListaPasajero {
public:
    NodoListaPasajero();                       // Constructor por defecto
    NodoListaPasajero(const Persona& persona); // Constructor con argumento
    virtual ~NodoListaPasajero();              // Destructor

    Persona& getPersona();                     // Obtener la persona almacenada
    NodoListaPasajero* getSiguiente();         // Obtener el siguiente nodo
    void setSiguiente(NodoListaPasajero* siguienteNodo); // Establecer el siguiente nodo

private:
    Persona persona;                           // Objeto Persona almacenado en el nodo
    NodoListaPasajero* siguiente;              // Puntero al siguiente nodo
};

#endif // NODOLISTAPASAJERO_H
