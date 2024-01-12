#ifndef LISTADC_H_INCLUDED
#define LISTADC_H_INCLUDED

#include <iostream>

template <typename T>
class ListaDC{

public:

    /** \brief Constructor por default
     */
    ListaDC() : tam(0), cabeza(nullptr){};

    /** \brief Constructor de copias
     *
     * \param Lista tipo T para copiarla jeje.
     *
     */
    ListaDC(const ListaDC<T> &LDC);

    /** \brief Sobrecarga del operador de asignacion
     *
     * \param Lista constante tipo T por referencia
     * \return Lista tipo T por referencia
     *
     */
    ListaDC<T> & operator=(const ListaDC<T> &LDC);

    /** \brief Destructor
     */
    ~ListaDC();

    /** \brief Agrega nuevo elemento en la cabeza de la lista.
     *
     * \param valor tipo T
     *
     */
    void agregarCabeza(T v);

    /** \brief Agrega nuevo elemento después de la cabeza de la lista.
     *
     * \param valor tipo T
     *
     */
    void agregarDespuesCabeza(T v);

    /** \brief Elimina el elemento que se encuentre a la cabeza de la lista.
     *
     * \exception Lista vacia.
     *
     */
    void eliminarCabeza();

    /** \brief Elimina el elemento de valor que se solicite.
     *
     * \exception Lista vacia.
     *
     */
    void eliminarVDado(T v);

    /** \brief Rota en el sentido de las manesillas del reloj.
     * \exception Lista vacia.
     */
    void rotarAReloj();

    /** \brief Rota en contra del sentido de las manesillas del reloj.
     *
     * \exception Lista vacia.
     *
     */
    void rotarAContrarreloj();

    /** \brief Saber el valor que se encuentra en la cabeza de la lista.
     *
     * \return valor tipo T
     * \exception Lista Vacia.
     *
     */
    const T & valorCabeza() const;

    /** \brief Busca el elemento que se le solicite.
     *
     * \param valor tipo T.
     * \return true/false si el elemento que se solicite está en la lista.
     *
     */
    bool buscar(T v) const;

    /** \brief Da el tamaño de la lista
     *
     * \return tamaño tipo unsigned entero
     *
     */
    unsigned int tamanio() const;

    /** \brief Da a conocer si la lista se encuentra vacia.
     *
     * \return true/false si la lista se encuentra vacia
     *
     */
    bool listaVacia() const;

    /** \brief Vacia la lista
     */
    void vaciarLista();

    /** \brief Imprime todos los valores que la lista tenga de manera ascendente
     *
     * \exception Lista Vacia.
     *
     */
    void imprimirAReloj() const;

    /** \brief Imprime todos los valores que la lista tenga de manera descendente
     *
     * \exception Lista Vacia.
     *
     */
    void imprimirAContrarreloj() const;

    /** \brief Elimina todos los elementos tipo v que se solicite
     *
     * \param valor tipo T
     * \exception ListaVacia
     * \exception Valor no encontrado
     *
     */
    void eliminarTodaOcurrencia(T v);

    /** \brief Mensaje lanzado (exception) cuando la lista está vacía
     *
     */
    struct ListaVacia : public std::exception{
        const char *what() const noexcept override;
    };

private:

    unsigned int tam = 0;                   /**< Variable de tipo sin signo entero que almacena la cantidad de elemento que la lista posee */

    struct Elemento{

        /** \brief Inicializa la estructura
         *
         * \param Valor tipo T
         * \param Puntero al siguiente elemento
         * \param Puntero al anterior elemento
         * \return
         *
         */
        Elemento(T d, Elemento * sig = nullptr, Elemento * ant = nullptr) : dato(d), siguiente(sig), anterior(ant){}

        T dato;                             /**< Valor tipo T */
        Elemento * siguiente = nullptr;     /**< Puntero de tipo Elemento al siguiente valor de la lista */
        Elemento * anterior = nullptr;      /**< Puntero de tipo Elemento al anterior valor de la lista */

    } *cabeza;                             /**< Puntero de tipo Elemento a la cabeza de la lista */

};

#include "ListaDC.tpp"




#endif












// ~Mephisto
