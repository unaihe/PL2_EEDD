#ifndef LISTA_H
#define LISTA_H
#include "Box.h"
#include "NodoLista.h"


class Lista
{
    public:
        Lista();
        virtual ~Lista();

        void agregarBox(Box b);
        void eliminarCabeza();
        void eliminarEspecifico(Box b);
        void mostrarEstadoBox();
        bool esVacia();
        Box boxMenosPasajeros();
        Box boxMasOcupado();
        void eliminarVacios();
        int numeroBoxes();
        NodoLista* getCabeza();
        bool hayPasajerosAtendidos();

    private:
        NodoLista* cabeza;
};

#endif // LISTA_H
