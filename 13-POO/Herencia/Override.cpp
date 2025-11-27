/* 
    PARA QUE SIRVE??
        - Para evitar errores silenciosos al sobreescribir métodos de la clase padre por error en la
        firma del método, por errores a la hora de escribir ese metodo que estamos sobreescribiendo.
        es decir si por ejemplo el metodo del padre es mostrarDatos() y ponemos en la clase hijo
        mostrarDato() no da error porque el compilador lo considera como un metodo nuevo, pero no
        sobreescribe el metodo mostrarDatos() del padre, al no dar error por eso es un error silencioso

        - ¿Como lo hace? Para evitar estos errores debemos indicar explicitamente al compilador que un método tiene que 
        que sobreescribir obligatoriamente uno virtual de la clase padre, debemos usar la palabra override
        en el metodo que queremos sobreescribir

        - ¿Como funciona? lanzando un error el compilador si la sobreescritura del método de la clase padre no es correcta
        ya que al poner override le indicamos que debe sobreescribir el metodo virtual del padre

        -Añade seguridad, claridad y mantenimiento a largo plazo

    Ejemplos de utilidad:
        - Protección ante cambios en la clase base
        - Mejora legibilidad del código
        - Previene errores de mantenimiento y refactorización
        - Claridad semántica
*/

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
        void mostrarDatos() override{
            //reutilizacion del metodo mostrarDatos de la clase padre Persona2, usamos la clase Persona2 y llamamos al metodo
            Persona::mostrarDatos();
            cout << "Vamos a ver los estudios del alumno: " << endl;
            //mostramos el atributo particular de la clase Alumno
            cout << "Estudios: " << estudios << endl;
        }
};

class Profesor: public Persona{     //para heredar en c++ se pone : public NombreDeLaClaseQueHereda

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



int main(){

    Persona* p1 = new Alumno("Ana", 20, "Informática");

    p1->mostrarDatos();

    delete p1;
    
}


