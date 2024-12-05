#ifndef LISTAPASAJEROS_H
#define LISTAPASAJEROS_H
#include "Pasajero.h"
#include "NodoListaPasajeros.h"
class ListaPasajeros
{
    public:
        ListaPasajeros();
        virtual ~ListaPasajeros();

        void agregarPasajero(Pasajero p);


        void eliminarCabeza();
        bool esVacia();

        // Mostrar todos los pasajeros en la lista
        void mostrarPasajeros();

        // Obtener la cabeza de la lista (primer nodo)
        NodoListaPasajeros* getCabeza();
        int getLongitud() const;

    private:
        NodoListaPasajeros* cabeza;
};

#endif // LISTAPASAJEROS_H
