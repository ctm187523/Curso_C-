#include <iostream>
#include <string>
using namespace std;

//funcion para pasar dos parametros y intercambiar sus valores
//indicamos con el simbolo & que los parametros son referencias, si no son referencias se crean copias de variables locales
//por valor y no intercambia el valor fuera del ambito de la funcion.
void intercambio(int &a, int &b){

    int temp = a;

    a = b;

    b = temp;
}

int main(){

    int var1 = 10;
    int var2 = 20;

    cout << "Antes del intercambio: var1 = " << var1 << " var2 = " << var2 << endl;

    intercambio(var1, var2);

    cout << "después del intercambio: var1 = " << var1 << " var2 = " << var2 << endl;

}