#include <iostream>
#include <string>
using namespace std;

//El mismo ejemplo anterior pero esta vez usando punteros en lugar de referencias para ver la difernecia
//con el simbolo * indicamos que recibimos como parametros 2 punteros
//En este caso es mejor hacerlo con referencias ya que no vamos a hacer operaciones con bloques de memoria solo sus valores
//los punteros son mas adecuados para manejar memoria a bajo nivel o vamos a utilizar valores nulos
//las referencias no puede trabajar con valores nulos
void intercambio(int *a, int *b){

    //al trabajar con punteros debemos desferenciar los parametros, trabajar con punteros
    int temp = *a;

    *a = *b;

    *b = temp;
}

int main(){

    int var1 = 10;
    int var2 = 20;

    cout << "Antes del intercambio: var1 = " << var1 << " var2 = " << var2 << endl;

    intercambio(&var1, &var2); //como trabajamos con punteros debemos pasar por parametros a la funcion la direccion de memoria de las varaibles para ello usamos &

    cout << "después del intercambio: var1 = " << var1 << " var2 = " << var2 << endl;

}