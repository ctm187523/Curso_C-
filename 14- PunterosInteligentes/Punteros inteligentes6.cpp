#include <iostream>
using namespace std;


//ES EL MISMO CODIGO DE PunterosInteligentes5.cpp PERO CON PUNTEROS TRADICIONALES 
//Ejemplo de simulación de un juego con PUNTEROS TRADICIONALES (A mano)
// Las 3 grandes diferencias con el código anterior:Gestión Manual (new y delete): En este código estás
//  obligado a escribir new Textura(...) al inicio y delete texturaEnemigo; al final. 
//  Si olvidas el delete, la textura se queda en la memoria RAM para siempre hasta que cierres el juego.
//  Sin contador de referencias: Los punteros tradicionales son variables simples que solo guardan una 
//  dirección de memoria (un número). No tienen funciones como .use_count().
//  No hay forma de saber cuántos enemigos la están usando a menos que crees tú mismo una variable contador.
//  Peligro de Punteros Colgantes (Dangling Pointers): Si por error llamaras a delete texturaEnemigo;
//  antes de que terminen de usarse los enemigos, los enemigos intentarían dibujar con una textura
//  que ya no existe, rompiendo el programa por completo (crash). Los punteros inteligentes evitan esto.
//  En el código con punteros tradicionales, el destructor ~Textura() se ejecuta única y exclusivamente en el momento en
//  que el programa lee la línea delete.
// Si borraras la línea delete texturaEnemigo; de ese programa, el main() terminaría, la consola se cerraría,
// pero el destructor ~Textura() nunca llegaría a ejecutarse durante la vida del programa.
// La textura se quedaría "viva" e inaccesible en la memoria RAM (un Memory Leak).

class Textura {
    private:
        string archivo;
       
    public:
        // Constructor
        Textura(string archivo) : archivo(archivo) {  
            cout << "Cargando textura: " << archivo << endl;
        }

        // Destructor
        ~Textura() {
            cout << "Liberando textura: " << archivo << endl;
        }

        // Método que dibujaría el personaje
        void dibujar() {
            cout << "Dibujando con textura: " << archivo << endl;
        }
};

class Enemigo {
    private:
        Textura* textura; // Puntero tradicional (raw pointer) a la textura

    public:
        // Constructor: Recibe la dirección de memoria de la textura
        Enemigo(Textura* textura) : textura(textura) { 
        }

        // Método para dibujar el enemigo
        void dibujar() {
            textura->dibujar(); // El operador -> se sigue usando igual
        }
};

int main() {
    // 1. CREACIÓN MANUAL: Usamos 'new' para reservar memoria dinámica.
    // Guardamos la dirección en un puntero tradicional 'Textura*'
    Textura* texturaEnemigo = new Textura("texturaEnemigo.png"); 

    {
       // Pasamos el puntero tradicional a los enemigos
       Enemigo enemigo1(texturaEnemigo); 
       Enemigo enemigo2(texturaEnemigo); 
       Enemigo enemigo3(texturaEnemigo); 

       // DIFERENCIA 1: No existe el método .use_count(). 
       // Los punteros tradicionales no tienen ni idea de cuántos objetos los están usando.
       cout << "Propietarios: [No se puede saber de forma automática con punteros puros]" << endl;
       
       enemigo1.dibujar();   
       enemigo2.dibujar(); 
       enemigo3.dibujar(); 
    } // Aquí los enemigos mueren.

    cout << "Salimos del bloque de codigo..." << endl;

    // DIFERENCIA 2: Al salir del bloque, el recurso NO se libera automáticamente.
    // Si no escribimos la siguiente línea, la textura se quedaría "olvidada" en la memoria de la PC (Fuga de memoria / Memory Leak).
    
    // 2. LIBERACIÓN MANUAL: Tenemos que destruir el recurso explícitamente.
    delete texturaEnemigo; 

    return 0;
}
