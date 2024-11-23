//                  Delegacion de constructores
/*
    Que es la delegación de constructores?
    - Como su nombre indica,"delegar" el trabajo de un constructor en otro constructor de la misma clase
    Para que sirve?
    - Para evitar la duplicidad de código bajo algunos escenarios, cuando hay sobrecarga de constructores

    Introducido en C++ en la version 11
*/ 

#include <iostream>
using namespace std;


class CuentaBancaria {

    public:
        string titular;
        double saldo;

    //tenemos 2 constructores 
    //vemos que los constructores tienen codigo repetitivo(mismo código) para eso usamos la delegacion de constructores
    //constructor del que conocemos el nombre del titular pero no el saldo, inicializamos el saldo a 0
    //usamos inicialitation list visto anteriormente
    CuentaBancaria(string t): CuentaBancaria(t,0.0){ //llamamos al constructor de abajo para delegar el código repetitivo comentado, le pasamos el valor del parametro recibido y el segundo lo ponemos por defecto a 0.0, este constructor solo recibe un parametro, al que delegamos recibe 2 parametros

        //comentamos la linea de código de abajo porque al tener los 2 constructores el mismo código
        //delegamos código de un constructor a otro, ver en la linea 25 como llamamos al constructor de abajo pasandole los parametros y dentro de este constructor no ponemos código ya que es el mismo
        //cout << "Cuenta creada para el cliente " << titular << " con un saldo de " << saldo << endl;
    }

      //constructor del que conocemos el nombre del titular y el saldo
      //usamos inicialitation list visto anteriormente
    CuentaBancaria(string t, double s): titular(t), saldo(s){

        cout << "Cuenta creada para el cliente " << titular << " con un saldo de " << saldo << endl;
    }

    //en C++ tambien podemos usar constructores con parametros opcionales con valores por defecto, lo comentamos se muestra solo para ver que existen
    // CuentaBancaria(string t, double s=0.0):titular(t), saldo(s){

    //     cout << "Cuenta creada para el cliente " << titular << " con un saldo de " << saldo << endl;
    // }
};

int main(){

    CuentaBancaria cuenta1("Maria"); //no conocemos el saldo
    CuentaBancaria cuenta2("Antonio", 1750.25); //conocemos nombre dle titular y saldo

}