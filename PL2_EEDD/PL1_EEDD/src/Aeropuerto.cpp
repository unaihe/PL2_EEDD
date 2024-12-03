#include "Aeropuerto.h"
#include "Pasajero.h"
using namespace std;
#include <iostream>
#include "Box.h"


Aeropuerto::Aeropuerto()
{
    //ctor
    tiempoTranscurrido=0;
    listaBoxes.agregarBox(Box(1));
}

Aeropuerto::~Aeropuerto()
{
    //dtor
}

void Aeropuerto::eliminarBoxVacio() {
    if (listaBoxes.numeroBoxes() > 1) {
        listaBoxes.eliminarVacios();
    }
}
void Aeropuerto::mostrarEstadoBoxes() {
    std::cout << "Estado de todos los boxes:\n";
    listaBoxes.mostrarEstadoBox();
}


void Aeropuerto::crearPila()
{

    Pasajero pa1(1, 0, 10, "Indonesia", 6);
    Pasajero pa2(2, 0, 15, "Portugal", 1);
    Pasajero pa3(3, 5, 29, "Australia", 7);
    Pasajero pa4(4, 7, 8, "Sudáfrica", 5);
    Pasajero pa5(5, 9, 16, "Australia", 7);
    Pasajero pa6(6, 9, 13, "Indonesia", 6);
    Pasajero pa7(7, 10, 10, "Indonesia", 6);
    Pasajero pa8(8, 10, 15, "Portugal", 1);
    Pasajero pa9(9, 15, 29, "Australia", 7);
    Pasajero pa10(10, 17, 8, "Sudáfrica", 5);
    Pasajero pa11(11, 19, 16, "Australia", 7);







    pilaPasajeros.apilar(pa11);
    pilaPasajeros.apilar(pa10);
    pilaPasajeros.apilar(pa9);
    pilaPasajeros.apilar(pa8);
    pilaPasajeros.apilar(pa7);
    pilaPasajeros.apilar(pa6);
    pilaPasajeros.apilar(pa5);
    pilaPasajeros.apilar(pa4);
    pilaPasajeros.apilar(pa3);
    pilaPasajeros.apilar(pa2);
    pilaPasajeros.apilar(pa1);

}

void Aeropuerto::mostrarPila()
{
    pilaPasajeros.mostrarPila();
}

void Aeropuerto::borrarPila()
{
    pilaPasajeros.borrarPila();
}
void Aeropuerto::mostrarColaMasYMenosLlena() {
    if (listaBoxes.getCabeza() == nullptr) {
        std::cout << "No hay boxes disponibles para mostrar.\n";
        return;
    }

    NodoLista* boxMasLleno = listaBoxes.getCabeza();
    NodoLista* boxMenosLleno = listaBoxes.getCabeza();

    for (NodoLista* temp = listaBoxes.getCabeza(); temp != nullptr; temp = temp->getSiguiente()) {
        Box& boxActual = temp->getBox();
        int longitudColaActual = boxActual.getColaPasajeros().getLongitud();


        if (longitudColaActual > boxMasLleno->getBox().getColaPasajeros().getLongitud()) {
            boxMasLleno = temp;
        }


        if (longitudColaActual < boxMenosLleno->getBox().getColaPasajeros().getLongitud()) {
            boxMenosLleno = temp;
        }
    }

    std::cout << "Box con la cola más llena: Box " << boxMasLleno->getBox().getId()
              << " con " << boxMasLleno->getBox().getColaPasajeros().getLongitud() << " pasajeros.\n";

    std::cout << "Box con la cola menos llena: Box " << boxMenosLleno->getBox().getId()
              << " con " << boxMenosLleno->getBox().getColaPasajeros().getLongitud() << " pasajeros.\n";
}


