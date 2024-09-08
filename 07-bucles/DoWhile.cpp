
#include<iostream>
using namespace std;


int main(){

    int opcion;


    //El bucle do-while al menos se ejecuta una vez
    do{

        cout << "Menú de opciones:\n";
        cout << "1. Opcion 1\n";
        cout << "2. Opcion 2\n";
        cout << "3. Salir 1\n";

        cin >> opcion;

        if(opcion!=3) cout << "Has elegido la opcion " << opcion << ".\n";
        

    }while(opcion!=3);
   
    cout << "Has elegido salir";

}