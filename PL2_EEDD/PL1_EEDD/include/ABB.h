#ifndef ABB_H
#define ABB_H
#include "NodoABB.h"


class ABB
{
    public:
        ABB();
        ABB(NodoABB *r);
        ABB(string pais, NodoABB *hIz=NULL, NodoABB *hDer=NULL);
        virtual ~ABB();
        void verInOrden();
        void verInOrden(NodoABB *arb);


       // void verInOrdenABB();
        void insertar(string pais, Pasajero pasajero);
        void insertar(string pais, Pasajero pasajero, NodoABB*& nodo);
        void mostrarArbol();
        void mostrarArbol(NodoABB* nodo);
        void mostrarPasajerosPais(const string& pais);
        NodoABB* buscarPais(const std::string& pais);
        NodoABB* buscarPais(const std::string& pais, NodoABB* nodo);
        void mostrarPaisesOrdenados();
        void mostrarPaisesEnOrden(NodoABB* nodo);
        void calcularPaisMasYMenosPasajeros();
        void calcularPaisMasYMenosPasajeros(NodoABB* nodo, NodoABB*& paisMas, NodoABB*& paisMenos, int& maxPasajeros, int& minPasajeros);
        void setTiempoFinal(int i, int id);
        Pasajero* buscarPorId(int id);
        Pasajero* buscarRecursivo(NodoABB* nodo, int id);
        void calcularTiempoMedioPais(const std::string& pais);
        void calcularTiempoMedioPaisPreorden();
        void calcularTiempoMedioPaisPreorden(NodoABB* nodo);
        void calcularTiempoMedioPaisDePais(NodoABB* nodo);
    private:
        NodoABB *raiz;
};

#endif // ABB_H

