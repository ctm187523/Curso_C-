
#include <iostream>
#include <cmath> //incluimos la libreria para usar expresiones matematicas, ver api https://en.cppreference.com/w/
using namespace std;

//las funciones prototipos son aquellas que se declaran al inicio del programa, tambien pueden ir en archivos de tipo
//con extensiones .h/.hpp.
//en este ejemplo como la funcion esta despues del main si no pusieramos la declaracion de la funcion(funcion prototipo)
//antes del main, el programa no funcionaria, de esta manera avisamos al compilador de que se usara esta funcion
void elevaPotencia(double base, double exponente);

int main(){

    cout << "El resultado es: "; elevaPotencia(5,2);
}

void elevaPotencia(double base, double exponente){

    cout << pow(base,exponente);
}