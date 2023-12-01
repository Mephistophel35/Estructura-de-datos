#include <iostream>
#include "Lista.h"

using namespace std;

int main()
{
    Lista<int> L;

    L.AgregarInicio(2);
    L.AgregarInicio(5);
    L.AgregarInicio(3);
    L.AgregarInicio(75);
    L.AgregarInicio(2);
    L.AgregarInicio(123);
    L.AgregarInicio(2);
    L.AgregarInicio(6);
    L.AgregarInicio(3);

    L.Imprimir();

    cout << endl << endl;
    L.Imprimir();



    return 0;
}



// ~Mephisto
