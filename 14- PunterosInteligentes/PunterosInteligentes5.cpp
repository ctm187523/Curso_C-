// RAII (Resource Acquisition Is Initialization) es un principio de programación en C++ que asegura que los recursos se adquieran y liberen
//      de manera automática mediante el uso de constructores y destructores. 
// RAII es una técnica en C++ según el cual un recurso queda ligado a la vida de un objeto.
//      Funcionamiento: El recurso se adquiere cuando el objeto se crea y se libera automáticamente cuando el objeto se destruye.
//      PERO ¿Qué es el "recurso"?
//      -Memoria dinámica (new y delete)
//      -Archivos abiertos (fopen y fclose)
//      -Conexiones de red (socket y close)
//      -Socket (socket y close)
//      etc...
//SOLUCIÓN A PROBLEMAS PUNTEROS TRADICIONALES(Ver imagen en C:\Users\cleme\Documents\C++\14- PunterosInteligentes\PunterosInteligentes.png)
//    1. Unique pointers (unique_ptr) 
//       Gestionan un recurso con un único propietario. La memoria se libera automáticamente cuando el puntero
//       deja de existir.
//    2. Shared pointers (shared_ptr)
//       Permiten que varios punteros compartan la propiedad del mismo recurso. La memoria se libera cuando ya no
//       queda ningun propietario del recurso.
//    3. Weak pointers (weak_ptr)
//       Permiten observar un recurso gestionado por shared_ptr sin ser propietarios de él. Ayudan a evitar
//       referencias circulares.
//     
//     UTILIDADES
//     1.La utilidad práctica de shared_ptr 
//     aparece cuandas varias partes del programa necesitan usar el mismo objeto
//     y no está claro cúal de ellas debe destruirlo, o cuando el recurso debe seguir vivo mientras haya alguien usándolo.


//   Cuándo se ejecuta realmente el DESTRUCTOR ~Textura() 
//   se ejecutará de forma automática al final de la función main() (justo en su última llave de cierre }).
//   En ese instante:La variable texturaEnemigo del main sale de su ámbito y se destruye.
//   El contador de referencias del shared_ptr baja de 1 a 0.Al llegar a cero, 
//   el propio shared_ptr detecta que ya nadie en todo el programa posee el recurso
//   .El sistema invoca inmediatamente al destructor ~Textura(),
//    imprimiendo en pantalla:Liberando textura: texturaEnemigo.png
//    Si usaras punteros tradicionales (como Textura* t = new Textura()), 
//    el compilador nunca llamaría al destructor por sí solo; tendrías que escribir delete t; a mano.
//    El shared_ptr es una clase inteligente que tiene su propio destructor 
//    (creado por los desarrolladores de C++ en la librería <memory>)
//VER CODIGO DE PunterosInteligentes6.cpp para ver el mismo ejemplo pero con punteros tradicionales (raw pointers) y sin RAII,
// donde se ve claramente la diferencia de gestión de memoria y la necesidad de liberar recursos manualmente.

#include <iostream>
using namespace std;

//incluimos en la cabecera del programa la libreria de punteros inteligentes, contine unite_ptr, shared_ptr y weak_ptr
#include <memory>


//Ejemplo de una simulacion de un juego donde creamos una clase textura que es la textura de los personajes
//mientras se usa esa textura, el recurso no se libera, pero cuando ya no se usa, el recurso se libera automaticamente cuando
//ya no hay ningun puntero compartido que apunte a esa textura, es decir, cuando ya no hay ningun propietario del recurso

class Textura {

    private:
        string archivo;

       
    public:
        //constructor
        Textura(string archivo) : archivo(archivo) {  //: archivo(archivo) es la inicializacion de la variable archivo con el valor del parametro archivo
            
            cout << "Cargando textura: " << archivo << endl;
        }

        //destructor
        ~Textura() {
                cout << "Liberando textura: " << archivo << endl;
        }

        //metodo que dibujaria el personaje
        void dibujar() {
                cout << "Dibujando con textura: " << archivo << endl;
        }

};

//creamos la textura creando enemigos
class Enemigo {

    private:
        shared_ptr<Textura> textura; //puntero compartido a la textura del enemigo

    public:
        //constructor
        Enemigo(shared_ptr<Textura> textura) : textura(textura) { //: textura(textura) es la inicializacion de la variable textura con el valor del parametro textura
           
        }


        //metodo para dibujar el enemigo, que llama al metodo dibujar de la textura del enemigo
        //llama  al metodo dibujar de esta clase, que a su vez llama al metodo dibujar de la textura del enemigo
        //si te preguntas que metodo dibujar llama si al de la clase Textura o al de la clase Enemigo, la respuesta es que llama al metodo dibujar de la clase Enemigo, 
        //que a su vez llama al metodo dibujar de la clase Textura
        void dibujar() {
            
            // Este método es un excelente ejemplo de un patrón de diseño llamado Delegación.
            // Significa que la clase Enemigo no sabe cómo dibujar pixeles en la pantalla,
            // por lo que le delega (le pasa la responsabilidad) ese trabajo a la clase Textura, 
            // que sí sabe cómo hacerlo.
            // Para acceder a los métodos de un objeto a través de un puntero, C++ te obliga a usar 
            //el operador flecha -> en lugar del punto .
            textura->dibujar(); //llamamos al metodo dibujar de la textura del enemigo
        }

};


main() {

    //creamos un puntero compartido a la textura del enemigo, que es un recurso compartido entre varios enemigos
    shared_ptr<Textura> texturaEnemigo = make_shared<Textura>("texturaEnemigo.png"); //creamos la textura del enemigo 1

    {
       Enemigo enemigo1(texturaEnemigo); //creamos el enemigo 1 
       Enemigo enemigo2(texturaEnemigo); //creamos el enemigo 2 
       Enemigo enemigo3(texturaEnemigo); //creamos el enemigo 3

       //vamos haber cuantos propietarios hay del recurso compartido
       cout << "Propietarios del recurso compartido(textura): " << texturaEnemigo.use_count() << endl; //mostramos el numero de propietarios del recurso compartido, que es 4 los 3 enemigos y el puntero compartido texturaEnemigo
       
       
       enemigo1.dibujar(); //dibujamos el enemigo 1  
       enemigo2.dibujar(); //dibujamos el enemigo 2
       enemigo3.dibujar(); //dibujamos el enemigo 3
    }

    //cuando salimos del bloque de codigo, los enemigos dejan de existir y se destruyen, y el recurso compartido(textura) se libera automaticamente
    //si miramos cuantos propietarios hay del recurso compartido, veremos que es 1, ya que solo queda el puntero compartido texturaEnemigo
    cout << "Propietarios del recurso compartido(textura) despues de salir del bloque: " << texturaEnemigo.use_count() << endl;

}







