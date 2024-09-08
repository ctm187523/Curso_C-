
#include<iostream>
using namespace std;

//las funciones auto return o dedución automática del tipo de retorno en funciones es una característica introducida
//en el estandar c++14. Permite que el compilador deduzca automaticamente el tipo de retorno de una función basandose
//en el tipo de valor que retorno, simplifica la escritura de código y permite trabajar con tipos complicados o plantillas
// es util para tipos complejos, genericos, anidados profundos, funciones lambda, variables auto, definidas por el programador,
//con funciones con return condicionales depende le return en funcion del if condicional
auto suma(int a,int b){
    return a +b ;
}

int main(){

    int x=5;
    int y=3;

    int resultado = suma(x,y);

    cout << "resultado de la suma " << resultado;
}