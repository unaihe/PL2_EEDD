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


void ABB::verInOrden()
{
    verInOrden(raiz);
}
void ABB::verInOrden(NodoABB *arb)// Método para ver Arbol empezando por su izquirda, después pasamos por la raiz y por ultimo por la rama derecha
{
    if (arb)
    {
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
void ABB::mostrarArbol()
{
    mostrarArbol(raiz);
}

void ABB::mostrarArbol(NodoABB* nodo)
{
    if (nodo != nullptr)
    {
        mostrarArbol(nodo->hi); // Recursión izquierda

        // Mostrar el país y la lista de pasajeros
        cout << "País: " << nodo->pais << endl;
        cout << "Pasajeros:" << endl;
        nodo->listaPasajeros.mostrarPasajeros();

        mostrarArbol(nodo->hd); // Recursión derecha
    }
}

void ABB::insertar(string pais, Pasajero pasajero)
{
    insertar(pais, pasajero, raiz);
}

void ABB::insertar(string pais, Pasajero pasajero, NodoABB*& nodo)
{
    if (nodo == nullptr)
    {
        cout << "Creando nuevo nodo para el país: " << pais << endl;
        nodo = new NodoABB(pais);
        nodo->listaPasajeros.agregarPasajero(pasajero); // Agregar pasajero
    }
    else if (pais < nodo->pais)
    {
        cout << "El país " << pais << " es menor que " << nodo->pais << ". Insertando a la izquierda." << endl;
        insertar(pais, pasajero, nodo->hi);
    }
    else if (pais > nodo->pais)
    {
        cout << "El país " << pais << " es mayor que " << nodo->pais << ". Insertando a la derecha." << endl;
        insertar(pais, pasajero, nodo->hd);
    }
    else
    {
        cout << "El país " << pais << " ya existe. Agregando pasajero a la lista." << endl;
        nodo->listaPasajeros.agregarPasajero(pasajero);
    }
}

NodoABB* ABB::buscarPais(const std::string& pais)
{
    return buscarPais(pais, raiz);  // Llamamos al método recursivo pasando la raíz
}

NodoABB* ABB::buscarPais(const std::string& pais, NodoABB* nodo)
{
    // Si el nodo es NULL, no se encontró el país
    if (nodo == nullptr)
    {
        return nullptr;
    }

    // Si el país es igual al del nodo actual, lo encontramos
    if (nodo->pais == pais)
    {
        return nodo;
    }

    // Si el país a buscar es menor al del nodo actual, buscamos en el subárbol izquierdo
    if (pais < nodo->pais)
    {
        return buscarPais(pais, nodo->hi);
    }

    // Si el país a buscar es mayor al del nodo actual, buscamos en el subárbol derecho
    return buscarPais(pais, nodo->hd);
}

void ABB::mostrarPasajerosPais(const string& pais)
{
    NodoABB* nodo = buscarPais(pais);

    if (nodo != nullptr)
    {
        std::cout << "Pasajeros con destino a " << pais << ":\n";
        nodo->listaPasajeros.mostrarPasajeros(); // Mostrar los pasajeros de ese país
    }
    else
    {
        std::cout << "No se encontraron pasajeros con destino a " << pais << ".\n";
    }
}

void ABB::mostrarPaisesOrdenados()
{
    // Llamamos al método recursivo que mostrará los países en orden
    std::cout << "Países con pasajeros:\n";
    mostrarPaisesEnOrden(raiz);
}

// Método recursivo que recorre el árbol en inorden y muestra los países
void ABB::mostrarPaisesEnOrden(NodoABB* nodo)
{
    if (nodo == nullptr)
    {
        return;  // Si el nodo es nulo, no hacemos nada
    }

    // Recorremos el subárbol izquierdo
    mostrarPaisesEnOrden(nodo->hi);

    // Mostrar el país del nodo actual
    std::cout << nodo->pais << std::endl;

    // Recorremos el subárbol derecho
    mostrarPaisesEnOrden(nodo->hd);
}
