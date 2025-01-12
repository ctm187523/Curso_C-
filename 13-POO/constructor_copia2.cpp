/*
    ---------    C O N S T R U C T O R E S   C O P I A    --------------------
    
    - Cuando se va a crear una copia de un objeto, C++ debe crear un nuevo objeto a partir de uno existente
    - ¿Cuándo se crea una copia de un objeto en C++?
      - Cuando pasamos un objeto a una función por valor
            ej: void function(Clase obj){ .. } -> pasamos un objeto por valor , se crea una copia
      - Cuando una función devuelve por valor un objeto
            ej: Clase crearObjeto(){
                    Clase obj;
                    return obj;  -> devolvemos una copia del objeto
               }
      - Cuando cosntruimos un objeto basasdo en otro objeto de la misma clase
            ej:  Clase obj1;
                 Clase obj2=obj1; -> hacemos una copia de otro objeto

    
    - El compilador de C++ proporciona una manera para realizar estas tareas proporcionando
      un "constructor copia" si no lo creamos explícitamente, encargado de crear copias de los
      objetos.

    - El "constructo copia" puede dar problemas, el constructor-copia por defecto proporcionando
      por el compilador una copia superficial(shallow copy,member-wise copy).
      una copia superficial copia los valores de los miembros(campos de clase, primitivos) pero
      no los recursos dinámicos que puedean ir asociados al objeto(posiciones en la memoria,etc)
      ej: los punteros, archivos abiertos, etc. 
      Posibles problemas derivados:
        - doble liberación de memoria
        - referencias compartidas     


    CONSTRUCTORES COPIA  -¿ CUANDO CREARLOS?:
        - cuando se van a crear en el programa copia de objetos y estos objetos gestionan 
        - recursos dinámicos como:
            - Memoria
            - Archivos
            - Conexiones
            - etc
        - Cuando una clase tiene recursos exclusivos no copiables por diseño:
            - Sockets de red
            - Handles
            - Archivos abiertos

        - Cuando queremos controlar como se copia un objeto
        - Evitar referencias compartidas no deseadas
        _ Cuando trabajamos con clases que no pueden ser copiadas automáticamente
 */

//   --- VER PROGRAMA constructor_copia

#include <iostream>
using namespace std;

class Ejemplo {

    private:
        int *puntero;
    public:

        //Constructor
        Ejemplo(int valor){
            //asignamos en el puntero la direccion de memoria del entero que acabamos de asignar dinamicamente
            puntero = new int(valor); //asignacion dinámica en el heap, para un entero
        }

        //creamos un constructor copia personalizado, usamos const para garantizar que no se puede modificar
        // con el simbolo & conseguimos crear una referencia del objeto que se va a copiar, para
        // evitar una copia infinita y para una cuestion de rendimineto, para no tener que copiar los atributos
        //del objeto origen
        Ejemplo(const Ejemplo &origen){

            //asignamos una nueva memoria y copiamos el contenido
            //con new int reservamos un nuevo bloque de memoria en el heap para garantizar que tenga
            //el mismo espacio en memoria y no la comparta
            // con *origen.puntero usamos con * el operador de desreferencia estamos accediendo al contenido del puntero
            //puntero en el objeto origen y esto da el valor entero almacenado en la memoria al que
            //apunta origen.puntero, el valor obtenido se copia en el nuevo bloque de memoria recien creado
            //a diferencia de la copia superficial por defecto con esto obtenemos una DEEP COPY
            //copia profunda implica que tenemos una nueva memoria independiente ya que creamos un nuevo bloque de memoria
            //y que se copia en ese nuevo bloque de memoria el contenido
            //AHORA EL PROGRAMA YA NO SE QUEDA COLGADO COMO EN EL ANTERIOR constructor_copia.cpp
            puntero = new int(*origen.puntero);
        }

        //destructor
        ~Ejemplo(){
            delete puntero;
        }
};
int main(){


    Ejemplo obj1(10);
     //usamos el constructor copia por defecto de c++, al tener los mismos metodos(metodo destructor) 
    //como es una copia los dos quieren liberar la misma memoria y hace que el programa no funcione
    //quiere liberar un recurso que ya no existe, al ejecutar el programa se queda colgado
    //LA SOLUCION EN EL PROGRAMA constructor_copia 2 donde creamos el constructor copia personalizado
    Ejemplo obj2 = obj1; 

    return 0;
}