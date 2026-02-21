
//Herencia principio ES UN -> en este caso un Alumno es una Persona, un Profesor es una Persona, etc. Es una relacion de tipo ES UN
//ESTE CODIGO ES COPIADO DEL CODIGO polimorfismoReferencias.cpp, ver comentarios en polimorfismoReferencias.cpp
//DONDE SE EXPLICA EL POLIMORFISMO EN C++ Y EL PROBLEMA DEL SLICING, 
//EN ESTE CODIGO TRATAMOS LAS CLASES ABSTRACTAS
//LAS CLASES ABSTACTAS SON CLASES QUE NO SE PUEDEN INSTANCIAR, SOLO SE PUEDEN HEREDAR, SE USAN PARA CREAR UNA ESTRUCTURA DE CLASES, 
//PARA CREAR UNA JERARQUIA DE CLASES, PARA CREAR UNA INTERFAZ, ETC. EN C++ SE CREAN CON LA PALABRA VIRTUAL Y SE DECLARAN COMO VIRTUAL PURE, ES DECIR, 
//SE DECLARAN COMO VIRTUAL Y SE ASIGNAN A 0, ESTO INDICA QUE EL METODO ES ABSTRACTO Y QUE LA CLASE ES ABSTRACTA, LAS CLASES ABSTRACTAS PUEDEN TENER METODOS 
//CON IMPLEMENTACION O SIN IMPLEMENTACION, PERO SI TIENEN UN METODO ABSTRACTO LA CLASE ES ABSTRACTA Y NO SE PUEDE INSTANCIAR, SOLO SE PUEDE HEREDAR.

//UTILIDAD CLASES ABSTRACTAS:
// 1.Definir como sera el diseño de la herencia(contratos), ejemplo en un videojuego se definen los comportamientos comunes de los actores del juego como moverse, etc
// 2.Garantizar coherencia en un equipo de trabajo, tiene mas sentido cuando se trabaja en equipo, ya que se pueden definir las clases abstractas como contratos, para que los programadores sepan que metodos tienen que implementar, etc
// 3.Permitir extensibilidad futura, si queremos agregar nuevas clases que hereden de una clase abstracta, solo tenemos que implementar los metodos abstractos de la clase padre, sin tener que modificar el codigo de las clases hijas, etc
// 4.Reducir acoplamiento, la dependencia directa entre partes del codigo, si queremos cambiar el comportamiento de una clase hija, solo tenemos que cambiar el codigo de esa clase hija, sin tener que modificar el codigo de las clases hijas, etc
// 5.Facilitar pruebas, si queremos probar el comportamiento de una clase hija, solo tenemos que crear un objeto de esa clase hija, sin tener que crear un objeto de la clase padre, etc
//   pruebas unitarias aisladas lo que se conoce como mocks, por ejemplo si queremos probar una base de datos, podemos crear una clase mock que herede de la clase abstracta que define el comportamiento de la base de datos, y luego en las pruebas unitarias podemos usar esa clase mock para simular el comportamiento de la base de datos, etc
// 6.Forzar consistencia semántica, si queremos que todas las clases hijas tengan un comportamiento similar, podemos definir ese comportamiento en la clase abstracta, y luego todas las clases hijas tienen que implementar ese comportamiento, etc
#include <iostream>
#include <string>
using namespace std;

//hacemos que la clase Animal sea una clase abstracta, para eso declaramos el metodo hacerSonido como virtual pure, es decir, virtual y asignamos a 0, esto indica que el metodo es abstracto y que la clase es abstracta, las clases abstractas no se pueden instanciar, solo se pueden heredar
class Animal{

    public:
        //metodo virtual puro, indicamos que todo lo que herede de esta clase tiene que implementar este metodo
        virtual void hacerSonido()=0; //esto indica que el metodo es abstracto y que la clase es abstracta, las clases abstractas no se pueden instanciar, solo se pueden heredar


};

//si no sobreescribimos el metodo hacerSonido de la clase que hereda, la clase Animal
//esta clase se convierte en una clase abtracta, ya que no se ha implementado el metodo hacerSonido
//esto tambien pasa en otros lenguajes como Java o C#, si una clase no implementa un metodo abstracto de la clase padre, la clase hija se convierte en una clase abstracta, y no se puede instanciar, solo se puede heredar
class Gato: public Animal{

  
};

//un perro es un animal
class Perro: public Animal{

    public:
        //sobrescribimos el metodo hacerSonido de la clase Animal, con override indicamos que estamos sobrescribiendo un metodo virtual de la clase padre, si no lo hacemos el compilador no nos avisaria de que no estamos sobrescribiendo correctamente el metodo
        void hacerSonido() override{
            cout << "El perro ladra" << endl;
        }

};

int main(){

    //Animal miAnimal;     //no se puede instanciar una clase abstracta, esto se debe a que la clase Animal es una clase abstracta, ya que tiene un metodo virtual puro, es decir, un metodo abstracto, las clases abstractas no se pueden instanciar, solo se pueden heredar
    //Gato miGato;         //no se puede instanciar una clase abstracta, esto se debe a que la clase Gato es una clase abstracta, ya que no ha implementado el metodo hacerSonido de la clase Animal, las clases abstractas no se pueden instanciar, solo se pueden heredar

    Perro miPerro;       //si se puede instanciar una clase que hereda de una clase abstracta, siempre y cuando implemente todos los metodos abstractos de la clase padre, en este caso la clase Perro implementa el metodo hacerSonido de la clase Animal, por lo tanto se puede instanciar, las clases abstractas no se pueden instanciar, solo se pueden heredar
    //con referencias seria de la siguiente manera
    Animal &a = miPerro; //El perro ladra, con punteros o referencias el resultado seria el perro ladra
    a.hacerSonido(); //El perro ladra, con punteros o referencias el resultado seria el perro ladra

    //en Java y C++ siempre el comportamiensto es polimorfico, C++ podemos elegir el comportamiento polimorfico
    //ahorrando recursos, en Java y C# el comportamiento es siempre polimorfico, en C++ el comportamiento es polimorfico solo si usamos punteros o referencias, con punteros o referencias el resultado seria el perro ladra
    //ahorramos recursos como el uso de memoria, ya que no tenemos que crear un objeto de la clase Perro para usar el metodo hacerSonido, con punteros o referencias el resultado seria el perro ladra


}