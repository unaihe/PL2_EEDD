#ifndef BOX_H
#define BOX_H
#include "Pasajero.h"
#include "Cola.h"

class Box
{
    public:
        Box();
        Box(int id);
        virtual ~Box();
        void asignar_pasajero(Pasajero p);
        void liberar_box();
        bool esta_libre();
        void actualizar_tiempo(int minutos);
        void mostrar();
        Pasajero getPasajero();
        int getTiempoRestante();
        void disminuirTiempo();
        void mostrarColaEspera();
        int getId();
        int numeroPasajeros();
        Cola getColaPasajeros();
        bool hayPasajerosAtendidos();
    private:
        int id;
        bool ocupado=false;
        Pasajero pasajero;
        int tiempo_restante;
        Cola colaPasajeros;

};

#endif // BOX_H
