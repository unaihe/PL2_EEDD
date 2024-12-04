#ifndef T4MADRID_H
#define T4MADRID_H
#include "Colas.h"
#include "Pilas.h"
#include "Persona.h"
#include "Box.h"
#include "Lista.h"

class T4Madrid
{
    public:
        T4Madrid();
        virtual ~T4Madrid();
        void minuto();
        Persona llegada();
        void iniciarAeropuerto();
        void borrarPila();
        void mostrarPasajerosPila();
        void mostrarPasajerosCola();
        void comprobarPila();
        void comprobarCola();
        void comprobarBox();
        void mostrarDatosBox();
        void simulacion();
        void consultarBoxesOperativos();
        void consultarBoxMenosOcupado();
        void consultarBoxMasOcupado();
        void fin();

    protected:

    private:
        int tiempo=0;
        Colas colaPasajeros=Colas();
        Pilas pilaPasajeros=Pilas();
        Box box1=Box(1);
        Lista listaPasajeros=Lista(box1);
        int tTot=0;
        int pasajeros=0;


};

#endif // T4MADRID_H
