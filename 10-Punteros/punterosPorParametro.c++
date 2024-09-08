//PASO DE PUNTEROS POR PARÁMETROS
//- Modificacion Directa: permite modificar la variable original sin necesidad de retornar que la funcioón retorne un valor y asignarlo y sin hacer copias
//- Eficiencia en la Transmisión de Datos Grandes: Al pasar solo la dirección de memoria de un objeto grande(como arrays o estructuras complejas),
//  se ahorra tiempo y memoria porque no es necesario copiar todo el objeto
// -Trabajo con Arrays y Cadenas: Los arrays se pasan por defecto como punteros a sus primeros elementos, lo que hace que trabajar con ellos
//  mediante funciones sea natural y eficiente
// -Gestión de Memoria Dinámica: Facilita el trabajo con memoria dinámica (asignada con new o malloc), permitiendo que las funciones modifiquen
//  estructuras de datos complejas o arrays dinámicos
//PASO POR REFERENCIA VERSUS PASO DE PUNTEROS
//--POR PARÁMETRO POR REFERENCIA A FUNCIONES:
//  1.No trabajas directamente con direcciones de memoria en el código
//  2.Acceso directo al original, sin necesidad de desreferenciar.
//  3.Sintaxis y el manejo son generalmente más sencillos y seguros
//  4.No permite trabajo a bajo nivel y trabajo con la memoria
//--PASAR PUNTEROS POR PARÁMETRO A FUNCIONES:
//  1.Pasas dirección de memoria de variable
//  2.Hay que desreferenciar el puntero para modificar el valor al que apunta
//  3.Sintaxis más compleja
//  4.Permite el trabajo a bajo nivel y el trabajo directamente con la memoria.


//La ventaja de usar punteros por parametros es que en tiempo de ejecución no hay que hacer una copia de la variable y es mas eficiente

#include <iostream>
using namespace std;


//funcion que recibe un puntero por parámetro, no devuelve nada es void ya que al pasar un puntero podemos modificar el valor de la variable directamente
void cambiarValor(int* valor){

    //incrementamos el valor que recibe el puntero en 5, al desreferenciar el puntero con el * accedemos al valor almacenado en la dirección de la memoria
    (*valor)+=5;  
}

int main(){

    int num=5;

    cout << "Antes de llamar a la función: " << num << " con la dirección de memoria: "<< &num << endl;

    //le pasamos como parametro a la funcion creada arriba la dirección de la memoria de la variable num con &
    cambiarValor(&num);

    cout << "Después de llamar a la función: " << num << endl;

}

