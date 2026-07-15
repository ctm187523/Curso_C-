//    3. Weak pointers (weak_ptr)
//       Permiten observar un recurso gestionado por shared_ptr sin ser propietarios de él. Ayudan a evitar
//       referencias circulares.


// ESTE CODIGO VIENE DE PunterosInteligentes7.cpp, PERO AQUI SE VE EL PROBLEMA DE LA REFERENCIA CIRCULAR Y LA FUGA DE MEMORIA (MEMORY LEAK)
// Usaremos un puntero débil (weak_ptr) en lugar de un puntero compartido (shared_ptr) en uno de los dos atributos, para que no se produzca la fuga de memoria
// Porque no usar siempre weak_ptr en lugar de shared_ptr? Porque weak_ptr no tiene contador de referencias, por lo que no se puede usar para compartir la propiedad de un objeto
// entre varios punteros inteligentes, solo para observarlo. Por eso, en este caso, usamos weak_ptr en el atributo b de la ClaseA, y shared_ptr en el atributo a de la ClaseB.


#include <iostream>
using namespace std;

//incluimos en la cabecera del programa la libreria de punteros inteligentes, contine unite_ptr, shared_ptr y weak_ptr
#include <memory>


//fijarse en el main que hace esta instruccion primero -> shared_ptr<ClaseA> a = make_shared<ClaseA>();
//como llamamos al constructor de la ClasA y aun no ha sido creada, no sabe qeu es Clase B
//necesitamos hacer una declaracion adelantada o forward declaration es lo que hacemos en la 
//siguiente linea
class ClaseB; //forward declaration, declaramos la clase B antes de definirla, para que la clase A pueda usarla

class ClaseA {

    public:
    weak_ptr<ClaseB> b;  //puntero débil a la clase B, que es un puntero inteligente que permite observar un recurso gestionado por shared_ptr sin ser propietarios de él y asi evitar referencias circulares, ya que no incrementa el contador de referencias del objeto al que apunta

    //constructor
    public:
        ClaseA() {
            cout << "ClaseA creada" << endl;
        }

        //destructor
        ~ClaseA() {
            cout << "ClaseA destruida" << endl;
        }

};


class ClaseB {

    public:
        shared_ptr<ClaseA> a; //el atributo a pertenece a la ClaseB pero es un puntero compartido a la ClaseA, que es un puntero inteligente que permite compartir la propiedad de un objeto entre varios punteros inteligentes
    
    //constructor
    public:
        ClaseB() {
            cout << "ClaseB creada" << endl;
        }

        //destructor
        ~ClaseB() {
            cout << "ClaseB destruida" << endl;
        }

};

int main(){

    shared_ptr<ClaseA> ObjetoA = make_shared<ClaseA>(); //creamos un puntero compartido a la ClaseA, que es un puntero inteligente que permite compartir la propiedad de un objeto entre varios punteros inteligentes
    shared_ptr<ClaseB> ObjetoB = make_shared<ClaseB>(); //creamos un puntero compartido a la ClaseB, que es un puntero inteligente que permite compartir la propiedad de un objeto entre varios punteros inteligentes

    //vamos a contar cuantos propietarios tiene ahora mismo ClaseA y ClaseB, que es 1 cada uno
    cout << "Propietarios de ClaseA: " << ObjetoA.use_count() << endl; //mostramos el numero de propietarios de la ClaseA, que es 1
    cout << "Propietarios de ClaseB: " << ObjetoB.use_count() << endl; //mostramos el numero de propietarios de la ClaseB, que es 1

    ObjetoA->b = ObjetoB; //asignamos el puntero compartido de la ClaseB al atributo b de la ClaseA
    ObjetoB->a = ObjetoA; //asignamos el puntero compartido de la ClaseA al atributo a de la ClaseB

    //vamos a contar cuantos propietarios tiene ahora mismo ClaseA y ClaseB, que es 2 cada uno
    cout << "Propietarios de ClaseA: " << ObjetoA.use_count() << endl; //mostramos el numero de propietarios de la ClaseA, que es 2
    cout << "Propietarios de ClaseB: " << ObjetoB.use_count() << endl; //mostramos el numero de propietarios de la ClaseB, que es 2 

    //Tal como lo tenemos ahora tenemos una referencia circular, ClaseA tiene un puntero compartido a ClaseB y ClaseB tiene un puntero compartido a ClaseA,
    // lo que provoca que nunca se liberen los recursos de memoria, ya que ambos punteros compartidos tienen un contador de referencias mayor a 0,
    // por lo que nunca se ejecutan los destructores de las clases y se produce una fuga de memoria (memory leak)
    // Para que esto no ocurra, debemos usar un puntero débil (weak_ptr) en lugar de un puntero compartido (shared_ptr) en uno de los dos atributos,
    // lo vemos en el archivo PunterosInteligentes8.cpp
}