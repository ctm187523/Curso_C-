#include <iostream>
using namespace std;

int main()
{

    // selecciona el idioma Español(E) Ingles(I) por defecto solo adminte char no estring
    // una vez seleccionado seleccionar libros(l), Ropa(R), Tecnologia(T) debe decir que categoria
    // ha seleccionado el usuario

    char idioma, opcion;

    cout << "Selecciona idioma Español(E), Ingles(I)";
    cin >> idioma;

    idioma = toupper(idioma); // pasamos a mayúsculas

    switch (idioma)
    {
    case 'E':
        cout << "Selecciona una opcion Libros(I), Ropa(R), Tecnologia(T)";
        cin >> opcion;
        opcion = toupper(opcion);
        switch (opcion)
        {
        case 'I':
            cout << "Has seleccionado libros";
            break;
        case 'R':
            cout << "Has seleccionado ropa";
            break;
        case 'T':
            cout << "Has seleccionado tecnologia";
            break;
        default:
            cout << "debes de seleccionar L o R o T" << endl;
            break;
        }
        break;

    case 'I':
        cout << "Choose an option Books(B), Clothing(C), Technology(T)";
        cin >> opcion;
        opcion = toupper(opcion);
        switch (opcion)
        {
        case 'B':
            cout << "You have chosen books";
            break;
        case 'C':
            cout << "You have chosen clothing";
            break;
        case 'T':
            cout << "You have chosen technology";
            break;
        default:
            cout << "you must select B o C o T" << endl;
            break;
        }
        break;

    default:
        cout << "debes de seleccionar E o I" << endl;
        break;
    }
}