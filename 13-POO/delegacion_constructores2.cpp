//                  Delegacion de constructores
/*
    Que es la delegación de constructores?
    - Como su nombre indica,"delegar" el trabajo de un constructor en otro constructor de la misma clase
    Para que sirve?
    - Para evitar la duplicidad de código bajo algunos escenarios, cuando hay sobrecarga de constructores

    Introducido en C++ en la version 11
*/ 

#include <iostream>
using namespace std;

//calcula area del rectangulo base * altura y cuadrado base * base
class Figura {

    //propiedades
    public:
        int base;
        int altura;
        int area;

    //constructor
    Figura(int b, int h):base(b), altura(h), area(b*h){

         cout << "La figura tiene una base de " << base << " una altura de " << altura << " y un área de " << area << endl;
    }

    //segundo constructor
    //delegamos al constructor de arriba, para el cuadrado solo tenemos un parámetro, 
    //en la delegacion pasamos lado y lado para que calcule el area, evitamos repetir el
    //codigo del contenido de los constructores ya que seria el mismo
    Figura(int lado ): Figura(lado,lado){}
  
};


int main(){

   Figura rectangulo(10,5);
   Figura cuadrado(7);

}