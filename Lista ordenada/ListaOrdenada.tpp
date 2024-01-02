#include <iostream>
using std::cout;
using std::endl;

template <typename T>
ListaOrdenada<T>::ListaOrdenada() : tam(0), primero(nullptr), ultimo(nullptr){}

template <typename T>
ListaOrdenada<T>::ListaOrdenada(const ListaOrdenada<T> &LO) : tam(0), primero(nullptr), ultimo(nullptr)
{
    //Here we go again, ya saben, igualan porque tenemos la sobrecarga abajo.
    *this = LO;
}

//Esta es la sobrecarga, es casi igual o mismamente es igual al de los anteriores códigos, muy importante esto!.
template <typename T>
ListaOrdenada<T> & ListaOrdenada<T>::operator=(const ListaOrdenada<T> &LO)
{
    if(this == &LO){
        return *this;
    }
    vaciarLista();
    if(LO.listaVacia()){
        return *this;
    }
    Elemento * actual = LO.primero;

    while(actual != nullptr){
        agregar(actual->dato);
        actual = actual->siguiente;
    }
    return *this;
}

//Este es el Galactus de la clase.
template <typename T>
ListaOrdenada<T>::~ListaOrdenada()
{
    vaciarLista();
}

template <typename T>
void ListaOrdenada<T>::agregar(T v)
{
    //El mismo puntero auxiliar de siempre.
    Elemento * aux = primero;

    //Recorremos el puntero para encontrar el lugar del nuevo dato a agregar.
    while(aux != nullptr && aux->dato < v){
        aux = aux->siguiente;
    }

    //Dependiendo de que si el puntero llega al final pues hacemos que el anterior elemento del nuevo elemento apunte al que era el último en ese momento.
    Elemento * nuevo = new Elemento(v, aux, aux == nullptr ? ultimo : aux->anterior);
    //Si el puntero apunta a null...
    if(aux == nullptr){
        //si el primero apunta a null pues hacemos que ahora el primero apunte al nuevo
        //En el caso de que no pues hacemos que el siguiente del último elemento en ese momento apunte al nuevo elemento.
        (primero == nullptr ? primero : ultimo->siguiente) = nuevo;
        //Hacemos que el puntero al último elemento apunte al nuevo.
        ultimo = nuevo;
    //En caso de que el puntero NO apunte a null...
    } else {
        //Si el puntero auxiliar apunta al primer elemento...
            //hacemos que el puntero al primer elemento apunte ahora al nuevo elemento.
        //Si el puntero auxiliar NO apunta al primer elemento...
            //hacemos que el siguiente del anterior del puntero auxiliar apunte al nuevo elemento.
        (aux == primero ? primero : aux->anterior->siguiente) = nuevo;

        //Ahora hacemos que el anterior del puntero auxiliar apunte al nuevo elemento.
        aux->anterior = nuevo;
    }
    //Incrementamos el tamaño de la lista.
    ++tam;
}

template <typename T>
bool ListaOrdenada<T>::eliminar(T v)
{
    //Mismo puntero.
    Elemento * aux = primero;

    //Recorremos el puntero...
    while(aux != nullptr && aux->dato != v) aux = aux->siguiente;

    //Como es casi una búsqueda, puede ser el caso de que estemos apuntando al siguiente del último elemento (null)
    //Si llegamos ahí retornamos un false como diciendo que no eliminamos nada.
    if(aux == nullptr) return false;

    //Si el auxiliar apunta al primero, pues hacemos que el primero ahora apunte al siguiente del auxiliar.
    //Si no, hacemos que el siguiente del anterior del auxiliar apunte al siguiente del auxiliar.
    (aux == primero ? primero : aux->anterior->siguiente) = aux->siguiente;
    //Si el auxiliar apunta al ultimo, hacemos que el último apunte al anterior del auxiliar.
    //Si no, hacemos que el anterior del siguiente del auxiliar apunte ahora al anterior del auxiliar.
    (aux == ultimo ? ultimo : aux->siguiente->anterior) = aux->anterior;

    //Eliminamos el puntero que usamos.
    delete aux;
    //Le quitamos 1 al tamaño de la lista porque pues ya le quitamos un elemento.
    --tam;
    //Regresamos true como diciendo que si eliminamos algo.
    return true;
}

