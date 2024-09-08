
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

//metodo que da una temperatura aleatoria entre 20 y 40 grados
double leerTemperatura(){

    return 20.0 + ( rand() % 20); //rand crea un numero aleatorio entre 0 y 20(%20) el 20 exclusivo, siempre son los mismos numeros ya que es la misma semilla
}

//usamos la programacion concurrente para dormir el hilo principal
//cada 3 segundos(recibido por parametro) para simular que un dispositivo da la tempertatura cada 3 segundos
void esperarSegundos(int segundos) {

    //creamos un hilo y decimos que duerma los segundos recibidos por parametro
    this_thread::sleep_for(chrono::seconds(segundos));
}


int main() {

    const double LIMITE_TEMPERATURA=35.0;

    //creamos un bucle infinito para que el programa este permanentemente
    //a la escucha del dispostivo que da la temperatura,el bucle nos avisara cuando la temperatura
    //supere los 35 grados
    while(true){

        double tempActual = leerTemperatura();

        cout << "Temperatura actual: " << tempActual << endl;
        
        if(tempActual > LIMITE_TEMPERATURA){
            cout << " !! ALERTA !! la temperatura es superior a 35 grados" << endl;
        }
        esperarSegundos(3);
    }

}