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
        float calcularSueldoMensual();  // Sobrecarga de métodos
        float calcularSueldoMensual(int numeroPagos);  // Es hacer la misma funcion pero con parametros
        string nombreCompleto();
        friend class Supervisor; // Haciendo que la clase Supervisor sea amiga de la clase empleado

        // Métodos Observadors (getters) - obtener la información
        const string* getNombre() const; // Prohibo alterar el estado del objeto const after, el valor
        const string* getApellido() const;
        const float* getSueldoAnual() const;
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
// Demostración clases amigas
class Supervisor{
    public:
        void mostrarSueldoAnualEmpleado(const Empleado* empleado);
    private: 
};

//Declaración de métodos
float Empleado::calcularSueldoMensual(){
    return (sueldoAnual/numeroPagos);
}
float Empleado::calcularSueldoMensual(int numeroPagos){
    return (sueldoAnual/numeroPagos); // Para referise al atributo de la clase es con this->numeroPagos
}
string Empleado::nombreCompleto(){
    return (nombre + " " + apellido);
}
// Setters - inicializan el valor de la varible
void Empleado::setNombre(string nombre){this->nombre = nombre;}
void Empleado::setApellido(string apellido){this->apellido = apellido;}
void Empleado::setSueldoAnual(float sueldoAnual){this->sueldoAnual = sueldoAnual;} 

// Getters - devuelven una copia del valor que se desea obtener
const string* Empleado::getNombre() const {return &nombre;} // Importante el const hace que usuario no pueda modificar el valor del objeto
const string* Empleado:: getApellido() const{return &apellido;}
const float* Empleado::getSueldoAnual() const{return &sueldoAnual;}
const int Empleado::getNumeroPagos() const{return numeroPagos;}

void Supervisor::mostrarSueldoAnualEmpleado(const Empleado* empleado){
    cout << "El sueldo anual del empleado es: " << empleado->sueldoAnual << endl;
}

int main(){

    //Manejo automatico de memoria //Objeto temporal dentro del main
   // Empleado empleado1;
    //float sueldoEmpleado1 = empleado1.calcularSueldoMensual();

    //Manejo NO automatico
    //Empleado *p = new Empleado(); //Solicitamos memoria acudimos al puntero
    //float sueldoEmpleado2 = p->calcularSueldoMensual();

    // Función amiga
    Empleado* p_empleado = new Empleado();
    p_empleado->setSueldoAnual(20200);

    Supervisor* p_supervisor = new Supervisor();
    p_supervisor->mostrarSueldoAnualEmpleado(p_empleado);

    return 0;
}