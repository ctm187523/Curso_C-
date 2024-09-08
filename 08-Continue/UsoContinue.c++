
#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<double> precios = {50,120,75,300,90,200};

    double descuento=0.15;

    //recorremos el bucle y si el precio es menor 0 igual a 100
    //no aplicamos el descuento usamos continue si se cumple la
    //condicion y de esta manera pasamos a la siguiente iteracion
    //del bucle, la diferencia con break es que con break saldriamos
    //del bucle saltando las demas iteraciones
    for (int i = 0; i < precios.size(); i++)
    {
        if(precios[i] <= 100){
            continue;
        }

        precios[i]-=precios[i]*descuento;
    }

    for (int i = 0; i < precios.size(); i++)
    {
        cout << "Precio final del producto: " <<(i+1) << ": " << precios[i] << endl;
    }
 
}


