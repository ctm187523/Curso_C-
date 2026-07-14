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

#include <iostream>
using namespace std;

//incluimos en la cabecera del programa la libreria de punteros inteligentes, contine unite_ptr, shared_ptr y weak_ptr
#include <memory>

void mostrarNumero(){

    //sustituimos el puntero tradicional por un puntero inteligente unique_ptr, que se encarga de liberar la memoria automáticamente cuando deja de existir
    unique_ptr<int> numero = make_unique<int>(200); // Reservamos memoria para un entero inteligente y le asignamos el valor 200

    cout << "El numero es: " << *numero << endl; // Mostramos el valor del entero

    //ya no es necesario liberar la memoria con delete, ya que el puntero inteligente se encarga de ello automáticamente cuando deja de existir
    //al finalizar el bloque de la función mostrarNumero, el puntero inteligente numero deja de existir y libera la memoria automáticamente, evitando la fuga de memoria
}
int main() {

    //cuando deja de existir la funcion mostrarNumero, el puntero inteligente numero deja de existir y libera la memoria automáticamente, evitando la fuga de memoria
    mostrarNumero(); // Llamamos a la función mostrarNumero
    
}