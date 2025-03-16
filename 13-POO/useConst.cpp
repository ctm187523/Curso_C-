/*
    Uso de const en c++, importancia en c++, se puede usar const en cualquier propiedad punteros,metodos,campos de clases, etc:

    1. Seguridad y robustez en el código
        -Evita modificaciones accidentales en objetos que no deberían cambiar.
        -Reduce errores dificíles de depurar al mantener la inmutabilidad de ciertos objetos

    2. Optimización
       -Permite al compilador hacer optimizaciones cuando sabe que un método no cambiará el estado del objeto
    
    3. Buenas prácticas de programación
       -Código más legible y fácil de entender
       -Señala de forma clara qué métodos pueden o no pueden modificar un objeto

*/

#include <iostream>
#include <string>

using namespace std;

class Empleado {
    private:
        const string nombre;    //uso de const no podemos modificar esta propiedad
        const string apellido;  //uso de const no podemos modificar esta propiedad
        double salario;

    public:
        //constructor
        Empleado(string n, string a, double s)
            : nombre(n),apellido(a),salario(s) {}

        //usamos const en estos metodos setters porque estos metodos no midifican el valor de las propiedades de la clase
        //usamos const en metodos que solo devuelven valores para evitar modificaciones accidentales dentro del metodo y para
        //poder llamar estos metodos con objetos const
        string get_nombre() const {return nombre; }                 
        string get_apellido() const {return apellido; }
        int get_salarrio() const {return salario; }

        //no usamos const ya que este metodo modifica propiedades de la clase
        void set_salario(double nuevo_salario) {
            if (nuevo_salario >= 0 ){
                salario = nuevo_salario;
            }else{
                cout << "ERROR: El salario no puede ser negativo. " << endl;
            }
        }

        //usamos const ya que no midifica las propiedades de la clase
        //al ser const puede ser llamado por un objeto const(ver abajo con el objeto emp2)
        void mostrar_info() const {
            cout << "Empleado: " << nombre << " " << apellido << endl;
            cout << "Salario: " << salario << endl;

         }
};

int main() {
    
    Empleado emp("Juan", "Perez", 3000);
    emp.mostrar_info();

    cout << "\nModificando el salario..." << endl;
    emp.set_salario(3500);
    emp.mostrar_info();

    //creamos objetos const, esto implica que una vez creado el empleado no se puede modificar
    //no podemos modificar el salario en este caso, pero si podemos ver la info por que el metodo mostrar_info() creado arriba es const
    //si no fuese const no podriamos llamarlo con este objeto que es const
    const Empleado emp2("Manolo","Gutierrez", 4500);
    cout << "\nObjeto de tipo const " << endl;
    emp2.mostrar_info();
}