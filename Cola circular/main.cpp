#include <iostream>
#include "ColaCircular.h"

using namespace std;

int main()
{
    Cola<int> C;

    try{

    for(int i = 0; i < 7; ++i){
        C.Agregar(i*2);
    }

    C.Imprimir();

    cout << endl << endl;

    C.Eliminar();

    C.Imprimir();

    cout << endl << endl << "El elemento al principio de la cola es: " << C.Primero() << endl << endl;

    cout << "El elemento al final de la cola es: " << C.Ultimo() << endl << endl;

    if(C.ColaVacia()) cout << "La cola se encuentra vacia" << endl << endl;
    else cout << "La cola NO se encuentra vacia" << endl << endl;

    cout << "El tamanio de la cola es de: " << C.Tamanio() << " elementos" << endl << endl;

    cout << "Vaciando cola..." << endl << endl;

    C.VaciarCola();

    if(C.ColaVacia()) cout << "La cola se encuentra vacia" << endl << endl;
    else cout << "La cola NO se encuentra vacia" << endl << endl;

    cout << "El tamanio de la cola es de: " << C.Tamanio() << " elementos" << endl << endl;

    cout << "Imprimiendo la cola..." << endl << endl;

    C.Imprimir();

    }catch(const exception & exc){
        cerr << "Error: " << exc.what() << endl;
    }catch(...){
        cerr << "Ocurri\242 un error inesperado." << endl;
    }

    return 0;
}

// ~Mephisto
