#ifndef NODOCOLAS_H
#define NODOCOLAS_H
#include <iostream>
#include "Persona.h"
class NodoColas
{
    friend class Colas;
private:
    NodoColas *siguiente;
    Persona elemento;
public:
    NodoColas();
    NodoColas(Persona per, NodoColas*sig = NULL);
    ~NodoColas();
};
#endif
