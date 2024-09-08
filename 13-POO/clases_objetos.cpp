#include <iostream>
using namespace std;

class Coche {

    //atributos o propiedades
    string modelo;
    int cilindrada;
    int potencia;
    string color;
    double precio;

    //metodos

    void arrancar(){
        cout << "El cochle esta arrancado." << endl;
    }

    void acelerar(){
        cout << "El cochle esta acelerando." << endl;
    }

    void frenar(){
        cout << "El cochle esta frenando." << endl;
    }

    void girar(){
        cout << "El cochle esta girando." << endl;
    }

     bool en_marcha(){
        return true;
    }
};     //ojo!! al final de la clase lleva un punto y coma

int main(){

    //instanciamos las clases o ejemplarizar clases es lo mismo
    Coche coche_Pepe;

    Coche coche_Sara;

    return 0;
}