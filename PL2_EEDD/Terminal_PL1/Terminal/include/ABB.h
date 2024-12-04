#ifndef ABB_H
#define ABB_H
#include "NodoABB.h"


class ABB
{
    public:
        ABB();
        ABB(NodoABB *r);
        ABB(string nom, NodoABB *hIz=NULL, NodoABB *hDer=NULL);
        virtual ~ABB();
        void verInOrden();
        void verInOrden(NodoABB *arb);


       // void verInOrdenABB();
        void insertar(string nom);
        void insertar(string nom, NodoABB *nodo);


    protected:

    private:
        NodoABB *raiz;
};

#endif // ABB_H

