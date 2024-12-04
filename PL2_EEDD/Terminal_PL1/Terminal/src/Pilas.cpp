#include "Pilas.h"
#include "NodoPilas.h"
#include "iostream"
using namespace std;
Pilas::Pilas()
{
    cima = NULL;
    longitud=0;
}
Pilas::~Pilas()
{
    while(cima) desapilar();
}
bool Pilas::esVacia()
{
    return cima == NULL;
}
void Pilas::apilar(Persona per)
{
    pnodo nuevo = new NodoPilas(per,cima);
//comienzo de la pila nevo nodo
    cima = nuevo;
}
void Pilas::desapilar()
{
    pnodo nodo; //puntero aux para manipular el nodo
    if(cima)
        nodo = cima;
    cima = nodo->siguiente;
    delete nodo;
    longitud--;
}
int Pilas::mostrar()
{
    if(esVacia())
    {
        cout << "Pila vacia"<<endl;
    }
    else
    {
        cout << "Cima pila: "<<endl;
    }
    return 0;
}
 void Pilas::apilarmenormayor(Persona per)
{
    if (esVacia())
    {
        apilar(per);
    }
    else if (per.getHoraLLega() <=(cima->valor).getHoraLLega())
    {
        apilar(per);
    }
    else
    {
        Persona cimap=cima->valor;
        desapilar();
        apilarmenormayor(per);
        apilar(cimap);
    }
    longitud++;
}
pnodo Pilas::getCima()
{
    return cima;
}
void Pilas::borrarDatos()
{
    while(cima) desapilar();
}
int Pilas::getLongitud()
{
    return longitud;
}

