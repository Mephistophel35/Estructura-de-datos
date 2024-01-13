#ifndef FUNCIONESDEGESTION_H_INCLUDED
#define FUNCIONESDEGESTION_H_INCLUDED

#include <iostream>
#include <limits>
#include <conio.h>
#include <windows.h>

#include "TablaHashDC.h"
#include "Utilerias.h"


/**
 * \brief Muestra el menú de inicio y permite seleccionar una opción.
 * \return El número de la opción seleccionada.
 */
int MenuDeInicio();

/**
 * \brief Permite agregar elementos a la tabla hash.
 * \param tabla La tabla hash donde se agregarán los elementos.
 */
void AgregarElementos(TablaHashDC& tabla);

/**
 * \brief Permite eliminar elementos de la tabla hash.
 * \param tabla La tabla hash de la cual se eliminarán los elementos.
 */
void EliminarElementos(TablaHashDC& tabla);

/**
 * \brief Permite buscar elementos en la tabla hash.
 * \param tabla La tabla hash en la cual se buscarán los elementos.
 */
void BuscarElementos(TablaHashDC& tabla);

/**
 * \brief Imprime en pantalla la tabla hash.
 * \param tabla La tabla hash que se imprimirá.
 */
void ImprimirTabla(TablaHashDC& tabla);

/**
 * \brief Imprime en pantalla las estadísticas de la tabla hash.
 * \param tabla La tabla hash de la cual se obtendrán las estadísticas.
 */
void ImprimirEstadisticas(const TablaHashDC& tabla);

/**
 * \brief Copia una tabla hash en otra.
 * \param tablaA La tabla hash que se copiará.
 * \param tablaB La tabla hash donde se realizará la copia.
 */
void CopiarTabla(TablaHashDC& tablaA, TablaHashDC& tablaB);

/**
 * \brief Restaura la última copia de la tabla hash.
 * \param tablaA La tabla hash que se restaurará.
 * \param tablaB La tabla hash desde la cual se restaurará la copia.
 */
void RestaurarUltimaCopia(TablaHashDC& tablaA, TablaHashDC& tablaB);

/**
 * \brief Vacia la tabla hash.
 * \param tabla La tabla hash que se vaciará.
 * \return true si se vació la tabla correctamente, false si la tabla ya estaba vacía.
 */
bool VaciarTabla(TablaHashDC& tabla);

#endif // FUNCIONESDEGESTION_H_INCLUDED
