
#include <iostream>
using namespace std;

int var = 15;

//la funcion recibe por parametro un puntero, si no usaramos punteros
//no modifica el valor de la variable var, al pasar un puntero es mas eficiente ya que 
//lo estamos referenciando no copiando y es mas eficiente
void miFuncion(int *valor){

    //el valor al que apunto el puntero es a el mismo + 10
    *valor = *valor + 10;
}

int main(){

    //como la funcion tiene que recibir un puntero le pasamos la direccion de memoria de la variable var usando &
    //ver archivo punteros1.cpp de este directorio Punteros
    miFuncion(&var);

    cout << var << endl;
}