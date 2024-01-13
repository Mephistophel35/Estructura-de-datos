#ifndef UTILERIAS_H_INCLUDED
#define UTILERIAS_H_INCLUDED

#include <iostream>
#include <windows.h>
#include <limits>

#define FLECHA_ARRIBA 72
#define FLECHA_ABAJO 80
#define ENTER 13

enum estadoCursor {APAGADO, ENCENDIDO};
enum modoCursor {MINI = 5, NORMAL = 20, SOLIDO = 80};


/**
 * \brief Captura un número real de doble precisión desde la entrada estándar.
 * \param solicitud El mensaje que se muestra para solicitar el número.
 * \return El número real de doble precisión capturado.
 * \throw std::string si se produce una pérdida de datos en el flujo de entrada.
 */
long double CapturarRealDoble(const char solicitud[]);

/**
 * \brief Captura un número entero desde la entrada estándar.
 * \param solicitud El mensaje que se muestra para solicitar el número.
 * \return El número entero capturado.
 */
int CapturaEntero(const char solicitud[]);

/**
 * \brief Captura un entero sin signo desde la entrada estándar.
 * \param solicitud El mensaje que se muestra para solicitar el número.
 * \return El número entero sin signo capturado.
 */
int CapturaUnsignedInt(const char solicitud[]);

/**
 * \brief Mueve el cursor de la consola a la posición especificada.
 * \param x La coordenada x del cursor.
 * \param y La coordenada y del cursor.
 */
void gotoxy(unsigned short x, unsigned short y);

/**
 * \brief Cambia el estado y modo del cursor de la consola.
 * \param estado El estado del cursor (APAGADO o ENCENDIDO).
 * \param modo El modo del cursor (MINI, NORMAL o SOLIDO).
 */
void CambiaCursor(estadoCursor estado, modoCursor modo = NORMAL);

/**
 * \brief Borra el contenido de la consola sobreescribiendo espacios.
 */
void borrador();

/**
 * \brief Espera 2.5 segundos para borrar una línea de la consola sobreescribiendo espacios.
 */
void borradorTemp();

/**
 * \brief Cambia el color del texto en la consola.
 * \param X El código de color a establecer.
 */
void color(int X);

#endif // UTILERIAS_H_INCLUDED
