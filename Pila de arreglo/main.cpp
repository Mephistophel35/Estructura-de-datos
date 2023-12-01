//Creado por Mephistopheles

#include <iostream>
#include "Pila.h"

using namespace std;

int main()
{
    Pila<int> p;

    try{

    for(int i = 0; i <= 10; ++i){

        p.Agregar(i*2);

    }

    p.Imprimir();

    cout << "\nEliminando dato...";
    p.Eliminar();

    cout << endl << endl;
    p.Imprimir();

    cout << "\nElemento en el tope de la pila: " << p.Tope() << endl;

    p.pilaVacia() ? cout << "\nPila vacia" << endl : cout << "\nLa pila no esta vacia" << endl;

    cout << "\nTamanio de la pila: " << p.Tamanio() << endl;

    cout << "\nCapacidad de la pila: " << p.Capacidad() << endl;

    }catch(const std::exception & exc){
        std::cerr << "Error: " << exc.what() << std::endl;
    }catch(...){
        std::cerr << "Ocurri\242 un error inesperado." << std::endl;
    }
}
