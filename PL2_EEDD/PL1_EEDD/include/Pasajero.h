#ifndef PASAJERO_H
#define PASAJERO_H
#include <string>

class Pasajero
{
    public:

        Pasajero();
        Pasajero(int id,int hora_llegada,int duracion_control, std::string pais, int prioridad);
        ~Pasajero();

        int getId() const;
        int getHora_llegada() const;
        int getDuracion_control() const;
        std::string getPais() const;
        int getPrioridad() const;
        void setTiempoFinal(int i);
        int getTiempoFinal();
        void mostrarPasajero(const Pasajero& pasajero);


    private:
        int tiempoAeropuerto;
        int id;
        int hora_llegada;
        int duracion_control;
        std::string pais;
        int prioridad;
        int tiempoFinal;

};

#endif // PASAJERO_H
