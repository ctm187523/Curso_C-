
//En C++ sintácticamente no hay diferencia entre una clase abstracta y una interfaz, 
//la diferencia es semántica

#include <iostream>
#include <string>
using namespace std;


//para ver si es una clase abtracta usamos el princpio es un 
//al hacer es-un hacemos referencias a objetos, pertenencia 
//en el ejemplo en el archivo clasesAbstractas.cpp se muestra el ejemplo de la clase Animal, que es una clase abstracta
//y todas las clases que heredan de Animal son animales, todos es-un animal.
//En las interfaces no se hace referencia a objetos, pertenencia hacemos referencia a capacidades, comportamientos
//que puede hacer en este ejemplo mostramos la clase Volador y los que heredan de el 
//hace referencia a una capacidad es decir un Pajaro puede volar, un avion tambien etc.
//es una diferenciacion semantica, no sintactica no hay ninguna palabra reservada que indique que es una interfaz
//como en Java que usa la palabra reservada interface(ver imagen de la tabla adjunta al proyecto ->C:\Users\cleme\Documents\C++\13-POO\ClasesAbstractasVersusInterfaces.png)
//Es dificil aveces diferenciar entre clase abstracta e interfaz
//las interfaces no suelen tener atributos ni metodos implementados, es una manera de diferenciar entre clases abstractas e interfaces
//Las interfaces suelen implementar un destructor 

//Las interfaces se usan para poder usar la herencia multiple
//En c++ tenemos herencia multiple, con la herencia multiple podemos tener el problema llamado Diamond Problem
//que consiste en que si tenemos una clase A que hereda de una clase B y una clase C, y la clase B y la clase C heredan de una clase D, entonces la clase A tiene dos copias de la clase D,
// lo que puede causar problemas de ambiguedad, para solucionar este problema se usa la palabra reservada virtual al heredar de la clase D, esto se llama herencia virtual, con la herencia virtual 
//se crea una sola copia de la clase D, y se comparte entre las clases B y C, lo que soluciona el problema de ambiguedad, en este ejemplo no tenemos el problema del Diamond Problem porque no tenemos 
//herencia multiple, pero si tuvieramos herencia multiple tendriamos que usar la palabra reservada virtual al heredar de la clase D para solucionar el problema del Diamond Problem

//el diamond problem lo veremos en el siguiente ejemplo
//las interfaces se usan para solventar o simplificar este problema de Diamond Proble
class IVolador{     //por convencion se pone una I al inicio para diferenciar que es una interfaz
    public:
        virtual void puedoVolar()=0;  

        //destructor, las interfaces suelen implementar un destructor virtual
        virtual ~Volador(){}; 
}

class Pajaro: public IVolador{
    public:
        void puedoVolar() override{
            cout << "Vuelo batiendo mis alas" << endl;
        }
};

class Avion: public IVolador{
    public:
        void puedoVolar() override{
            cout << "Vuelo consumiendo combustible" << endl;
        }
};

class Murcielago: public IVolador{
    public:
        void puedoVolar() override{
            cout << "Vuelo guiándome por ultrasonidos" << endl;
        }
};

class Superman: public IVolador{
    public:
        void puedoVolar() override{
            cout << "Vuelo utilizando mis super poderes" << endl;
        }
};

