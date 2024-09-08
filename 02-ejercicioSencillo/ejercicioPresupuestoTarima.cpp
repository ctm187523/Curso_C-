#include <iostream>
using namespace std;

int main()
{

    const int IVA = 21;
    const int diasValidez{30}; //otra manera de iniciar variables
    const double precioMedia = 35.5;
    const double precioAlta = 55.3;

    int calidadMedia{0}; //iniciamos la varaible en 0
    int calidadAlta = 0;
    double total;
    double totalIva;

    cout << "Presupuesto montaje de tarima" << endl;
    cout << "-----------------------------" << endl;

    cout << "\n¿Cuantos metros quieres instalar de calidad media?" << endl;
    cin >> calidadMedia;

    cout << "¿Cuantos metros quieres instalar de calidad alta?" << endl;
    cin >> calidadAlta;

    total = (calidadMedia * precioMedia) + (calidadAlta * precioAlta );
    totalIva = total * 0.21;

    cout << "el precio total con iva es de " << totalIva << endl;
    cout << "el precio de tarima de calidad media es de " << calidadMedia << endl;
    
    cout << "La validez del presupuestoo es de " << diasValidez << " dias";

    cin >> calidadAlta; //lo he puesto para que al ejecutar el exe no desaparezca la ventana

}
