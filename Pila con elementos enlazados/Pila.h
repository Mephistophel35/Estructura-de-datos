#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

template <typename T>
class Pila{


public:

    class pilaVacia : public std::exception{
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
    Pila(const Pila<T> & P);

    /** \brief Sobrecarga del operador igual
     *
     * \param Pila tipo T constante por referencia
     * \param Pila del mismo tipo que del par�metro recibido por referencia
     *
     */
    Pila<T> & operator=(const Pila<T> & P);

     /** \brief Destructor
      *
      */
    ~Pila();

    /** \brief M�todo agregar a la pila
     *
     * \param valor tipo T constante por referencia (valor que deseamos agregar a la Pila).
     *
     */
    void Agregar(const T &v);

    /** \brief M�todo eliminar de la pila (Elimina el elemento en el tope de la pila)
     *
     */
    void Eliminar();

    /** \brief Conocer el tope de la pila (dato). ~M�todo constante
     *
     * \return dato tipo T constante por referencia, enviamos el dato que tenemos almacenado en la estructura tipo Elemento.
     *
     */
    const T &Tope() const;

    /** \brief M�todo pila vacia. ~M�todo constante.
     *
     * \return True/False si la pila se encuentra vac�a o no.
     *
     */
    bool PilaVacia() const;

    /** \brief M�todo vaciar pila.
     *
     */
    void VaciarPila();

    /** \brief M�todo conocer el tama�o de la pila. ~M�todo constante.
     *
     * \return Tama�o de la pila (entero).
     *
     */
    int Tamanio() const;

    /** \brief M�todo imprimir la Pila. ~M�todo constante.
     *
     */
    void Imprimir() const;


private:

    int NumElem;                        /**< N�mero de elemento que la pila posee. */


    struct Elemento{

        /** \brief Constructor por defaul de la estructura.
         *
         * \param Dato tipo T
         * \param Puntero tipo Elemento al siguiente.
         *
         */
        Elemento(T d, Elemento * sig = nullptr): dato(d), siguiente(sig){};

        T dato;                         /**< Dato tipo T */
        Elemento * siguiente;           /**< Puntero tipo elemento al siguiente */

    };
    Elemento * tope;                    /**< Puntero tipo elemento al tope de la pila */


};

#include "Pila.tpp"

#endif // PILA_H_INCLUDED





// ~Mephisto
