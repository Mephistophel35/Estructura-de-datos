#include <iostream>
#include "Pila.h"

using namespace std;

int main()
{
    Pila<int> p;

    try{

    for(int i = 0; i <= 5; ++i){

        p.Agregar(i*2);

    }

    p.Imprimir();

    p.Eliminar();

    cout << endl << "Eliminando tope..." << endl << endl;

    p.Imprimir();

    cout << endl <<"Elemento en el tope de la pila: " << p.Tope() << endl << endl;

    p.PilaVacia() ? cout << "Pila vacia" << endl << endl : cout << "La pila no est\240 vacia" << endl << endl;

    cout << "Tamanio de la pila: " << p.Tamanio() << endl;

    p.VaciarPila();

    cout << "Vaciando pila..." << endl << endl;

    p.PilaVacia() ? cout << "Pila vacia" << endl : cout << "La pila no est\240 vacia" << endl;

    }catch(const std::exception & exc){
        std::cerr << "Error: " << exc.what() << std::endl;
    }catch(...){
        std::cerr << "Ocurri\242 un error inesperado." << std::endl;
    }

    return 0;
}


// ~Mephisto
