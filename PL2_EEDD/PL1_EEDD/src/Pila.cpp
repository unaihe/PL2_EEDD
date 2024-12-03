#include "Pila.h"
#include "NodoPila.h"
#include <cstddef>
#include "Pasajero.h"
#include <iostream>

Pila::Pila()
{cima = nullptr;
    //ctor
}

Pila::~Pila()
{
    //dtor
}
bool Pila::esVacia(){
return cima==NULL;}

void Pila::apilar(Pasajero p) {
    NodoPila* nuevo = new NodoPila();
    nuevo->p = p;
    nuevo->siguiente = cima;
    cima = nuevo;
}


void Pila::borrarPila() {
    while (cima != nullptr) {
        NodoPila* temp = cima;
        cima = cima->siguiente;
        delete temp;
    }
    std::cout << "Pila vaciada." << std::endl;
}
void Pila::invertirPila() {
    Pila pilaTemp;
    while (!esVacia()) {
        Pasajero p = obtenerCima();
        pilaTemp.apilar(p);
        desapilar();
    }


    while (!pilaTemp.esVacia()) {
        Pasajero p = pilaTemp.obtenerCima();
        apilar(p);
        pilaTemp.desapilar();
    }
}



void Pila::desapilar(){
NodoPila* nodo;
if (cima)
    nodo = cima;
    cima = nodo->siguiente;
    delete nodo;
}
void Pila::mostrarPila(){
    NodoPila* temp = cima;
    while (temp != nullptr) {
        std::cout << "ID Pasajero: " << temp->p.getId() << std::endl;
        std::cout << "Hora de Llegada: " << temp->p.getHora_llegada() << " minutos" << std::endl;
        std::cout << "Duracion del Control: " << temp->p.getDuracion_control() << " minutos" << std::endl;
        std::cout << "Pais de Destino: " << temp->p.getDestino() << std::endl;
        std::cout << "Prioridad: " << temp->p.getPrioridad() << std::endl;
        std::cout << "-----------------------------" << std::endl;
        temp = temp->siguiente;
    }
}

    Pasajero Pila::obtenerCima() {
        if (esVacia()) {
            throw std::out_of_range("La pila está vacía. No hay pasajeros en la cima.");
        }
        return cima->p;
    }



