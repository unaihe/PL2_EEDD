#ifndef COLA_H
#define COLA_H
#include "NodoCola.h"
#include "Pasajero.h"

class Cola
{
    public:
        Cola();
        virtual ~Cola();
        void encolar(const Pasajero& p);
        Pasajero inicio();
        Pasajero fin();
        Pasajero desencolar();
        bool es_vacia();
        void mostrarCola();
        void ordenarCola();
        int getLongitud();

    private:
        NodoCola *primero;
        NodoCola *ultimo;
        int longitud;
};

#endif // COLA_H
