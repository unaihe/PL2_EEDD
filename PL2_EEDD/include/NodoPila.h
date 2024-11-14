#ifndef NODOPILA_H
#define NODOPILA_H
#include "Pasajero.h"
#include <cstddef>

class NodoPila
{
    public:
        NodoPila();
        NodoPila(Pasajero p, NodoPila* sig=NULL);
        virtual ~NodoPila();

    private:
        Pasajero p;
        NodoPila* siguiente;
        friend class Pila;

};

#endif // NODOPILA_H
