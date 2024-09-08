#include <iostream>
#include <vector>
using namespace std;

int main(){

    //En los vetores no hay que especificar el numero de elementos son dinámicos pero tambien hay la opción de 
    //indicar un número de elementos si queremos. Del ejemplo de abajo seria con 5 elementos -->vector <int> records (5); 
    vector <int> records{25,45,60,35}; 

    vector <char> letras{'z','w','r'};

    vector <double> salario_base (350, 2125.50); //creamos un vector de tipo double que tendra 350 posiciones y por defecto estaran inicializadas en 2125.50

    //bucle for, bucle determinado sabemos las iteraciones que va a hacer
    for(int i=0; i< 350; i++){

        cout << salario_base[i] << endl;
    }

    //bucle while indeterminado no sabemos las iteraciones que va a haber

    int i=0;

    while( i<salario_base.size()){

        cout << salario_base[i] << " en bucle while " << endl;
        i++;
    }

    //usamos metodos de los vectores
    //cout << records.at(7); //si usamos una variable fuera de rango usando este metodo si que da error controla los elementos
    
    //le damos valores o cambiamos valores con el metodo at
    records.at(3) = 105;

    //vemos e valor en la posicion del vector con el metodo at
    cout << records.at(3) << endl;

    //usamos el metodo push_back para meter un valor al final de manera dinamica sin decir el tamaño inicial
    records.push_back(49);

    cout << records.at(4); //vemos el nuevo elemento añadido al final
    
    }