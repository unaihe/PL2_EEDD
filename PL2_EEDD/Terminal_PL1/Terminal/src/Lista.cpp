#include "Lista.h"
#include <iostream>
using namespace std;
Lista::Lista()
{
    //ctor
    primero = nullptr;
    longitud = 0;
}
Lista::Lista(Box b)
{
    //ctor
    Box *nuevo_nodo = new Box(b);
    primero=nuevo_nodo;
    longitud=1;

}

Lista::~Lista()
{
    //dtor
}

bool Lista::esVacia()
{
    return (primero == nullptr);
}
void Lista::anadirLista()
{
    Box *nuevo_nodo = new Box(longitud+1);
    if (esVacia())
    {

        primero=nuevo_nodo;
    }
    else
    {
        nuevo_nodo->siguiente=primero;
        primero=nuevo_nodo;
    }
    longitud++;
}
void Lista::anadirLista(Box b)
{
    Box *nuevo_nodo = new Box(b);
    if (esVacia())
    {

        primero=nuevo_nodo;
    }
    else
    {
        nuevo_nodo->siguiente=primero;
        primero=nuevo_nodo;
    }
    longitud++;
}
void Lista::anadirListaDer(Box b)
{
    Box* nuevoNodo = new Box(b);
    if (esVacia())
    {
        primero = nuevoNodo;
    }
    else
    {
        Box* temp = primero;
        while (temp->siguiente)
        {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
    longitud++;
}

bool Lista::llenarHueco(Persona per)
{
    Box* temp = primero;
    int contador = 1;
    while (contador<=longitud)
    {
        if (!(temp->ocupado))
        {
            temp->asignarPasajero(per);
            return true;
        }
        temp = temp->siguiente;
        contador++;
    }
    return false;
}
bool Lista::todoLleno()
{
    bool llen=true;
    Box* temp = primero;
    int contador=1;
    while (contador<=longitud)
    {
        if (!(temp->ocupado))
        {
            llen=false;
        }
        temp = temp->siguiente;
        contador++;
    }
    return llen;
}
bool Lista::todoVacio()
{
    bool llen=true;
    Box* temp = primero;
    int contador=1;
    while (contador<=longitud)
    {
        if (temp->ocupado)
        {
            llen=false;
        }
        temp = temp->siguiente;
        contador++;
    }
    return llen;
}
int Lista::atenderPasajeros(int t)
{
    /*if(box1.atender()){
        tTot+=tiempo-box1.getPasajero().getHoraLLega();
        pasajeros++;
    }*/
    Box* temp = primero;
    int contador=1,i=0;
    while (contador<=longitud)
    {
        if (temp->atender())
        {
            i+=t-temp->pasajero.getHoraLLega();
        }
        temp = temp->siguiente;
        contador++;
    }
    return i;
}
void Lista::mostrar()
{
    Box* temp = primero;
    int contador=1;
    while (contador<=longitud)
    {
        temp->mostrarBox();
        temp = temp->siguiente;
        contador++;
    }
}
Box& Lista::menor()
{
    Box* temp = primero;
    Box* menor = primero; // El puntero menor apunta al primer elemento.

    while (temp)
    {
        if (temp->getCola().get_longitud() < menor->getCola().get_longitud())
        {
            menor = temp; // Actualizamos el puntero para apuntar al elemento con menor longitud.
        }
        temp = temp->siguiente; // Avanzamos al siguiente nodo.
    }

    return *menor; // Devolvemos la referencia al objeto al que apunta menor.
}
Box Lista::elmtoLista(int n)
{
    Box* temp = primero;
    int contador=1;
    while (contador!=n)
    {
        temp = temp->siguiente;
        contador++;
    }
    Box a=*temp;
    return a;
}
Box& Lista::operator[](int n)
{
    Box* temp = primero;
    for (int i = 0; i < n; ++i)
    {
        temp = temp->siguiente;
    }

    return *temp;
}
int Lista::getLongitud()
{
    return longitud;
}
bool Lista::boxNuevo()
{
    Box* temp = primero;
    while (temp)
    {
        if (temp->getCola().get_longitud() < 2)
        {
            return false;
        }
        temp = temp->siguiente;
    }
    return true;
}
void Lista::comprobarColaMin(int t)
{
    Box* temp = primero;
    int contador=1;
    while (contador<=longitud)
    {
        if (!(temp->getCola().es_vacia()))
        {
            temp->comprobarCola(t);
        }
        temp = temp->siguiente;
        contador++;
    }
    borrarBoxVac();
}
void Lista::borrarBoxVac()
{
    Box* temp1 = primero;
    int contador=1,n=0;
    while (contador<=longitud)
    {
        if (temp1->estaVacio())
        {
            n++;
        }
        temp1 = temp1->siguiente;
        contador++;
    }
    Box* temp = primero;
    Box* anterior = nullptr;
    if (n>=2)
    {
        while (temp&&longitud!=1&&contador!=1)
        {
            temp->mostrarBox();
            if (temp->estaVacio())
            {
                if (anterior == nullptr)
                {
                    primero = temp->siguiente;
                    temp = primero;
                }
                else
                {
                    anterior->siguiente = temp->siguiente;
                    temp = anterior->siguiente;
                }
                longitud--;
            }
            else
            {
                anterior = temp;
                temp = temp->siguiente;
            }
            contador--;
        }
    }
}
Box* Lista::getPrimero()
{
    return primero;
}
void Lista::mayor()
{

    Box* mayor = primero;
    int mayorPasajeros = mayor->getCola().get_longitud();
    int contador=1;
    Box* temp = primero;
    while (contador<=longitud)
    {
        if (temp->getCola().get_longitud() > mayorPasajeros)
        {
            mayor = temp;
            mayorPasajeros = temp->getCola().get_longitud();
        }
        temp = temp->siguiente;
        contador++;
    }

    cout << "- El Box más ocupado es:";
    mayor->mostrarBox();
    cout<< " con " << mayorPasajeros << " pasajeros." << endl;

}
