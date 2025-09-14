#include <iostream>
#include <string>
using namespace std;

//clase padre
class Persona{

    protected:               //con protected podemos acceder a los campos desde la propia clase y desde clase que heredan de esta clase
        string nombre;
        int edad;

    //constructor
    public:

        Persona(string n, int e):nombre(n), edad(e){}

        //metodos public
        void mostrarDatos(){
            cout << "Nombre: " << nombre << endl;
            cout << "Edad: " << edad << endl;
        }

};


//clases que hereden de Persona

class Alumno: public Persona{     //para heredar en c++ se pone : public NombreDeLaClaseQueHereda

    private:     //encapsulamos con private para que los campos sean exclusivos de esta clase Persona

        string estudios;

    //constructor
    public:
        //recibe los parametros que heredan de la Clase Persona(nombre(n) y edad(e)) y la propia clase Alumno(estudios(es))
        //la clase padre Persona seria en este caso como la instruccion super en java llama al constructor de la clase padre(Persona)
        Alumno(string n, int e, string es): Persona(n, e), estudios(es){}  

        //metodo propio de mostrarDatos, aqui no es una sobreescritura conmo en otros lenguajes
        void mostrarDatos(){
            //reutilizacion del metodo mostrarDatos de la clase padre Persona, usamos la clase Persona y llamamos al metodo
            Persona::mostrarDatos();
            //mostramos el atributo particular de la clase Alumno
            cout << "Estudios: " << estudios << endl;
        }
};

class Profesor: public Persona{     //para heredar en c++ se pone : public NombreDeLaClaseQueHereda

    private:     //encapsulamos con private para que los campos sean exclusivos de esta clase Persona

        string materia;

    //constructor
    public:
        //recibe los parametros que heredan de la Clase Persona(nombre(n) y edad(e)) y la propia clase Profesor(materia(m))
        //la clase padre Persona seria en este caso como la instruccion super en java llama al constructor de la clase padre(Persona)
        Profesor(string n, int e, string m): Persona(n, e), materia(m){}  

        //metodo propio de mostrarDatos, aqui no es una sobreescritura conmo en otros lenguajes
        void mostrarDatos(){
            //reutilizacion del metodo mostrarDatos de la clase padre Persona, usamos la clase Persona y llamamos al metodo
            Persona::mostrarDatos();
            //mostramos el atributo particular de la clase Profesor
            cout << "Materia: " << materia << endl;
        }
};





int main(){

    //creamos las instancias
    Alumno a1("Laura",20,"Ingenieria Informatica");

    Profesor p1("Carlos", 45, "Programacion en C++");

    cout << "------------------Alumno:--------------------------"  << endl;

    a1.mostrarDatos();

    cout << "------------------Profesor:--------------------------"  << endl;

    p1.mostrarDatos();
}