#include <iostream>
using namespace std;

int main(){

    //matriz bidimensional de 4 filas y 5 columnas total 20 elementos
    int mi_matriz [4][5]= {15,25,8,-7,92,77,12,11,7,55,56,12,45,23,5,67,54,23,1,78};

    //cout << "el numero es: " << mi_matriz[0][2];

    //bucle for para introducir los valores por parte del usuario, sobreescribimos los valores anteriores
    for(int fila=0;fila<4;fila++){
        for(int columna=0;columna<5;columna++){

            cout << "introduce un numero" << endl;
            cin >> mi_matriz[fila][columna];
            cout << "el numero introducido es: " << mi_matriz[fila][columna]<< endl;
        }
    }

    cout << "visualizamos ahora los valores almacenados en el array" <<endl;

    //bucle for para visualizar los valores introducidos por parte del usuario, sobreescribimos los valores anteriores
    for(int fila=0;fila<4;fila++){
        for(int columna=0;columna<5;columna++){

            cout <<  mi_matriz[fila][columna];
        }

        cout << endl;
    }
}