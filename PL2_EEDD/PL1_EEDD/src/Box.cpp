#include "Box.h"
#include <iostream>



Box::Box()
{
    //ctor
}

Box::Box(int id)
{
    //ctor
    this->id=id;
}

Box::~Box()
{
    //dtor
}

void Box::asignar_pasajero(Pasajero p) {
    if (!ocupado) {
        pasajero = p;
        tiempo_restante = p.getDuracion_control();
        ocupado = true;
        std::cout << "Pasajero " << p.getId() << " asignado al box " << id << ".\n";
    } else {
        std::cout << "Box " << id << " ocupado; encolando pasajero " << p.getId() << ".\n";
        colaPasajeros.encolar(p);
    }
}
void Box::liberar_box(int i) {
    if (ocupado) {
        pasajeros++;
        tiempoTotal+=i-pasajero.getHora_llegada();
        media=tiempoTotal/pasajeros;
        std::cout << "Liberando el box " << id << " ocupado por el pasajero " << pasajero.getId() << ".\n";
        ocupado = false;
        tiempo_restante = 0;
        pasajero = Pasajero();

        if (!colaPasajeros.es_vacia()) {
            asignar_pasajero(colaPasajeros.desencolar());
        }
    }
}
bool Box::esta_libre() {
    return !ocupado;
}
void Box::actualizar_tiempo(int minutos) {
    if (ocupado) {
        tiempo_restante -= minutos;


        if (tiempo_restante <= 0) {
            liberar_box(minutos);
            std::cout << "El pasajero ha salido del box " << id << "." << std::endl;
        }
    }
}
void Box::mostrar() {

    if (ocupado) {
        std::cout << "Estado: Ocupado" << std::endl;
        std::cout << "Id pasajero:" << pasajero.getId() << std::endl;
        std::cout << "Tiempo restante: " << tiempo_restante << " minutos" << std::endl;
    } else {
        std::cout << "El box está libre" << std::endl;
    }
}

Pasajero Box::getPasajero(){
    return pasajero;
}


int Box::getTiempoRestante(){
    return tiempo_restante;
}
void Box::disminuirTiempo(int i) {

    if (ocupado) {

        tiempo_restante--;


        if (tiempo_restante <= 0) {
            liberar_box(i);
            std::cout << "El pasajero ha terminado y el box " << id << " está libre.\n";
            std::cout << "La media de tiempo que pasan los pasajeros en este momento es de: " << media << " \n";
        }
    }
}

int Box::getId(){
    return id;
}

int Box::numeroPasajeros(){
    return colaPasajeros.getLongitud();
}

Cola Box::getColaPasajeros(){
    return colaPasajeros;
}

bool Box::hayPasajerosAtendidos()  {
        return ocupado;
    }


