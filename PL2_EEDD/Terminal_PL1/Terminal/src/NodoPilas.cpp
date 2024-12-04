#include "NodoPilas.h"
NodoPilas::NodoPilas()
{
valor=Persona();
siguiente=NULL;
//ctor
}
NodoPilas::NodoPilas(Persona per, NodoPilas *sig)
{
valor = per;
siguiente = sig;
}
NodoPilas::~NodoPilas()
{
//dtor
}
