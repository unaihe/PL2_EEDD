#ifndef NODOABB_H
#define NODOABB_H
#include <iostream>
#include <stdio.h>
#include "ListaPasajeros.h"

using namespace std;
class NodoABB
{
    friend class ABB;

    public:
        NodoABB(string pais, NodoABB *izq=NULL, NodoABB *der=NULL);
        virtual ~NodoABB();
        void verNombre();



    private:
        string pais;
        ListaPasajeros listaPasajeros;
        NodoABB *hi, *hd;
};

#endif // NODOABB_H
