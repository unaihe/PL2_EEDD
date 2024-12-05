#include "ABB.h"
#include "NodoABB.h"

ABB::ABB() //crea �rbol vac�o
{
    //ctor
    raiz=NULL;
}
ABB::ABB(NodoABB *r)
{
    raiz=r;

}
ABB::ABB(string nom, NodoABB *hIz, NodoABB *hDer)//constructor que crea �rbolBin con dato y dos sub�rboles
{
    raiz= new NodoABB(nom, hIz, hDer);//llamamos al constructor del Nodo y raiz es un puntero al Nodo creado

}

ABB::~ABB()
{
    //dtor
}


void ABB::verInOrden() { verInOrden(raiz);}
void ABB::verInOrden(NodoABB *arb)// M�todo para ver Arbol empezando por su izquirda, despu�s pasamos por la raiz y por ultimo por la rama derecha
{
    if (arb) {
       verInOrden(arb->hi);//Recursion para la rama izquierda
       cout<< arb->pais<<endl;//Mostrar nombre
        verInOrden(arb->hd);// Recursion para la rama derecha
    }
}
/*void ABB::verInOrdenABB()// M�todo para ver Arbol en inorden sin tener que pasar puntero, resulta farragoso crear objetos cada vez...
{
    if (raiz) {
            ABB hijoIz(raiz->hi);hijoIz.verInOrden();//Recursion para la rama izquierda
        raiz->cliente.verDatos();//Mostrar datos del cliente
        ABB hijoDer(raiz->hd);hijoDer.verInOrden();// Recursion para la rama derecha
    }
}*/
void ABB::mostrarArbol() {
    mostrarArbol(raiz);
}

void ABB::mostrarArbol(NodoABB* nodo) {
    if (nodo != nullptr) {
        mostrarArbol(nodo->hi); // Recursi�n izquierda

        // Mostrar el pa�s y la lista de pasajeros
        cout << "Pa�s: " << nodo->pais << endl;
        cout << "Pasajeros:" << endl;
        nodo->listaPasajeros.mostrarPasajeros();

        mostrarArbol(nodo->hd); // Recursi�n derecha
    }
}

void ABB::insertar(string pais, Pasajero pasajero) {
    insertar(pais, pasajero, raiz);
}

void ABB::insertar(string pais, Pasajero pasajero, NodoABB*& nodo) {
    if (nodo == nullptr) {
        cout << "Creando nuevo nodo para el pa�s: " << pais << endl;
        nodo = new NodoABB(pais);
        nodo->listaPasajeros.agregarPasajero(pasajero); // Agregar pasajero
    } else if (pais < nodo->pais) {
        cout << "El pa�s " << pais << " es menor que " << nodo->pais << ". Insertando a la izquierda." << endl;
        insertar(pais, pasajero, nodo->hi);
    } else if (pais > nodo->pais) {
        cout << "El pa�s " << pais << " es mayor que " << nodo->pais << ". Insertando a la derecha." << endl;
        insertar(pais, pasajero, nodo->hd);
    } else {
        cout << "El pa�s " << pais << " ya existe. Agregando pasajero a la lista." << endl;
        nodo->listaPasajeros.agregarPasajero(pasajero);
    }
}


