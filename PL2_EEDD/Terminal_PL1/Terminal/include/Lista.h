#ifndef LISTA_H
#define LISTA_H
#include "Box.h"
#include "Persona.h"
class Lista
{
    public:
        Lista();
        Lista(Box b);
        virtual ~Lista();
        void anadirLista(Box b);
        void anadirLista();
        void anadirListaDer(Box b);
        bool esVacia();
        bool llenarHueco(Persona per);
        Box elmtoLista(int n);
        bool todoLleno();
        int atenderPasajeros(int n);
        bool todoVacio();
        void mostrar();
        Box& menor();
        Box& operator[](int n);
        int getLongitud();
        bool boxNuevo();
        void comprobarColaMin(int t);
        void borrarBoxVac();
        Box* getPrimero();
        void mayor();

    protected:

    private:
        Box * primero;
        Box * ultimo;
        int longitud;
};

#endif // LISTA_H
