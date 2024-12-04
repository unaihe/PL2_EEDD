#ifndef COLAS_H
#define COLAS_H
#include "NodoColas.h"
#include "Persona.h"
class Colas
{
private:
    NodoColas * primero;
    NodoColas * ultimo;
    int longitud;
public:
    Colas();
    ~Colas();
    void encolar(Persona per);
    Persona inicio();
    Persona fin();
    Persona desencolar();
    bool es_vacia();
    int get_longitud();
    void concatenar(Colas c);
    void encolarPrioridad(Persona per);
    void mostrarCola(); //No es correcto
};
#endif // COLA_H
