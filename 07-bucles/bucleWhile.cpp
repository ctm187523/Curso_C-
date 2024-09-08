
#include <iostream>
using namespace std;

int main(){

    int num, suma{0};

    cout << "Introduce un numero (0 para salir)" << endl;

    cin >> num;

    while( num != 0){

        suma+= num;
        cout << "Introduce un numero (0 para salir)" << endl;
        cin >> num;
    }

    cout << "La suma total es: " << suma <<endl;
}