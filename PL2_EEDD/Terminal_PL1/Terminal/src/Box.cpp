#include "Box.h"
#include <iostream>
using namespace std;
Box::Box()
{
    //ctor
}

Box::Box(int i)
{
    id=i;
    ocupado=false;
}
Box::~Box()
{
    //dtor
}
bool Box::estaVacio()
{
    return !ocupado;
}
void Box::setOcupado(bool oc)
{
    ocupado=oc;
}
void Box::asignarPasajero(Persona per)
{
    pasajero=per;
    pasajero.setIdentBox(id);
    setOcupado(true);
    tiempoRestante=per.getDuracion();
}
bool Box::atender()
{
    if(!estaVacio())
    {
        tiempoRestante --;
        if(tiempoRestante == 0)
        {
            setOcupado(false);
            pasajero.mostrarPersona();
            cout<< " salió del Aeropuerto."<<endl;
            return true;
        }
    }
    return false;
}
void Box::mostrarBox()
{
    if (ocupado)
    {
        cout<<"[Box "<<id<<"]- Pasajero con id"<<pasajero.getId()<<". Tiempo restante:" << tiempoRestante<<" min."<<endl;
    }
    else
    {
        cout<<"[Box "<<id<<"]- Box vacio"<<endl;
    }
    colaPas.mostrarCola();
}
int Box::getTiempo()
{
    return pasajero.getCola();
}
Persona Box::getPasajero()
{
    return pasajero;
}
bool Box::colaVacia(){
    return colaPas.es_vacia();
}
Colas Box::getCola()
{
    return colaPas;
}

void Box::comprobarCola(int t)
{
    bool aux=true;
    while (colaPas.get_longitud()!=0 && aux)
    {
        Persona per=colaPas.desencolar();
        if (ocupado)
        {
            colaPas.encolarPrioridad(per);
            aux=false;
        }
        else
        {

            asignarPasajero(per);
            per.setCola(t-per.getHoraLLega()+per.getDuracion());
            per.mostrarPersona();
            cout<<"Entro en el box."<<endl;
        }
    }
}
void Box::encol(Persona per)
{
    colaPas.encolarPrioridad(per);
}
