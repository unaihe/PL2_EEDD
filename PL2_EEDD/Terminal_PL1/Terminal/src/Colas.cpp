#include "Colas.h"
#include "iostream"
using namespace std;
Colas::Colas()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}
Colas::~Colas() { }
void Colas::encolar(Persona per)
{
    NodoColas *nuevo_nodo = new NodoColas(per);
    if(es_vacia())
    {
        primero = nuevo_nodo;
        ultimo = nuevo_nodo;
    }
    else
    {
        ultimo->siguiente = nuevo_nodo;
        ultimo = nuevo_nodo;
    }
    longitud++;
}
Persona Colas::desencolar()
{
    if(!es_vacia())
    {
        Persona elemento = primero->elemento;
        NodoColas *aux = primero;
        if((primero == ultimo) && (primero->siguiente == NULL))
        {
            primero = NULL;
            ultimo = NULL;
            aux->siguiente = NULL;
            delete(aux);
        }
        else
        {
            primero = primero->siguiente;
            aux->siguiente = NULL;
            delete(aux);
        }
        longitud--;
        return elemento;
    }
}
Persona Colas::inicio()
{
    if(!es_vacia())
    {
        return primero->elemento;
    }
}
Persona Colas::fin()
{
    if(!es_vacia())
    {
        return ultimo->elemento;
    }
}
int Colas::get_longitud()
{
    return longitud;
}
bool Colas::es_vacia()
{
    return ((primero == NULL) && (ultimo ==
                                  NULL));
}
void Colas::mostrarCola()
//No es correcto,
{
    NodoColas *aux = primero;
    if (es_vacia())
    {
        cout<<"Cola Vacía: "<<endl;
    }
    else
    {
        cout<<"Datos de la Cola: "<<endl;

        while (aux)
        {
            Persona pers;
            pers=aux->elemento;
            pers.mostrarPersona();
            aux = aux->siguiente;
        }
    }
}
void Colas::concatenar(Colas c)
{
    while (!c.es_vacia())
    {
        encolar(c.inicio());
        c.desencolar();
    }
}
void Colas::encolarPrioridad(Persona per)
{
    int l=longitud;
    bool esta=true;
    Persona per1=inicio();
    // Si es vacia añade el elemento a la cola directamente
    if(es_vacia()) encolar(per);
    else
    {
        int l=longitud;
        bool esta=true;
        Persona per1=inicio();
        //Comprobamos todos los datos de la Cola
        while(l>0)
        {
            //En caso de que uno sea mayor se añade a la cola
            if (inicio().getPrioridad()>per.getPrioridad() && esta)
            {
                encolar(per);
                esta=false;
            }
            encolar(per1);
            desencolar();
            per1=inicio();
            l--;

        }
        //Si despues de recorrer la cola no se ha añadido la persona se añade después.
        if (esta)encolar(per);

    }
}
