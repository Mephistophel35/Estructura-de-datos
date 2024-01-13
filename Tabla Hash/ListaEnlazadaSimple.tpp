#include "ListaEnlazadaSimple.h"

template<typename T>
ListaEnlazadaSimple<T>::ListaEnlazadaSimple(ListaEnlazadaSimple const &c) : tam(0), ultimo(nullptr), primero(nullptr)
{
    *this = c; // Constructor de copia: se copian los elementos de la lista original en la nueva lista
}

template<typename T>
ListaEnlazadaSimple<T> &ListaEnlazadaSimple<T>::operator=(const ListaEnlazadaSimple &c)
{
    if (this == &c)
        return *this; // Comprueba si la lista es la misma que la que se está asignando y devuelve la lista actual si es verdadero

    Vaciar(); // Vacía la lista actual
    Elemento *actual = c.primero; // Puntero al primer elemento de la lista original
    while (actual != nullptr)
    {
        AgregarComoUltimo(actual->valor); // Agrega cada elemento de la lista original a la lista actual
        actual = actual->siguiente; // Avanza al siguiente elemento en la lista original
    }
    return *this; // Devuelve la lista actualizada
}

template<typename T>
ListaEnlazadaSimple<T>::~ListaEnlazadaSimple()
{
    Vaciar(); // Destructor: vacía la lista
}

template<typename T>
void ListaEnlazadaSimple<T>::AgregarComoPrimero(const T valor)
{
    auto *nuevo = new Elemento(valor); // Crea un nuevo elemento con el valor dado
    if (EstaVacia())
    {
        primero = ultimo = nuevo; // Si la lista está vacía, el nuevo elemento se convierte en el primero y el último
    }
    else
    {
        nuevo->siguiente = primero; // Establece el siguiente del nuevo elemento como el primer elemento actual
        primero = nuevo; // El nuevo elemento se convierte en el primer elemento
    }
    ++tam; // Incrementa el tamaño de la lista
}

template<typename T>
void ListaEnlazadaSimple<T>::AgregarComoUltimo(const T valor)
{
    auto *nuevo = new Elemento(valor); // Crea un nuevo elemento con el valor dado
    if (EstaVacia())
    {
        primero = ultimo = nuevo; // Si la lista está vacía, el nuevo elemento se convierte en el primero y el último
    }
    else
    {
        ultimo->siguiente = nuevo; // Establece el siguiente del último elemento actual como el nuevo elemento
        ultimo = nuevo; // El nuevo elemento se convierte en el último elemento
    }
    ++tam; // Incrementa el tamaño de la lista
}

template<typename T>
void ListaEnlazadaSimple<T>::AgregarEnPosicion(const unsigned int pos, const T valor)
{
    if (pos < 0 || pos > tam)
        throw FueraDeRango(); // Lanza una excepción si la posición está fuera de rango

    if (pos == 0)
    {
        AgregarComoPrimero(valor); // Si la posición es 0, agrega el elemento como el primero
    }
    else if (pos == tam)
    {
        AgregarComoUltimo(valor); // Si la posición es igual al tamaño de la lista, agrega el elemento como el último
    }
    else
    {
        Elemento *ant = primero;
        for (unsigned int i = 1; i < pos; ++i)
        {
            ant = ant->siguiente; // Encuentra el elemento anterior a la posición dada
        }
        auto *nuevo = new Elemento(valor, ant->siguiente); // Crea un nuevo elemento con el valor dado y el siguiente apuntando al elemento en la posición dada
        ant->siguiente = nuevo; // Establece el siguiente del elemento anterior al nuevo elemento
        ++tam; // Incrementa el tamaño de la lista
    }
}

template<typename T>
void ListaEnlazadaSimple<T>::EliminarPrimerElemento()
{
    if (EstaVacia())
        throw ListaVacia(); // Lanza una excepción si la lista está vacía
    Elemento *porBorrar = primero; // Almacena el puntero al primer elemento
    if (primero == ultimo)
        primero = ultimo = nullptr; // Si la lista solo tiene un elemento, establece el primero y el último como nulos
    else
        primero = primero->siguiente; // Establece el primer elemento como el siguiente elemento
    delete porBorrar; // Libera la memoria del elemento eliminado
    --tam; // Reduce el tamaño de la lista
}

template<typename T>
void ListaEnlazadaSimple<T>::EliminarUltimoElemento()
{
    if (EstaVacia())
        throw ListaVacia(); // Lanza una excepción si la lista está vacía
    Elemento *porBorrar = ultimo; // Almacena el puntero al último elemento
    if (primero == ultimo)
    {
        primero = ultimo = nullptr; // Si la lista solo tiene un elemento, establece el primero y el último como nulos
    }
    else
    {
        Elemento *aux = primero;
        while (aux->siguiente != ultimo)
        {
            aux = aux->siguiente; // Encuentra el elemento anterior al último elemento
        }
        aux->siguiente = nullptr; // Establece el siguiente del elemento anterior al último como nulo
        ultimo = aux; // Establece el último elemento como el elemento anterior
    }
    delete porBorrar; // Libera la memoria del elemento eliminado
    --tam; // Reduce el tamaño de la lista
}

