#ifndef LISTAORDENADA_H_INCLUDED
#define LISTAORDENADA_H_INCLUDED

#include <iostream>

template <typename T>
class ListaOrdenada{

public:

    /** \brief Constructor por default
     */
    ListaOrdenada();

    /** \brief Constructor de copias, crea una nueva lista a partir de una ya existente.
     * \param Lista.
     */
    ListaOrdenada(const ListaOrdenada<T> &LO);

    /** \brief Sobrecarga del operador "=" para copiar una lista en otra.
     * \param Lista
     * \return Lista
     */
    ListaOrdenada<T> & operator=(const ListaOrdenada<T> &LO);

    /** \brief Destructor que libera la memoria asignada a la lista cuando ya no se necesita.
     */
    ~ListaOrdenada();

    /** \brief Agregar un elemento a la lista de manera ordenada.
     * \param valor que se desee agregar a la lista.
     */
    void agregar(T v);

    /** \brief Elimina un elemento específico de la lista, si es que la lista existe.
     * \param valor que se desee eliminar de la lista.
     * \return bool para saber si se eliminó un elemento o no (esto es opcional, puedes en vez de un bool poner un void)
     */
    bool eliminar(T v);

    /** \brief Busca un elemento en la lista. Método constante ya no modifica nada de la lista.
     * \param valor que se desee buscar.
     * \return True si encuentra el dato, false en caso contrario.
     */
    bool buscar(T v) const;

    /** \brief Elimina todos los elementos de la lista.
     */
    void vaciarLista();

    /** \brief Verifica si la lista está vacía. Método constante ya no modifica nada de la lista.
     * \return true si la lista se encuentra vacía, false en caso contrario.
     */
    bool listaVacia() const;

    /** \brief Devuelve el tamaño (número de elementos) de la lista. Método constante ya no modifica nada de la lista.
     * \return tamaño de la lista.
     */
    unsigned tamanio() const;

    /** \brief Imprime los elementos de la lista en orden ascendente. Método constante ya no modifica nada de la lista.
     */
    void imprimirAscendente() const;

    /** \brief Imprime los elementos de la lista en orden descendente. Método constante ya no modifica nada de la lista.
     */
    void imprimirDescendente() const;

    /** \brief Elimina todas las ocurrencias de un valor específico
     * \param valor que se desee eliminar de la lista (sea uno o varios).
     */
    void eliminarTodaOcurrencia(T v);

    /** \brief Devuelve una nueva lista que es el resultado de mezclar la lista actual con otra lista proporcionada como argumento
                manteniendo el orden.
     * \param Lista
     * \return Nueva lista mezclada
     */
    ListaOrdenada<T> mezclar(const ListaOrdenada<T> &LO) const;

private:

    unsigned tam = 0;                       /**< Almacena el tamaño actual de la lista. */

    /** \brief Define una estructura de un nodo en la lista doblemente enlazada, que contiene un dato de tipo "T", así como
                como punteros al siguiente y al anterior elemento de la lista
     */
    struct Elemento{

        /** \brief Constructor de la estructura.
         */
        explicit Elemento(T d, Elemento * sig = nullptr, Elemento * ant = nullptr) :
            dato(d), siguiente(sig), anterior(ant){}

        T dato;                             /**< Espacio donde se almacenará el dato */
        Elemento * siguiente = nullptr;     /**< Puntero tipo Elemento al siguiente elemento de la lista */
        Elemento * anterior = nullptr;      /**< Puntero tipo Elemento al elemento anterior de la lista*/

    } * primero, * ultimo;                  /**< Punteros al primer y último elemento de la lista */

};

#include "ListaOrdenada.tpp"


#endif // LISTAORDENADA_H_INCLUDED













//~Mephisto
