#include "NodoABB.h"
#include "listaPasajeros.h"

NodoABB::NodoABB(string pais, NodoABB *izq, NodoABB *der)
{
    //ctor
    this->pais=pais;
    listaPasajeros=ListaPasajeros();
    hi=izq;
    hd=der;

}

NodoABB::~NodoABB()
{
    //dtor
}

void NodoABB::verNombre(){cout<<pais<<endl;}
