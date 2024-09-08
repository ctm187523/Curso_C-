/*
    En c++ existen 3 modificadores de acceso para controlar la visibilidad y el encapsulamiento:

    1. Public -> accesible desde cualquier parte del programa(incluidos funciones y clases externas)
    2. Private -> Accesible solo dentro de la misma clase
    3. Protected -> Accesible dentro de la misma clase y desde clases derivadas(herencia)
    
    -cuando no se pone nada es implícito o por defecto, funciona de diferentes maneras dependiendo si
     se aplica a clases o estructuras(struct)
*/

#include <iostream>
using namespace std;

class MiClase {

   protected:         //si no pusieramos nada seria private, modificador de acceso por defecto en clases
        int edad; //Miembro público

    public:
        void setValor(int valor){
            
            if(valor<0 || valor > 100){
                cout << "Esta edad no es posible";
            }
            else edad = valor;
        }



};     //ojo!! al final de la clase lleva un punto y coma


//clase que hereada de la clase MiClase, ponemos : y public con el nombre de la clase que hereda.
//Al heredar ya tenemos los metodos y atributos de la clase padre si la clase padre tiene
//los atributos como protected si son private no los hereda
class Derivada:public MiClase{

    public:
        void getMostrar(){
        cout << "Valor de edad: " << edad << endl;
    }

};

int main(){

    //instanciamos las clases o ejemplarizar clases es lo mismo
    Derivada obj;

    obj.setValor(35);

    obj.getMostrar();
    

    return 0;
}