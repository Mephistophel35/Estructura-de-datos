#include <iostream>

using std::cout;
using std::endl;

template <typename T>
ListaDC<T>::ListaDC(const ListaDC<T> &LDC) : tam(0), cabeza(nullptr)
{
   //Ya se la saben, igualamos esto, esto es posible por la sobrecarga del =
    *this = LDC;
}

//Esto ya se lo saben de los anteriores códigos, no cambia mucho.
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

//Destrucción
template <typename T>
ListaDC<T>::~ListaDC()
{
    vaciarLista();
}

template <typename T>
void ListaDC<T>::agregarCabeza(T v)
{
   //Creamos un puntero auxiliar que dependiendo si cabeza apunta a null hacemos que el siguiente apunte o a null o que apunte al siguiente de la cabeza y hacemos que el
   //anterior apunte a cabeza
    Elemento * aux = new Elemento(v, cabeza == nullptr ? nullptr : cabeza->siguiente, cabeza);
   //Checamos en fa
    if(listaVacia()){
      //Si si está vacía, debemos hacer que cabeza apunte a donde apunte auxiliar
        cabeza = aux;
      //Después hacemos que el siguiente de la cabeza apunte a la cabeza, es decir a sí mismo, igual para el anterior de cabeza, hacemos que apunte a así mismo.
        cabeza->siguiente = cabeza;
        cabeza->anterior = cabeza;
    }else{
      //Si la lista no está vacía...
         //hacemos que el anterior del siguiente de cabeza apunte al auxiliar
        cabeza->siguiente->anterior = aux;
         //que el siguiente de la cabeza apunte al auxiliar
        cabeza->siguiente = aux;
         //Y como no, hacemos que cabeza apunte a auxiliar
        cabeza = aux;
    }
   //Incrementamos el tamaño de la lista.
    ++tam;
}

//Esta mugre lo que hace es que agregue después de cabeza, es decir a cabeza->siguiente
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

//Eliminar, bueno ya se la sabem , desconectar de la lista el elemento y eliminarlo.
template <typename T>
void ListaDC<T>::eliminarCabeza()
{
    if(listaVacia()) throw ListaVacia();

   //Puntero épico que apunte a la cabeza, porque es el elemento que queremos eliminar.
    Elemento * porBorrar = cabeza;
   //Si cabeza apunta así misma, hacemos que cabeza apunte a null y listo.
    if(cabeza == cabeza->siguiente){
        cabeza = nullptr;
    }else{
   //De lo contrario hacemos que la cabeza apunte al siguiente elemento.
        cabeza = cabeza->siguiente;
   //hacemos que el siguiente de cabeza apunte al siguiente del porBorrar (del elemento a eliminar)
        cabeza->siguiente = porBorrar->siguiente;
   //Le decimos que el anterior del siguiente del elemento a eliminar apunte a cabeza
        porBorrar->siguiente->anterior = cabeza;
    }
   //Y le tiramos la nuke con el delete
    delete porBorrar;
   //restamos el tamaño de la lista. épico.
    --tam;
}

//Ahora si, la machaca buena
template <typename T>
void ListaDC<T>::eliminarVDado(T v)
{
    if(listaVacia()) throw ListaVacia();

   //puntero auxiliar, ya se la saben, nunca falla.
    Elemento * aux = cabeza->siguiente;
   
   //si el siguiente de la cabeza apunta a cabeza, es decir a sí mismo, mandamos a eliminar la cabeza, facilito que no.
    if(cabeza->siguiente == cabeza) eliminarCabeza();

   //Como te amo do while
   do{  
      //rotamos a contrarreloj la lista
        rotarAContrarreloj();
      //si el dato que está en la cabeza es igual al valor que queremos eliminar...
        if(cabeza->dato == v){
         //Si el auxiliar apunta a cabeza recorremos el auxiliar
            if(aux == cabeza){
                aux = aux->siguiente;
            }
         //Eliminamos el dato, facilito, practicamente estamos rotando hasta encontrar el valor y ya que lo encontremos GG.
            eliminarCabeza();
         //Viva el break
            break;
        }
      //Bueno, esto se hará mientras el auxiliar no se haya paseado por toda la lista.
    }while(cabeza->siguiente != aux);
      //Esto es meramente para que cuando ya hayamos eliminado el elemento devolverlo a como estaba al inicio.
    while(cabeza->siguiente != aux){
        rotarAContrarreloj();
    }
}

//Esto es super sencillo.
template <typename T>
void ListaDC<T>::rotarAReloj()
{
    if(listaVacia()) throw ListaVacia();
    cabeza = cabeza->anterior;
}

//Esto igual
template <typename T>
void ListaDC<T>::rotarAContrarreloj()
{
    if(listaVacia()) throw ListaVacia();
    cabeza = cabeza->siguiente;
}

//Aquí simplemente eliminamor el dato que esté en la cabeza
template <typename T>
const T &ListaDC<T>::valorCabeza() const
{
    return cabeza->dato;
}

//Magnífico el buscar, les fakin go
template <typename T>
bool ListaDC<T>::buscar(T v) const
{
    if(listaVacia()) throw ListaVacia();
   
   //Ya se saben este puntero
    Elemento * aux = cabeza->siguiente;
    do{
      //Si encontramos el dato devolvemos que simón
        if(aux->dato == v){
            return true;
        }
      //Si no pues vamos recorriendo.
        aux = aux->siguiente;
   //Este ciclo se ejecutará mientras el auxiliar no se haya paseado por toda la lista.
    }while(aux != cabeza->siguiente);
   //Retornamos que ño si no lo encontramos.
    return false;
}

//Regresamos el tamaño
template <typename T>
unsigned int ListaDC<T>::tamanio() const
{
    return tam;
}

//Aquí simplemente checamos que si cabeza apunta a null pues está vacía.
template <typename T>
bool ListaDC<T>::listaVacia() const
{
    return (cabeza == nullptr);
}

//Aquí pues vamos eliminando cabeza por cabeza u know.
template <typename T>
void ListaDC<T>::vaciarLista()
{
    while(cabeza != nullptr){
        eliminarCabeza();
    }
}

//Esto pues está papita, solo vamos recorriendo el puntero aux e imprimiendo cada uno de los datos
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

//Mismo del anterior
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

//Algo bien este, wachen.
template <typename T>
void ListaDC<T>::eliminarTodaOcurrencia(T v)
{
    if(listaVacia()) throw ListaVacia();

   //Puntero de siempre   
    Elemento * aux = cabeza->siguiente;
   //Si se fijan es lo mismo de ahorita pero sin break, sisis es trampa i know, pero nimode, soportar
    do{
      //Rotamos esta vaina
        rotarAContrarreloj();
        if(cabeza->dato == v){
            if(aux == cabeza){
                aux = aux->siguiente;
            }
            eliminarCabeza();
        }
    }while(cabeza->siguiente != aux);
}

//Y esto pues ya se la saben, esto es 100% customizable
template <typename T>
const char *ListaDC<T>::ListaVacia::what() const noexcept
{
    return "Lista vac\241a pa";
}






















// ~ Mephisto
