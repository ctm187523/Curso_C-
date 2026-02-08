
//Herencia principio ES UN -> en este caso un Alumno es una Persona, un Profesor es una Persona, etc. Es una relacion de tipo ES UN


#include <iostream>
#include <string>
using namespace std;

//un animal no es un perro
class Animal{

    public:
        //metodo virtual para que se pueda sobreescribir en las clases hijas
        virtual void hacerSonido(){
            cout << "El animal hace un sonido" << endl;
        }

};

//un perro es un animal
class Perro: public Animal{

    public:
        //sobrescribimos el metodo hacerSonido de la clase Animal, con override indicamos que estamos sobrescribiendo un metodo virtual de la clase padre, si no lo hacemos el compilador no nos avisaria de que no estamos sobrescribiendo correctamente el metodo
        void hacerSonido() override{
            cout << "El perro ladra" << endl;
        }

};

int main(){

    //en Java si hacemos, el resultado seria el perro ladra, en C++ si hacemos lo mismo el resultado seria
    // el animal hace un sonido, esto se debe a que en C++ el enlace de los metodos es estático por defecto, 
    //es decir, el compilador determina en tiempo de compilación que metodo se va a ejecutar, en este caso el 
    //metodo hacerSonido de la clase Animal, para solucionar esto en C++ tenemos que usar el polimorfismo, 
    // para eso tenemos que declarar el metodo hacerSonido como virtual en la clase Animal, con esto le indicamos
    // al compilador que el enlace de este metodo es dinámico, es decir, se determina en tiempo de ejecución, con esto el resultado seria el perro ladra
    //Animal a = new Perro();
    //a.hacerSonido(); //El perro ladra

    Perro miPerro;
    Animal a = miPerro; //El animal hace un sonido, esto se debe a que el enlace de los metodos es estático por defecto, es decir, el compilador determina en tiempo de compilación que metodo se va a ejecutar, en este caso el metodo hacerSonido de la clase Animal
    //en la siguiente linia hay un slicing, seria como un corte donde perdemos la parte de la clase Perro que es la que tiene el metodo hacerSonido sobrescrito, por eso el resultado es el animal hace un sonido, para evitar esto tenemos que usar punteros o referencias, con punteros o referencias el resultado seria el perro ladra
    a.hacerSonido(); //El animal hace un sonido, llamamos al metodo hacerSonido de la clase Animal, no al metodo hacerSonido de la clase Perro, en java o c# el resultado seria el perro ladra, en C++ el resultado es el animal hace un sonido, esto se debe a que en C++ el enlace de los metodos es estático por defecto, es decir, el compilador determina en tiempo de compilación que metodo se va a ejecutar, en este caso el metodo hacerSonido de la clase Animal

    //para evitar el slicing tenemos que usar punteros o referencias, con punteros o referencias el resultado seria el perro ladra
    //esto se hace por seguridad, para evitar que se pierda la parte de la clase Perro que es la que tiene el metodo hacerSonido sobrescrito, con punteros o referencias el resultado seria el perro ladra
    Perro* miPerro2 = new Perro();  
    Animal* a2 = miPerro2; //El perro ladra, con punteros o referencias el resultado seria el perro ladra
    a2->hacerSonido(); //El perro ladra, con punteros o referencias el resultado seria el perro ladra

    //con referencias seria de la siguiente manera
    Perro miPerro3;
    Animal& a3 = miPerro3; //El perro ladra, con punteros o referencias el resultado seria el perro ladra
    a3.hacerSonido(); //El perro ladra, con punteros o referencias el resultado seria el perro ladra

    //en Java y C++ siempre el comportamiensto es polimorfico, C++ podemos elegir el comportamiento polimorfico
    //ahorrando recursos, en Java y C# el comportamiento es siempre polimorfico, en C++ el comportamiento es polimorfico solo si usamos punteros o referencias, con punteros o referencias el resultado seria el perro ladra
    //ahorramos recursos como el uso de memoria, ya que no tenemos que crear un objeto de la clase Perro para usar el metodo hacerSonido, con punteros o referencias el resultado seria el perro ladra


}