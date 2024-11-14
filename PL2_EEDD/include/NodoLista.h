#ifndef NODOLISTA_H
#define NODOLISTA_H
#include "Box.h"

class NodoLista
{
    public:
        NodoLista();
        NodoLista(Box b);
        virtual ~NodoLista();
        Box& getBox();
        NodoLista* getSiguiente();
        void setSiguiente(NodoLista* siguienteNod);



    private:
        Box box;
        NodoLista* siguiente;
};

#endif // NODOLISTA_H
