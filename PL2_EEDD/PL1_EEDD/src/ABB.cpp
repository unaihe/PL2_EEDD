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


void ABB::verInOrden()
{
    verInOrden(raiz);
}
void ABB::verInOrden(NodoABB *arb)// M�todo para ver Arbol empezando por su izquirda, despu�s pasamos por la raiz y por ultimo por la rama derecha
{
    if (arb)
    {
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
void ABB::mostrarArbol()
{
    mostrarArbol(raiz);
}

void ABB::mostrarArbol(NodoABB* nodo)
{
    if (nodo != nullptr)
    {
        mostrarArbol(nodo->hi); // Recursi�n izquierda

        // Mostrar el pa�s y la lista de pasajeros
        cout << "Pa�s: " << nodo->pais << endl;
        cout << "Pasajeros:" << endl;
        nodo->listaPasajeros.mostrarPasajeros();

        mostrarArbol(nodo->hd); // Recursi�n derecha
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
        cout << "Creando nuevo nodo para el pa�s: " << pais << endl;
        nodo = new NodoABB(pais);
        nodo->listaPasajeros.agregarPasajero(pasajero); // Agregar pasajero
    }
    else if (pais < nodo->pais)
    {
        cout << "El pa�s " << pais << " es menor que " << nodo->pais << ". Insertando a la izquierda." << endl;
        insertar(pais, pasajero, nodo->hi);
    }
    else if (pais > nodo->pais)
    {
        cout << "El pa�s " << pais << " es mayor que " << nodo->pais << ". Insertando a la derecha." << endl;
        insertar(pais, pasajero, nodo->hd);
    }
    else
    {
        cout << "El pa�s " << pais << " ya existe. Agregando pasajero a la lista." << endl;
        nodo->listaPasajeros.agregarPasajero(pasajero);
    }
}

NodoABB* ABB::buscarPais(const std::string& pais)
{
    return buscarPais(pais, raiz);  // Llamamos al m�todo recursivo pasando la ra�z
}

NodoABB* ABB::buscarPais(const std::string& pais, NodoABB* nodo)
{
    // Si el nodo es NULL, no se encontr� el pa�s
    if (nodo == nullptr)
    {
        return nullptr;
    }

    // Si el pa�s es igual al del nodo actual, lo encontramos
    if (nodo->pais == pais)
    {
        return nodo;
    }

    // Si el pa�s a buscar es menor al del nodo actual, buscamos en el sub�rbol izquierdo
    if (pais < nodo->pais)
    {
        return buscarPais(pais, nodo->hi);
    }

    // Si el pa�s a buscar es mayor al del nodo actual, buscamos en el sub�rbol derecho
    return buscarPais(pais, nodo->hd);
}

void ABB::mostrarPasajerosPais(const string& pais)
{
    NodoABB* nodo = buscarPais(pais);

    if (nodo != nullptr)
    {
        std::cout << "Pasajeros con destino a " << pais << ":\n";
        nodo->listaPasajeros.mostrarPasajeros(); // Mostrar los pasajeros de ese pa�s
    }
    else
    {
        std::cout << "No se encontraron pasajeros con destino a " << pais << ".\n";
    }
}

void ABB::mostrarPaisesOrdenados()
{
    // Llamamos al m�todo recursivo que mostrar� los pa�ses en orden
    std::cout << "Pa�ses con pasajeros:\n";
    mostrarPaisesEnOrden(raiz);
}

// M�todo recursivo que recorre el �rbol en inorden y muestra los pa�ses
void ABB::mostrarPaisesEnOrden(NodoABB* nodo)
{
    if (nodo == nullptr)
    {
        return;  // Si el nodo es nulo, no hacemos nada
    }

    // Recorremos el sub�rbol izquierdo
    mostrarPaisesEnOrden(nodo->hi);

    // Mostrar el pa�s del nodo actual
    std::cout << nodo->pais << std::endl;

    // Recorremos el sub�rbol derecho
    mostrarPaisesEnOrden(nodo->hd);
}
void ABB::calcularPaisMasYMenosPasajeros() {
    if (raiz == nullptr) {
        std::cout << "No hay pa�ses en el �rbol." << std::endl;
        return;
    }

    // Inicializamos las variables para almacenar el pa�s con m�s y menos pasajeros
    NodoABB* paisMas = nullptr;
    NodoABB* paisMenos = nullptr;
    int maxPasajeros = -1;  // Inicializamos con un valor negativo, ya que no queremos que se considere la ra�z como la inicial
    int minPasajeros = INT_MAX;  // Inicializamos con un valor muy alto

    // Recorremos el �rbol en inorden
    calcularPaisMasYMenosPasajeros(raiz, paisMas, paisMenos, maxPasajeros, minPasajeros);

    if (paisMas != nullptr) {
        std::cout << "Pa�s con m�s pasajeros: " << paisMas->pais << " con " << maxPasajeros << " pasajeros." << std::endl;
    }
    if (paisMenos != nullptr) {
        std::cout << "Pa�s con menos pasajeros: " << paisMenos->pais << " con " << minPasajeros << " pasajeros." << std::endl;
    }
}

void ABB::calcularPaisMasYMenosPasajeros(NodoABB* nodo, NodoABB*& paisMas, NodoABB*& paisMenos, int& maxPasajeros, int& minPasajeros) {
    if (nodo != nullptr) {
        // Primero recorremos el sub�rbol izquierdo
        calcularPaisMasYMenosPasajeros(nodo->hi, paisMas, paisMenos, maxPasajeros, minPasajeros);

        // Solo procesamos nodos que no sean la ra�z con el pa�s "MM"
        if (nodo->pais != "MM") {
            // Contamos los pasajeros de este nodo
            int numPasajeros = nodo->listaPasajeros.getLongitud();  // Suponiendo que getLongitud() retorna el n�mero de pasajeros

            // Comprobamos si es el pa�s con m�s pasajeros
            if (numPasajeros > maxPasajeros) {
                paisMas = nodo;
                maxPasajeros = numPasajeros;
            }

            // Comprobamos si es el pa�s con menos pasajeros
            if (numPasajeros < minPasajeros) {
                paisMenos = nodo;
                minPasajeros = numPasajeros;
            }
        }

        // Luego recorremos el sub�rbol derecho
        calcularPaisMasYMenosPasajeros(nodo->hd, paisMas, paisMenos, maxPasajeros, minPasajeros);
    }
}
