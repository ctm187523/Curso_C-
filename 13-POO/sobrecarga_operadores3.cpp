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


//queremos comprobar si el sueldo de 2 empleados son iguales cambiando el comportamiento del operador ==
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

            return Empleado("Nuevo empleado", nuevoSueldo);  //devolvemos un objeto de tipo empleado pasandole los parametros que exige el constructor de Empleado
        }

        //Sobrecarga del operador == para la comprobacion de si el sueldo de 2 empleados es el mismo
        bool operator ==(const Empleado& otro){
            //comentamos el codigo de abajo lo usamos utilizando el codigo de debajo de los comentarios
            // if(sueldo == otro.sueldo){
            //     return  true;
            // }else{
            //     return  false;
            // }

            //En C++, el símbolo -> se utiliza para acceder a miembros (atributos o métodos) de un objeto a través de un puntero.
            /*
                ¿Qué significa this->sueldo?
                    this es un puntero al objeto actual (es decir, al objeto que está ejecutando el método).
                    this->sueldo accede al atributo sueldo del objeto actual usando ese puntero.
                    otro.sueldo accede directamente al atributo sueldo de otro objeto (pasado como parámetro por referencia).
            */ 
            return this->sueldo==otro.sueldo;
        }

        //creamos una funcion amiga visto anteriormente friend para poder acceder desde fuera de la clase
        //a los atributos privados de la clase Empleado, la usamos abajo para definir el operador <<
        friend ostream& operator << (ostream& salida, const Empleado& e);

        //comentamos el metodo mostrar ya que en este archivo modificamos el comportamineto del operador <<
        // void mostrar() const {
        //     cout << "Empleado: " << nombre << ", Sueldo: " << sueldo << " $\n";
        // }
};

//creamos la sobrecarga del operador << fuera de la clase Empleado ostream es la clase en c++ que se encarga de controlar
//el flujo de salida por lo tanto usamos la clase ostream de c++
//usamos la palabra clave operator seguido del operador con el que queremos trabajar <<
//como parametros usamos por referencia la clase ostream para salida y obtenemos un objeto de la clase Empleado
ostream& operator <<(ostream& salida, const Empleado& e){

    //definimos el comportamiento que tendra la sobrecarga del operador <<
    //como los campos nombre y sueldo de la clase Empleado son private usamos lo visto anteriormente friends of a class
    salida << "Empleado: " << e.nombre << " , Sueldo: " << e.sueldo <<" $";
    return salida; //retornamos el flujo de salida usando la clase ostream
}



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

    //nuevo.mostrar();

    cout << nuevo;   //como hemos modificado al operador <<, con solo poner cout << nuevo se muestra la información como lo haria el metodo mostrar creado anteriormente

    cout << endl;    //salto de linea
    //usamos la sobrecarga del operador == creada arriba en la clase Empleado para comparar sueldos
    //siponemos == entre dos objetos empleados este ya entiende que queremos comprobar los sueldos no si
    //los 2 objetos son iguales como haria por defecto.
    if (emp1 == emp2){
        cout << "El salario de ambos empleados es igual";
    }else{
        cout << "El salario de ambos empleados es diferente";
    }
}