template <typename T>
bool ListaOrdenada<T>::buscar(T v) const
{
    //Mismo puntero.
    Elemento * aux = primero;
    //Lo recorremos
    while(aux != nullptr && aux->dato != v) aux = aux->siguiente;
    //Son las mismas instrucciones casi casi del eliminar cuando lleguemos a un lugar en el que no esté el dato que estémos buscando.
    //Entonces regresamos false si no está el dato.
    if(aux == nullptr) return false;
    //retornamos true si si está.
    return true;
}

template <typename T>
void ListaOrdenada<T>::vaciarLista()
{
    //Mientras la lista NO esté vacía pues vamos eliminando datos, hasta que la lista quede vacía.
    while(!listaVacia()){
        eliminar(primero->dato);
    }
}

template <typename T>
bool ListaOrdenada<T>::listaVacia() const
{
    //Si el puntero al primero apunta a null hay de dos sopas
    //O realmente no hay nada en la lista.
    //O algo hicimos mal en las conexiones de punteros (te sugiero revisar!).
    return(primero == nullptr);
}

template <typename T>
unsigned ListaOrdenada<T>::tamanio() const
{
    //Regresamos el tamaño de la lista.
    return tam;
}

template <typename T>
void ListaOrdenada<T>::imprimirAscendente() const
{
    //Si la lista está vacía pues imprimo esto como dando a conocer que no hay elemento en la lista.
    if(listaVacia())
    {
        cout << "[]" << endl;
        //No digan nada de esto shhh
        return;
    }

    //Mismo puntero, mientras vamos recorriendo, vamos imprimiendo los datos.
    Elemento * aux = primero;
    while(aux != nullptr){
        cout << "[" << aux->dato << "]";
        aux = aux->siguiente;
    }
}

template <typename T>
void ListaOrdenada<T>::imprimirDescendente() const
{
    //Lo mismo de ahorita si la lista está vacía.
    if(listaVacia())
    {
        cout << "[]" << endl;
        return;
    }

    //En vez de apuntar al primer elemento, apuntamos al último porque pues vamos ahora ir de atrás hacia adelante.
    Elemento * aux = ultimo;
    while(aux != nullptr){
        cout << "[" << aux->dato << "]";
        aux = aux->anterior;
    }
}

template <typename T>
void ListaOrdenada<T>::eliminarTodaOcurrencia(T v)
{
    //Si la lista está vacía pues no hay nada que borrar pue
    if(listaVacia()){
        cout << "Lista vacía, vuelva pronto" << endl;
        return;
    }
    //Mismo puntero
    Elemento * aux = primero;
    //Si el elemento se encuentra aquí en la lista pues lo mandamos a levantar y luego reiniciamos el conteo haciendo que el auxiliar apunte al primero de nuevo.
    while(aux != nullptr)
    {
        if(aux->dato == v)
        {
            eliminar(v);
            aux = primero;
        }else{
            //Si aux->dato no es el dato que estamos buscando pues recorremos el puntero al siguiente elemento.
            aux = aux->siguiente;
        }
    }
}

template <typename T>
ListaOrdenada<T> ListaOrdenada<T>::mezclar(const ListaOrdenada<T> &LO) const
{
    //Mismo puntero que usamos, solo que ahora hacemos que apunte al primer elemento de la lista del argumento.
    Elemento * aux = LO.primero;

    //Creamos otra lista del mismo tipo del parámetro
    ListaOrdenada<T> LM;
    //Hacemos que la nueva lista sea igual a la de la instancia.
    LM = *this;

    //Mientras el puntero no apunte a null pues vamos agregando los datos de la lista del parámetro a la nueva que creamos para después devolver esa lista ya mezclada.
    while(aux != nullptr){
        LM.agregar(aux->dato);
        aux = aux->siguiente;
    }
    return LM;
}



























//~Mephisto
