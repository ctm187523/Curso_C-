#include<iostream>
#include<vector>
using namespace std;

int main(){

    int edades [] {15,25,27,35,95};

    //usamos auto para que c++ usa la INFERENCIA DE DATOS y detecte de que tipo de dato es, en este caso String
    auto perro = "perro amarron";
    cout << perro << endl;

    //usamos un blucle for-each no tenemos que saber el numero de elementos del array
    //si no sabemos el tipo de dato del array ponemos que es de tipo auto y por INFERENCIA DE TIPO
    //c++ detecta automaticamente el tipo de dato
    for(auto e: edades){
        cout <<  e << endl;
    }

    string email="pepe@gmail.com";

    //pone letra por letra los caracteres de la variable email, lo interpreta como char, podemos usarlo
    // para buscar por ejemplo la @ del email
    for( auto s: email){
        cout << s << endl;
        
    }

    //para este ejemplo usamos el tipo de dato vector, hay que importarlo con include arriba
    //el usuario introduce numeros hasta que al poner 0 sale del bucle while
    vector<int> numeros;

    int num;

    cout << "Introduce varios números. Escribe 0 para salir" << endl;

    //recorremos mientras se introduzca numeros y el numero sea diferente de 0
    while( cin >> num && num!=0 ){
        numeros.push_back(num); //introducimos en el vector los numeros introducidos por el usuario al final
    }

    //mostramos los valores con el bucle foreach, es ideal este bucle porque no sabemos los numeros que se van a introducir
    cout << "Has introducido los siguientes numeros: " << endl;

    for ( int n : numeros) {
        cout << n << endl;
    }
}