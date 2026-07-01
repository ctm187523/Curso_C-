#include <iostream>
using namespace std;

//Clase Abstracta Base
//Lo comun lo ponemos en una clase abstracta, Animal todos los animales respiran y tienen edad
//Lo especifico lo ponemos en las interfaces Imamifero no todos los Animales son mamiferos y IVolador no todos los Animales son voladores, pero todos los mamiferos amamantan y todos los voladores vuelan
class Animal {
    public:
        int edad;

        Animal(): edad(0) {}

        virtual void respirar() = 0; //metodo virtual puro, esto hace que la clase Animal sea una clase abstracta, no se puede crear objetos de la clase Animal, solo se pueden crear objetos de las clases que heredan de Animal y implementan el metodo respirar()}

        virtual ~Animal(){}; //destructor virtual, las clases abstractas suelen implementar un destructor virtual

};

//Interfaz
class IMamifero {
    public:
        virtual void amamantar() = 0; //metodo virtual puro, esto hace que la clase IMamifero sea una interfaz, no se puede crear objetos de la clase IMamifero, solo se pueden crear objetos de las clases que heredan de IMamifero y implementan el metodo amamantar()
        virtual ~IMamifero(){}; //destructor virtual, las interfaces suelen implementar un destructor virtual
};
//Interfaz
class IVolador {

    public:
        virtual void volar() = 0; //metodo virtual puro, esto hace que la clase IVolador sea una interfaz, no se puede crear objetos de la clase IVolador, solo se pueden crear objetos de las clases que heredan de IVolador y implementan el metodo volar()
        virtual ~IVolador(){}; //destructor virtual, las interfaces suelen implementar un destructor virtual    
};

//Hereda de Animal e implementa las interfaces IMamifero e IVolador
//Tiene que desarrollar los metodos de la clas Animal y de las interfaces IMamifero e IVolador
class Murcielago: public Animal, public IMamifero, public IVolador {
    public:
        //metodo propio de la clase Murcielago
        void dormir() {
            cout << "El murciélago duerme boca abajo" << endl;
        }
        //desarrollamos el metodo respirar() de la clase Animal y los metodos amamantar() de la interfaz IMamifero 
        //y el metodo volar() de la interfaz IVolador
        void respirar() override {
            cout << "El murciélago está respirando" << endl;
        }
        void volar() override {
            cout << "El murciélago vuela guiándose por ultrasonidos" << endl;
        }
        void amamantar() override {
            cout << "El murciélago es un mamífero y amamanta a sus crias" << endl;
        }
};

int main() {


    Murcielago miMurcielago;
    miMurcielago.dormir();
    miMurcielago.volar();
    miMurcielago.amamantar();
    miMurcielago.respirar(); 
    miMurcielago.edad = 5; 
    
    cout << "El murciélago tiene " << miMurcielago.edad << " años" << endl;
}