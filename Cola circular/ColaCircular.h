#ifndef COLACIRCULAR_H_INCLUDED
#define COOLACIRCULAR_H_INCLUDED
#include <iostream>

template <typename T>
class Cola{

public:

    /** \class ColaVacia
     *
     *  \exception lanzada cuando se intenta acceder a los elementos de una Cola vacia.
     */
    class ColaVaciaExc : public std::exception{
    public:
        virtual const char * what() const throw();
    };

    /** \brief Construcor por default
     *
     */
    Cola();

    /** \brief Constructor de copias
     *
     * \param Cola tipo T constante por referencia.
     *
     */
    Cola(const Cola<T> &C);

    /** \brief Sobrecarga del operador =
     *
     * \param Cola tipo T constante por referencia.
     * \return Cola del mismo tipo que el del par�metro recibido por referencia.
     *
     */
    Cola<T> & operator=(const Cola<T> &C);

    /** \brief Destructor
     *
     */
    ~Cola();

    /** \brief M�todo agregar elemento a la cola.
     *
     * \param Dato que se desea ingresar tipo T constante por referencia.
     *
     */
    void Agregar(const T &v);

    /** \brief M�todo eliminar elemento de la cola.
     *
     */
    void Eliminar();

    /** \brief M�todo conocer el valor que se encuentra al prinipio de la cola. ~M�todo constante
     *
     * \return valor constante tipo T por referencia
     *
     */
    const T & Primero() const;

    /** \brief M�todo conocer el valor que se encuentra al final de la cola. ~M�todo constante
     *
     * \return valor constante tipo T por referencia
     *
     */
    const T & Ultimo() const;

    /** \brief M�todo conocer si la cola est� vacia. ~M�todo constante
     *
     * \return True/False si la cola est� vacia o no.
     *
     */
    bool ColaVacia() const;

    /** \brief M�todo para eliminar todos los elementos de la cola.
     *
     */
    void VaciarCola();

    /** \brief M�todo para conocer el tama�o de la cola. ~M�todo constante.
     *
     * \return Tama�o de la cola (entero).
     *
     */
    int Tamanio() const;

    /** \brief M�todo para imprimir la cola. ~M�todo constante.
     *
     */
    void Imprimir() const;

private:

    int NumElem;                    /**< Entero que almacena el n�mero de elementos que la cola posee.(Atributo de la clase Cola) */

    struct Elemento{

        /** \brief Constructor por default de la estructura Elemento
         *
         * \param Dato tipo T
         * \param Puntero tipo Elemento al siguiente elemento.
         *
         */
        Elemento(T d, Elemento * sig) : dato(d), siguiente(sig){}

        T dato;                     /**< Dato tipo T */
        Elemento * siguiente;       /**< Puntero tipo elemento al siguiente elemento */

    };
    Elemento * ultimo;              /**< Puntero tipo elemento al �ltimo elemento de la cola. (Atributo de la clase Cola) */
};

#include "ColaCircular.tpp"

#endif // COLACIRCULAR_H_INCLUDED

// ~Mephisto
