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
            static int siguienteId;    //no se puede inicializar una variable static la tenemos que inicializar fuera de la clase, la incializamos justo despues de acabar la clase
       
            //a apartir de la version 17 de C++ ya no es necesario inicializar la variable static fuera de la clase
            //para ello se usa la palabara reservada inline, lo dejamos comentado pero podriamos usarlo y comentar lo de arriba linea 28
            //inline static int siguienteId=1;
       
            public:

            //constructor
            Empleado(string _nombre) {
                //alamcenamos lo que hay en siguienteId y lo incrementamos para el siguiente empleado al ser static podemos hacerlo asi ya que la propiedad 
                //static siguienteId es de la clase y no del objeto en particular y al ser de la clase se mantiene el valor de siguienteId actualizado
                nombre = _nombre;
                id = siguienteId++;  
            }

            void mostrarInfo(){
                cout << "Nº de empleado:" << id << " Nombre:" << nombre << endl;
            }
    };

    //inicializamos la variable static siguienteId de la clase de arriba Empleado, ya que las propiedades static no se pueden inicializar en la clase donde es creado
    int Empleado::siguienteId=1;

    //a apartir de la version 17 de C++ ya no es necesario inicializar la variable static fuera de la clase
    //para ello se usa la palabara reservada inline, podriamos comentar lo de arriba ->    int Empleado::siguienteId=1;
    //y usar lo que hay comentado debajo de la declaracion de la variable static siguienteId en la linea 32
    //y comentar la linea 28

    int main(){

        Empleado e1("Juan");
        Empleado e2("Maria");
        Empleado e3("Carlos");

        e1.mostrarInfo();
        e2.mostrarInfo();
        e3.mostrarInfo();
    }