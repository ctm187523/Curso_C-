
#include <iostream>
using namespace std;

int main (){

    //averiguar si el numero es par o impar
    int number{};

    cout << "introduce un número entero" << endl;
    cin >> number;

   // (number%2 == 0) ? cout << number << " es par" : cout << number << " es impar";

   //lo hacemos de otra manera
   cout << number << " es " << ((number%2 == 0) ? " par" : " impar");

    
}