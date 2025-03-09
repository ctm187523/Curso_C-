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

  //constructor, pide por parámetro saldo de tipo double
  CuentaBancaria(double saldo):saldo(saldo) {}

  //con CuentaBancaria& decimos que nos devuelva una referencia de tipo CuentaBancaria
  //esto nos permite en el main crear llamadas encadenadas -> cuenta.setSalto(2000).mostrarSaldo();
  //ya que en el metodo setSaldo devolvemos una referencia a CuentaBancaria y podemos llamar al metodo mostrarSaldo()
   CuentaBancaria& setSalto(double saldo){
        this->saldo = saldo;   //usamos this para resolver la ambiguedad entre el parametro recibido y el parametro de la clase CuentaBancaria
        return *this;   //desreferenciamos el objeto actual con *this, para devolver por referencia, no por valor, retornamos una referencia al mismo objeto, no una copia, permite llamadas encadenadas
   }

   void mostrarSaldo() const {
    cout << "Saldo: " << saldo << endl;
   }

};


int main(){

  CuentaBancaria cuenta(1000);

  cuenta.setSalto(2000).mostrarSaldo();

}