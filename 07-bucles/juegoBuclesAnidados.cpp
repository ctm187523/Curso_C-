
#include <iostream>
#include <cstdlib> //para los metodos rand() y srand()
#include <ctime>   //para el metodo time
using namespace std;

int main()
{

    //propiedades

    // metodo srand() importado arriba en las librerias para cambiar la semilla de los numeros aleatorios
    // usamos la funcion time de la libreria ctime importada arriba, devuelve el tiempo actual(en segundos desde 1-1-1970)
    //  y de esta manera la semilla sera distinta cada vez.
    srand(time(nullptr)); // como argumento pasamos nullptr para obtener el instante actual cuando se ejecuta el programa

    char continuar;

    //bucle principal
    do
    {

        int numeroSecreto = rand() % 100 + 1; // obtenemos un numero entre 1 y 100 cada vez distinto ya que arriba cambiamos la semilla cada vez
        int intentos = 0;
        bool adivinado = false;

        // bucle while anidado
        while (intentos < 5 && !adivinado)
        {

            int miNumero;            
            cout << "Introduce un número entre 1 y 100 \n";
            cin >> miNumero;

            if (miNumero == numeroSecreto)
            {

                cout << "¡Acertaste! \n";
                adivinado = true;
            }
            else if (miNumero < numeroSecreto)
                cout << "El numero es mayor. \n";
            else
                cout << "El numero es menor. \n";

            intentos++;
        }

        if (!adivinado)
            cout << "Lo siento no has adivinado el numero. Era el número: " << numeroSecreto << ".\n";

        cout << "Quieres jugar de nuevo? (s/n)";

        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    cout << "Gracias por jugar!";
}
