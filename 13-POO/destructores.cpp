/*
    DESTRUCTORES
    - Método especial.
    - Mismo nombre que el constructor pero precedido de ~   para el signo ~ usar ALTGR + 4
    - Invocado cuando un objeto es destruido, es automática pero se puede programar según los casos.
    - No devuelven tipo (no return).
    - NO admiten sobrecarga. Solo un destructor por clase.No llevan parámetros.
    - Útil para liberar memoria y recursos
    - *Nota: Todas las clases tienen un destructor por defecto, de igual manera como el constructor de una clase.
    - El destructor por defecto elimina cosas del Stack pero no del Heap

    ¿CUANDO ES NECESARIO USAR EL DESTRUCTOR?
    -Memoria dinámica:
        -si tu clase asigna memoria dinámica con new o new[], debes liberar esa memoria en el destructor usando
        delete o delete[]. Si no lo haces, tendrás fugas de memoria.
    -Archivos abiertos:
        -Si tu clase abre archivos, deberías cerrarlos en el destructor para liberar correctamente esos recursos.
    -Conexiones de red o BBDD(Base de datos):
        -Si tu clase establece conexiones a bases de datos o redes, el destructor debe cerrarlas para evitar
        mantener recursos innecesarios abiertos.
    -Handles / Recursos del sistema:
        -Cualquier otro recurso del sistema operativo, como descriptores de archivos mutexes o recursos gráficos,
        también deben ser liberados adecuadamente con el destructor.

    DIFERENCIAS ENTRE TIPOS DE MEMORIA
    TIPO DE MEMORIA         UBUCACIÓN           AISIGNACIÓN         LIBERACIÓN      ALCANCE         EJEMPLO DE USO
    Automática(pila)        Stack(pila)         Automática en       Automática      Dentro de un    Varialbles
                                                tiempo de           al salir del    bloque o        locales dentro
                                                compilación         bloque          función         de funciones
    
    Dinámica(montón)        Heap(montón)        Explícita con       Manual con      Mientras se     Estructuras de   
                                                new/new[]           delete/         gestione        datos dinámicas    
                                                                    delete[]        manualmente     arrays de tamaño
                                                                    destructores                    dinámico

    Estática(global)        Memoria             En tiempo de        Automática      Todo el         Variables 
                            estática            compilación         al final del    programa        globales y
                                                                    programa                        estáticas
                                                                                                    locales.
 */


#include <iostream>
using namespace std;


class Rectangulo{

    //propiedades
    private:
        int ancho;
        int alto;
        string nombre;

    //constructor debemos hacerlo public si no por defecto es privado
    public:
        Rectangulo(string nom){

            ancho=10;
            alto=5;
            nombre = nom;
        }

        //sobrecarga de constructores, creamos otro constructor
        Rectangulo(int medida, string nom){

            ancho = medida;
            alto = 4;
            nombre = nom;
        }

        //sobrecarga de constructores, creamos otro constructor
        Rectangulo(int an, int al, string nom){

            ancho = an;
            alto = al;
            nombre = nom;
        }

    //implementamos un destructor aunque viene uno por defecto, usa el signo ~
    //no haria falta crearlo en este ejemplo, al ejecutar el programa aparece 3 veces
    //una vez por cada llamada en el main a los 3 objetos rectángulos muestra el nombre, al liberar los recursos 
    //como todo esta en el stack ya que no usamos en el main el new, se libera automáticamente
    //El STACK es una pila de tipo LIFO, el último que entra es el primero que sale
    ~Rectangulo(){

        cout << "Destructor invocado para objeto " << nombre  << endl;
    }

};



int main(){

    Rectangulo r1("r1");  //llamamos al primer constructor que no tiene parametros

    Rectangulo r2(12,"r2");  //usamos el segundo constructor le pasamos la medida

    Rectangulo r3(17,9,"r3"); //usamos el tercer contructor le pasamos los dos parametros requeridos

  
}

