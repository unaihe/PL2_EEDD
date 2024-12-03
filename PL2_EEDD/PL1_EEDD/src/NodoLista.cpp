#include "NodoLista.h"
#include "Box.h"

NodoLista::NodoLista()
{
    //ctor
    siguiente=nullptr;
}

NodoLista::NodoLista(Box b)
{
    //ctor
    box=b;
    siguiente=nullptr;
}

NodoLista::~NodoLista()
{
    //dtor
}

Box& NodoLista::getBox() {
    return box;
}

NodoLista* NodoLista::getSiguiente() {
    return siguiente;
}

void NodoLista::setSiguiente(NodoLista* siguienteNodo) {
    siguiente = siguienteNodo;
}
