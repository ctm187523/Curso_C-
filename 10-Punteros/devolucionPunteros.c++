//Funciones que devuelven punteros
// -Acceso a Estructuras de Datos o Clases: Devolviendo un puntero a una instancia, permites que otras partes de tu 
//  programa interactúne con ella
// -Eficiencia en la gestión de la memoria: Al devolver un puntero, evitas la copia innecesaria de datos, ya que simplemente
//  estás pasando la dirección de memoria donde reside el objeto o los datos
// -Control sobre la vida útil de los Objetos: Cuando devuelves un puntero a un objeto creado dinámicamente ( por ejemplo, usando
//  new),puedes controlar cuanto tiempo existe ese objeto. El objeto puede seguir existiendo incluso después de que la función
//  que lo creó haya terminado su ejecución, con delete borrariamos
// -Funciones que Devuelven Múltiples Valores: Devolver un puntero a una estructura o arreglo puede ser una forma más eficiente de 
//  devolver múltiples valores, especialmente si el tamaño de resultado no se conoce de antemano.
// -Interfaz de Funciones Polimórficas: Permite que la función devuelva objetos de cualquiera de la clases derivadas, manteniendo la flexibilidad
//  y permitiendo al código que llama tratar esos objetos de manera uniforme a través de punteros a la clase base.


#include <iostream>
#include <string>
using namespace std;

// Definicion de la clase Coche
class Coche{

    //propiedades
    private:
        string modelo;

    //constructor, incializa el modelo del coche
    public:
        Coche(string mod):modelo(mod){}


    //método para obtener el modelo del coche, usa const porque no modifica el estado 
    string getModelo() const {

        return modelo;
    }

};

//Función que crea un nuevo coche y devuelve un puntero a el, es el primer caso expuesto arriba en la teoria
//indicamos que devuelve un puntero de tipo coche
//la ventaja que tiene hacer esto es que podemos diponer de esta instancia desde qualquier parte del programa
Coche* crearCoche(string modelo){

    //creamos un puntero de tipo coche y en almacenamos la creación de un nuevo coche con new, pasandole por parametro el modelo recibido
    Coche* nuevoCoche = new Coche(modelo);
    
    //retornamos el puntero
    return nuevoCoche;
}

int main(){

    //crea Coche llamando a la función crearCoche, almacenamos en la variable miCoche que es un puntero de tipo coche 
    //desde el main podemos manipular un objeto creado fuera del main
    Coche* miCoche=crearCoche("Mazda MX5");

    //accede al modelo del coche a traves del puntero y muestra el modelo
    cout << "Modelo del coche: " << miCoche->getModelo() << endl;

    //Es importante liberar la memoria, decidimos cuando liberar la memoria, debemos hacerlo para no consumir recursos si no la
    //vamos a usar mas
    delete miCoche;

}