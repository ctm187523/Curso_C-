
// Problemas con punteros conocidos como POINTERFALLS
// Causas:
//1. Desreferenciación de punteros nulos. intentar acceder o modificar a un puntero que no ha sido inicializado o es nulo
//2. Fugas de memoria(Memory leaks), se pierde la referencia de bloques de memoria sin ser liberado y no se puede acceder a ese bloque, pasa si no se libera la memoria asignada con new
//3. Desbordamiento de buffer(Buffer overflow), se accede o escribe mas haya del limite de un array
//4. Doble liberación(Double free), liberar la misma memoria mas de una vez
//5. Punteros colgantes(Dangling pointeres), mencion a memoria previamente liberada, se libera la memoria pero el puntero sigue apuntando
//6. Violación de acceso (Acces violation), acceder a memoria que no se puede acceder, no se tiene permiso

#include <iostream>
#include <string>
using namespace std;

int main(){

    //1. Desreferenciación de punteros
    int* ptr = nullptr; //puntero nulo no esta referenciado a ninguna posicion de memoria

   //hacemos una comprobación de si el puntero es nulo para evitar errores, ya que el puntero que contiene es nulo
    if(ptr!=nullptr){
         *ptr = 10; //DA ERROR YA QUE ESTAMOS DANDO UN VALOR A UN PUNTERO NO INICIALIZADO NO ESTA REFERENCIADO A NINGUNA POSICION DE MEMORIA

    }

    //2. Fugas de memoria(Memory leaks)
    int* ptr2 = new int[10]; //asignamos una memoria con new
    
    //reasignamos la memoria anterior
    ptr2 = new int[20];

    delete[] ptr2; //con esta instruccion eliminamos la asignacion anterior la de int[20], pero queda sin liberar la de int[10], con lo cual queda consumiendo recursos, deberiamos de haber liberado la primera antes de reasignar la segunda

    //3. Desbordamiento de buffer(Buffer overflow), los punteros y los array estan relacionados en c++, si accedemos a elementos fuera del array sale este tipo de error

    //4. Doble liberación(Double free)
    int* ptr3 = new int; //creamos y asignamos un puntero

    delete ptr3; //liberamos el puntero anterior

    if(ptr!=nullptr) delete ptr3; //volvemos a liberarlo ESTO PUEDE DAR LUGAR A COMPORTAMIENTOS INDEBIDOS ERRORES EXTRAÑOS YA QUE DE SINTAXIS NO DA ERROR, hacemos una comprobación previa para evitar que esto ocurra


    //5. Punteros colgantes(Dangling pointeres)
    int* ptr4 = new int(10); //creamos y asignamos y inicializamos un puntero

    delete ptr4;  //lo borramos

    if(ptr!=nullptr) *ptr=5; //ERROR EL PUNTERO YA HA SIDO LIBERADO, hacemos comprovacion para evitar error


    //6. Violación de acceso (Acces violation)
    int array[5]={0,1,2,3,4}; //creamos un array y lo inicializamos

    //puntero que apunta mas halla del final del array
    int* ptr5=&array[4]; //queremos acceder a la posición 5 y no existe DA ERROR, ponemos la 4 para que compile

    int valor=*ptr5;

     cout << "hasta aqui hemos llegado" << endl;
}
