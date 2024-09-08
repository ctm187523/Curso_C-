//los punteros son variables que almacenan direcciones de memoria, las direcciones de memoria pueden haber variables
//primitivas, Arrays, Clases, otro puntero, Funciones, Bloqe de memoria dinámica, bloque de memoria reservada para
//el sistema operativo,etc
//PRINCIPALES APLICACIONES: acceso directo y modificacion de la memoria, crear funciones dinámicas y estructura de datos
//como listas enlazadas, arboles, estructuras que cambiaran de tamaño, 
//paso de parametros por referencia, para modificar el valor de la variable pasada
//manejo de Arrays y Strings
//Programacion de bajo de nivel, sistemas operativos, software que interactua con el hardware, drivers
//Comptabilidad con C
//Optimizacion, Flexibilidad en manejo de datos(listas, arboles,etc)

#include <iostream>
using namespace std;

int main(){

    int var = 10;

    //creamos un puntero
    int * ptr;

    //asociamos el puntero a la direccion de memoria de la variable antes creada var
    ptr=&var;

    cout << var << endl;        //imprimimos el valor de la variable var

    cout << &var << endl;       //imprimimos la direccion de memoria de la variable var

    cout << ptr  << endl;       //imprimimos la direccion de memoria que contiene el puntero antes creada ptr que sera la misma de &var

    cout << *ptr << endl;        //con * imprimimos el valor que tiene el puntero en la direccion de memoria de la variable var que sera 10

    //cambiamos el valor de la variable var creada desde el puntero, usando el * para acceder al valor
    *ptr = 55;

    cout << var << endl;        //imprimimos el valor de la variable var ahora actualizada por el puntero
    

}