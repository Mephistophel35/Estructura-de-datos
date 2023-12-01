#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <iostream>
#include <exception>

template <typename T>
class Lista{

public:

     /** \class listaVacia
     *
     *  \exception lanzada cuando se intenta acceder a los elementos de una Lista vacia.
     */
    class listaVacia : public std::exception{
    public:
        virtual const char * what() const throw();
    };

    /** \class FueraDeRango
     *
     *  \exception lanzada cuando el indice proporcionado en algunos métodos está fuera del rango esperado.
     */
    class FueraDeRango : public std::exception{
    public:
        virtual const char * what() const throw();
    };

    /** \class ValorNoEncontrado
     *
     *  \exception lanzada cuando al usar el método "Buscar" no encuentra la información.
     */
    class ValorNoEncontrado : public std::exception{
    public:
        virtual const char * what() const throw();
    };

    /** \brief Constructor por default
     *
     */
    Lista();

    /** \brief Constructor de copias
     *
     * \param Lista tipo T constante por referencia.
     *
     */
    Lista(const Lista<T> &L);

    /** \brief Sobrecarga del operador =
     *
     * \param Lista tipo T constante por referencia
     * \return Lista tipo T por referencia
     *
     */
    Lista<T> & operator=(const Lista<T> &L);

    /** \brief Destructor
     *
     */
    ~Lista();

    /** \brief Agregar al Inicio de la lista
     *
     * \param dato tipo T constante por referencia.
     *
     */
    void AgregarInicio(const T &v);

    /** \brief Agregar al final de la lista.
     *
     * \param dato tipo T constante por referencia.
     *
     */
    void AgregarFinal(const T &v);

    /** \brief Agregar en posición específica en la lista
     *
     * \param dato tipo T constante por referencia.
     * \param indice donde se agregará el valor dado. (entero).
     *
     */
    void AgregarEnPos(const T &v, int ind);

    /** \brief Eliminar al inicio de la lista.
     *
     */
    void EliminarInicio();

    /** \brief Eliminar al final de la lista.
     *
     */
    void EliminarFinal();

    /** \brief Eliminar en una posición específica en la lista.
     *
     * \param indice (entero).
     *
     */
    void EliminarEnPos(int ind);

    /** \brief Eliminar primera ocurrencia, es decir, se da un valor y si encuentra un valor igual al proporcionado lo elimina.
     *
     * \param dato tipo T constante por referencia,
     *
     */
    void EliminarPrimeraOcurrencia(const T &v);

    /** \brief Elimina toda ocurrencia, es decir, se da un valor y si lo encuentra elimina en la lista todos los elementos iguales a él.
     *
     * \param dato tipo T constante por referencia.
     *
     */
    void EliminarTodaOcurrencia(const T &v);

    /** \brief Método "Buscar". ~Método constante
     *
     * \param dato tipo T constante por referencia.
     * \return True/False si el dato proporcionado se encuentra en la lista.
     *
     */
    bool Buscar(const T &v) const;

    /** \brief Método buscar posición del dato. ~Método constante.
     *
     * \param dato tipo T constante por referencia
     * \return Posición del dato en la lista (entero).
     *
     */
    int * BuscarPosicion(const T &v) const;

    /** \brief Método Lista Vacia. ~Método constante
     *
     * \return True/False si la lista se encuentra vacia.
     *
     */
    bool ListaVacia() const;

    /** \brief Método qie devuelve el dato en la primera posición de la lista. ~Método constante.
     *
     * \return dato tipo T constante por referencia de la primera posición.
     *
     */
    const T &Primero() const;

    /** \brief Método que devuelve el dato en la última posición de la lista. ~Método constante.
     *
     * \return dato tipo T constante por referencia de la última posición.
     *
     */
    const T &Ultimo() const;

    /** \brief Método que devuelve el dato en la posición proporcionada de la lista. ~Método constante.
     *
     * \param índice del dato que se desea saber. (entero)
     * \return dato tipo T constante por referencia que se encuentra en la posición proporcionada.
     *
     */
    const T &ValorEnPosicion(int ind) const;

    /** \brief Método para modificar un elemento en una posición dada.
     *
     * \param indice constante (entero)
     * \param dato tipo T constante por referencia para hacer el reemplazo.
     *
     */
    void ModificarElem(const int ind, const T &v);

    /** \brief Método saber el Tamaño de la lista. ~Método constante.
     *
     * \return Tamaño de la lista. (entero)
     *
     */
    int Tamanio() const;

    /** \brief Método vaciar lista.
     *
     */
    void Vaciar();

    /** \brief Método imprimir lista. ~Método constante.
     *
     */
    void Imprimir() const;

    /** \brief Sobrecarga del operador []. ~Método constante.
     *
     * \param indice constante. (entero)
     * \return dato tipo T constante por referencia
     *
     */
    const T &operator[](const int ind) const;

    /** \brief Sobrecarga del operador [].
     *
     * \param indice constante. (entero).
     * \return dato tipo T por referencia.
     *
     */
    T & operator[](const int ind);


private:

    int tam = 0;                            /**< Contador del tamaño de la lista */

    struct Elemento{

        /** \brief Constructor de la estructura Elemento
         *
         * \param dato tipo T.
         * \param Puntero tipo elemento a la siguiente estructura, en este caso, siguiente contenedor de información.
         *
         */
        Elemento(T d, Elemento * sig = nullptr) : dato(d), siguiente(sig){};

        T dato;                             /**< Dato tipo T que se guardará (key) */
        Elemento * siguiente;               /**< Puntero tipo Elemento al siguiente elemento. */

    };

    Elemento * primero;                     /**< Puntero tipo Elemento al primer elemento de la lista (atributo de la clase)*/
    Elemento * ultimo;                      /**< Puntero tipo Elemento al último elemento de la lista (atributo de la clase)*/

};

#include "Lista.tpp"

#endif // LISTA_H_INCLUDED




// ~Mephisto
