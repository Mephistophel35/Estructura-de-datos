#include <iostream>
#include "ListaDoble.h"
#include <complex>

using namespace std;

//Ahora si... a probar nuestra clase y los métodos.

//Bucket-list de nuestra clase, crucemos los dedos...

// Crearemos una lista          V
// Agregaremos elementos        V
// Eliminaremos elementos       V
// Buscaremos elementos.        V
// Conoceremos elementos.
// Vamos a checar que si en un punto nuestra lista está vacía.      V
// Modificaremos un elemento.   V
// Eliminaremos toda ocurrencia de un elemento.     V
// Eliminaremos todos los elementos repetidos.       V
// Eliminaremos todos los elementos que cumplan cierta condición.   V
// Intercambiaremos listas!!    V
// Transferiremos elementos de una lista a otra.    V
// Ordenaremos una lista!!!     V
// Conoceremos el tamaño de la lista.   V
// Imprimiremos la lista.       V
// Vaciaremos la lista

bool condicion(int n);
int main()
{
    ListaDoble<int> L1;
    ListaDoble<int> L2;

    int datos[10] = {0,1,2,3,4,5,6,7,8,9};
//.---------------------Crear Listas---------------------.
    cout << "Lista creadas" << endl;
    L1.ImprimirAscendente();
    L2.ImprimirAscendente();
    cout << endl << endl;
    system("pause");
//.--------------------Agregando datos--------------------.
    system("cls");
    cout << "Agregando datos de chill" << endl;
    L1.AgregarPrincipio(datos[0]);
    L1.AgregarFinal(datos[2]);
    L1.AgregarEnPos(datos[1], 1);
    L1.AgregarPrincipio(datos[6]);
    L1.AgregarPrincipio(datos[7]);
    L1.AgregarEnPos(datos[4], 3);
    L1.ImprimirAscendente();
    cout << endl << endl;
    system("pause");
//.--------------------Eliminando datos--------------------.
    system("cls");
    cout << "Eliminando datos de chill" << endl;
    L1.ImprimirAscendente();
    cout << endl;
    L1.EliminarEnPos(1);
    L1.EliminarPrincipio();
    L1.EliminarFinal();
    L1.ImprimirAscendente();
    cout << endl << endl;
    system("pause");
//.--------------------Conoceremos valores---------------------.
    system("cls");
    cout << "Primer elemento de la lista: " << L1.PrimerValor() << endl;
    cout << "Ultimo elemento de la lista: " << L1.UltimoValor() << endl;
    cout << "Elemento en la posicion 1 es: " << L1.ValorEnPos(1) << endl << endl;
    L1.ImprimirAscendente();
    cout << endl << endl;
    system("pause");
//.----------------------Buscaremos un elemento----------------------.
    system("cls");
    cout << "Buscando el elemento " << datos[5] << " en lista..." << endl;
    if(L1.Buscar(datos[5])) cout << "El elemento esta en la posición: " << L1.PosicionDelValor(datos[5]) << endl;
    else cout << "El elemento no se encuentra en la lista... :/" << endl;
    L1.ImprimirAscendente();
    cout << endl << endl;
    system("pause");
//.----------------------La lista está vacía?----------------------.
    system("cls");
    cout << "La lista esta vacia???" << endl << endl;
    if(L1.listaVacia()) cout << "Shi UwU" << endl << endl;
    else cout << "noup :P" << endl << endl;
    L1.ImprimirAscendente();
    cout << endl << endl;
    system("pause");
//.----------------------Modificaremos un valor----------------------.
    system("cls");
    cout << "Modificaremos el elemento de la posicion 0 de la lista por: " << datos[8] << endl << endl;
    L1.ImprimirAscendente();
    cout << endl << endl;
    L1.ModificarValor(0, datos[8]);
    L1.ImprimirAscendente();
    cout << endl << endl;
    system("pause");
//.----------------------Eliminaremos toda ocurrencia----------------------.
    system("cls");
    L1.AgregarPrincipio(datos[8]);
    L1.AgregarPrincipio(datos[8]);
    L1.AgregarPrincipio(datos[8]);
    L1.AgregarPrincipio(datos[8]);
    L1.AgregarPrincipio(datos[8]);
    L1.AgregarPrincipio(datos[8]);
    L1.AgregarPrincipio(datos[8]);
    L1.ImprimirAscendente();
    cout << endl << endl;
    cout << "Eliminando todas las ocurrencias del elemento: " << datos[8] << endl << endl;
    L1.EliminarTodaOcurrencia(datos[8]);
    L1.ImprimirAscendente();
    cout << endl << endl;
    system("pause");
//.----------------------Eliminando repetidos----------------------.
    system("cls");
    cout << "Agregando valores repetidos..." << endl << endl;
    L1.AgregarPrincipio(datos[3]);
    L1.AgregarPrincipio(datos[3]);
    L1.AgregarPrincipio(datos[3]);
    L1.AgregarPrincipio(datos[3]);
    L1.AgregarPrincipio(datos[3]);
    L1.AgregarPrincipio(datos[3]);
    cout << "Eliminando todos los elementos repetidos de la lista." << endl << endl;
    L1.ImprimirAscendente();
    L1.EliminarRepeticiones();
    cout << endl << endl;
    L1.ImprimirAscendente();
    cout << endl << endl;
    system("pause");
//.----------------------Eliminando por condición----------------------.
    system("cls");
    cout << "Eliminando elementos que cumplan cierta condicion" << endl;
    L1.ImprimirAscendente();
    cout << "\nEn este caso eliminara todos los valores mayores a 3" << endl;
    L1.EliminarPorCondicion(condicion);
    L1.ImprimirAscendente();
    cout << endl << endl;
    system("pause");
//-----------------------INTERCAMBIO DE LISTAS!!-------------------------.
    system("cls");
    for(int i = 0; i < 6; ++i)L2.AgregarFinal(datos[i]);
    cout << "Lista 1: " << endl;
    L1.ImprimirAscendente();
    cout << endl;
    cout << "Lista 2: " << endl;
    L2.ImprimirAscendente();
    cout << "\nIntercambiando listas." << endl << endl;
    L1.Cambiar(L2);
    cout << "Lista 1: " << endl;
    L1.ImprimirAscendente();
    cout << endl;
    cout << "Lista 2: " << endl;
    L2.ImprimirAscendente();
    cout << endl << endl;
    system("pause");
//-----------------------TRANSFERIR 1!!-------------------------.
    system("cls");
    cout << "Lista 1: " << endl;
    L1.ImprimirAscendente();
    cout << endl;
    cout << "Lista 2: " << endl;
    L2.ImprimirAscendente();
    cout << "\nTransfiriendo los elementos de la lista 2 a la lista 1." << endl;
    L1.Transferir(L2);
    cout << "Lista 1: " << endl;
    L1.ImprimirAscendente();
    cout << endl;
    cout << "Lista 2: " << endl;
    L2.ImprimirAscendente();
    cout << endl << endl;
    system("pause");
//-----------------------TRANSFERIR 2!!-------------------------.
    system("cls");
    cout << "Lista 1: " << endl;
    L1.ImprimirAscendente();
    cout << endl;
    cout << "Lista 2: " << endl;
    L2.ImprimirAscendente();
    cout << "\nTransfiriendo los elementos de la lista 2 a la lista 1." << endl;
    L2.Transferir(L1,2,6);
    cout << "Lista 1: " << endl;
    L1.ImprimirAscendente();
    cout << endl;
    cout << "Lista 2: " << endl;
    L2.ImprimirAscendente();
    cout << endl << endl;
    system("pause");
//-----------------------TRANSFERIR 3!!-------------------------.
    system("cls");
    cout << "Lista 1: " << endl;
    L1.ImprimirAscendente();
    cout << endl;
    cout << "Lista 2: " << endl;
    L2.ImprimirAscendente();
    cout << "\nTransfiriendo los elementos de la lista 2 a la lista 1." << endl;
    L1.Transferir(L2,1);
    cout << "Lista 1: " << endl;
    L1.ImprimirAscendente();
    cout << endl;
    cout << "Lista 2: " << endl;
    L2.ImprimirAscendente();
    cout << endl << endl;
//-----------------------ORDENASAO-------------------------.
    system("cls");
    cout << "Ordenando la lista..." << endl;
    L1.ImprimirAscendente();
    cout << endl;
    L1.Ordenar();
    cout << endl;
    L1.ImprimirAscendente();
    cout << endl << endl;
    system("pause");
//-----------------------TAMAÑO DE LA LISTA-------------------------.
    system("cls");
    L1.ImprimirAscendente();
    cout << "\nEl tamanio de la lista es: " << L1.Tamanio() << endl << endl;
    system("pause");
//-----------------------LISTA AL REVÉS-------------------------.
    system("cls");
    cout << "Imprimir lista al reves..." << endl << endl;
    L1.ImprimirDescendente();
    cout << endl << endl;
    system("pause");
//-----------------------VACIANDO LISTAS-------------------------.
    system("cls");
    cout << "Vaciando listas..." << endl << endl;
    L1.VaciarLista();
    L2.VaciarLista();
    cout << "Lista 1: " << endl << endl;
    L1.ImprimirAscendente();
    cout << endl << endl;
    cout << "Lista 2: " << endl << endl;
    L2.ImprimirAscendente();
    cout << endl << endl;
    system("pause");
//----------------------------------------------------------------//
    system("cls");
    cout << "Adios mundo! ;)" << endl << endl;

    cout << "UUUUUUUU     UUUUUUUU                                       UUUUUUUU     UUUUUUUU" << endl;
    cout << "U::::::U     U::::::U                                       U::::::U     U::::::U" << endl;
    cout << "U::::::U     U::::::U                                       U::::::U     U::::::U" << endl;
    cout << "UU:::::U     U:::::UU                                       UU:::::U     U:::::UU" << endl;
    cout << " U:::::U     U:::::Uwwwwwww           wwwww           wwwwwwwU:::::U     U:::::U " << endl;
    cout << " U:::::D     D:::::U w:::::w         w:::::w         w:::::w U:::::D     D:::::U " << endl;
    cout << " U:::::D     D:::::U  w:::::w       w:::::::w       w:::::w  U:::::D     D:::::U " << endl;
    cout << " U:::::D     D:::::U   w:::::w     w:::::::::w     w:::::w   U:::::D     D:::::U " << endl;
    cout << " U:::::D     D:::::U    w:::::w   w:::::w:::::w   w:::::w    U:::::D     D:::::U " << endl;
    cout << " U:::::D     D:::::U     w:::::w w:::::w w:::::w w:::::w     U:::::D     D:::::U " << endl;
    cout << " U:::::D     D:::::U      w:::::w:::::w   w:::::w:::::w      U:::::D     D:::::U " << endl;
    cout << " U::::::U   U::::::U       w:::::::::w     w:::::::::w       U::::::U   U::::::U " << endl;
    cout << " U:::::::UUU:::::::U        w:::::::w       w:::::::w        U:::::::UUU:::::::U " << endl;
    cout << "  UU:::::::::::::UU          w:::::w         w:::::w          UU:::::::::::::UU  " << endl;
    cout << "    UU:::::::::UU             w:::w           w:::w             UU:::::::::UU    " << endl;
    cout << "      UUUUUUUUU                www             www                UUUUUUUUU      " << endl;
    cout << endl << endl;
    system("pause");
    return 0;

}



//Condicion para el eliminar por condicion

bool condicion(int n)
{
    return n > 3;
}













// ~Mephisto
