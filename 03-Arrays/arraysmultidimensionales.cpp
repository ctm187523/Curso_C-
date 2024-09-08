#include <iostream>
using namespace std;

int main (){

    //array de 3 dimensiones para calcular hora, dias y meses de los coches que pasan en un lugar concreto
    int pasoCoches[24][31][12];

    //de forma manual ingresamos los coches que pasan en la fecha del 15 de mayo a las 2 de la madrugada
    //para las horas lo ponemos tal cual el 0 seria las 12 el 1 para la una etc
    //para el dia tenemos que poner 14 en lugar de 15 ya el dia uno es 0
    //para el mes lo mismo enero es el mes 0 por tanto mayo es el mes 4
    pasoCoches[2][14][4]=4;

    cout << "El numero de coches que pasaron el 15 de mayo a las 2 AM son: "<< pasoCoches[2][14][4]  << endl;

    //rellenamos con mumeros aleatorios el array empezamos por las horas, dias y meses
    for (int i=0;i<24;i++){
        for(int j=0; j< 31;j++){
            for(int z=0;z<12;z++){
                pasoCoches[i][j][z] = rand() % 1000;  //creamos numeros aleatorios entre el 0 y el 1000, si quisieramos numeros aleatorios entre 5 y mil seria--> 5 + rand() % 1000
            }
        }
    }

    //buscamos un dia en concreto
    cout << "El numero de cohces que pasaron el 7 de Noviembre a las 19:00 fueron: " << pasoCoches[19][6][10];

    //si accedemos en c++ en un array en una posicion fuera de rango no marca error seria un Undefined Behavior
    //devuelve un comportamiento indefinido no controla el error como tal
}