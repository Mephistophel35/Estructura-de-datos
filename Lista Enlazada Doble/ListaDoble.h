#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#include <iostream>
#include <exception>

/** \class ListaDoble
 *
 * \tparam T tipo de valores que manejará la lista.
 *
 */
template <typename T>
class ListaDoble{

public:

    /** \class ListaVacia
     *  Excepción lanzada cuando la lista esté vacia.
     */
    class ListaVacia : public std::exception{
    public:
        virtual const char * what() const throw();
    };

    /** \class IndiceInvalido
     *  Excepción lanzada cuando un índice usado es invalido.
     */
    class IndiceInvalido : public std::exception{
    public:
        virtual const char * what() const throw();
    };

    /** \brief Constructor por default
     * Crea una lista vacia.
     */
    explicit ListaDoble();

    /** \brief Constructor de copias
     *
     * \param Lista Doble para copiarla.
     *
     */
    ListaDoble(const ListaDoble<T> & LD);

    /** \brief Sobrecarga del operador "=".
     *
     * \param Lista Doble para copiar
     * \return Instancia de la clase copiada.
     *
     */
    ListaDoble & operator=(const ListaDoble<T> &LD);

    /** \brief Destructor.
     *  Libera espacio en memoria.
     */
    ~ListaDoble();
//-----------------------------------------------
    /** \brief Agregar al principio de la lista.
     *
     * \param Valor que queremos agregar principio de la lista.
     *
     */
    void AgregarPrincipio(const T &v);

    /** \brief Agregar al final de la lista.
     *
     * \param Valor que queremos agregar al final de la lista.
     *
     */
    void AgregarFinal(const T &v);

    /** \brief Agregar en una posición específica
     *
     * \param Valor que quieremos meter a la lista.
     * \param indice de la posición que queremos que el valor pasado como parámetro esté.
     * \exception ListaDoble::IndiceInvalido cuando el índice no corresponda con la lista.
     */
    void AgregarEnPos(const T &v, int ind);
//-----------------------------------------------
    /** \brief Eliminar al principio de la lista.
     * Elimina el primer elemento que tenga la lista.
     * \exception ListaDoble::ListaVacia cuando la lista esté vacía.
     */
    void EliminarPrincipio();

    /** \brief Eliminar al final de la lista.
     * Elimina el ultimo elemento que tenga la lista.
     * \exception ListaDoble::ListaVacia cuando la lista esté vacia.
     */
    void EliminarFinal();

    /** \brief Eliminar elemento de una posición específica.
     *
     * \param Indice de la posición del valor que quermos eliminar.
     *
     * \exception ListaDoble::ListaVacia cuando la lista esté vacia.
     * \exception ListaDoble::IndiceInvalido cuando el índice no corresponda con la lista,
     */
    void EliminarEnPos(int ind);
//-----------------------------------------------
    /** \brief Buscar (Metodo constante ya que modificamos nada de la instancia).
     *
     * Busca un valor en la lista.
     * \param Valor que querémos buscar.
     * \exception ListaDoble::ListaVacia cuando la lista esté vacia.
     */
    bool Buscar(const T &v) const;

    /** \brief Posición del valor (Metodo constante ya que modificamos nada de la instancia).
     *
     * Busca la posición del un valor en la lista.
     * \param Valor el cual queremos saber su posición (índice).
     *
     */
    int PosicionDelValor(const T &v) const;
//-----------------------------------------------
    /** \brief Lista vacia (Metodo constante ya que modificamos nada de la instancia).
     * Nos dice si la lista está vacia.
     */
    bool listaVacia() const;
//-----------------------------------------------
    /** \brief Primer valor (Metodo constante ya que modificamos nada de la instancia).
     *
     * \return Regresa el valor que se encuentre al principio de la lista.
     * \exception ListaDoble::ListaVacia cuando la lista esté vacia.
     */
    const T &PrimerValor() const;

    /** \brief Ultimo valor (Metodo constante ya que modificamos nada de la instancia).
     *
     * \return Regresa el valor que se encuentre al final de la lista.
     * \exception ListaDoble::ListaVacia cuando la lista esté vacia.
     */
    const T &UltimoValor() const;

