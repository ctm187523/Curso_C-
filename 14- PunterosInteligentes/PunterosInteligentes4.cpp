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




#include <iostream>
using namespace std;

//incluimos en la cabecera del programa la libreria de punteros inteligentes, contine unite_ptr, shared_ptr y weak_ptr
#include <memory>


int main() {

    //creamos un puntero compartido shared_ptr de tipo int 
    shared_ptr<int> p1= make_shared<int>(100); //p1 es el propietario del recurso, y el recurso es un entero con valor 100

    {
        //creamos un segundo puntero compartido que accedera al mismo recurso que p1, es decir, al entero con valor 100
        //en memoria tenemos dos punteros compartidos que apuntan al mismo recurso, y el recurso no se liberara hasta que ambos punteros compartidos dejen de existir
        shared_ptr<int> p2 = p1; //p2 es el segundo propietario del recurso, y el recurso es un entero con valor 100
    
        cout << "Valor del recurso compartido: " << *p1 << endl; //mostramos el valor del recurso compartido, que es 100

        //p2 = nullptr; //podemos destruir el puntero compartido p2 manualmente, LO DEJAMOS COMENTADO
        
        cout << "Propietarios del recurso compartido: " << p1.use_count() << endl; //mostramos el numero de propietarios del recurso compartido, que es 2
    
   
    }
    
    cout << "Propietarios del recurso compartido despues de salir del bloque: " << p1.use_count() << endl; //mostramos el numero de propietarios del recurso compartido, que es 1, ya que hemos salido del bloque de codigo y el anterior propietario(p2) que estaba en el bloque se destruye
}