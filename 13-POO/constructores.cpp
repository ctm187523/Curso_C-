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


class Persona{

//constructor debemos hacerlo public si no por defecto es privado
public:
    Persona(){

        cout << "Hola! soy el constructor";
    }

};



int main(){

    Persona p1;

  
}