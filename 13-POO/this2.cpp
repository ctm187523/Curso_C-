/*

- ¿Qué es "this"?
  -Palabra reservada en C++, podemos traducir mentalmento por "este mismo"
  - En C++ this ers un puntero que contiene la dirección de memoria del objeto actual
  - Solo puede usarse en el ámbito de la clase
  - Cuando se accede a campos de clase, implícitamnete se accede utilizando "this"

  -¿Para qué se utiliza?
   - Para acceder a propiedades y métodos.
   - Evita errores de ambigüedad de nombres.
   - Para comparar si dos objetos son el mismo objeto
   - Para desreferenciar(*this) y así obtener el objeto actual.Muy utilizado para llamadas encadenadas.


*/

#include <iostream>
using namespace std;

class CuentaBancaria{

  private:
    double saldo;

  public:

    void setSaldo(double sal) {
      this->saldo = sal;  //no es necesario poner el this en este caso, porque el nombre del parametro(sal) es diferente de la propiedad saldo de la clase CuentaBancaria
    }

    double getSaldo(){
       return this->saldo;  //no es necesario poner el this en este caso
    }

    //por parametro recibe la direccion de memoria(&) de una cuenta por referencia
    //compara si son la misma cuenta ya que tienen la misma dirección de memoria
    void compararCuentas(const CuentaBancaria &otra){

        //this hace de puntero que apunta al objeto actual, lo compara con la direccion de memoria
        //pasada por parámetro
        if(this==&otra){
            cout << "Son la misma cuenta" << endl;
        }else{
            cout << "No son la misma cuenta" << endl;
        }
    }

};


int main(){

  CuentaBancaria cuenta1;

  CuentaBancaria cuenta2;


  cout << "primera comparacion: " << endl; 
  cout << "---------------------" << endl;
  cuenta1.compararCuentas(cuenta2);
  cout << "" << endl; 
  cout << "segunda comparacion: " << endl;
  cout << "---------------------" << endl;
  cuenta1.compararCuentas(cuenta1);
  cout << "" << endl; 

}