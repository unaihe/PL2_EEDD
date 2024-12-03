#ifndef PASAJERO_H
#define PASAJERO_H


class Pasajero
{
    public:

        Pasajero();
        Pasajero(int id,int hora_llegada,int duracion_control, const char* destino, int prioridad);
        ~Pasajero();

        int getId() const;
        int getHora_llegada() const;
        int getDuracion_control() const;
        const char* getDestino() const;
        int getPrioridad() const;
        void mostrarPasajero(const Pasajero& pasajero);


    private:
        int id;
        int hora_llegada;
        int duracion_control;
        const char* destino;
        int prioridad;
};

#endif // PASAJERO_H
