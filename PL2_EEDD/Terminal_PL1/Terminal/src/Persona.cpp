#include "Persona.h"
#include "iostream"
#include <cstring>
using namespace std;

Persona::Persona()
{
    //ctor
}
Persona::Persona(int i,int hl, int d, int p,const char* pa)
{
    //ctor
    ident=i;
    horaLleg=hl;
    duracion=d;
    prioridad=p;
    strncpy(pais, pa, sizeof(pais) - 1);
    pais[sizeof(pais) - 1] = '\0';
}
Persona::~Persona()
{
    //dtor
}
void Persona::mostrarPersona()
{
    cout << "El pasajero: "<<ident<< " con destino: "<<pais<<" (Prioridad "<<prioridad<<"). [Duración aduanas: "<<duracion<<"]."<< endl;
}
int Persona::getDuracion()
{
    return duracion;
}
int Persona::getPrioridad()
{
    return prioridad;
}
int Persona::getHoraLLega()
{
    return horaLleg;
}
void Persona::setHoraLleg(int n)
{
    horaLleg=n;
}
void Persona::setHoraSal(int n)
{
    tCola=n;
}
void Persona::setIdentBox(int n)
{
    identBox=n;
}
int Persona::getId()
{
    return ident;
}
void Persona::setCola(int n)
{
    tCola=n;
}
int Persona::getCola()
{
    return tCola;
}
