/*
    CONSTRUCTORES
    - Método especial
    - Invocado durante la creación de un objeto
    - Tiene como finalidad dar estado inicial a los objetos
    - Tiene el mismo nombre que la clase
    - No devuelven tipo( no return)
    - Admiten sobrecarga
    - aunque no tenga la clase el método constructor, se asume que tiene un constructor por defecto, es un constructor vacio
*/


#include <iostream>
using namespace std;


class Rectangulo{

    //propiedades
    private:
        int ancho;
        int alto;

    //constructor debemos hacerlo public si no por defecto es privado
    public:
        Rectangulo(){

            ancho=10;
            alto=5;
        }

        //sobrecarga de constructores, creamos otro constructor
        Rectangulo(int medida){

            ancho = medida;
            alto = 4;
        }

        //sobrecarga de constructores, creamos otro constructor
        Rectangulo(int an, int al){

            ancho = an;
            alto = al;
        }

};



int main(){

   
    Rectangulo r1;  //llamamos al primer constructor que no tiene parametros

    Rectangulo r2(12);  //usamos el segundo constructor le pasamos la medida

    Rectangulo r3(17,9); //usamos el tercer contructor le pasamos los dos parametros requeridos

  
}