#ifndef LISTAPASAJEROS_H
#define LISTAPASAJEROS_H
#include "Persona.h"
#include "NodoListaPasajero.h"

class ListaPasajeros
{
    public:
        ListaPasajeros();
        virtual ~ListaPasajeros();
        void agregarPasajero(Persona p);
        void eliminarCabeza();
        bool esVacia();
        // Mostrar todos los pasajeros en la lista
        void mostrarPasajeros();
        // Obtener la cabeza de la lista (primer nodo)
        NodoListaPasajero* getCabeza();
    private:
        NodoListaPasajero* cabeza;
};

#endif // LISTAPASAJEROS_H
