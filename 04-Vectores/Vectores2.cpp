 #include <iostream>
 #include <vector>
 using namespace std;

 int main(){

   

    cout << "Cuantos elementos quieres que tenga el vector?";

    auto elementos = 0; //en lugar de poner un tipo por ejemplo int ponemos auto y c++ le asigna el tipo de dato a partir de su valor

    cin >> elementos;

    //declaramos un vector con un numero determinado de elementos
    vector <int> records (elementos);

    for(int i=0; i<records.size(); i++){

        cout <<"Introduce el elemento del vector nº " <<i+1<<endl;

        cin>>records.at(i);
    } 

    cout<< "A continuacion te muestro los elementos almacenados en el vector: "<<endl;

    int i=0;
    while(i<records.size()){

        cout << records.at(i) <<endl;
        i++;
    }
 }