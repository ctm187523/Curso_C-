//VER IMAGEN EN C:\Users\cleme\Documents\C++\13-POO\Herencia\DiamondProblem.png
#include <iostream>
using namespace std;

class Animal {
    public:
        int edad;

        Animal(): edad(0) {}

        void respirar() {
            cout << "El animal está respirando" << endl;
        }
};

//añadimos la palabra reservada virtual para evitar el proble de ambiguedad del Diamond Problem
//con esto conseguimos que Mamifero y Volador compartan un unica copia de edad y respirar()
class Mamifero: virtual  Animal {
    public:
        void amamantar() {
            cout << "Soy un mamífero y amamanto a mis crias" << endl;
        }
};

//añadimos la palabra reservada virtual para evitar el proble de ambiguedad del Diamond Problem
//con esto conseguimos que Mamifero y Volador compartan un unica copia de edad y respirar()
class Volador: virtual public Animal {

    public:
        void volar() {
            cout << "Soy un animal volador y puedo volar" << endl;
        }
};

//Murcielago al heredar de Mamifero y Volador hereda todo o que tiene Mamifero y todo lo que tiene Volador
//A su vez Mamifero y Volador heredan de Animal, entonces Murcielago tiene dos copias de Animal, una copia de Animal que hereda de Mamifero y otra copia de Animal que hereda de Volador
//Esto puede causar problemas de ambiguedad
//Mamifero de Animal hereda el atributo edad y el metodo respir
//Volador de Animal hereda el atributo edad y el metodo respirar
//Murcielago tiene dos copias del atributo edad y dos copias del metodo respirar que herdan de Mamifero y Volador y a su vez ellos lo heredadn de Animal
//Entonces como tienes dos edad, cual de las dos edad estas usando, la de Mamifero o la de Volador, lo mismo con el metodo respirar, cual de las dos respirars estas usando, la de Mamifero o la de Volador
//En resumen heredad 2 edades y dos metodos respirar()
class Murcielago: public Mamifero, public Volador {
    public:
        void dormir() {
            cout << "El murciélago duerme boca abajo" << endl;
        }
};

int main() {

    //Hasta aqui no hay problema
    Murcielago miMurcielago;

    miMurcielago.dormir();
    miMurcielago.volar();
    miMurcielago.amamantar();

    //El problema esta si quiero usar el metodo respirar()
    //Tenemos un error por la ambiguedad que comento arriba, en el error dice que es ambiguousç
    //miMurcielago.respirar();
    //comento lo de arriba para solucionarlo puedo hacer referencia de a quien me refiero:
    // miMurcielago.Mamifero::respirar(); //le digo que quiero usar el metodo respirar() que hereda de Mamifero
    //Comento lo de arriba usaremos la herencia virtual para solucionar el problema de ambiguedad, 
    //con la herencia virtual se crea una sola copia de la clase Animal, y se comparte entre las clases Mamifero y Volador, 
    //lo que soluciona el problema de ambiguedad
    miMurcielago.respirar(); // ahora si funciona hemos usado virtual al crear las clases Mamifero y Volador

    // lo mismo para para la edad, comento abajo
    //miMurcielago.edad = 5;
    //para desaparecer el error puedo hacer referencia de a quien me refiero:
    //miMurcielago.Mamifero::edad = 5; 
    //comento lo de arriba usaremos la herencia virtual para solucionar el problema de ambiguedad,
    //con la herencia virtual se crea una sola copia de la clase Animal, y se comparte entre las clases Mamifero y Volador,
    //lo que soluciona el problema de ambiguedad
    miMurcielago.edad = 5; // ahora si2 funciona hemos usado virtual al crear las clases Mamifero y Volador
}