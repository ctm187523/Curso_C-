
#include<iostream>
#include<map>
#include<string>
using namespace std;

//funcion que devuelve un iterador a un elemento específico del mapa
auto buscaEnMapa(const map<string, int>& myMap, const string& key){
    return myMap.find(key); //esta funcion devuelve un iterador si ponemos que devuelve int o string da error, lo que devuelve es map<string, int>::const_iterator
}

int main(){
    
    //Creando y llenando un mapaç
    map<string, int> miMapa = {

        {"manzana", 1},
        {"platano", 2},
        {"naranja", 3},
    };

    //Buscar un elemento en el mapa
    auto it = buscaEnMapa(miMapa, "platano");

    //verificar si el elemento fue encontrado y mostrar su valor
    if (it != miMapa.end()){
        cout << "encontrado 'platano' con el valor: " << it->second << endl;

    }else{
        cout << "'Platano' no se ha encontrado en el mapa." << endl;
    }

    return 0;
}

