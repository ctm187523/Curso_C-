#include <iostream>
#include <string>
using namespace std;

//El mismo ejemplo anterior, este ejemplo solo puede trabajar con punteros ya que podemos trabajar
//con valores nulos
//En C++, desreferenciar significa acceder al valor almacenado en una dirección de memoria apuntada por un puntero.
// Para ello, se usa el operador de desreferenciación (*).
void incrementarSiNoNulo(int *valor){

    if(valor !=nullptr) ++(*valor); // decimos que si no es nulo incremente el valor del parametro valor ponemos * para desreferenciar ya que valor es un puntero pasado por paramametro 
}

int main(){

    int *a = nullptr;
    int b = 5;

    incrementarSiNoNulo(a); //como la variable a pasar ya es un puntero no debemos poner el simbolo & para pasarle la direccion de memoria

    cout << "Valor de a: " << a  << endl;       //el valor es 0 ya que no pasamos ningun valor, 0 quiere decir ninguna direccion

    incrementarSiNoNulo(&b); //debemos poner el simbolo & para pasarle la direccion de memoria ya que ñla variable b no es un puntero

    cout << "Valor de a: " << b  << endl;       //el valor es 6 al pasar por la funcion incrementarSiNoNulo incrementa el valor si el valor pasado no es nulo


}