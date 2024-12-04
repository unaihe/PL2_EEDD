#include "NodoColas.h"
NodoColas::NodoColas()
{
    elemento=Persona();
    siguiente=NULL;
//constructor por defecto
}
NodoColas::NodoColas(Persona per, NodoColas*sig )
{
    elemento = per;
    siguiente = sig;
}
NodoColas::~NodoColas()
{
//dtor
}
