#include "NodoCola.h"
#include "Pasajero.h"

NodoCola::NodoCola()
{

    siguiente = NULL;

    //ctor
}
NodoCola::NodoCola(Pasajero p, NodoCola *sig)
{
    this->p = p;
    siguiente = sig;
}


NodoCola::~NodoCola()
{
    //dtor
}
