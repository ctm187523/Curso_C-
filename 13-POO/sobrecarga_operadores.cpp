/*
                                                     SOBRECARGA DE OPERADORES
    -¿QUE ES?
      -Mecanismo que permite cambiar el comportamiento por defecto de los operadores cuando los aplicamos a objetos
       propios, los operadores son +(sumar),-(restar),*(multiplicar),etc

    -¿PARA QUÉ SIRVE?
      -Para que los objetos de una clase puedan interactuar de "forma natural" con los operadores igual que los 
      tipos primitivos.

    -¿CÓMO SE SOBRECARGA UN OPERADOR?
      -Utilizando la palabra reservada "operator" seguida del operador que se quiere sobrecargar.

    -¿QUÉ OPERADORES PODEMOS SOBRECARGAR?
      -Aritmeticos: +,-,*,/,%
      -Relacionales: ==,!=,<,>,<=,>=
      -De asignación: =,+=,-=,etc.
      -De acceso:[],(),->,*
       IMPORTANTE!!
      -No podemos crear operadores nuevos como( ** o @@ )
      -No podemos cambiar la precedencia ni la cantidad de operandos de un operador, ejemplo orden aritmetico para
       las operaciones
      -Hay operadores que no se pueden sobrecargar(.:,.*.sizeof,etc.) 
*/

#include <iostream>
#include <string>

using namespace std;


class Empleado {
    private:
        string nombre;
        double sueldo;

    public:
        //constructor
        Empleado(string n, double s): nombre(n), sueldo(s) {}

        //Sobrecarga del operador +, cambiamos el comportamiento del operador + para poder sumar los sueldos
        //de los empleados sin tener que usar getters y setters
        //creamos un metodo usando como palabra reservada operator para definir el nuevo comportamiento
        //que tendra el operador +, pasamos por referencia con & al Empleado con el que queremos operar
        Empleado operator +(const Empleado& otro){
            
            //el nuevo sueldo(suma de sueldos) sera el sueldo del empleado(objeto) actual mas el que pasamos por parametro
            double nuevoSueldo = sueldo+otro.sueldo; //definimos el nuevo comportamiento del operador +

            return Empleado("Nuevo Empleado", nuevoSueldo);  //devolvemos un objeto de tipo empleado pasandole los parametros que exige el constructor de Empleado
        }

        void mostrar() const {
            cout << "Empleado: " << nombre << ", Sueldo: " << sueldo << " $\n";
        }
};



int main(){

    //el operador + por defecto solo nos permite sumar primitivos y lo que queremos es sumar empleados
    //queremos sumar los sueldos de los diferentes operarios, cambiamos el comportamiento del operador +
    //podriamos sumarlos usando getters y setters pero lo haremos cambiando el comportamiento del operador +
    //simplificando el trabajo.

    Empleado emp1("Ana", 2000);
    Empleado emp2("Luis", 1800);

    //como en la clase Empleado hemos redefinido el comportamiento del operador +, podemos sumar objetos de 
    //tipo empleado para en este caso sumar sus sueldos
    //si no redefinimos el comportamiento del operador +, lo de abajo nos daria error.
    Empleado nuevo = emp1+emp2;

    nuevo.mostrar();

}