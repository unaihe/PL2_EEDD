#ifndef BOX_H
#define BOX_H
#include "Persona.h"
#include "Colas.h"

class Box
{
    friend class Lista;
    public:
        Box();
        Box(int id);
        virtual ~Box();
        bool estaVacio();
        void asignarPasajero(Persona per);
        bool atender();
        void setOcupado(bool oc);
        void mostrarBox();
        int getTiempo();
        Persona getPasajero();
        Colas getCola();
        bool colaVacia();
        void comprobarCola(int t);
        void encol(Persona per);

    protected:

    private:
        Box *siguiente;
        bool ocupado;
        Persona pasajero;
        int id;
        int tiempoRestante;
        Colas colaPas=Colas();
};

#endif // BOX_H
