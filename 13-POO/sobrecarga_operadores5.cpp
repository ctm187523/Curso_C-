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

class MiClase {

    int* datos;

    public:
    //constructor
    MiClase(int valor) {
        datos = new int(valor);   //almacenamos un espacio en el heap(montón), al usar el operador new
    }

    //destructor
    ~MiClase() {
        delete datos;
    }

    //Sobrecarga de operador asignación (copia profunda)
    MiClase& operator=(const MiClase& otra){  //cambiamos el comportamiento del operador =
        delete datos; //liberamos la memoria antigua
        datos = new int(*otra.datos);  //creamos la copia profunda, ahoraal ejecutar b = a creamos una copia profunda no un shallow copy
        return *this;
    }
};

//El programa no devuelve nada
int main() {
    
    //creamos dos objetos 
    MiClase a(5);           //creamos el objeto a de la clase MiClase en el Stack(pila)
    MiClase b(10);          //creamos el objeto b de la clase MiClase en el Stack(pila)

    //si no sobrecargamos el operador = el programa falla, al hacer ctrl+f5 se para el la linea del destructor delete datos;
    //como hemos visto al ejecutar el main y crear el objeto a de la clase MiClase creamos el objeto a.datos en el stack
    //donde el valor que le pasamos en el constructor en el primer caso el 5 se almacena en el Heap
    //lo mismo para el objeto b
    //al asignar b = a, el interprete lee b = a y ocurre una copia superficial o shallow copy(copia superficial) ver en ejemplos anteriores
    //el constructor copia, aqui ocurre un shallow copy, esto quiere decir que al hacer la asignacion no copiamos el objeto
    //con todas sus propiedades y valores en el heap solo hacemos una copia superficial del puntero
    //con esto estamos haciendo que ahora el objeto b apunta al puntero en el heap del objeto a, los dos objetos
    //apuntan a la misma zona de memoria, con el valor al que apuntaba el objeto b se crea una fuga de memoria(memory leak)
    //aunque este no es el principal problema, la caida del program se crea porque cuando asignamos a = b acaba el programa
    //acaba la ejecucion del main, cuando se termina el main es cuando se llaman a los destructores, se ejecuta el destructor
    //el destructor se ejecuta en orden inverso, primero se elimina la zona de memoria donde apunta el objeto b que es el mismo que
    //el objeto a en el heap, se elimina el contenido, pero al querer eliminar el estructor donde apunta el objeto a
    //ya no hay nada ya que se elimino anteriormente y es ahy donde ocurre el problema, se esta intentando borrar
    //algo que ya fue eliminado, es hay donde el programa tiene un crash, cae
    //para solucionar esto SOBRECARGAMOS EL OPERADOR ASIGNACION =
    //para que en lugar de hacer una copia superficial que primero libere la memoria que tenia b.datos y luego cree
    //una nueva copia del valor de a.datos usando new, haciendo una copia profunda(ver videos anteriores)
    //ahora al ejecutar b = a no usamos un shallow copy si no que hacemos una copia profunda
    //al usar el operador = , primero borramos donde apunta el objeto b en el heap que es 10, evitamos ahora la fuga de memoria
    //seguidamente ponemos el valor de a que es 5 y se lo asignamos a b, ahora los objetos a y b tienen el mismo valor
    //pero apuntan a diferentes posiciones de memoria, ya no conparten memoria tienen el mismo valor pero en
    //diferentes posiciones de memoria
    //VER VIDEO 72 recomendado esquemas
    b = a;  

}