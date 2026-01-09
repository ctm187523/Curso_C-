/*
                                FINAL

¿Para que sirve?
 Para evitar que una clase o método pueda seguir heredándose o sobrescribiéndose.

¿Como lo hace?
 Agregando el especificador "final" tras rl nombre del método o la clase

¿Cómo funciona?
 Lanzando un error el compilador si se sobrescribe el método final, error en tiempo de compilación

 A diferencia de Java y otros lenguaje solo podemos usar el especificador final a metodos virtuales y clases
 no podemos usar final a constantes, variables y otras estructuras
 */


 //codigo sacado de Override.cpp
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

        Persona(string n, int e):nombre(n), edad(e){

        }

        //Destructor
        virtual ~Persona(){
            cout <<"Destructor de Persona"  << endl;
        }

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

class Alumno: public Persona{     //para heredar en c++ se pone : public NombreDeLaClaseQueHereda

    private:     //encapsulamos con private para que los campos sean exclusivos de esta clase Persona

        string* estudios;

    //constructor
    public:
        //recibe los parametros que heredan de la Clase Persona(nombre(n) y edad(e)) y la propia clase Alumno(estudios(es))
        //la clase padre Persona seria en este caso como la instruccion super en java llama al constructor de la clase padre(Persona)
        Alumno(string n, int e, string es): Persona(n, e){
            estudios = new string(es);
        }  

        //destructor
         ~Alumno(){

            cout << "Destructor de Alumno" << endl;

            delete estudios;  //borramos el puntero antes creado para evitar fugas de memoria, eliminamos el recurso
        }

        //metodo propio de mostrarDatos, aqui no es una sobreescritura conmo en otros lenguajes
        //usamos override para evitar errores silenciosos ver explicacion arriba
        //SI PONEMOS EL EXPECIFICADOR final CUANDO UNA CLASE HEREDE DE ESTA CLASE ALUMNO NO PODRA SOBREESCRIBIR
        //EL METODO mostrarDatos()
        void mostrarDatos() override {
            //reutilizacion del metodo mostrarDatos de la clase padre Persona2, usamos la clase Persona2 y llamamos al metodo
            Persona::mostrarDatos();
            cout << "Vamos a ver los estudios del alumno: " << endl;
            //mostramos el atributo particular de la clase Alumno
            cout << "Estudios: " << estudios << endl;
        }
};

//HEREDAMOS DE CLASE Alumno PARA COMPROBAR QUE COMO EL METODO mostrarDatos() TIENE EL ESPECIFICADOR final
//ESTA CLASE QUE HEREDA DE ALUMNO NO PUEDE USAR EL METODO mostrarDatos()

class AlumnoBecado: public Alumno {

    public:

        //COMENTAMOS EL METODO DE ABAJO PORQUE AUNQUE HEREDE DE LA CLASE Alumno COMO EL METOOD mostrarDatos()
        //EN LA CLASE Alumno ES final NO LO PUEDO SOBRESCRIBIR.
        // void mostrarDatos() override {

        // }

};

//SI PONEMOS final EN LA CLASE Profesor EVITAMOS QUE DE ESTA CLASE NO SE PUEDA HEREDAR
class Profesor final: public Persona{     //para heredar en c++ se pone : public NombreDeLaClaseQueHereda

    private:     //encapsulamos con private para que los campos sean exclusivos de esta clase Persona

        string* materia;

    //constructor
    public:
        //recibe los parametros que heredan de la Clase Persona(nombre(n) y edad(e)) y la propia clase Profesor(materia(m))
        //la clase padre Persona seria en este caso como la instruccion super en java llama al constructor de la clase padre(Persona)
        Profesor(string n, int e, string m): Persona(n, e){

            materia = new string(m);
        }  

        //destructor
         ~Profesor(){

            cout << "Destructor de Profesor" << endl;

            delete materia;  //borramos el puntero antes creado para evitar fugas de memoria, eliminamos el recurso
        }

        //metodo propio de mostrarDatos, aqui no es una sobreescritura conmo en otros lenguajes
        void mostrarDatos(){
            //reutilizacion del metodo mostrarDatos de la clase padre Persona, usamos la clase Persona y llamamos al metodo
            Persona::mostrarDatos();
            //mostramos el atributo particular de la clase Profesor
            cout << "Materia: " << materia << endl;
        }
};

//COMENTAMOS LO DE ABAJO PORQUE NO PODEMOS HEREDAR DE LA CLASE Profesor YA QUE TIENE EL ESPECIFICADOR final
// class ProfesorTitular: public Profesor {

// }

int main(){

    Persona* p1 = new Alumno("Ana", 20, "Informática");

    p1->mostrarDatos();

    delete p1;
    
}

