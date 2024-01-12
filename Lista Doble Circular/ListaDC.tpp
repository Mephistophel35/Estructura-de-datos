#include <iostream>

using std::cout;
using std::endl;

template <typename T>
ListaDC<T>::ListaDC(const ListaDC<T> &LDC) : tam(0), cabeza(nullptr)
{
    *this = LDC;
}

template <typename T>
ListaDC<T> & ListaDC<T>::operator=(const ListaDC<T> &LDC)
{
    if(this == &LDC)
    {
        return *this;
    }
    vaciarLista();
    if(LDC.listaVacia())
    {
        return *this;
    }
    Elemento * act = LDC.cabeza;

    do{

        agregarCabeza(act->dato);
        act = act->siguiente;


    }while(act != LDC.cabeza);

    return *this;
}

template <typename T>
ListaDC<T>::~ListaDC()
{
    vaciarLista();
}

template <typename T>
void ListaDC<T>::agregarCabeza(T v)
{
    Elemento * aux = new Elemento(v, cabeza == nullptr ? nullptr : cabeza->siguiente, cabeza);
    if(listaVacia()){
        cabeza = aux;
        cabeza->siguiente = cabeza;
        cabeza->anterior = cabeza;
    }else{
        cabeza->siguiente->anterior = aux;
        cabeza->siguiente = aux;
        cabeza = aux;
    }
    ++tam;
}

template <typename T>
void ListaDC<T>::agregarDespuesCabeza(T v)
{
    Elemento * aux = new Elemento(v, cabeza == nullptr ? nullptr : cabeza->siguiente, cabeza);
    if(listaVacia()){
        cabeza = aux;
        cabeza->siguiente = cabeza;
        cabeza->anterior = cabeza;
    }else{
        cabeza->siguiente->anterior = aux;
        cabeza->siguiente = aux;
    }
    ++tam;
}

template <typename T>
void ListaDC<T>::eliminarCabeza()
{
    if(listaVacia()) throw ListaVacia();

    Elemento * porBorrar = cabeza;
    if(cabeza == cabeza->siguiente){
        cabeza = nullptr;
    }else{
        cabeza = cabeza->siguiente;
        cabeza->siguiente = porBorrar->siguiente;
        porBorrar->siguiente->anterior = cabeza;
    }
    delete porBorrar;
    --tam;
}

template <typename T>
void ListaDC<T>::eliminarVDado(T v)
{
    if(listaVacia()) throw ListaVacia();

    Elemento * aux = cabeza->siguiente;

    if(cabeza->siguiente == cabeza) eliminarCabeza();
    do{
        rotarAContrarreloj();
        if(cabeza->dato == v){
            if(aux == cabeza){
                aux = aux->siguiente;
            }
            eliminarCabeza();
            return;
        }
    }while(cabeza->siguiente != aux);

    while(cabeza->siguiente != aux){
        rotarAContrarreloj();
    }
}

template <typename T>
void ListaDC<T>::rotarAReloj()
{
    if(listaVacia()) throw ListaVacia();
    cabeza = cabeza->anterior;
}

template <typename T>
void ListaDC<T>::rotarAContrarreloj()
{
    if(listaVacia()) throw ListaVacia();
    cabeza = cabeza->siguiente;
}

template <typename T>
const T &ListaDC<T>::valorCabeza() const
{
    return cabeza->dato;
}

template <typename T>
bool ListaDC<T>::buscar(T v) const
{
    if(listaVacia()) throw ListaVacia();

    Elemento * aux = cabeza->siguiente;
    do{
        if(aux->dato == v){
            return true;
        }
        aux = aux->siguiente;
    }while(aux != cabeza->siguiente);

    return false;
}

template <typename T>
unsigned int ListaDC<T>::tamanio() const
{
    return tam;
}

template <typename T>
bool ListaDC<T>::listaVacia() const
{
    return (cabeza == nullptr);
}

template <typename T>
void ListaDC<T>::vaciarLista()
{
    while(cabeza != nullptr){
        eliminarCabeza();
    }
}

template <typename T>
void ListaDC<T>::imprimirAReloj() const
{
    if(listaVacia()){
        cout << "[]" << endl;
        return;
    }

    Elemento * aux = cabeza->anterior;

    cout << "[" << cabeza->dato << "]";
    while(aux != cabeza){
        cout << "[" << aux->dato << "]";
        aux = aux->anterior;
    }
}

template <typename T>
void ListaDC<T>::imprimirAContrarreloj() const
{
    if(listaVacia()){
        cout << "[]" << endl;
        return;
    }

    Elemento * aux = cabeza->anterior;

    cout << "[" << cabeza->dato << "]";
    while(aux != cabeza){
        cout << "[" << aux->dato << "]";
        aux = aux->siguiente;
    }
}

template <typename T>
void ListaDC<T>::eliminarTodaOcurrencia(T v)
{
    if(listaVacia()) throw ListaVacia();

    Elemento * aux = cabeza->siguiente;

    do{
        rotarAContrarreloj();
        if(cabeza->dato == v){
            if(aux == cabeza){
                aux = aux->siguiente;
            }
            eliminarCabeza();
        }
    }while(cabeza->siguiente != aux);
}

template <typename T>
const char *ListaDC<T>::ListaVacia::what() const noexcept
{
    return "Lista vac\241a pa";
}












// ~ Mephisto
