#include <iostream>
using namespace std;

//ver https://docs.hektorprofe.net/cpp/07-punteros-memoria/06-tipos-memoria-stack-heap/
// https://www.youtube.com/watch?v=RbyBnpADQS4

int main(){

    //declaramos un puntero int y inicializamos para que apunte a una direccion de memoria, si no inicializamos
    //podria apuntar a una direccion de memoria aleatoria, lo mejor es inicializarlo, aunque sea null con nullptr
    int * int_ptr{nullptr};

    //con new asignamos la memoria en el heap, el puntero esta almacenado en el stack y apunta al espacio creado con new en el heap(memoria dinamica)
    //en el stack(memoria fja) se almacenan las variables locales, llamadas a funciones, punteros
    //pero como puntero apunta a un espacio de memoria en el heap gracias al new
    //el heap esta controlado por el programador, es quien asigna los espacios y los libera(en java y otros es automatico)
    //el stack es memoria fija y lo controla el sistema
    int_ptr=new int;

    //imprimimos la direccion donde el puntero apunta, no la posicion del puntero en el stack si no donde apunta el puntero creado int_ptr
    cout << "direccion de memoria en el heap donde apunta el puntero: " << int_ptr << endl;

    //ahora imprimimos la direccion de memoria del propio puntero en el stack, con el simbolo &
     cout <<  "direccion de memoria en el stack del propio puntero: " << &int_ptr << endl;

     //creamos un puntero y lo asignamos directamente en el heap
     int * int_ptr2 = new int;
     //le asignamos un valor al puntero
     *int_ptr2 = 10;

     //imrpimimos el valor almacenado en el espacio donde apunta el puntero en el heap y luego lo borraremos liberando memoria
     cout << " Valor antes del delete: " << *int_ptr2 << endl;

     //usamos delete para liberar la memoria previamente reservada en el heap, donde apuntaba el puntero
     //el puntero se convierte en un puntero colgante, porque sigue conteniendo la direccion de memoria que ya fue liberada
     delete int_ptr2;

    //tenemos aun la direccion de memoria del puntero a la que apuntaba y que ha sido liberada
     cout << "direccion de memoria aun almacenada: " << int_ptr2 << endl;

    //para elimnar la direccion que apuntaba usamos nullptr
    int_ptr2 = nullptr;

     cout << "ya no apunta a ninguna direccion de memoria: " << int_ptr2 << endl;
}