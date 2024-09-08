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


int main(){

   string s1="Hola que tal";

   //convertimos s1 en un R-value con move en este caso no lo copiamos como si pusieramos s2=s1, lo movemos 
   //no hacemos copias movemos directamente el contenido de la direccion de memoria, ahorramos recursos
   //en este caso es pocos datos pero podriamos con esta tecnica mover enormes cantidades de datos
   string s2=move(s1);  

   cout << "El contenido es: "  << s1  << endl;  // no imprime nada lo hemos movido con move(s1) a s2

   cout << "El contenido es: "  << s2  << endl;  // imprime -> El contenido es: Hola que tal


}

