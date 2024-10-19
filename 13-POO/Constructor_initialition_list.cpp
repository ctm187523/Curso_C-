#include <iostream>
using namespace std;


class Persona {


    private:
        string nombre;
        int edad;

    public:

        //constructor lo comentamos porque el constructor lo hacemos de la manera constructor initialization list
        // Persona(string nom, int ed){
        //     nombre = nom;
        //     edad = ed;
        //     cout << "Constructor llamado"  << endl;
        // }

        //cosntructor initialization list, la inicializacion la hacemos antes de los corchetes
        //esta manera de hacer el constructor es mas eficiente, el código del constructo iria entre los corchetes
        Persona(string nom, int ed):nombre(nom), edad(ed){
            cout << "Constructor llamado"  << endl;
        }

    void mostrarDatos() const {
        cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
    }

};


int main() {

    Persona p1("Carlos", 30);
    p1.mostrarDatos();
}