#ifndef PILA_H
#define PILA_H
#include "Pasajero.h"
#include "NodoPila.h"

class Pila
{
    public:
        Pila();
        virtual ~Pila();
        bool esVacia();
        void apilar(Pasajero p);
        void desapilar();
        void mostrarPila();
        void borrarPila();
        void invertirPila();
        Pasajero obtenerCima();

    private:
        NodoPila* cima;
};

#endif // PILA_H
