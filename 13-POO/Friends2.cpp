/*
    Amigo de una clase, caracteristica del lenguaje que permite dar acceso especial a funciones u otras clases
    a los campos privados o protegidos de una clase.

    Sirven para que ciertas funciones o incluso otras clases si puedan acceder a esos miembros sin ser parte
    de la clase

    Precauciones, Friends rompe la encapsulacion ( no del todo, pero la rompe)

    Se declaran dentro de la clase, escribiendo friend antes de la funcion de la clase

        FRIENS   VS GETTERS

        CUANDO USAR GETTERS                                           CUANDO USAR FRIENDS
        -la mayoria de las veces                                     -necesitas acceso a multiples campos
        -Cuando quieres mantener de manera                            privados de golpe
         muy clara la encapsulación                                  -Cuando además el acceso lo
        -Cuando quieres mantener una independecia                     quieres rápido sin tener que 
         clara entre clases y funciones                               desarollar getters.
        -Cuando necesitas leer o modificar un                        -Cuando hay relación estrecha entre
         atributo de forma controlada                                 clases y funciones
                                                                     -Cuando necesitas acceso puntual
                                                                      a campos o atributos
        REGLAS DE ORO
        - Primero intenta usar getter/getters
        - Solo usa friend si tienes una buena razón técnica para
          ello( relación especial, rendimiento, diseño de operadores, etc.)                                                            

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

    //ponemos friend a la clase de abajo Inspector para que pueda acceder a las propiedades
    //encapsuladas de esta clase Caja
    friend class Inspector;
};

//Hacemos que esta clase pueda acceder a las propiedades de la clase Caja
//Ya que en la clase Caja hemos puesto esta clase con friend
class Inspector{

    public:
        void mostrarDimensiones(const Caja& c){  //usamos la clase Caja y queremos acceder abajo a sus propiedades encapsuladas como private
            cout << "Largo: " << c.largo << ", Ancho: " << c.ancho << endl;
        }
};

int main(){
    Caja c(5.0, 3.0);           //instancia de la clase Caja
    Inspector i;                //instancia de la clase Inspector
    i.mostrarDimensiones(c);    //podemos acceder en el metodo mostrarDimensiones a las propiedades privadas de Caja gracias a friend
    
    return 0;
}

