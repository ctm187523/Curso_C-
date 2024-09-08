// Aritmética de punteros es un concepto en programación, especialmente relevante en C y C++, que permite realizar 
// operaciones aritméticas sobre punteros. Los punteros son variables que almacenan valores en memoria, y la 
// aritmética de punteros se utiliza para calcular direcciones de memoria, lo que permite acceder y manipular
// datos en diferentes posiciones de un array o bloque de memoria.
// Operaciones con punteros:
// -Incremento (++): Al incrementar un puntero, se aumenta su valor para que apunte al siguiente elemento de un arreglo
// el incremento se realiza en base al tamaño del tipo de dato al que apunta el puntero. Por ejemplo, si un puntero
// de tipo int(suponiendo que int tenga un tamaño de 4 bytes) apunta al inicio de un arreglo, al incrementar el puntero,
// este apuntará 4 bytes adelante en la memoria, es decir, al siguiente entero del arreglo.
// -Decremento (--): similar al incremento pero en dirección opuesta
// Suma (+): Se puede sumar un entero a un puntero para que el puntero avance varios elementos en un arreglo. Al igual
// que con el incremento, el avance se calcula multiplicando el número entero por el tamaña del tipo de dato al que
// apunta el puntero
// Resta (-): Se puede restar un entero a un puntero para mover el puntero hacia atrás en el arreglo. También se puede
// restar dos punteros para obtener la diferenia en elemetos entre ellos, siempre y cuando ambos punteros apunten a elementos
// dentro del mismo arreglo.


#include <iostream>
using namespace std;

int main(){

    //en este array cifras seria un puntero al primer elemento que es 10
    int cifras[]={10,20,30}; 

    //creamos un puntero del mismo tipo(int) que apunte al array cifras podemos usar tambien --> int *ptr_cifras = cifras;
    int *ptr_cifras {cifras};

    cout << "accedemos a la primera posicion del array: " << ptr_cifras[0] << endl;

    cout << "accedemos a la segunda posicion del array: " << ptr_cifras[1] << endl;

    cout << "accedemos a la tercera posicion del array: " << ptr_cifras[2] << endl;

    cout << "accedemos a la direccion de memoria de la primera posicion del array: " << ptr_cifras << endl;

    cout << "accedemos al valor del primer elemento del array: " << *ptr_cifras << endl;

    //usamos la aritmética del puntero

     cout << "accedemos a la direccion de memoria del segundo elemento del array: " << (ptr_cifras +1 )<< endl;

     cout << "accedemos al valor del segundo elemento del array: " << *(ptr_cifras +1 )<< endl;

     cout << "accedemos al valor del tercer elemento del array: " << *(ptr_cifras +2 )<< endl;
}