void Aeropuerto::simularMinutos() {
    int minutos;
    std::cout << "Ingrese el número de minutos a simular: ";
    std::cin >> minutos;

    for (int tiempoActual = 0; tiempoActual < minutos; ++tiempoActual) {
        std::cout << "Minuto " << tiempoTranscurrido + tiempoActual + 1 << ":\n";


        for (NodoLista* temp = listaBoxes.getCabeza(); temp != nullptr; temp = temp->getSiguiente()) {
            temp->getBox().disminuirTiempo(tiempoActual);
        }


        while (!pilaPasajeros.esVacia() && pilaPasajeros.obtenerCima().getHora_llegada() <= tiempoTranscurrido + tiempoActual) {
            Pasajero proxPasajero = pilaPasajeros.obtenerCima();
            std::cout << "El pasajero " << proxPasajero.getId() << " ha llegado al aeropuerto.\n";
            pilaPasajeros.desapilar();


            NodoLista* boxConMenosPasajeros = nullptr;
            for (NodoLista* temp = listaBoxes.getCabeza(); temp != nullptr; temp = temp->getSiguiente()) {
                Box& boxActual = temp->getBox();
                if (boxActual.getColaPasajeros().getLongitud() < 2) {
                    if (!boxConMenosPasajeros ||
                        boxActual.getColaPasajeros().getLongitud() < boxConMenosPasajeros->getBox().getColaPasajeros().getLongitud()) {
                        boxConMenosPasajeros = temp;
                    }
                }
            }


            if (boxConMenosPasajeros) {
                std::cout << "Asignando pasajero " << proxPasajero.getId() << " al box "
                          << boxConMenosPasajeros->getBox().getId() << ".\n";
                boxConMenosPasajeros->getBox().asignar_pasajero(proxPasajero);
            } else {
                std::cout << "Todos los boxes están llenos. Pasajero " << proxPasajero.getId() << " no puede ser atendido.\n";
            }
        }


        for (NodoLista* temp = listaBoxes.getCabeza(); temp != nullptr; temp = temp->getSiguiente()) {
            Box& boxActual = temp->getBox();
            if (boxActual.esta_libre() && !boxActual.getColaPasajeros().es_vacia()) {
                Pasajero siguientePasajero = boxActual.getColaPasajeros().desencolar();
                std::cout << "Pasajero " << siguientePasajero.getId() << " asignado al box " << boxActual.getId() << ".\n";
                boxActual.asignar_pasajero(siguientePasajero);
            }
        }


        for (NodoLista* temp = listaBoxes.getCabeza(); temp != nullptr; temp = temp->getSiguiente()) {
            std::cout << "Box " << temp->getBox().getId() << ":\n";
            temp->getBox().mostrar();
        }

        std::cout << "---------------------------------------\n";


        listaBoxes.eliminarVacios();


        bool todosOcupados = true;
        for (NodoLista* temp = listaBoxes.getCabeza(); temp != nullptr; temp = temp->getSiguiente()) {
            Box& boxActual = temp->getBox();
            if (boxActual.esta_libre() || boxActual.getColaPasajeros().getLongitud() < 2) {
                todosOcupados = false;
                break;
            }
        }


        if (todosOcupados) {
            int nuevoId = listaBoxes.numeroBoxes() + 1;
            Box nuevoBox(nuevoId);
            listaBoxes.agregarBox(nuevoBox);
            std::cout << "Todos los boxes están ocupados. Se ha creado un nuevo box con ID " << nuevoId << ".\n";
        }
    }

    tiempoTranscurrido += minutos;
    std::cout << "Simulación de " << minutos << " minutos completada.\n";
}


void Aeropuerto::simularTiempo() {
    std::cout << "Iniciando la simulación hasta que todos los pasajeros hayan sido atendidos...\n";

    int tiempoActual = 0;


    while (!pilaPasajeros.esVacia() || listaBoxes.hayPasajerosAtendidos()) {
        std::cout << "Minuto " << tiempoActual + 1 << ":\n";


        for (NodoLista* temp = listaBoxes.getCabeza(); temp != nullptr; temp = temp->getSiguiente()) {
            temp->getBox().disminuirTiempo(tiempoActual);
        }


        while (!pilaPasajeros.esVacia() && pilaPasajeros.obtenerCima().getHora_llegada() <= tiempoActual) {
            Pasajero proxPasajero = pilaPasajeros.obtenerCima();
            std::cout << "El pasajero " << proxPasajero.getId() << " ha llegado al aeropuerto.\n";
            pilaPasajeros.desapilar();


            NodoLista* boxConMenosPasajeros = nullptr;
            for (NodoLista* temp = listaBoxes.getCabeza(); temp != nullptr; temp = temp->getSiguiente()) {
                Box& boxActual = temp->getBox();

                if (boxActual.getColaPasajeros().getLongitud() < 2) {

                    if (!boxConMenosPasajeros ||
                        boxActual.getColaPasajeros().getLongitud() < boxConMenosPasajeros->getBox().getColaPasajeros().getLongitud()) {
                        boxConMenosPasajeros = temp;
                    }
                }
            }


            if (boxConMenosPasajeros) {
                std::cout << "Asignando pasajero " << proxPasajero.getId() << " al box " << boxConMenosPasajeros->getBox().getId() << ".\n";
                boxConMenosPasajeros->getBox().asignar_pasajero(proxPasajero);
            } else {
                std::cout << "Todos los boxes están llenos. Pasajero " << proxPasajero.getId() << " no puede ser atendido.\n";
            }
        }


        for (NodoLista* temp = listaBoxes.getCabeza(); temp != nullptr; temp = temp->getSiguiente()) {
            Box& boxActual = temp->getBox();

            if (boxActual.esta_libre() && !boxActual.getColaPasajeros().es_vacia()) {
                Pasajero siguientePasajero = boxActual.getColaPasajeros().desencolar();
                std::cout << "Pasajero " << siguientePasajero.getId() << " asignado al box " << boxActual.getId() << ".\n";
                boxActual.asignar_pasajero(siguientePasajero);
            }
        }


        for (NodoLista* temp = listaBoxes.getCabeza(); temp != nullptr; temp = temp->getSiguiente()) {
            std::cout << "Box " << temp->getBox().getId() << ":\n";
            temp->getBox().mostrar();
        }

        std::cout << "---------------------------------------\n";


        listaBoxes.eliminarVacios();


        bool todosOcupados = true;
        for (NodoLista* temp = listaBoxes.getCabeza(); temp != nullptr; temp = temp->getSiguiente()) {
            Box& boxActual = temp->getBox();
            if (boxActual.esta_libre() || boxActual.getColaPasajeros().getLongitud() < 2) {
                todosOcupados = false;
                break;
            }
        }


        if (todosOcupados) {
            int nuevoId = listaBoxes.numeroBoxes() + 1;
            Box nuevoBox(nuevoId);
            listaBoxes.agregarBox(nuevoBox);
            std::cout << "Todos los boxes están ocupados. Se ha creado un nuevo box con ID " << nuevoId << ".\n";
        }

        tiempoActual++;
    }

    std::cout << "Simulación completada. Todos los pasajeros han sido atendidos.\n";
}
