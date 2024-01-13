#ifndef ARBOLBB_H_INCLUDED
#define ARBOLBB_H_INCLUDED

#include <iostream>

template <typename T>
class ArbolBB{

public:

    /** \brief Constructor por default.
     */
    ArbolBB();

    /** \brief Constructor de copias.
     *
     * \param Arbol de tipo T constante por referencia.
     *
     */
    ArbolBB(const ArbolBB<T> &ABB);

    /** \brief Sobrecarga del operador igual.
     *
     * \param Arbol de tipo T constante por referencia.
     * \return copia del arbol.
     *
     */
    ArbolBB<T> & operator=(const ArbolBB<T> &ABB);

    /** \brief Destructor.
     *
     */
    ~ArbolBB();

    /** \brief Agregar nodo al arbol.
     *
     * \param Valor de tipo T.
     *
     */
    void agregar(T v);

    /** \brief Eliminar nodo del arbol.
     *
     * \param Valor de tipo T.
     *
     */
    void eliminar(T v);

    /** \brief Buscar nodo.
     *
     * \param Valor de tipo T.
     * \return true/false si el nodo del valor dado se encuentra en el arbol.
     *
     */
    bool buscar(T v);

    /** \brief Numero de nodos que el arbol posee, constante.
     *
     * \return valor sin signo entero.
     *
     */
    unsigned int tamanio() const;

    /** \brief Podar �rbol/subarbol a partir de un nodo dado.
     *
     * \param Valor de tipo T.
     *
     */
    void podarSubArbol(T v);

    /** \brief M�todo que verifica si el �rbol est� vac�o, constante.
     *
     * \return true/false si el �rbol est� vac�o.
     *
     */
    bool arbolVacio() const;

    /** \brief M�todo que vac�a el �rbol.
     *
     */
    void vaciarArbol();

    /** \brief Imprimir de manera ascendente, constante.
     *
     */
    void imprimirAscendente() const;

    /** \brief Imprimir de manera descendente, constante.
     *
     */
    void imprimirDescendente() const;

    /** \brief Imprimir nodos por niveles, constante.
     *
     */
    void imprimirPorNiveles() const;

private:

    unsigned int numNodos = 0;              /**< N�mero de nodos */

    struct Nodo{

        /** \brief Constructor por default
         *
         */
        Nodo(T d, Nodo * HI = nullptr, Nodo * HD = nullptr) : nodo(d), hijoIzq(HI), hijoDer(HD){}

        T nodo;                             /**< nodo de tipo T */
        Nodo * hijoIzq = nullptr;           /**< Puntero de tipo nodo al hijo izquierdo */
        Nodo * hijoDer = nullptr;           /**< Puntero de tipo nodo al hijo derecho */

        /** \brief M�todo que checa si un nodo es una hoja, constante.
         *
         * \return true/false si el nodo es una hoja.
         *
         */
        bool esHoja() const;

        /** \brief M�todo que checa si un nodo tiene solo hijo izquierdo, constante.
         *
         * \return true/false si el nodo tiene solo hijo izquierdo.
         *
         */
        bool soloHI() const;

        /** \brief M�todo que checa si un nodo tiene solo hijo derecho, constante.
         *
         * \return true/false si el nodo tiene solo hijo derecho.
         *
         */
        bool soloHD() const;

        /** \brief M�todo que checa si un nodo tiene ambos hijos, constante.
         *
         * \return true/false si el nodo tiene ambos hijos.
         *
         */
        bool tieneHIHD() const;

        /** \brief M�todo que checa si un nodo tiene hijo izquierdo, constante.
         *
         * \return true/false si el nodo tiene hijo izquierdo.
         *
         */
        bool tieneHI() const;

        /** \brief M�todo que checa si un nodo tiene hijo derecho, constante.
         *
         * \return true/false si el nodo tiene hijo derecho.
         *
         */
        bool tieneHD() const;
    } * raiz;                               /**< Puntero de tipo nodo perteneciente a la ra�z */

    /** \brief M�todo agregar nodo
     *
     * \param Puntero de tipo Nodo por referencia
     * \param  Valor del nodo tipo T
     *
     */
    void agregarPriv(Nodo * &r, T v);

    /** \brief M�todo Eliminar nodo
     *
     * \param Puntero de tipo Nodo por referencia
     * \param Valor del nodo tipo T
     * \return true/false si el nodo dado fue eliminado.
     *
     */
    bool eliminarPriv(Nodo * &r, T v);

    /** \brief M�todo Buscar nodo
     *
     * \param Puntero de tipo Nodo por referencia
     * \param Valor del nodo tipo T
     * \return true/false si el nodo dado fue encontrado.
     *
     */
    bool buscarPriv(Nodo * &r, T v);

    /** \brief M�todo podar.
     *
     * \param Puntero de tipo Nodo por referencia.
     *
     */
    void podarPriv(Nodo * &r);

    /** \brief Imprimir en Inorden, constante.
     *
     * \param Puntero de tipo nodo por referencia.
     *
     */
    void imprimirInorden(Nodo * r) const;

    /** \brief Imprimir en Inorden Inverso, constante.
     *
     * \param Puntero de tipo nodo por referencia.
     *
     */
    void imprimirInordenInv(Nodo * r) const;

    /** \brief Imprimir por nivel, constante.
     *
     * \param Puntero de tipo nodo por referencia.
     *
     */
    void imprimirPorNivel(Nodo * r) const;

    /** \brief Copiar en Preorden
     *
     * \param Puntero de tipo nodo por referencia.
     *
     */
    void copiarPreorden(Nodo * raiz);

    /** \brief Obtener menor de los m�s grandes, constante
     *
     * \param Puntero de tipo nodo por referencia.
     * \return Puntero tipo nodo por referencia
     */
    Nodo *& obtenerMenor(Nodo * &r) const;

    /** \brief Obtener mayor de los m�s peque�os, constante
     *
     * \param Puntero de tipo nodo por referencia.
     * \return Puntero tipo nodo por referencia
     */
    Nodo *& obtenerMayor(Nodo * &r) const;

    /** \brief Encontrar nodo
     *
     * \param Puntero de tipo nodo por referencia
     * \param valor T
     * \return Puntero tipo nodo por referencia
     *
     */

    Nodo *& encontrar(Nodo * &r, T v);

};


#include "ArbolBB.tpp"



#endif // ARBOLBB_H_INCLUDED

















// ~Mephisto
