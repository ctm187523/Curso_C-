/*
    Las Structs, son estructuras muy similares a las clases donde se agrupan variables bajo un mismo nombre, como empaquetar
    variables

    Las Structs sirven para organizar información en un solo bloque, a diferencia con las clases todos sun miembros son públicos,
    son ideales para representar datos simples y estructuras sin lógica completa.

    Usamos Structs cuando solo necesitamos guardar y acceder a datos de forma directa  y usamos clases
    cuando queremos encapsular, validar o proteger los datos
*/ 

#include <iostream>
using namespace std;


class PersonaClass{

        //si no ponemos modificador son private en las clases
        string nombre;
        int edad;


        string get_datos(){

            return "El nombre es: " + nombre + " y la edad: " + to_string(edad);
        }

};

//las struct tiene una alta compatibilidad con C, vienen de C las structs
struct PersonaStruct{

    //son siempre public los atributos de la struct
    string nombre;
    int edad;

    //puede haber metodos en las Structs pero no es habitual, si los hay son sencillos
    string get_datos(){

        return "El nombre es: " + nombre + " y la edad: " + to_string(edad);
    }

};



int main(){

    //creamos una instancia de la clase
    PersonaClass p;

    //lo comentamos al ser los metodos private no podemos acceder a la clase, las 3 sentencias dan error
    //debemos tener en la clase metodos setter y getter
    //p.nombre="Juan";   
    //p.edad=18;
    //cout << p.get_datos();  

 
    //creamos una instancia de la struct accedemos de igual manera que a la clase
    PersonaStruct ps;
    ps.nombre="Juan";   
    ps.edad=18;
    cout << ps.get_datos();


}

//Usamos STRUCTS porque es mas flexible, las propiedades son publicas y podemos acceder a ellas
//directamente sin usar capsulacion y no tener que usar setters y getters, usamos el mismo ejemplo
//de arriba pero en lugar de poner class ponemos struct, hacemos la Struct justo debajo de la clase