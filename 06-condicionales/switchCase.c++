
#include <iostream>
using namespace std;

int main() {

    int opcion;

    cout<<"Menu de opciones:" << endl;
    cout<<"1. Mostrar mensaje" <<endl;
    cout<<"2. Calcualr una suma" <<endl;
    cout<<"3. Salir del programa" <<endl;
    cout<<"Introduce la opcion deseada (1,2 0 3)" <<endl;

    cin >> opcion;

    //el condicional switch no admine String ni decimales de entrada, se puede hacer de otra manera con hash pero ya se vera
    switch (opcion)
    {
    case 1:
        cout << "Hola que tal";
        break;
    
    case 2:
        //las varaibles a y b estarian en el ambito de todo el switch case podriamos usarlas en otro case
        int a,b;
        cout << "Introduce dos números enteros: " <<endl;
        cin >> a >> b;
        cout << "La suma de " << a << " y " << b << " es : " << (a+b);
        break;

    case 3:
    cout << "Saliendo del programa";
    break;

    default:
        cout << "Opción no válida";
        break;
    }

    return 0; //no es necesario

}