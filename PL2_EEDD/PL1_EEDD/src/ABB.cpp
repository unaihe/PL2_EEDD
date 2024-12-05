#include "ABB.h"
#include "NodoABB.h"

ABB::ABB() //crea árbol vacío
{
    //ctor
    raiz=NULL;
}
ABB::ABB(NodoABB *r)
{
    raiz=r;

}
ABB::ABB(string nom, NodoABB *hIz, NodoABB *hDer)//constructor que crea árbolBin con dato y dos subárboles
{
    raiz= new NodoABB(nom, hIz, hDer);//llamamos al constructor del Nodo y raiz es un puntero al Nodo creado

}

ABB::~ABB()
{
    //dtor
}


void ABB::verInOrden() { verInOrden(raiz);}
void ABB::verInOrden(NodoABB *arb)// Método para ver Arbol empezando por su izquirda, después pasamos por la raiz y por ultimo por la rama derecha
{
    if (arb) {
       verInOrden(arb->hi);//Recursion para la rama izquierda
       cout<< arb->pais<<endl;//Mostrar nombre
        verInOrden(arb->hd);// Recursion para la rama derecha
    }
}
/*void ABB::verInOrdenABB()// Método para ver Arbol en inorden sin tener que pasar puntero, resulta farragoso crear objetos cada vez...
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
        mostrarArbol(nodo->hi); // Recursión izquierda

        // Mostrar el país y la lista de pasajeros
        cout << "País: " << nodo->pais << endl;
        cout << "Pasajeros:" << endl;
        nodo->listaPasajeros.mostrarPasajeros();

        mostrarArbol(nodo->hd); // Recursión derecha
    }
}

void ABB::insertar(string pais, Pasajero pasajero) {
    insertar(pais, pasajero, raiz);
}

void ABB::insertar(string pais, Pasajero pasajero, NodoABB*& nodo) {
    if (nodo == nullptr) {
        cout << "Creando nuevo nodo para el país: " << pais << endl;
        nodo = new NodoABB(pais);
        nodo->listaPasajeros.agregarPasajero(pasajero); // Agregar pasajero
    } else if (pais < nodo->pais) {
        cout << "El país " << pais << " es menor que " << nodo->pais << ". Insertando a la izquierda." << endl;
        insertar(pais, pasajero, nodo->hi);
    } else if (pais > nodo->pais) {
        cout << "El país " << pais << " es mayor que " << nodo->pais << ". Insertando a la derecha." << endl;
        insertar(pais, pasajero, nodo->hd);
    } else {
        cout << "El país " << pais << " ya existe. Agregando pasajero a la lista." << endl;
        nodo->listaPasajeros.agregarPasajero(pasajero);
    }
}


