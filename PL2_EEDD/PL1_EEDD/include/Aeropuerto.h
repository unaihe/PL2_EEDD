#ifndef AEROPUERTO_H
#define AEROPUERTO_H
#include <vector>
#include "Cola.h"
#include "Pila.h"
#include "Box.h"
#include "Lista.h"


class Aeropuerto
{
    public:
        Aeropuerto();
        virtual ~Aeropuerto();
        void crearPila();
        void mostrarPila();
        void borrarPila();
        void mostrarColaMasYMenosLlena();
        void mostrarEstadoBoxes();
        void simularMinutos();
        void simularTiempo();
        bool boxesVacios();
        void eliminarBoxVacio();


    private:
        Pila pilaPasajeros;
        Lista listaBoxes;
        int tiempoTranscurrido;

};

#endif // AEROPUERTO_H
