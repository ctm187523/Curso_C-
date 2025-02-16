/*
    CONSTRUCTORES DE MOVIMIENTO(MOVE CONSTRUCTORS)
    
    ¿QUE SON?
    
    -Introducido en C++ II
    -Se usan para evitar copias innecesarias de recursos cuando estos no serán necesarios en su ubicación original.
    -Sintaxis:  Ejemplo(Ejemplo&& otro);
    -El parámetro Ejemplo&& otro es una referencia a un rvalue.
     Un rvalue es una expresión que no puede tener un valor asignado. Tanto una constante literal 
     como una variable pueden servir como rvalue. Cuando aparece un lvalue en un contexto que requiere 
     un rvalue, el lvalue se convierte implícitamente en un rvalue.
     Permite capturar objetos temporales o recursos sin necesidad de copiarlos. 
*/


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


    //Ejemplo obj1(10);
    //al crear el objeto sin el operador new se guarda en el stack esto quiere decir que al salir del alcanze
    //del metodo main el objeto se destruye automaticamente, esto no pasa si se guarda en el heap
    //si creamos y almacenamos un objeto en el heap al salir del alcanze del main ese objeto permanece

    //vamos a crearlos con el operador new para que se almacene en el heap
    //creamos un puntero de tipo Ejemplo que apunta al objeto(10) que se almacenara en el heap
    //ver que en la primera linea de los comentarios esta comentado como se creo antes sin el operador new
    //en el stack
    Ejemplo* obj1 = new Ejemplo(10);
    Ejemplo obj2 = *obj1;   //decimos que lo que apunta el puntero obj1 se almacena en obj2(objeto de tipo Ejemplo), obj2 se almacena en el stack, obj1 permanece pero no obj2

    //en este caso obj1 como ha sido creado con el operador new y en la linea siguiente se ha copiado
    //no se necesitaria que se mantuviera en el heap, no pasaria nada si se queda pero consume recursos
    //y todo lo que se hizo anteriomente con el constuctor copia consume recursos

    //para ello si hicieramos esto en lugar de usar el constuctor copia, en lugar de copiar seria mejor
    //MOVER usando constructores de movimiento.(Seria un simil con hacer ctrl+c o hacer ctrl+x)
    //ctrl+c seria constructores copia y hacer ctrl+x seria hacer constructores de movimiento

    //podriamos borrar manualmente obj1, pero no tiene sentido haber echo el consturctor copia anterior
    //VER cosntructores_de_movimiento 2
    delete obj1;
    return 0;
}