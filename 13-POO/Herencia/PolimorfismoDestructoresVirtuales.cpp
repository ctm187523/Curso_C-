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

  
//clase padre
class Persona2{

    protected:               //con protected podemos acceder a los campos desde la propia clase y desde clase que heredan de esta clase
        string nombre;
        int edad;

    //constructor
    public:

        Persona2(string n, int e):nombre(n), edad(e){}

        //metodos public, usamos virtual para poder usar el polimorfismo tal como lo hacen lenguajes
        //de programación como Java,C#,etc. Lo que hace virtual es que el compilador genere una tabla
        //de metodos virtuales para cada clase, mostrarDatos para Persona, mostrarDatos para Alumno2,
        //mostrarDatos para Profesor2,etc, con esto creamos un enlace dinámico en tiempo de ejecucion
        //se mira el tipo real del objeto en este caso lo usamos para Alumno2 mas abajo,
        virtual void mostrarDatos(){
            cout << "Nombre: " << nombre << endl;
            cout << "Edad: " << edad << endl;
        }

};


//clases que hereden de Persona

class Alumno2: public Persona2{     //para heredar en c++ se pone : public NombreDeLaClaseQueHereda

    private:     //encapsulamos con private para que los campos sean exclusivos de esta clase Persona

        string estudios;

    //constructor
    public:
        //recibe los parametros que heredan de la Clase Persona(nombre(n) y edad(e)) y la propia clase Alumno(estudios(es))
        //la clase padre Persona seria en este caso como la instruccion super en java llama al constructor de la clase padre(Persona)
        Alumno2(string n, int e, string es): Persona2(n, e), estudios(es){}  

        //metodo propio de mostrarDatos, aqui no es una sobreescritura conmo en otros lenguajes
        void mostrarDatos(){
            //reutilizacion del metodo mostrarDatos de la clase padre Persona2, usamos la clase Persona2 y llamamos al metodo
            Persona2::mostrarDatos();
            //mostramos el atributo particular de la clase Alumno
            cout << "Estudios: " << estudios << endl;
        }
};
   

int main(){

    //creamos las instancias
    Alumno a1("Laura",20,"Ingenieria Informatica");

    Profesor p1("Carlos", 45, "Programacion en C++");

    //hacemos una asignacion, ponemos un objeto de tipo Alumno a uno de tipo Persona, principio es un, un alumno es una persona
    Persona persona1=a1;

    //hacemos una asignacion, ponemos un objeto de tipo Profesor a uno de tipo Persona, principio es un, un Profesor es una persona
    Persona persona2=p1;

    //en este caso hace referencia al metodo mostrarDatos de la clase Persona
    //en Java, C# y otros lenguajes llamaria a mostrarDatos de la clase Alumno
    //pero en C++ al hacer estas asignaciones se produce un object slicing, es decir
    //un corte de objeto, un corte de las propiedades, en este caso Alumno pierde sus propios
    //campos y sus propios métodos.
    persona1.mostrarDatos();

    cout << "------------------Con punteros y uso de virtual en la clase padre--------------------------"  << endl;

    //para lograr este polimorfismo y que el objeto que hereda de persona guarde sus propiedades y campos
    //debemos usar punteros y usar en la clase Padre en este caso Persona2,ver abajo, en el metodo mostrarDatos() 
    //la palabra reservada virtual.

    //creamos las instancias
    Alumno2 a3("Laura",20,"Ingenieria Informatica");

    //creamos un puntero de tipo Persona2 que apunta a una referecia de tipo Alumno2
    Persona2* persona3=&a3;

    //usamos -> ya que usamos punteros
    persona3->mostrarDatos();

}
   
 