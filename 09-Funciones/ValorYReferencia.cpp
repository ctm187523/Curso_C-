#include<iostream>
#include<cmath>
using namespace std;

//metodo que cambia el valor pasado por parametro, recibimos el parametro por valor
void ejemploFuncion(int num) {
    num=50;
    cout << "el valor dentro de la funcion ejemploFuncion vale: "<< num << endl;
}

//metodo que cambia el valor pasado por parametro, recibimos el parametro por referencia(puntero), en el nombre del parametro
//recibido le ponemos el simblo & y esto hace que ahora recibamos el parametro por referencia, lo que modifica
//el valor original de la variable minum
void ejemploFuncion2(int &num) {
    num=100;
    cout << "el valor dentro de la funcion ejemploFuncion2 vale: "<< num << endl;
}




int main(){
    int minum = 10;
    cout <<"Valor original: " << minum << endl;

    ejemploFuncion(minum); //llamamos a la funcion creada arriba
    //imprimimos el valor despues de llamar a la funcion y comprobamos que este no varia ya que el paso ha sido por valor
    //le pasamos una copia de la variable minum, pero el original queda inalterable
    cout << "Valor de la variable minum despues de llamar a la función ejemploFuncion1: "<< minum << endl;

    //ahora llamamos a la funcion ejemploFuncion2 creada arriba que al tener el simbolo & en el nombre del parametro
    //modifica el valor original ya que esta vez lo pasamos por referencia
    ejemploFuncion2(minum);
    cout << "Valor de la variable minum despues de llamar a la función ejemploFuncion2: "<< minum << endl; //esta vez modifica el valor original

    
}