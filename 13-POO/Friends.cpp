/*
    Amigo de una clase, caracteristica del lenguaje que permite dar acceso especial a funciones u otras clases
    a los campos privados o protegidos de una clase.

    Sirven para que ciertas funciones o incluso otras clases si puedan acceder a esos miembros sin ser parte
    de la clase

    Precauciones, Friends rompe la encapsulacion ( no del todo, pero la rompe)

    Se declaran dentro de la clase, escribiendo friend antes de la funcion de la clase
*/

#include <iostream>
using namespace std;

class Caja {

    private:
        double largo;
        double ancho;

    //constructor    
    public:
        Caja(double l, double a): largo(l), ancho(a){}

    //declaramos la funcion calcularArea fuera de la clase como amiga usando friend
    friend double calcularArea(const Caja& c);
};

//funcion fuera de la clase, estan encapsulados los parametros largo y ancho
//no podemos acceder si no tiene getter y setters
double calcularArea(const Caja& c){
    return c.largo * c.ancho;
}

int main(){
    Caja c(5.0, 3.0);
    cout << "Area de la caja: " << calcularArea(c) <<endl;
    return 0;
}

