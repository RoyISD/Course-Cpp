#include <iostream>
#include <string>

using namespace std;

// Objectos se abstraen en clases
//Objecto Empleado

//Nota: Por defecto se tiene la visibilidad private
// Buenas practicas: Solo dos secciones 
class Empleado{
    //visibilidad 
    public: //Permite establecer visibles los miembros desde afuera
        float calcularSueldoMensual();
        string nombreCompleto();

    private: // Visibilidad para atributos como metodos, desde el interior se puede
        string nombre, apellido;
        float sueldoAnual;
        static const int numeroPagos = 2;
};

//Declaración de métodos
float Empleado::calcularSueldoMensual(){
    return (sueldoAnual/numeroPagos);
}
string Empleado::nombreCompleto(){
    return (nombre + " " + apellido);
}

int main(){

    //Manejo automatico de memoria //Objeto temporal dentro del main
    Empleado empleado1;
    float sueldoEmpleado1 = empleado1.calcularSueldoMensual();

    //Manejo NO automatico
    Empleado *p = new Empleado(); //Solicitamos memoria acudimos al puntero
    float sueldoEmpleado2 = p->calcularSueldoMensual();

    return 0;
}