#ifndef NODOLISTA_H
#define NODOLISTA_H
#include <iostream>
#include "Box.h"
class NodoLista
{
    friend class Lista;
private:
    NodoLista *siguiente;
    Box valor;
public:
    NodoLista(Box b);
    ~NodoLista();
};
#endif
