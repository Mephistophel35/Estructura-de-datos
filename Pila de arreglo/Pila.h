//Creado por Mephistopheles

#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

template <typename T>
class Pila{

public:

    /** \class Clase Pila vacia
     *
     * \exception Lanza excepción cuando la pila está llena (cuando se intente agregar un elemento).
     *
     */
    class PilaVacia : public std::exception{

    public:
        virtual const char * what() const throw();
    };

    /** \brief Constructor por default
     *
     */
    Pila();

    /** \brief Constructor de copias
     *
     * \param Pila tipo T constante por referencia
     *
     */
    Pila(const Pila<T> &p);

    /** \brief Sobrecarga del operador igual
     *
     * \param Pila tipo T constante por referencia
     * \return  Pila tipo T por referencia
     *
     */
    Pila<T> & operator=(const Pila<T> &p);

    /** \brief Destructor
     *
     */
    ~Pila();

    /** \brief Metodo agregar a la pila (agrega hasta arriba de la pila, es decir, en el tope)
     *
     * \param dato tipo T
     *
     */
    void Agregar(T d);

    /** \brief Metodo eliminar de la pila (Elimina el elemento del tope).
     *
     */
    void Eliminar();

    /** \brief Metodo obtener elemento en el tope de la pila (método constante) ya que no modifica nada.
     *
     * \return Dato tipo T constante por referencia.
     *
     */
    const T & Tope() const;

    /** \brief Método que determina si la pila está vacia (método constante).
     *
     * \return True/False si la pila está vacía (evalua si el tope es igual a -1)
     *
     */
    bool pilaVacia() const;

    /** \brief Método que vacía la pila (Elimina los datos que tenga)
     *
     */
    void Vaciar();

    /** \brief Método que nos dice el tamaño de la pila, es decir, cuantos elementos tiene la pila (método constante).
     *
     * \return Cantidad de datos (entero).
     *
     */
    int Tamanio() const;

    /** \brief Método que nos dice la capacidad de datos que el arreglo tiene (método constante).
     *
     * \return Capacidad del arreglo (entero).
     *
     */
    int Capacidad() const;

    /** \brief Método que imprime la pila (método constante).
     *
     */
    void Imprimir() const;

private:

    int capacidad;                  /**< Entero que nos dice la capacidad del arreglo de datos (la pila) */
    int tope;                       /**< Entero usado como índice que determina el tope de la pila */
    T * Elementos;                  /**< Puntero al arreglo dinámico que contendrá los elementos en la pila */

    /** \brief Método para que amplía un x2 la capacidad del arreglo (la pila)
     *
     */
    void Redimensionar();

    /** \brief Método que determina si la pila está llena (método constante).
     *
     * \return True/False si la pila está llena.
     *
     */
    bool pilaLlena() const;
};

#include "Pila.tpp"

#endif // PILA_H_INCLUDED
