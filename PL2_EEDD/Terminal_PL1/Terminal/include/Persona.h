#ifndef PERSONA_H
#define PERSONA_H


class Persona
{

    private:
        int ident;
        int horaLleg;
        int duracion;
        int tCola;
        int identBox;
        int prioridad;
        char pais[30];
    public:
        Persona();
        Persona(int ident,int horaLleg,int duracion,int prioridad,const char* pais);
        ~Persona();
        void setHoraLleg(int n);
        void setHoraSal(int n);
        int getDuracion();
        int getPrioridad();
        void setIdentBox(int n);
        void mostrarPersona();
        int getHoraLLega();
        int getId();
        void setCola(int n);
        int getCola();

    protected:


};

#endif // PERSONA_H
