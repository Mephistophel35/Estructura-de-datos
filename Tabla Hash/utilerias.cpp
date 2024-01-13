#include "utilerias.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::numeric_limits;

// Función para capturar un número real de doble precisión desde la consola
long double CapturarRealDoble(const char solicitud[])
{
    long double numero;
    do
    {
        gotoxy(1,1);
        cout << "                                                                                                ";
        gotoxy(1,1);
        cout << solicitud;  // Mostrar solicitud al usuario
        CambiaCursor(ENCENDIDO);
        cin >> numero;  // Capturar el número desde la consola

        if (cin.bad())  // Verificar si hubo una pérdida de datos en el flujo de entrada
        {
            throw "  P\202rdida de datos en el flujo.";  // Lanzar una excepción indicando la pérdida de datos
        }

        if (cin.fail())  // Verificar si el dato introducido no es un número
        {
            cout << "  Error: El dato introducido no es un n\243mero.                                                     " << endl << endl;  // Mostrar mensaje de error
            cin.clear();  // Limpiar los indicadores de error del flujo de entrada
            cin.ignore(numeric_limits<int>::max(), '\n');  // Ignorar el resto de la línea inválida
            continue;  // Volver al inicio del bucle y solicitar nuevamente el número
        }

        // Verificar si hay caracteres no numéricos en el búfer
        string remainingInput;
        getline(cin, remainingInput);  // Leer el resto de la línea introducida

        bool containsNonNumeric = false;
        for (char c : remainingInput)
        {
            if (!isdigit(c) && c != '-' && c != '.' && c != 'e' && c != 'E')
            {
                containsNonNumeric = true;
                break;
            }
        }

        if (containsNonNumeric)  // Si hay caracteres no numéricos en el búfer, mostrar mensaje de error
        {
            cout << "  Error: El dato introducido no es un n\243mero.                                                      " << endl << endl;
            continue;  // Volver al inicio del bucle y solicitar nuevamente el número
        }

        break;  // Salir del bucle si el número es válido

    }
    while (true);

    return numero;  // Devolver el número capturado
}

// Función para capturar un número entero desde la consola
int CapturaEntero(const char solicitud[])
{

    int numero;
    long double aux;

    do
    {
        gotoxy(1,1);
        cout << "                                                                                                " ;
        gotoxy(1,1);

        aux = CapturarRealDoble(solicitud);  // Capturar un número real de doble precisión
        numero = static_cast<int>(aux);  // Convertir el número capturado a entero

        if (numero != aux)  // Verificar si el número no es exactamente un entero
        {
            cout << "  Error: Debe ser un n\243mero entero.                                                        " << endl << endl;  // Mostrar mensaje de error
        }

    }
    while (numero != aux);    // Repetir el bucle mientras el número no sea exactamente un entero

    return numero;  // Devolver el número entero capturado
}
// Función para capturar un número entero desde la consola
int CapturaUnsignedInt(const char solicitud[])
{

    int numero;
    long double aux;

    do
    {
        gotoxy(1,1);
        cout << "                                                                                                " ;
        gotoxy(1,1);
        aux = CapturarRealDoble(solicitud);  // Capturar un número real de doble precisión
        numero = static_cast<int>(aux);  // Convertir el número capturado a entero

        if (numero != aux)  // Verificar si el número no es exactamente un entero
        {
            cout << "  Error: Debe ser un n\243mero entero.                                            " << endl << endl;  // Mostrar mensaje de error
        }
        if (numero < 0) // Verificar si el número tiene algun signo.
        {

            cout << "  Error: El valor no puede ser negativo.                                                 " << endl << endl; // Mostrar mensaje de error
        }

    }
    while (numero != aux || numero < 0);    // Repetir el bucle mientras el número no sea exactamente un entero

    gotoxy(1,2);
    cout << "                                                                                                " ;
    return numero;  // Devolver el número entero capturado
}

// Función para posicionar el cursor en una posición específica de la consola
void gotoxy(unsigned short x, unsigned short y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // Obtener el identificador del flujo de salida
    COORD coord = { static_cast<SHORT>(x - 1), static_cast<SHORT>(y - 1) };  // Crear una estructura COORD con las coordenadas
    SetConsoleCursorPosition(handle, coord);  // Establecer la posición del cursor en la consola
}

// Función para cambiar el estado y modo del cursor en la consola
void CambiaCursor(estadoCursor estado, modoCursor modo)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);  // Obtener el identificador del flujo de salida
    CONSOLE_CURSOR_INFO ConCurInf;

    ConCurInf.dwSize = modo;  // Establecer el tamaño del cursor
    ConCurInf.bVisible = estado;  // Establecer la visibilidad del cursor

    SetConsoleCursorInfo(hOut, &ConCurInf);  // Establecer la información del cursor en la consola
}

// Función para borrar varias líneas en la consola
void borrador()
{
    for(int i = 0; i < 50; ++i)
    {
        std::cout <<"                                                                                                             " << std::endl;  // Imprimir espacios en blanco para borrar una línea
    }
}

// Funcion que espera unos segundos antes de borrar una línea en la consola.
void borradorTemp()
{
    Sleep(2500);
    std::cout <<"                                                                                                                 " << std::endl;  // Imprimir espacios en blanco para borrar una línea

}

// Función para cambiar el color del texto en la consola
void color(int X)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), X);  // Establecer el atributo de color del texto en la consola
}
