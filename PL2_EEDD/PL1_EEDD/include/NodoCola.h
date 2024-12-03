#ifndef NODOCOLA_H
#define NODOCOLA_H
#include "Pasajero.h"
#include <cstddef>

class NodoCola
{   friend class Cola;
    public:
        NodoCola();
        virtual ~NodoCola();
        NodoCola(Pasajero p, NodoCola *sig=NULL);

    private:
        NodoCola *siguiente;
        Pasajero p;
};

#endif // NODOCOLA_H
