// En C++ un array es básicamente un puntero al primer elemento del array
// El valor del nombre del array es la dirección en memoria del primer elemento del array.
// Cuando se usa el nombre del array sin ningún índice, se obtiene la dirección en memoria del primer elemento del array.
// Cuando un puntero apunta al mismo tipo de dato que los elementos de un array, en casi todos los escenarios, puedes usar
// en nombre del puntero y el nombre del array de manera intercambiable para realizar operaciones similares, especialmente
// en lo que respecta a la indexación y aritemética de punteros. Sin embargo, el "casi" indica que hay excepciones a la regla.

#include <iostream>
using namespace std;

int main(){

    int cifras[]= {10,20,30}; //en este array cifras seria un puntero al primer elemento que es 10

    cout << "si ponemos el nombre del array(cifras) devuelve la dirección de memoria del primer elemento del array: " << cifras << endl;

    cout << "ahora obtenemos el valor del primer elemento del array imprimiendo *cifras: " << *cifras << endl;

    //creamos un puntero del mismo tipo(int) que apunte al array cifras podemos usar tambien --> int *ptr_cifras = cifras;
    int *ptr_cifras {cifras};
    

    //ahora podemos usar indistintamente el nombre del array cifras o el nombre del puntero ptr_cifras
    cout << "usamos el puntero creado(ptr_cifras) para ver que se puede usar ahora en lugar de cifras: " << ptr_cifras << endl;
    cout << "usamos el puntero creado(ptr_cifras) para ver que se puede usar ahora en lugar de cifras: " << *ptr_cifras << endl;

    

}