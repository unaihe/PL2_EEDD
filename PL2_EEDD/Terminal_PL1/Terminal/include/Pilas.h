#ifndef PILAS_H
#define PILAS_H
#include "NodoPilas.h"
class Pilas
{
private:
    pnodo cima;
    int longitud=0;
public:
    Pilas();
    ~Pilas();
    bool esVacia();
    void apilar(Persona per);
    void desapilar();
    int mostrar();
    void apilarmenormayor(Persona per);
    pnodo getCima();
    void borrarDatos();
    int getLongitud();
};
#endif // PILAS_H

