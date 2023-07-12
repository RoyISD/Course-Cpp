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

        // Métodos Observadors (getters) - obtener la información
        const string* getNombre() const; // Prohibo alterar el estado del objeto const after, el valor
        string getApellido() const;
        float getSueldoAnual() const;
        const int getNumeroPagos() const;

        //Métodos modificadores (Setters)
        void setNombre(string nombre);
        void setApellido(string apellido);
        void setSueldoAnual(float sueldoAnual);

    private: // Visibilidad para atributos como metodos, desde el interior se puede
        string nombre, apellido;
        float sueldoAnual;
        static const int numeroPagos = 12; //Static = se trata de atributo compartido por todos los objetos const = no podra ser modificado ??
};

//Declaración de métodos
float Empleado::calcularSueldoMensual(){
    return (sueldoAnual/numeroPagos);
}
string Empleado::nombreCompleto(){
    return (nombre + " " + apellido);
}
// Setters - inicializan el valor de la varible
void Empleado::setNombre(string nombre){nombre = nombre;}
void Empleado::setApellido(string apellido){apellido = "Román";}
void Empleado::setSueldoAnual(float sueldoAnual){sueldoAnual = 28750.45;} 

// Getters - devuelven una copia del valor que se desea obtener
const string* Empleado::getNombre() const {return &nombre;} // Importante el const hace que usuario no pueda modificar el valor del objeto
string Empleado:: getApellido() const{return apellido;}
float Empleado::getSueldoAnual() const{return sueldoAnual;}
const int Empleado::getNumeroPagos() const{return numeroPagos;}

int main(){

    //Manejo automatico de memoria //Objeto temporal dentro del main
    Empleado empleado1;
    float sueldoEmpleado1 = empleado1.calcularSueldoMensual();

    //Manejo NO automatico
    Empleado *p = new Empleado(); //Solicitamos memoria acudimos al puntero
    float sueldoEmpleado2 = p->calcularSueldoMensual();

    
    printf("Nombre: %s", empleado1.getNombre());

    return 0;
}