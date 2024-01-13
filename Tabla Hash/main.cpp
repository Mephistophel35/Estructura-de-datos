/*
Nombre: Tabla Hash Direccionamiento Cerrado
Autores: - Jehu Jonathan Ramírez Ramírez.
         - Gael Balderrama Dominguez.
         - Christian Alexis Flores Alvarez.
Agradecimientos: - Irene Rodríguez Castillo. Impartidora del curso de Estructura de Datos en la Universidad de Sonora.
Fecha: 31/05/2023
Descripción: Programa que organiza y manupula datos en Tablas Hash con resolución de colisiones en Direccionamiento Cerrado.
*/
#include <iostream>
#include "TablaHashDC.h"
#include "FuncionesDeGestion.h"
#include "utilerias.h"

using namespace std;

int main()
{

    int opcion;
    TablaHashDC tablaOriginal(5);
    TablaHashDC tablaCopia(5);

    enum opciones {AGREGAR_ELEMENTOS=1, ELIMINAR_ELEMENTOS, BUSCAR_ELEMENTO, IMPRIMIR_TABLA, IMPRIMIR_ESTADISTICAS, GUARDAR_COPIA, RESTAURAR_COPIA, VACIAR_TABLA, ELIMINAR_COPIA, SALIR};


    do
    {
        opcion = MenuDeInicio();
        switch (opcion)
        {

        case AGREGAR_ELEMENTOS:
            AgregarElementos(tablaOriginal);
            break;

        case ELIMINAR_ELEMENTOS:
            EliminarElementos(tablaOriginal);
            break;

        case BUSCAR_ELEMENTO:
            BuscarElementos(tablaOriginal);
            break;

        case IMPRIMIR_TABLA:
            ImprimirTabla(tablaOriginal);
            break;

        case IMPRIMIR_ESTADISTICAS:
            ImprimirEstadisticas(tablaOriginal);
            break;

        case GUARDAR_COPIA:
            CopiarTabla(tablaOriginal, tablaCopia);
            break;

        case RESTAURAR_COPIA:
            RestaurarUltimaCopia(tablaOriginal, tablaCopia);
            break;

        case VACIAR_TABLA:

            if (VaciarTabla(tablaOriginal))
            {
                gotoxy(1,14);
                cout << "  La tabla se ha vaciado correctamente.                         " << endl;
            }
            else
            {
                gotoxy(1,14);
                cout << "  La tabla ya est\240 vac\241a.                            " << endl;
            }
            break;

        case ELIMINAR_COPIA:
            if (VaciarTabla(tablaCopia))
            {
                gotoxy(1,14);
                cout << "  La copia guardada se ha eliminado.                           " << endl;
            }
            else
            {
                gotoxy(1,14);
                cout << "  No hay ninguna copia guardada.                         " << endl;
            }
            break;

        case SALIR:
            color(0);
            gotoxy(1,14);
            borrador();
            tablaOriginal.VaciarTabla();
            tablaCopia.VaciarTabla();
            color(7);
            return 0;
            break;


        }
    }
    while(opcion != SALIR);

    cout <<endl;
}


