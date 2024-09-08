#include<iostream>
#include<vector>
using namespace std;

//metodo que duplica el valor recibido por parametro por referencia(puntero &)
void duplicarElementos(vector<int> &vec){

    for(int &valor:vec){
        valor *=2;
    }
}

//creamos una funcion que tiene un parametro ya definido por defecto veces=1, esto lo hace opcional, el parametro por defecto 
//siempre tiene que estar en el ultimo lugar, podemos tener mas de un parametro por defecto, si tenemos dos parametros por defecto
//ejmplo void mostrarMensaje(string msg = "hola", int veces=1, no podemos llamar al segundo parametro y omitir el primero
//podemos omitir los 2, omitir el segundo, pero no omitir el primero y poner el segundo, esto pasaria si tuvieramos mas parametros,
//los parametros por defecto siempre tienen que estar al final, hacer pruebas
void mostrarMensaje(string msg, int veces=1){

    for (int i=0; i<veces; i++){

        cout << msg << endl;
    }

}


int main(){
    
    vector<int> numeros={1,2,3,4,5};

    cout << "Valores originales: ";

    for (int valor:numeros) {
        cout << valor << " ";
    }

    cout << endl;

    //llamamos a la funcion duplicarElementos que recibe los valores por referencia, ver funcion de arriba,
    //si no fuera asi si los recibiera por valor al imprimir mas abajo en el bucle for saldrian los mismos valores
    //que los originales 1,2,3,4,5 y no los duplicaria
    duplicarElementos(numeros);

    cout << "valores una vez llamada la funcion duplicarElementos: ";

    for(int valor:numeros) {
        cout << valor << " ";
    }

    cout << endl;

    //si no ponemos el segundo parametro solo se imprimira una vez
    mostrarMensaje("hola",5);
}
