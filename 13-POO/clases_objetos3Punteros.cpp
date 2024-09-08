#include <iostream>
using namespace std;


/*
    ACCESO A PROPIEDADES Y MÉTODOS A TRAVÉS DE PUNTEROS

    Para que los necesitamos:
    - Gestión de memoria dinámica, crear objetos en tiempo de ejecución
    - Herencia y polimorfismo
    - Estructuras de datos dinámicas, listas enlazas, arboles, pilas, colas, gráficos, etc
    - Paso de objetos a funciones, queremos evitar la copia del objeto en memoria al pasarla a la función
      util para objetos grandes y no queremos penalizar el rendimiento
    - Manejo de APIS y Bibliotecas
    - Patrones de diseño, singleton, server, etc.
    - Manejo de funciones Callbacks y manejo de eventos, en tiempo de ejecución
    - Optimización del rendimiento, ejemplo videojuegos, simuladores, procesamientos en tiempo real, los punteros
      gestionan mejor la memoria y maneja mejor objetos grandes.
*/


class Coche {

    //atributos o propiedades, si no tiene modificador son privados, para cambiar a publico, public:
    //a partir del modificador public o private las propiedades que vienen detras se establecen con el ultimo modificador indicado
    string modelo;
    int cilindrada;
    int potencia;
    string color; 
    double precio;     


    //METODOS DE ACCESO para acceder a las propiedades privadas
    public: 
    void setPrecio(double p){
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
    public:
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
}; //ojo!! al final de la clase lleva un punto y coma

int main(){

    //instanciamos las clases o ejemplarizar clases es lo mismo
    Coche coche_Pepe;

    Coche coche_Sara;

   //crear punteros a los objetos creados arriba de la clase Coche
   Coche* ptrCochePepe = &coche_Pepe;
   Coche* ptrCocheSara = &coche_Sara;

   //accedemos a los metodos y propiedades de los punteros creados a los objetos Clase
    ptrCochePepe->setPrecio(37000);  //para acceder a punteros en lugar del . se usa el operador arrow ->
 
    cout << "El precio del coche es: " << ptrCochePepe->getPrecio() << " $" << endl;

    ptrCocheSara->acelerar();

    return 0;
}