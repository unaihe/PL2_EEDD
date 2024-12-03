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



    private:
        Pasajero pasajero;
        NodoListaPasajeros* siguiente;
};

#endif // NODOLISTAPASAJEROS_H
