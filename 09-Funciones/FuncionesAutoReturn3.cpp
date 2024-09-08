
#include<iostream>
using namespace std;

//funciones autoreturn con uso de genericos
//funcion de plantilla generica para sumar dos valores
//devolvemos auto, si en vez de auto fuera int
//no caeria el programa pero no daria los decimales
template <typename T, typename U>
auto suma(T a, U b){
    return a+b;
}

int main(){

    //uso de la funcion para enteros
    auto sum1 = suma(5,3);
    cout << "Suma de enteros: " << sum1 << endl;

    //uso para enteros y flotantes
    auto sum2 = suma(5,2.5);
    cout << "Suma de entero y flotante: " << sum2 << endl;

    //suma de dos flotantes
    auto sum3 = suma(5.2,3.7);
    cout << "Suma de flotantes: " << sum3 << endl;

    return 0;
}
