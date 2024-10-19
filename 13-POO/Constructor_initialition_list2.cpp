#include <iostream>
#include <chrono> //incluye la bibioteca chrono para hacer mediciones, queremos medir la diferencia entre usar los 2 constructores en tiempo
using namespace std;

//queremos ver lo que tarda en tiempo usar un constructor normal y un constructor initialition list
//para ello usamos la libreria chronos
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


//comentar y descomentar los constructores para ver las diferencias en lo que tarda en crear 10000 objetos Persona
int main() {

    //usamos la clase chrono para guardar la hora, y poder calcular lo que tarda usamos high_resolution_clock para que sea de alta precision la medicion, now para que registre la hora actual
    auto comienzo =  chrono::high_resolution_clock::now();   //auto para inferencia de tipos en tiempo de ejecucion se le asigna el tipo 
   
   //queremos crear muchos objetos para que le lleve tiempo y se vea la diferecia en eficiencia de los 2 constructores
    for(int i=0; i< 10000; i++) Persona p1("Carlos", 30);   //crea 10000 objetos de tipo Persona
    
    //p1.mostrarDatos();

    //guardamos la hora la finalizar el trabajo
    auto fin =  chrono::high_resolution_clock::now();

    //calculamos la diferencia entre los 2 tiempos hayados para ver la diferencia en usar uno o otro constructor
    //usamos la libreria chrono, usamos sus metodos
    chrono::duration<double> lapso = fin - comienzo;

    cout << "Tiempo de ejecucion: " << lapso.count() << " segundos" << endl;
}