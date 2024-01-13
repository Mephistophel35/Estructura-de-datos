#ifndef TABLAHASHDC_H_INCLUDED
#define TABLAHASHDC_H_INCLUDED

#include <iostream>
#include <string>
#include "ListaEnlazadaSimple.h"
#include "utilerias.h"

/**
 * \class TablaHashDC
 * \brief Clase que representa una tabla hash con resolución de colisiones mediante direccionamiento cerrado.
 *
 * La clase TablaHashDC implementa una tabla hash utilizando el método de direccionamiento cerrado.
 * Cuando se produce una colisión, los elementos con el mismo índice se acomodan en una lista enlazada.
 * Esto permite almacenar múltiples elementos en la misma posición de la tabla, evitando colisiones y
 * garantizando un acceso eficiente a los elementos.
 *
 * La clase TablaHashDC permite insertar y eliminar elementos, buscar elementos por su clave, obtener el número
 * de elementos almacenados y más. Además, proporcionaoperaciones de redimensionamiento de la tabla para mantener
 * un factor de carga adecuado y un acceso eficiente a los elementos.
 *
 */


/**
 * \struct Elemento
 * \brief Estructura que representa un elemento de la tabla hash.
 */
struct Elemento
{
    std::string Nombre; /**< Nombre del elemento */
    int Id; /**< Identificador del elemento */
};

/**
 * \class TablaHashDC
 * \brief Clase que representa una tabla hash con resolución de colisiones mediante direccionamiento abierto y doble dispersión.
 */
class TablaHashDC
{
public:
    /**
     * \brief Constructor de la clase TablaHashDC.
     * \param capacidad La capacidad inicial de la tabla hash.
     */
    TablaHashDC(int capacidad);

    /**
     * \brief Constructor de copia de la clase TablaHashDC.
     * \param otraTabla La tabla hash a copiar.
     */
    TablaHashDC(const TablaHashDC& otraTabla);

    /**
     * \brief Operador de asignación de la clase TablaHashDC.
     * \param otraTabla La tabla hash a asignar.
     * \return Una referencia a la tabla hash actualizada.
     */
    TablaHashDC& operator=(const TablaHashDC& otraTabla);

    /**
     * \brief Destructor de la clase TablaHashDC.
     */
    ~TablaHashDC();

    /**
     * \brief Inserta un elemento en la tabla hash.
     * \param elemento El elemento a insertar.
     */
    void InsertarElemento(const Elemento& elemento);

    /**
     * \brief Elimina un elemento de la tabla hash por su matrícula.
     * \param matricula La matrícula del elemento a eliminar.
     */
    void EliminarElemento(int matricula);

    /**
     * \brief Vacía la tabla hash, eliminando todos los elementos.
     */
    void VaciarTabla();

    /**
     * \brief Imprime los elementos de la tabla hash.
     */
    void ImprimirTabla() const;

    /**
     * \brief Obtiene el nombre de un elemento por su matrícula.
     * \param matricula La matrícula del elemento.
     * \return El nombre del elemento.
     */
    std::string ObtenerNombreElemento(int matricula) const;

    /**
     * \brief Obtiene el número de elementos en la tabla hash.
     * \return El número de elementos.
     */
    int ObtenerNumeroDeElementos() const;

    /**
     * \brief Verifica si la tabla hash está vacía.
     * \return true si la tabla está vacía, false en caso contrario.
     */
    bool EstaVacia() const;

    /**
     * \brief Busca un elemento en la tabla hash por su matrícula.
     * \param matricula La matrícula del elemento a buscar.
     * \return true si el elemento se encuentra en la tabla, false en caso contrario.
     */
    bool Buscar(int matricula) const;

    /**
     * \brief Obtiene la capacidad actual de la tabla hash.
     * \return La capacidad de la tabla hash.
     */
    int ObtenerCapacidad() const;

    /**
     * \brief Obtiene la lista enlazada correspondiente a un índice de la tabla hash.
     * \param indice El índice de la tabla hash.
     * \return Una referencia constante a la lista enlazada.
     */
    const ListaEnlazadaSimple<Elemento>& ObtenerListaEnlazada(int indice) const;

private:
    /**
     * \brief Calcula la función hash para una matrícula.
     * \param matricula La matrícula del elemento.
     * \return El valor hash calculado.
     */
    int FuncionHash(int matricula) const;

    /**
     * \brief Calcula la segunda función hash para una matrícula y una capacidad dada.
     * \param matricula La matrícula del elemento.
     * \param capacidad La capacidad de la tabla hash.
     * \return El valor hash calculado.
     */
    int FuncionHash(int matricula, int capacidad) const;

    /**
     * \brief Redimensiona la tabla hash cuando se alcanza la capacidad máxima.
     */
    void RedimensionarTabla();

    ListaEnlazadaSimple<Elemento>* tabla; /**< Array de listas enlazadas que almacena los elementos de la tabla hash */
    int Capacidad; /**< Capacidad actual de la tabla hash */
    int CapacidadMaxima; /**< Capacidad máxima de la tabla hash */
    int NumeroDeElementos; /**< Número de elementos en la tabla hash */
};

#endif // TABLAHASHDC_H_INCLUDED
