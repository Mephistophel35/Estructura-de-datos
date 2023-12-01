#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#include <iostream>
#include <exception>

/** \class ListaDoble
 *
 * \tparam T tipo de valores que manejar� la lista.
 *
 */
template <typename T>
class ListaDoble{

public:

    /** \class ListaVacia
     *  Excepci�n lanzada cuando la lista est� vacia.
     */
    class ListaVacia : public std::exception{
    public:
        virtual const char * what() const throw();
    };

    /** \class IndiceInvalido
     *  Excepci�n lanzada cuando un �ndice usado es invalido.
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

    /** \brief Agregar en una posici�n espec�fica
     *
     * \param Valor que quieremos meter a la lista.
     * \param indice de la posici�n que queremos que el valor pasado como par�metro est�.
     * \exception ListaDoble::IndiceInvalido cuando el �ndice no corresponda con la lista.
     */
    void AgregarEnPos(const T &v, int ind);
//-----------------------------------------------
    /** \brief Eliminar al principio de la lista.
     * Elimina el primer elemento que tenga la lista.
     * \exception ListaDoble::ListaVacia cuando la lista est� vac�a.
     */
    void EliminarPrincipio();

    /** \brief Eliminar al final de la lista.
     * Elimina el ultimo elemento que tenga la lista.
     * \exception ListaDoble::ListaVacia cuando la lista est� vacia.
     */
    void EliminarFinal();

    /** \brief Eliminar elemento de una posici�n espec�fica.
     *
     * \param Indice de la posici�n del valor que quermos eliminar.
     *
     * \exception ListaDoble::ListaVacia cuando la lista est� vacia.
     * \exception ListaDoble::IndiceInvalido cuando el �ndice no corresponda con la lista,
     */
    void EliminarEnPos(int ind);
//-----------------------------------------------
    /** \brief Buscar (Metodo constante ya que modificamos nada de la instancia).
     *
     * Busca un valor en la lista.
     * \param Valor que quer�mos buscar.
     * \exception ListaDoble::ListaVacia cuando la lista est� vacia.
     */
    bool Buscar(const T &v) const;

    /** \brief Posici�n del valor (Metodo constante ya que modificamos nada de la instancia).
     *
     * Busca la posici�n del un valor en la lista.
     * \param Valor el cual queremos saber su posici�n (�ndice).
     *
     */
    int PosicionDelValor(const T &v) const;
//-----------------------------------------------
    /** \brief Lista vacia (Metodo constante ya que modificamos nada de la instancia).
     * Nos dice si la lista est� vacia.
     */
    bool listaVacia() const;
//-----------------------------------------------
    /** \brief Primer valor (Metodo constante ya que modificamos nada de la instancia).
     *
     * \return Regresa el valor que se encuentre al principio de la lista.
     * \exception ListaDoble::ListaVacia cuando la lista est� vacia.
     */
    const T &PrimerValor() const;

    /** \brief Ultimo valor (Metodo constante ya que modificamos nada de la instancia).
     *
     * \return Regresa el valor que se encuentre al final de la lista.
     * \exception ListaDoble::ListaVacia cuando la lista est� vacia.
     */
    const T &UltimoValor() const;

    /** \brief Valor en posici�n. (Metodo constante ya que modificamos nada de la instancia).
     *
     * \param Indice del valor que queremos saber.
     * \return Regresa el valor que se encuentre en el �ndice pasado como par�metro.
     * \exception ListaDoble::ListaVacia cuando la lista est� vacia.
     * \exception ListaDoble::IndiceInvalido cuando el �ndice no corresponda con la lista.
     */
    const T &ValorEnPos(int ind) const;
//-----------------------------------------------
    /** \brief Modificar valor.
     *
     * \param Indice del valor.
     * \param Valor nuevo que cambiaremos por el que est� en el �ndice pasado como par�metro.
     * \exception ListaDoble::IndiceInvalido cuando el �ndice no corresponda con la lista.
     */
    void ModificarValor(int ind, const T &v);
//-----------------------------------------------
    /** \brief Tama�o (Metodo constante ya que modificamos nada de la instancia).
     *
     * \return Nos regresa el tama�o de la lista como un entero.
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
     * Imprime la lista partiendo desde el primer elemento hasta el �ltimo,
     */
    void ImprimirAscendente() const;

     /** \brief Imprime descendente. (Metodo constante ya que modificamos nada de la instancia).
     * Imprime la lista partiendo desde el ultimo elemento hasta el primero,
     */
    void ImprimirDescendente() const;
//-----------------------------------------------
    /** \brief Sobrecarga del operador "[]" LECTURA. (Metodo constante ya que modificamos nada de la instancia).
     *
     * \param Indice de la posici�n del elemento en la lista.
     * \return Elemento del �ndice que le pasamos por par�metro.
     *
     */
    const T &operator[](const int ind) const;

    /** \brief Sobrecarga del operador "[]" ESCRITURA.
     *
     * \param Indice de la posici�n del elemento en la lista.
     * \return Elemento del �ndice que le pasamos por par�metro.
     *
     */
    T& operator[](const int ind);
//-----------------------------------------------
    /** \brief Eliminar toda ocurrencia.
     * Tomar� el valor que le pasemos y mientras ese valor exista en la lista lo eliminar�.
     * hasta que ya no est� ese valor en toda la lista.
     * \param valor el cual queremos que se elimine en toda la lista.
     * \exception ListaDoble::ListaVacia cuando la lista se encuentre vac�a.
     */
    void EliminarTodaOcurrencia(const T &v);

    /** \brief Eliminar por condici�n.
     *
     * \param le pasamos una condici�n referencia a funci�n que va a evaluar los valores.
     * \exception ListaDoble::ListaVacia cuando la lista se encuentre vac�a.
     *
     */
    void EliminarPorCondicion(bool (*condicion) (T));

    /** \brief Eliminar Repeticiones.
     *
     */
    void EliminarRepeticiones();
//-----------------------------------------------
    /** \brief Ordenar.
     * Tomar� la lista y la ordenar� dependiendo el valor, se ordenar�
     * del m�s chikito al m�s grande.
     */
    void Ordenar();
//-----------------------------------------------
    /** \brief Cambiar lista.
     *
     * \param Lista Doble.
     * Tomar� la lista de par�metro del m�todo y la otra de la instancia y las cambiar�.
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
     * Tomar� la lista del par�metro, agarrar� todos los elementos que est�n en el �ndice
     * del inicio hasta el final y los ir� agregando a la lista de la instancia.
     */
    void Transferir(ListaDoble<T> &L, int ini, int fin);

    /** \brief Transferir
     *
     * \param Lista Doble
     * \param Indice que marque el inicio.
     *  Tomar� la lista del par�metro y agarrar� todos los elementos que empiecen en el �ndice
     *  de "ini" en adelante y los agregar� a la lista de las instancia.
     */
    void Transferir(ListaDoble<T> &L, int ini);

    /** \brief Transferir
     *
     * \param Lista Doble.
     * Tomar� TODOS los elementos de la lista par�metro y los agregar� a la lista de la
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
    Elemento * ultimo;                              /**< Puntero al �ltimo elemento de la lista */

    /** \brief Agregar ordenado
     *
     * \param Valor que queramos agregar a la lista.
     * Tomar� los valores que le vayamos pasando y los colocar� de manera ordenada.
     *
     */
    void AgregarOrdenado(const T &v);
};


#include "ListaDoble.tpp"


#endif // LISTADOBLE_H_INCLUDED
















// ~Mephisto
