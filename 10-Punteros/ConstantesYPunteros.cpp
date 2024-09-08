
/*  Punteros a constantes:
     -puntero que apunta a un valor constante. Esto significa que el valor al que apunta no puede ser modificado a través del puntero,
      aunque el puntero en sí puede cambiar y apuntar a otra dirección.

    Punteros constantes:
      -puntero cuya dirección de memoria no puede cambiar después de su inicialización; sin embargo el valor al que apunta sí que puede ser
       modificado, a menos que también sea constante.
    
    Puntero constantes a constantes:
      -puntero que no pueda cambiar la dirección a la que apunta ni modificar el valor almacenado en esa dirección.
*/

#include <iostream>
using namespace std;

int main(){

    //PUNTEROS QUE APUNTAN A CONSTANTES
    const int edad=10;

    const int salario=2500;

    const int *ptr =&edad; //puntero que apunta a una constante, ponemos const para decir que apunta a una constante pero no es la palabra reservada para indicar que el puntero es una constante

    cout << *ptr <<endl;           //valor al que apunta el puntero imprime 10

    //si podemos hacer que el puntero creado apunta a una direccion de memoria diferente
    ptr=&salario;

    cout << *ptr  <<endl;      //imprime 2500

    //PUNTEROS CONSTANTES
    int edad2=15;
    int* const ptr2=&edad2;//puntero constante ahora el puntero es constante el asterisco va delante de const, debemos inicializar al declarar el puntero constante
    int salario2=2500;

    //ahora podemos modificar el valor al que apunta el puntero constante pero no podemos apuntar a una direccion distinta de memoria
    *ptr2=20;

    cout << *ptr2 << endl;   //salida 20

    //ptr2=&salario2;    //no podemos apuntar a otra direccion de memoria

    //PUNTERO CONSTANTE QUE APUNTE A UNA CONSTANTE
     const int edad3=45;            //constante

     const int* const ptr3 = &edad3;  //puntero constante que apunta a una constante

     //no podemos modificar ni el valor ni a la direccion de memoria que apunta el puntero constante

}