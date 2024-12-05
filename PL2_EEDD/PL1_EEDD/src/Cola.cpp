#include "Cola.h"
#include "Pasajero.h"
using namespace std;
#include <iostream>


Cola::Cola(): longitud(0)
{
    //ctor
    primero = nullptr;
    ultimo = nullptr;
}

Cola::~Cola()
{
    //dtor
}

void Cola::encolar(const Pasajero& p) {
    NodoCola* nuevo_nodo = new NodoCola(p);

    if (es_vacia()) {
        primero = nuevo_nodo;
        ultimo = nuevo_nodo;
    } else {
        ultimo->siguiente = nuevo_nodo;
        ultimo = nuevo_nodo;
    }

    longitud++;

    ordenarCola();
}


Pasajero Cola::desencolar()
{ if(!es_vacia())
{ Pasajero p = primero->p;
NodoCola *aux = primero;
if((primero == ultimo) && (primero->siguiente == NULL))
{ primero = NULL;
ultimo = NULL;
aux->siguiente = NULL;
delete(aux);
}
else
{ primero = primero->siguiente;
aux->siguiente = NULL;
delete(aux);
}
longitud--;
return p;
}
}
Pasajero Cola::inicio()
{ if(!es_vacia())
{ return primero->p;
}
}
Pasajero Cola::fin()
{ if(!es_vacia())
{ return ultimo->p;
}
}

bool Cola::es_vacia()
{ return ((primero == NULL) && (ultimo ==
NULL));
}
void Cola::ordenarCola(){
    if (es_vacia() || primero == ultimo)
        return;
    bool intercambio;
    do {
        intercambio = false;
        NodoCola *actual = primero;

        while (actual->siguiente != nullptr) {
            if (actual->p.getPrioridad() < actual->siguiente->p.getPrioridad()) {
                Pasajero temp = actual->p;
                actual->p = actual->siguiente->p;
                actual->siguiente->p = temp;

                intercambio = true;
            }
            actual = actual->siguiente;
        }
    } while (intercambio);



}

    void Cola::mostrarCola() {
        if (es_vacia()) {
            std::cout << "La cola está vacía.\n";
            return;
        }
        NodoCola* temp = primero;
        while (temp != nullptr) {
            std::cout << "ID Pasajero: " << temp->p.getId() << ", Prioridad: " << temp->p.getPrioridad() << std::endl;
            temp = temp->siguiente;
        }
    }

int Cola::getLongitud(){
    return longitud;
}
