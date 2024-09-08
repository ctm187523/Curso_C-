#include <iostream>
using namespace std;

class Coche {

    //atributos o propiedades, si no tiene modificador son privados, para cambiar a publico, public:
    //a partir del modificador public o private las propiedades que vienen detras se establecen con el ultimo modificador indicado
    string modelo;
    int cilindrada;
    int potencia;
    public: string color; //la ponemos publica la propiedad, si no tiene nada es privada
    private: double precio;      //la ponemos privada ya que como la de arriba la hemos  puesta publica las siguientes seran publicas tambien


    //METODOS DE ACCESO para acceder a las propiedades privadas
    public: void setPrecio(double p){
        if(p <0 ) precio = 10000;
        
        else precio = p;
    }

    //al ser la de arriba public este metodo pasa a ser public tambien
    double getPrecio(){
        return precio;
    }


    //METODOS
    //metodos, si no ponemos nada son privados los modificadores de acceso, para hacerlo publico -> public:     <-- ojo a los 2 puntos
    //al poner el public todos los metodos que hay abajo se convierten en public, para hacerlo privados hay que indicarlo con private:
    public: void arrancar(){
        cout << "El cochle esta arrancado." << endl;
    }

    //se puede poner el public arriba y sangrarlo no es obligatorio sangrarlo ni ponerlo arriba
    public:
        void acelerar(){
            cout << "El cochle esta acelerando." << endl;
        }

    //hacemos que el metodo y los siguietes sean privados, el ultimo modificador de acceso modifica lo que hay a continuación
    private:
        void frenar(){
            cout << "El cochle esta frenando." << endl;
        }

        void girar(){
            cout << "El cochle esta girando." << endl;
        }

        bool en_marcha(){
            return true;
        }
}; //ojo!! al final de la clase lleva un punto y coma

int main(){

    //instanciamos las clases o ejemplarizar clases es lo mismo
    Coche coche_Pepe;

    Coche coche_Sara;

    coche_Sara.acelerar();

    coche_Pepe.color = "rojo";

    cout << "El color del coche es: " << coche_Pepe.color << endl;

    coche_Sara.setPrecio(2000);

     cout << "El precio del coche es: " << coche_Sara.getPrecio() << "$" << endl;

    return 0;
}