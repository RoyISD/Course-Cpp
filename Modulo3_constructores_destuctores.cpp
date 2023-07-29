#include <iostream>
#include <string>

using namespace std;

class Empleado{
    public: 
        Empleado(); // Constructor
        Empleado(string nombre, string apellido);
        float calcularSueldoMensual();
        string NombreCompleto();

        void setNombre(string _nombre_);
        void setPrimerApellido(string _apellido_);
        void setSueldoAnual(float _sueldo_);

    private:
        string Nombre;
        string PrimerApellido;
        float sueldoAnual;
        static const int numeroPago = 12;

};

int main(){

    Empleado* empleado1 = new Empleado();
    cout << empleado1->NombreCompleto() << endl;

    Empleado* empleado2 = new Empleado("Brisa", "Reyes");
    cout << empleado2->NombreCompleto() << endl;
    return 0;
}

float Empleado::calcularSueldoMensual(){
    return (sueldoAnual/numeroPago);
}
string Empleado::NombreCompleto(){
    return (Nombre + " " + PrimerApellido);
}
void Empleado::setNombre(string _nombre_){this->Nombre = _nombre_;}
void Empleado::setPrimerApellido(string _apellido_){this->PrimerApellido = _apellido_;}
void Empleado::setSueldoAnual(float _sueldo_){this->sueldoAnual = _sueldo_;}
Empleado::Empleado(){
    Nombre = "Rodrigo";
    PrimerApellido = "Reyes";
}
Empleado::Empleado(string nombre, string apellido){
    this->Nombre = nombre;
    this->PrimerApellido = apellido;
}