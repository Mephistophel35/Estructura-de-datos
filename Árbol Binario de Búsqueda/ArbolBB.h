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

    /** \brief Podar árbol/subarbol a partir de un nodo dado.
     *
     * \param Valor de tipo T.
     *
     */
    void podarSubArbol(T v);

    /** \brief Método que verifica si el árbol está vacío, constante.
     *
     * \return true/false si el árbol está vacío.
     *
     */
    bool arbolVacio() const;

    /** \brief Método que vacía el árbol.
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

    unsigned int numNodos = 0;              /**< Número de nodos */

    struct Nodo{

        /** \brief Constructor por default
         *
         */
        Nodo(T d, Nodo * HI = nullptr, Nodo * HD = nullptr) : nodo(d), hijoIzq(HI), hijoDer(HD){}

        T nodo;                             /**< nodo de tipo T */
        Nodo * hijoIzq = nullptr;           /**< Puntero de tipo nodo al hijo izquierdo */
        Nodo * hijoDer = nullptr;           /**< Puntero de tipo nodo al hijo derecho */

        /** \brief Método que checa si un nodo es una hoja, constante.
         *
         * \return true/false si el nodo es una hoja.
         *
         */
        bool esHoja() const;

        /** \brief Método que checa si un nodo tiene solo hijo izquierdo, constante.
         *
         * \return true/false si el nodo tiene solo hijo izquierdo.
         *
         */
        bool soloHI() const;

        /** \brief Método que checa si un nodo tiene solo hijo derecho, constante.
         *
         * \return true/false si el nodo tiene solo hijo derecho.
         *
         */
        bool soloHD() const;

        /** \brief Método que checa si un nodo tiene ambos hijos, constante.
         *
         * \return true/false si el nodo tiene ambos hijos.
         *
         */
        bool tieneHIHD() const;

        /** \brief Método que checa si un nodo tiene hijo izquierdo, constante.
         *
         * \return true/false si el nodo tiene hijo izquierdo.
         *
         */
        bool tieneHI() const;

        /** \brief Método que checa si un nodo tiene hijo derecho, constante.
         *
         * \return true/false si el nodo tiene hijo derecho.
         *
         */
        bool tieneHD() const;
    } * raiz;                               /**< Puntero de tipo nodo perteneciente a la raíz */

    /** \brief Método agregar nodo
     *
     * \param Puntero de tipo Nodo por referencia
     * \param  Valor del nodo tipo T
     *
     */
    void agregarPriv(Nodo * &r, T v);

    /** \brief Método Eliminar nodo
     *
     * \param Puntero de tipo Nodo por referencia
     * \param Valor del nodo tipo T
     * \return true/false si el nodo dado fue eliminado.
     *
     */
    bool eliminarPriv(Nodo * &r, T v);

    /** \brief Método Buscar nodo
     *
     * \param Puntero de tipo Nodo por referencia
     * \param Valor del nodo tipo T
     * \return true/false si el nodo dado fue encontrado.
     *
     */
    bool buscarPriv(Nodo * &r, T v);

    /** \brief Método podar.
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

    /** \brief Obtener menor de los más grandes, constante
     *
     * \param Puntero de tipo nodo por referencia.
     * \return Puntero tipo nodo por referencia
     */
    Nodo *& obtenerMenor(Nodo * &r) const;

    /** \brief Obtener mayor de los más pequeños, constante
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