    /** \brief Valor en posición. (Metodo constante ya que modificamos nada de la instancia).
     *
     * \param Indice del valor que queremos saber.
     * \return Regresa el valor que se encuentre en el índice pasado como parámetro.
     * \exception ListaDoble::ListaVacia cuando la lista esté vacia.
     * \exception ListaDoble::IndiceInvalido cuando el índice no corresponda con la lista.
     */
    const T &ValorEnPos(int ind) const;
//-----------------------------------------------
    /** \brief Modificar valor.
     *
     * \param Indice del valor.
     * \param Valor nuevo que cambiaremos por el que esté en el índice pasado como parámetro.
     * \exception ListaDoble::IndiceInvalido cuando el índice no corresponda con la lista.
     */
    void ModificarValor(int ind, const T &v);
//-----------------------------------------------
    /** \brief Tamaño (Metodo constante ya que modificamos nada de la instancia).
     *
     * \return Nos regresa el tamaño de la lista como un entero.
     *
     */
    int Tamanio() const;
//-----------------------------------------------
    /** \brief Vaciar lista.
     * Toma la lista y quita todos los elementos que tenga.
     */
    void VaciarLista();
//-----------------------------------------------
    /** \brief Imprime ascendente. (Metodo constante ya que modificamos nada de la instancia).
     * Imprime la lista partiendo desde el primer elemento hasta el último,
     */
    void ImprimirAscendente() const;

     /** \brief Imprime descendente. (Metodo constante ya que modificamos nada de la instancia).
     * Imprime la lista partiendo desde el ultimo elemento hasta el primero,
     */
    void ImprimirDescendente() const;
//-----------------------------------------------
    /** \brief Sobrecarga del operador "[]" LECTURA. (Metodo constante ya que modificamos nada de la instancia).
     *
     * \param Indice de la posición del elemento en la lista.
     * \return Elemento del índice que le pasamos por parámetro.
     *
     */
    const T &operator[](const int ind) const;

    /** \brief Sobrecarga del operador "[]" ESCRITURA.
     *
     * \param Indice de la posición del elemento en la lista.
     * \return Elemento del índice que le pasamos por parámetro.
     *
     */
    T& operator[](const int ind);
//-----------------------------------------------
    /** \brief Eliminar toda ocurrencia.
     * Tomará el valor que le pasemos y mientras ese valor exista en la lista lo eliminará.
     * hasta que ya no esté ese valor en toda la lista.
     * \param valor el cual queremos que se elimine en toda la lista.
     * \exception ListaDoble::ListaVacia cuando la lista se encuentre vacía.
     */
    void EliminarTodaOcurrencia(const T &v);

    /** \brief Eliminar por condición.
     *
     * \param le pasamos una condición referencia a función que va a evaluar los valores.
     * \exception ListaDoble::ListaVacia cuando la lista se encuentre vacía.
     *
     */
    void EliminarPorCondicion(bool (*condicion) (T));

    /** \brief Eliminar Repeticiones.
     *
     */
    void EliminarRepeticiones();
//-----------------------------------------------
    /** \brief Ordenar.
     * Tomará la lista y la ordenará dependiendo el valor, se ordenará
     * del más chikito al más grande.
     */
    void Ordenar();
//-----------------------------------------------
    /** \brief Cambiar lista.
     *
     * \param Lista Doble.
     * Tomará la lista de parámetro del método y la otra de la instancia y las cambiará.
     * como hacerle un swap.
     */
    void Cambiar(ListaDoble<T> &L);
//-----------------------------------------------
    /** \brief Transferir
     *
     * \param Lista Doble.
     * \param Indice que marque el inicio.
     * \param Indice que marque el final.
     * \exception ListaDoble::IndiceInvalido cuando el indice no coincida con la lista.
     * Tomará la lista del parámetro, agarrará todos los elementos que estén en el índice
     * del inicio hasta el final y los irá agregando a la lista de la instancia.
     */
    void Transferir(ListaDoble<T> &L, int ini, int fin);

    /** \brief Transferir
     *
     * \param Lista Doble
     * \param Indice que marque el inicio.
     *  Tomará la lista del parámetro y agarrará todos los elementos que empiecen en el índice
     *  de "ini" en adelante y los agregará a la lista de las instancia.
     */
    void Transferir(ListaDoble<T> &L, int ini);

    /** \brief Transferir
     *
     * \param Lista Doble.
     * Tomará TODOS los elementos de la lista parámetro y los agregará a la lista de la
     * instancia.
     */
    void Transferir(ListaDoble<T> &L);
private:

    int tam = 0;                                    /**< Indica el numero de elementos que tenga la lista actualmente */

    struct Elemento{

        Elemento(T d, Elemento * sig = nullptr, Elemento * ant = nullptr) : dato(d), siguiente(sig), anterior(ant){};

        T dato;
        Elemento * siguiente;
        Elemento * anterior;

    };

    Elemento * primero;                             /**< Puntero al primer elemento de la lista */
    Elemento * ultimo;                              /**< Puntero al último elemento de la lista */

    /** \brief Agregar ordenado
     *
     * \param Valor que queramos agregar a la lista.
     * Tomará los valores que le vayamos pasando y los colocará de manera ordenada.
     *
     */
    void AgregarOrdenado(const T &v);
};


#include "ListaDoble.tpp"


#endif // LISTADOBLE_H_INCLUDED
















// ~Mephisto
