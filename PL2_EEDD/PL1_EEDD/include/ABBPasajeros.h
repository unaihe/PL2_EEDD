#ifndef ABBPASAJEROS_H
#define ABBPASAJEROS_H
#include "NodoABB.h"

class ABBPasajeros
{
    public:
        ABBPasajeros();
        ABBPasajeros(NodoABB *r);
        ABBPasajeros(string nom, NodoABB *hIz=NULL, NodoABB *hDer=NULL);
        virtual ~ABBPasajeros();
        void verInOrden();
        void verInOrden(NodoABB *arb);
        void insertar(string nom);
        void insertar(string nom, NodoABB *nodo);

    private:
        NodoABB *raiz;
};

#endif // ABBPASAJEROS_H