template<typename T>
void ListaEnlazadaSimple<T>::EliminarEnPosicion(const unsigned int pos)
{
    if (EstaVacia())
        throw ListaVacia(); // Lanza una excepción si la lista está vacía

    if (pos < 0 || pos >= tam)
        throw FueraDeRango(); // Lanza una excepción si la posición está fuera de rango

    if (pos == 0)
    {
        EliminarPrimerElemento(); // Si la posición es 0, elimina el primer elemento
    }
    else if (pos == tam - 1)
    {
        EliminarUltimoElemento(); // Si la posición es igual al tamaño de la lista menos 1, elimina el último elemento
    }
    else
    {
        Elemento *ant = primero;
        for (unsigned int i = 1; i < pos; ++i)
        {
            ant = ant->siguiente; // Encuentra el elemento anterior al elemento en la posición dada
        }
        Elemento *porBorrar = ant->siguiente; // Almacena el puntero al elemento a eliminar
        ant->siguiente = porBorrar->siguiente; // Establece el siguiente del elemento anterior al siguiente del elemento a eliminar
        delete porBorrar; // Libera la memoria del elemento eliminado
        --tam; // Reduce el tamaño de la lista
    }
}

template<typename T>
void ListaEnlazadaSimple<T>::Eliminar(const T valor)
{
    if (EstaVacia())
        throw ListaVacia(); // Lanza una excepción si la lista está vacía

    EliminarEnPosicion(EncontrarPosicionValor(valor)); // Elimina el elemento en la posición donde se encuentra el valor dado
}

template<typename T>
void ListaEnlazadaSimple<T>::EliminarTodos(const T valor)
{
    if (EstaVacia())
        throw ListaVacia(); // Lanza una excepción si la lista está vacía
    Elemento *actual = primero;
    for (unsigned int i = 0; i < tam; ++i)
    {
        if (actual->valor == valor)
        {
            EliminarEnPosicion(i); // Elimina el elemento en la posición actual si su valor coincide con el valor dado
            i--; // Decrementa el contador para evitar omitir un elemento después de eliminar uno
        }
        actual = actual->siguiente; // Avanza al siguiente elemento
    }
}

template<typename T>
void ListaEnlazadaSimple<T>::Vaciar()
{
    while (!EstaVacia())
        EliminarPrimerElemento(); // Elimina el primer elemento repetidamente hasta que la lista esté vacía
}

template<typename T>
bool ListaEnlazadaSimple<T>::EstaVacia() const
{
    return primero == nullptr; // Verifica si el primer elemento es nulo para determinar si la lista está vacía
}

template<typename T>
T ListaEnlazadaSimple<T>::ObtenerPrimero() const
{
    if (EstaVacia())
        throw ListaVacia(); // Lanza una excepción si la lista está vacía
    return primero->valor; // Devuelve el valor del primer elemento
}

template<typename T>
T ListaEnlazadaSimple<T>::ObtenerUltimo() const
{
    if (EstaVacia())
        throw ListaVacia(); // Lanza una excepción si la lista está vacía
    return ultimo->valor; // Devuelve el valor del último elemento
}

template<typename T>
T ListaEnlazadaSimple<T>::ObtenerEnPosicion(const int pos) const
{
    return (*this)[pos]; // Devuelve el valor en la posición dada utilizando el operador de indexación sobrecargado
}

template<typename T>
void ListaEnlazadaSimple<T>::ModificarEnPosicion(const int pos, const T valor)
{
    (*this)[pos] = valor; // Modifica el valor en la posición dada utilizando el operador de indexación sobrecargado
}


template<typename T>
T ListaEnlazadaSimple<T>::operator[](const unsigned int pos) const
{
    if (EstaVacia())
        throw ListaVacia(); // Lanza una excepción si la lista está vacía
    if (pos < 0 || pos >= tam)
        throw FueraDeRango(); // Lanza una excepción si la posición está fuera de rango
    Elemento *actual = primero;
    for (unsigned int i = 1; i <= pos; ++i)
    {
        actual = actual->siguiente; // Avanza al siguiente elemento hasta llegar a la posición dada
    }
    return actual->valor; // Devuelve el valor del elemento en la posición dada
}

template<typename T>
T& ListaEnlazadaSimple<T>::operator[](const unsigned int pos)
{
    if (EstaVacia())
        throw ListaVacia(); // Lanza una excepción si la lista está vacía
    if (pos < 0 || pos >= tam)
        throw FueraDeRango(); // Lanza una excepción si la posición está fuera de rango
    Elemento *actual = primero;
    for (unsigned int i = 1; i <= pos; ++i)
    {
        actual = actual->siguiente; // Avanza al siguiente elemento hasta llegar a la posición dada
    }
    return actual->valor; // Devuelve una referencia al valor del elemento en la posición dada
}

template<typename T>
unsigned int ListaEnlazadaSimple<T>::ObtenerTam() const
{
    return tam; // Devuelve el tamaño de la lista
}

template<typename T>
int ListaEnlazadaSimple<T>::EncontrarPosicionValor(const T valor) const
{
    Elemento *actual = primero;
    for (unsigned int i = 0; i < tam; ++i)
    {
        if (actual->valor == valor)
            return i; // Devuelve la posición actual si el valor coincide con el valor dado
        actual = actual->siguiente; // Avanza al siguiente elemento
    }
    return -1; // Devuelve -1 si el valor no se encuentra en la lista
}

template<typename T>
const char *ListaEnlazadaSimple<T>::ListaVacia::what() const noexcept
{
    return "La lista est\240 vac\241a";
}

template<typename T>
const char *ListaEnlazadaSimple<T>::FueraDeRango::what() const noexcept
{
    return "Valor fuera de rango";
}
