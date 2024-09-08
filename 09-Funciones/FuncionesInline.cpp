
#include<iostream>
using namespace std;

//ventajas de usar fucnciones inline
// .Optimización de rendimiento
// .Menor tiempo de ejecución
// .El compilador decide, los compiladores modernos deciden si usar una funcion inline o no, incluso si no se ha declarado inline

//Desventajas de usar funciones inline
//Impacto en el tamaño del código, no del codigo fuente sino del código compilado

//declaramos la funcion inline
inline  int sumar(int a, int b){
    return a+b;
}
int main(){

    int x=5, y=3;

    //llamamos a la funcion inline creada arriba, sustituye el cuerpo de la funcion, por la llamada
    //cuando se declara una funcion inline, el compilador intenta expandir el codigo de la fucion al lugar
    //donde se le llama, en lugar de hacer una llamada de función tradicional para reducir recursos
    int resultado = sumar(x,y);

    cout << "la suma de " << x << " y " << y << " es: " << resultado;

}