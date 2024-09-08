#include <iostream>
using namespace std;

int main(){

    int matrix[] {15,20,25}; //crear y inicializar un array sin poner la cantidad de elementos

    cout << matrix[1] <<endl;

    cout << matrix[2] <<endl;

    const int total{10}; //si ponemos una variable como indice de elementos del array tiene que ser const si no da error ya que ese valor tiene que ser inmutable

    int edades[total] {15,20,10}; //crear array indicando el numero de elementos que tendra, las posiciones que no estan definidas valdra 0

    cout << edades[2] <<endl;

    int matrix2[] = {1,6,2}; //tambien se puede crear y inicializar un array por el metodo tradicional

    cout << matrix2[0] <<endl;

    matrix2[0]=5; //variamos el valor del array

    cout << matrix2[0] <<endl;

    cin >> matrix[0]; //pedimos al usuario que por consola introduzca un numero que almacenaremos en esa posicion

    cout << "la edad es de " << matrix[0]  << " años";


}