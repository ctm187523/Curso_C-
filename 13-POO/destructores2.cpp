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


class Persona{

   int* edad;  //puntero que apunta a edad

   //constuctor
   public:
       Persona(int e){
            //guardamos la edad que es un puntero antes definido en el Heap, guardamos un dato en el Heap 
            //ya que uso el operador new, asignacion de memoria dinámica, 
            //debemos crear un destructor para liberar la memoria si no creamos uan fuga de memoria, en este
            //programa no seria problemático pero si en uno más complejo. Ya que consumimos recursos sin liberarlos
            edad=new int(e);  
       }

    //destructor
    ~Persona(){
        delete edad;  //borramos el puntero antes creado para evitar fugas de memoria, eliminamos el recurso
    }
};



int main(){

   
    Persona p1(18);
    
  
}

