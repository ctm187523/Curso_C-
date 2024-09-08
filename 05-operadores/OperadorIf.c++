#include <iostream>
using namespace std;

//funcion para pasar a minusculas ya que c++ no tiene una funcion para ello como en java toLowerCase
//tiene una funcion para pasar un caracter pero una una palabra entera
//como parametro pasamos un string por referencia &cadena y no por valor, si lo pasaramos por valor el metodo
//deberia de devolver un String en lugar de ser void y en void crear una variable donde llamamos al metodo
//y almacenamos la palabra en minuscula, al pasarlo por referencia no hace falta hacer todo esto ya que ocupa
//el mismo lugar en memoria
void toLowerCase(string &cadena){

    for(int i=0; i<cadena.length(); i++){
        cadena[i]=tolower(cadena[i]); //usamos el metodo de c++ cadena para pasar un caracter a minusculas
    }
}

int main()
{

    int edad;
    string ex_medico;

    cout << "Introduce tu edad";

    cin >> edad;
    cout << "Has pasado el examen médico (Si/No)";
    cin >> ex_medico;

    //llamamos a la funcion para pasar a minusculas creado arriba
    toLowerCase(ex_medico);

    if (edad >= 18 && ex_medico=="si")
    {
        cout << "Puedes obtener el carnet de conducir";
    }
    else
    {
        cout << "No cumples los requisitos";
    }

    
}