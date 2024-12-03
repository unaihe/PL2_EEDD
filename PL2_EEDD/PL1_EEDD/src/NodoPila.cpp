#include "NodoPila.h"

NodoPila::NodoPila()
{

    siguiente=NULL;
    //ctor
}

NodoPila::~NodoPila()
{
    //dtor
}
NodoPila::NodoPila(Pasajero p, NodoPila* sig)
{
    Pasajero pasajero= p;
    siguiente=sig;
    //ctor
}
