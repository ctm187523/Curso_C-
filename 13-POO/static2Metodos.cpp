/*
¿Que es static?

- Atributo o método que pertenece a la propia clase y no a instacias de la clase

-¿Que significa que un atributo o método sea static?
  .Atributos static
     - Son compartidos por todas las instancias de la clase
     - No dependen de un objeto/instancia en particular
     - Se almacenan en un solo lugar de la memoria y no se replican en cada instancia

   .Métodos static
      - No pueden acceder a miembros de instancia de la clase, es decir, a aquellos que no son static
      - Pueden manipular solo otros miembros static
      - No requieren una instancia/objeto para ser llamados. 


-¿Para que sirven?
   -Obtener información de la clase sin necesidad de instanciarla.
   -Funciones de utilidad en clases especializadas.
     -Ej: cálculos matemáticos
   -Controlar y compartir información entre todas las intacias(ej: id empleados)

*/

#include <iostream>
using namespace std;

class Empleado {

    private:
        string nombre;
        int id;
         //queremos almacenar numeros consecutivos a medida que creamos empleados, lo hacemos static
        inline static int siguienteId=1;    //usamos inline para inicializar propiedades static ver comentarios codigo de static.cpp

        inline static int totalEmpleados=0; //propiedad para mostrar los empleados creados

        public:
        //constructor
        Empleado(string _nombre) {
            //alamcenamos lo que hay en siguienteId y lo incrementamos para el siguiente empleado al ser static podemos hacerlo asi ya que la propiedad 
            //static siguienteId es de la clase y no del objeto en particular y al ser de la clase se mantiene el valor de siguienteId actualizado
            nombre = _nombre;
            id = siguienteId++;  
            totalEmpleados++; //incrementamos en 1 el numero de empleados creados
        }

        //Destructores, usamos el destructor al eliminar un empleado
        //el simbolo ~ lo creamos con ALT GR + 4
        ~Empleado(){
            //decrementamos al eliminar un empleado para actualizar la propiedad totalEmpleados
            totalEmpleados--;
        }
        

        void mostrarInfo(){
            cout << "Nº de empleado:" << id << " Nombre:" << nombre << endl;
        }

        //metodo static para indicar cual sera el siguiente Id disponible
        //devuelve lo almacenado en la propiedad static siguienteId
        static int obtenerSiguienteId(){
            return siguienteId;
        }

        //metodo static para mostrar cuantos empleados tenemos creados
        static int contarEmpleadosCreados(){
            return totalEmpleados;
        }
};



int main(){

    Empleado e1("Juan");
    Empleado e2("Maria");
    Empleado e3("Carlos");

    //colocamos el objeto e4 entre llaves asi al salir del bloque usamos el destructor de la clase Empleado
    //para que destruya el empleado, ya que esta en el stack y se elimina al salir de su ambito
    {
        Empleado e4("Pepito");
    }
    

    e1.mostrarInfo();
    e2.mostrarInfo();
    e3.mostrarInfo();

    //llamamos al metodo estatico obtenerSiguienteId() usando el nombre de la clase Empleado
    cout << "El siguiente ID disponible es: " << Empleado::obtenerSiguienteId() << endl;

    cout << "Total empleados: " << Empleado::contarEmpleadosCreados() << endl;


} 