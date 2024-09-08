#include <iostream>
using namespace std;

int main()
{

    const string nombre = "Pepe"; //usamos una constante

    int edad{21}; // otra forma de inicializar variables

    double salario;

    cout << "Introduce el salario del empleado: ";

    cin >> salario;

    cout << "Introduce la edad del empleado: ";

    cin >> edad;

    cout << "----------------------------------------------" << endl;

    cout << "Datos del empleado: " << endl;

    cout << "Nombre: " << nombre << ". Edad " << edad << ". Salario " << salario;
}