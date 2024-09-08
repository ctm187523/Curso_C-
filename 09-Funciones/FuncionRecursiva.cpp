#include<iostream>
using namespace std;


//las funciones recursivas son las que se llaman a sí mismas durante la ejecucción
//puden resolver problemas que pueden ser desglosados en subproblemas mas pequelis de la misma naturaleza
//puede hacer recorrido de estructuras complejas como árboles o grafos, algoritmos de busqueda, algoritmos de
//ordenamiento, algoritmos matemáticos 
//aspectos a tener en cuenta -> debe de tener un Caso base para que detenga la recursion
//en ocasiones puede ser menos eficinete pero con mayor legibilidad


//calcula un factorial de un numero ej: 5! = 5*4*3*2*1
//SIN USAR RECURSIVIDAD
int factorial(int n) {
    
    int resultado = 1; //si pusieramos resutado=2 al acabar el bucle seria 5(2)*4(2)*3(2)*2(2)*1(2) = 240 el doble

    for(int i=1; i<=n; i++){
        resultado = resultado * i;
    } 

    return resultado;
}

//calcula un factorial de un numero ej: 5! = 5*4*3*2*1
//USANDO RECURSIVIDAD
int factorialRecursivo(int n) {
    
    if(n==0){
        return 1; //Caso base, detiene la recursividad
    }else{
        //cada vez que da una vuelta(numero introducido 5) primera vuelta--> 5*factorialRecursivo(4), segunda -> 4*factorialRecursivo(3) 
        //tercera -> 3*factorialRecursivo(2) , cuarta -> 2*factorialRecursivo(1) , quinta -> 1*factorialRecursivo(0), a la siguiente sale n=0 return 1
        //quedan a la espera en memoria con su valor porque no sabe que es factorialRecursivo(n) hasta que n=0 Caso base y se resuelve devolviendo todo
        //lo que habia estado a la espera es decir 5(1)*4(1)*3(1)*2(1)*1(1) ya que factorial finalmente vale 1 cuando n=0 multiplicamos todos por 1 
        return n*factorialRecursivo(n-1); //llamamos a la propia funcion, recursividad, ver explicacion video 41 minuto 15
    }
}

int main(){

    
    int numero;

    cout << "introduce un número" << endl;
    cin >> numero;

    //llamamos a la funcion sin recursividad
    int resultado = factorial(numero);

    cout << "el factorial hayado con la funcion no recursiva del número " << numero << " es: " << resultado << endl;

    //llamamos a la funcion con recursividad
    resultado = factorialRecursivo(numero);

    cout << "el factorial hayado con la funcion recursiva del número " << numero << " es: " << resultado << endl;

}