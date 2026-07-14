//Problemas que tenemos con los punteros tradicionales:
// 1. Memory leaks(fuga de memoria): Reservamos memoria con "new" pero nunca lo liberamos con "deletes".
// 2. Doble liberación de memoria: Liberamos memoria con "delete" más de una vez sobre la misma memoria.
//    Poner puntero a nullptr evita algunos errores, pero no soluciona el problema de raiz.
// 3. Punteros colgantes: Liberamos memoria con "delete" pero seguimos usando el puntero que apunta a esa memoria liberada.
// 4. Perdida de ownership: cuando no queda claro quien es el dueño de la memoria.

// Solucion a estos problemas: PUNTEROS INTELIGENTES (SMART POINTERS)
// 1. Unique pointers (unique_ptr): Gestionana un recurso com un único propietario. La memoria se libera autoáticamente
//    cuando el puntero deja de existir.
// 2. Shared pointers (shared_ptr): Permiten que varios punteros compartan la propiedad del mismo recurso. La memoria
//     se libera cuando ya no queda ningún propietario.
// 3. Weak pointers (weak_ptr): Permiten observar un recurso gestionado por un shared_ptr sin ser propietarios de él.
//     Ayudan a evitar referencias circulares que podrían impedir la liberación de memoria.

#include <iostream>
using namespace std;

//incluimos en la cabecera del programa la libreria de punteros inteligentes, contine unite_ptr, shared_ptr y weak_ptr
#include <memory>

void mostrarNumero(){

    //sustituimos el puntero tradicional por un puntero inteligente unique_ptr, que se encarga de liberar la memoria automáticamente cuando deja de existir
    //int* numero = new int(200); // Reservamos memoria para un entero y le asignamos el valor 10
    unique_ptr<int> numero = make_unique<int>(200); // Reservamos memoria para un entero inteligente y le asignamos el valor 200

    cout << "El numero es: " << *numero << endl; // Mostramos el valor del entero

    //ya no es necesario liberar la memoria con delete, ya que el puntero inteligente se encarga de ello automáticamente cuando deja de existir

}
int main() {

    //cuando deja de existir la funcion mostrarNumero, el puntero inteligente numero deja de existir y libera la memoria automáticamente, evitando la fuga de memoria
    mostrarNumero(); // Llamamos a la función mostrarNumero
    
}