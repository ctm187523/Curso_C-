/*
                                                         L-VALUES
                                                         --------- 
    L-Value(Left value) es una expresión que representa una ubicación en memoria. Esto significa que un L-value tiene
    una dirección de memoria asociada. ej int z = 15, la z sera el L-Value esta a la izquierda de la expresión

    Características:
    - Puede aparecer en el lado izquierdo de una asignación
    - Puede ser modificado
    - puede incluir variables, referencias, y des-referencias de punteros. 


    R-Value(Right value) , es una expresión que representa un valor temporal que no tiene una ubicación en memoria persistente.
    Se trata de datos que estan a la "derecha" de una asignación.
    en el ejemplo anterior z = 15, 15 seria el R-Value el valor esta a la derecha de la expresión

    
    Características:
    - No puede aparecer en el lado izquierdo de una asignación(excepto en casos de referencia a R-values o con movimientos).
    - Es temporal y suele ser destruido al final de la expresión en la que aparece.
 
*/




#include <iostream>
#include <utility>  // para std::move
using namespace std;


//funcion que recibe una referencia y la incrementa en 5
//con el simbolo & decimos que x es un L-value, es una referencia por la izquierda
void funcion1(int &x){

    x+=5;
}

//con doble && pedimos que un R-value por parametro en la función, un valor en lugar de una referencia
void funcion2(int &&x){

    x+=5;
}

int main(){

    int z=15;  //LValue seria la z, esta en la parte izquierda de la expresión, RValue seria el 15 parte derecha de la expresión

    int b=z;   //Lvalue seria b, en este caso z es un L-value evaluado como R-value

    int h=15;

    int j=20;

    funcion1(h);

    funcion2(move(j));    //con el metodo move(), importado arriba, converitimos un valor L-value en R-value, semántica de movimientos

    cout << "El valor de z es: " << z << endl;    //obtenemos 15

    cout << "El valor de b es: " << z << endl;    //obtenemos 15

    cout << "El valor de h es: " << h << endl;    //obtenemos 20

    cout << "El valor de j es: " << j << endl;    //obtenemos 25


}

