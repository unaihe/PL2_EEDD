#include "T4Madrid.h"
#include <iostream>
using namespace std;
T4Madrid::T4Madrid()
{
    int tiempo=0,tTot=0,pasajeros=0;
}

T4Madrid::~T4Madrid()
{
    //dtor
}
void T4Madrid::minuto()
{

    tiempo++;
    cout << "" << endl;
    cout << "_______________________________" << endl;
    cout << "" << endl;
    cout << "-----------MINUTO "<<tiempo<<"-----------" << endl;
    cout << "_______________________________" << endl;

    /*if(box1.atender()){
        tTot+=tiempo-box1.getPasajero().getHoraLLega();
        pasajeros++;
    }
    if(box2.atender()){


        tTot+=tiempo-box2.getPasajero().getHoraLLega();
        pasajeros++;
    }
    if(box3.atender()){
        tTot+=tiempo-box3.getPasajero().getHoraLLega();
        pasajeros++;
    }*/
    tTot+=listaPasajeros.atenderPasajeros(tiempo);

    if (!pilaPasajeros.esVacia())
    {
        comprobarPila();
    }
    listaPasajeros.comprobarColaMin(tiempo);
    if(pilaPasajeros.esVacia()&&listaPasajeros.todoVacio())
    {

        fin();
    }
}
void T4Madrid::iniciarAeropuerto()
{
    pilaPasajeros.borrarDatos();
    Persona per1=Persona(1,0,10,6,"Indonesia");
    Persona per2=Persona(2,0,15,1,"Portugal");
    Persona per3=Persona(3,5,29,7,"Australia");
    Persona per4=Persona(4,7,8,5,"Sudáfrica");
    Persona per5=Persona(5,9,16,7,"Australia");
    Persona per6=Persona(6,9,13,6,"Indonesia");
    Persona per7=Persona(7,10,10,6,"Indonesia");
    Persona per8=Persona(8,10,15,1,"Portugal");
    Persona per9=Persona(9,15,29,7,"Sudáfrica");
    Persona per10=Persona(10,17,8,5,"Sudáfrica");
    Persona per11=Persona(11,19,16,7,"Australia");
    Persona per12=Persona(12,19,13,6,"Indonesia");
    Persona per13=Persona(13,15,29,7,"Sudáfrica");
    Persona per14=Persona(14,17,8,5,"Sudáfrica");
    Persona per15=Persona(15,19,16,7,"Australia");
    Persona per16=Persona(16,19,13,6,"Indonesia");
    pilaPasajeros.apilarmenormayor(per1);
    pilaPasajeros.apilarmenormayor(per2);
    pilaPasajeros.apilarmenormayor(per3);
    pilaPasajeros.apilarmenormayor(per4);
    pilaPasajeros.apilarmenormayor(per5);
    pilaPasajeros.apilarmenormayor(per6);
    pilaPasajeros.apilarmenormayor(per7);
    pilaPasajeros.apilarmenormayor(per8);
    pilaPasajeros.apilarmenormayor(per9);
    pilaPasajeros.apilarmenormayor(per10);
    pilaPasajeros.apilarmenormayor(per11);
    pilaPasajeros.apilarmenormayor(per12);
    pilaPasajeros.apilarmenormayor(per13);
    pilaPasajeros.apilarmenormayor(per14);
    pilaPasajeros.apilarmenormayor(per15);
    pilaPasajeros.apilarmenormayor(per16);
    pasajeros=0;
    pasajeros+=pilaPasajeros.getLongitud();
    comprobarPila();
    Box& b=listaPasajeros.menor();
    b.comprobarCola(tiempo);
}
void T4Madrid::mostrarPasajerosPila()
{
    NodoPilas *auxp=pilaPasajeros.getCima();
    while (auxp)
    {
        Persona per=auxp->valor;
        per.mostrarPersona();
        auxp=auxp->siguiente;
    }
}
void T4Madrid::borrarPila()
{
    while(pilaPasajeros.getCima()) pilaPasajeros.desapilar();
}
void T4Madrid::mostrarPasajerosCola()
{
    colaPasajeros.mostrarCola();
}
void T4Madrid::comprobarPila()
{
    while (!pilaPasajeros.esVacia()&&(pilaPasajeros.getCima()->valor).getHoraLLega()==tiempo)
    {
        Box& b=listaPasajeros.menor();
        b.encol(pilaPasajeros.getCima()->valor);
        pilaPasajeros.desapilar();
        listaPasajeros.comprobarColaMin(tiempo);
        if (listaPasajeros.boxNuevo())
        {
            listaPasajeros.anadirLista();
        }
    }

}
/*void T4Madrid::comprobarCola()
{
    /*
    while (colaPasajeros.get_longitud()!=0&&(box1.estaVacio()||box2.estaVacio()||box3.estaVacio()))
    {
        Persona per=colaPasajeros.desencolar();
        if (box1.estaVacio())
        {
            box1.asignarPasajero(per);
            per.setCola(tiempo-per.getHoraLLega()+per.getDuracion());
            per.mostrarPersona();
            cout<<"Entro en el box."<<endl;
            mostrarDatosBox();
        }
        else if (box2.estaVacio())
        {
            box2.asignarPasajero(per);
            per.setCola(tiempo-per.getHoraLLega()+per.getDuracion());
            per.mostrarPersona();
            cout<<"Entro en el box."<<endl;
            mostrarDatosBox();
        }
        else if (box3.estaVacio())
        {
            box3.asignarPasajero(per);
            per.setCola(tiempo-per.getHoraLLega()+per.getDuracion());
            per.mostrarPersona();
            cout<<"Entro en el box."<<endl;
            mostrarDatosBox();
        }}
    bool aux=true;
    Box b;
    while (colaPasajeros.get_longitud()!=0 && aux)
    {
        Persona per=colaPasajeros.desencolar();
        bool asig=listaPasajeros.llenarHueco(per);
        if (!asig)
        {
            colaPasajeros.encolarPrioridad(per);
            aux=false;
        }
        else
        {
            per.setCola(tiempo-per.getHoraLLega()+per.getDuracion());
            per.mostrarPersona();
            cout<<"Entro en el box."<<endl;
            mostrarDatosBox();
        }
    }
}*/
void T4Madrid::mostrarDatosBox()
{
    listaPasajeros.mostrar();
}
void T4Madrid::simulacion()
{
    bool aux=true;
    while(!pilaPasajeros.esVacia()||!aux)
    {

        minuto();
        aux=listaPasajeros.todoVacio();
    }

}
void T4Madrid::consultarBoxesOperativos()
{
    cout << "- El número de boxes operativos es: " << listaPasajeros.getLongitud() << "." << endl;
}
void T4Madrid::consultarBoxMenosOcupado()
{
    listaPasajeros.menor().mostrarBox();
}
void T4Madrid::consultarBoxMasOcupado()
{

    listaPasajeros.mayor();
}
void T4Madrid::fin()
{
    double media;
    media=static_cast<double>(tTot+2)/pasajeros;
    cout<<"Tiempo medio en el aeropuerto = "<<media<< endl;
}

