#ifndef NODOLISTAPASAJEROS_H
#define NODOLISTAPASAJEROS_H
#include "Pasajero.h"

class NodoListaPasajeros
{
    public:
        NodoListaPasajeros();
        NodoListaPasajeros(Pasajero p);
        virtual ~NodoListaPasajeros();
        Pasajero& getPasajero();
        NodoListaPasajeros* getSiguiente();
        void setSiguiente(NodoListaPasajeros* siguienteNod);
        NodoListaPasajeros* siguiente;


    private:
        Pasajero pasajero;

};

#endif // NODOLISTAPASAJEROS_H
