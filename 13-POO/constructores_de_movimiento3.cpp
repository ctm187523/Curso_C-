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

        //MOVE CONSTRUCTOR(CONSTRUCTOR DE MOVIMIENTO), es mas eficiente que el constructor copia
        //CONSTRUCTOR DE MOVIMIENTO(simil->ctrl+c(copia),ctrl+x(copiar en otro sitio borrando lo anterior))
        //En lugar de copiar como hacemos abajo con la instruccion -> Ejemplo obj2 = *obj1; aqui comentado y usado en constructores_de_movimiento2.cpp
        //ahora tenemos que obj2 es una copia de obj1 y no necesitamos obj1 ya que obj2 es lo mismo
        //para ello usamos el constructor de movimiento en lugar de copiar lo que hacemos es mover
        //y de esta manera tenemos un unico objeto con la información del objeto original
        //MAS DETALLES ABAJO EXPLICADO
        Ejemplo(Ejemplo&& origen):puntero(origen.puntero){  //con && indicamos que es un Rvalue, eso quiere decir que el constructor acepta objetos temporales o recursos que se van a poder mover(Rvalue no tiene nombre ni direccion ver en carpeta L values)

            //con puntero(origen.puntero) de arriba lo que hacemos es transferir el puntero del objeto Ejemplo llamado puntero,movemos los recursos de un objeto original a un objeto que acabamos de crear
            origen.puntero=nullptr; //anulamos el puntero original ya que hemos tranferido la informacion
                                    //con esta instruccion evitamos que el destructor del objeto original intente liberar el recurso dinamico que ahora esta en el nuevo objeto, el destructor intetaria liberar los recursos de los 2 objetos y como el original ha transferido sus recursos daria un error si no se pone esta instruccion
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
    //Ejemplo obj2 = *obj1;   //decimos que lo que apunta el puntero obj1 se almacena en obj2(objeto de tipo Ejemplo), obj2 se almacena en el stack, obj1 permanece pero no obj2

   
    //para ello si hicieramos esto en lugar de usar el constuctor copia, en lugar de copiar seria mejor
    //MOVER usando constructores de movimiento.(Seria un simil con hacer ctrl+c o hacer ctrl+x)
    //ctrl+c seria constructores copia y hacer ctrl+x seria hacer constructores de movimiento

    //usamos el constructor de movimiento creado arriba
    //usamos move para usar el constructor de movimiento
    Ejemplo obj2 = move(*obj1);

    //podemos eliminar obj1 sin problemas ya que en el constructor de movimiento hemos liberado los recursos
    delete obj1;
    return 0;

    //EN RESUMEN LO QUE HEMOS HECHO CON EL CONSTRUCTOR DE MOVIMIENTO ES
    //PRIMERO TENEMOS EN OBJ1 QUE APUNTA A UN OBJETO DINAMICO CREADO CON NEW EN EL HEAP-> Ejemplo* obj1 = new Ejemplo(10);
    //AHOR AL OBJ1 LE DAMOS EL VALOR DE NULLPTR
    //OBJ2 AHORA TIENE LOS RECURSOS DINAMICOS QUE TENIA OBJ1
    //ESTE CONSTRUCTOR COMO VENTAJA ES QUE ES MAS EFICIENTE YA QUE NO SE CREAN COPIAS NI ASIGNACIONES DE MEMORIA NUEVAS
    //SIEMPRE QUE TENGAS QUE PRESCINDIR DEL OBJETO ORIGINAL, ES MAS SEGURO YA QUE ELIMINAS EL OBJETO ORIGINAL
    //Y SE PUEDEN EVITAR POSIBLES CONFLICTOS
}




//EXPLICACION CON CHAT GPT
/*
En C++, los dos puntos (:) que aparecen justo después de la firma del constructor se utilizan para iniciar la lista de inicialización de miembros. Esto significa que, antes de ejecutar el cuerpo del constructor, se inicializan los miembros de la clase con los valores que se indiquen en dicha lista.

¿Por qué usar la lista de inicialización?
Inicialización directa: Permite inicializar los miembros de la clase directamente, lo que suele ser más eficiente que asignarlos dentro del cuerpo del constructor.
Constantes y referencias: Es obligatorio usar la lista de inicialización para miembros constantes (const) o referencias, ya que deben inicializarse en el momento de la construcción.
Constructores de movimiento y copia: Facilita la transferencia de recursos, como en el caso de los constructores de movimiento.
Ejemplo en el código proporcionado

Ejemplo(Ejemplo&& origen): puntero(origen.puntero) {
     Transferimos la propiedad del recurso
    origen.puntero = nullptr; // Anulamos el puntero original para evitar liberación doble
}
Ejemplo(Ejemplo&& origen): Define el constructor de movimiento, que acepta un objeto rvalue (temporal) de la clase Ejemplo.
: puntero(origen.puntero): Es la lista de inicialización de miembros. Aquí se inicializa el miembro puntero del nuevo objeto con el valor de origen.puntero. Esto significa que, desde el inicio, puntero tendrá la dirección de memoria que tenía en el objeto original.
Dentro del cuerpo del constructor: Se asigna nullptr a origen.puntero para que el objeto original ya no intente liberar el recurso, ya que la propiedad del recurso se ha transferido al nuevo objeto.
Resumen
:: Indica el comienzo de la lista de inicialización.
puntero(origen.puntero): Inicializa el miembro puntero del nuevo objeto con el valor de origen.puntero del objeto original.
Esta técnica es esencial para la correcta gestión de recursos, especialmente en constructores de movimiento, para evitar errores como la doble liberación de memoria.
*/