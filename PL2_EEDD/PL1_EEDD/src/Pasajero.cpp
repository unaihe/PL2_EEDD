#include "Pasajero.h"
#include <iostream>

Pasajero::Pasajero()
{
    //ctor
}

Pasajero::Pasajero(int id,int hora_llegada,int duracion_control, const char* destino, int prioridad)
{
    this->id=id;
    this->hora_llegada=hora_llegada;
    this->duracion_control=duracion_control;
    this->destino=destino;
    this->prioridad=prioridad;
    this->tiempoFinal=0;
    this->tiempoAeropuerto=0;
}

Pasajero::~Pasajero()
{
    //dtor
}

void Pasajero::setTiempoFinal(int i)
{
    this->tiempoFinal=i;
};

int Pasajero::getId() const
{
    return id;
};

int Pasajero::getHora_llegada() const
{
    return hora_llegada;
};

int Pasajero::getDuracion_control() const
{
    return duracion_control;
};

const char* Pasajero::getDestino() const
{
    return destino;
};

int Pasajero::getPrioridad() const
{
    return prioridad;
};
// Función para mostrar los detalles de un pasajero
void Pasajero::mostrarPasajero(const Pasajero& pasajero) {
    std::cout << "ID Pasajero: " << pasajero.getId() << std::endl;
    std::cout << "Hora de llegada: " << pasajero.getHora_llegada() << " minutos" << std::endl;
    std::cout << "Duración del control: " << pasajero.getDuracion_control() << " minutos" << std::endl;
    std::cout << "País de destino: " << pasajero.getDestino() << std::endl;
    std::cout << "Prioridad: " << pasajero.getPrioridad() << std::endl;
    std::cout << "-------------------------------" << std::endl;
}
