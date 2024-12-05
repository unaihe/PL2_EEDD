#ifndef ABB_H
#define ABB_H
#include "NodoABB.h"


class ABB
{
    public:
        ABB();
        ABB(NodoABB *r);
        ABB(string pais, NodoABB *hIz=NULL, NodoABB *hDer=NULL);
        virtual ~ABB();
        void verInOrden();
        void verInOrden(NodoABB *arb);


       // void verInOrdenABB();
        void insertar(string pais, Pasajero pasajero);
        void insertar(string pais, Pasajero pasajero, NodoABB*& nodo);
        void mostrarArbol();
        void mostrarArbol(NodoABB* nodo);



    protected:

    private:
        NodoABB *raiz;
};

#endif // ABB_H

