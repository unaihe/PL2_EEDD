#ifndef NODOPILAS_H
#define NODOPILAS_H
#include <iostream>
#include "Persona.h"
class NodoPilas
{
private:
    Persona valor;
    NodoPilas *siguiente;
    friend class Pilas; friend class T4Madrid;
public:
    NodoPilas();
    NodoPilas(Persona per, NodoPilas *sig = NULL);
    ~NodoPilas();
};
typedef NodoPilas *pnodo;
#endif // NODOPILAS_H

