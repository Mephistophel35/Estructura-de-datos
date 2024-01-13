#include "FuncionesDeGestion.h"

using std::cout; // Permite utilizar el objeto cout de la biblioteca estándar de C++.
using std::endl; // Permite utilizar el objeto endl de la biblioteca estándar de C++.

int MenuDeInicio()
{
    char tecla; // Variable para almacenar la tecla presionada.
    int x = 1; // Variable para almacenar la posición actual en el menú.

    CambiaCursor(APAGADO); // Llama a la función CambiaCursor y apaga el cursor.
    gotoxy(1, 1); // Mueve el cursor a la posición (1, 1) en la consola.

    cout << "  ******TABLA HASH CON DIRECCIONAMIENTO CERRADO******" << endl << endl; // Imprime un encabezado en la consola.

    color(240); // Cambia el color de la fuente a gris claro.
    cout << "  Agregar elementos a la tabla " << endl; // Imprime una opción en el menú.

    color(7); // Restaura el color de la fuente al predeterminado.
    // Imprime las siguientes opciones en el menú:
    cout << "  Eliminar elementos de la tabla " << endl;
    cout << "  Buscar elemento " << endl;
    cout << "  Imprimir tabla " << endl;
    cout << "  Imprimir estad\241sticas " << endl;
    cout << "  Guardar copia de la tabla " << endl;
    cout << "  Restaurar \243ltima copia " << endl;
    cout << "  Vaciar tabla " << endl;
    cout << "  Eliminar copia " << endl;
    cout << "  Salir " << endl;
    x = 1;
    while (true)
    {

        if (kbhit())   // Verifica si se ha presionado una tecla en el teclado
        {
            tecla = getch(); // Obtiene la tecla presionada

            if (tecla == FLECHA_ABAJO)   // Comprueba si la tecla presionada es la flecha hacia abajo
            {
                if (x < 10)
                {
                    x = x + 1; // Incrementa el valor de x si es menor que 10
                }
                else
                {
                    x = 1; // Si x es igual a 10, lo establece en 1
                }
            }

            if (tecla == FLECHA_ARRIBA)   // Comprueba si la tecla presionada es la flecha hacia arriba
            {
                if (x > 1)
                {
                    x = x - 1; // Decrementa el valor de x si es mayor que 1
                }
                else
                {
                    x = 10; // Si x es igual a 1, lo establece en 10
                }
            }

            // Comprueba la posición actual en el menú y muestra las opciones correspondientes resaltadas.
            for (int i = 1; i <= 10; i++)
            {
                gotoxy(1, 2 + i); // Establece la posición del cursor en la pantalla
                if (i == x)
                {
                    color(240); // Establece el color del texto en resaltado si i es igual a x
                }
                else
                {
                    color(7); // Establece el color del texto en blanco si i no es igual a x
                }
                switch (i)
                {
                case 1:
                    cout << "  Agregar elementos a la tabla " << endl;
                    break;
                case 2:
                    cout << "  Eliminar elementos de la tabla " << endl;
                    break;
                case 3:
                    cout << "  Buscar elemento " << endl;
                    break;
                case 4:
                    cout << "  Imprimir tabla " << endl;
                    break;
                case 5:
                    cout << "  Imprimir estad\241sticas " << endl;
                    break;
                case 6:
                    cout << "  Guardar copia de la tabla " << endl;
                    break;
                case 7:
                    cout << "  Restaurar \243ltima copia " << endl;
                    break;
                case 8:
                    cout << "  Vaciar tabla " << endl;
                    break;
                case 9:
                    cout << "  Eliminar copia " << endl;
                    break;
                case 10:
                    cout << "  Salir " << endl;
                    break;
                }
            }

            if (tecla == ENTER)   // Comprueba si la tecla presionada es la tecla "Enter"
            {
                return x; // Devuelve el valor de x
            }
        }
    }

}

void AgregarElementos(TablaHashDC& tabla)
{
    char opcion; // Variable para almacenar la opción del usuario (S/N)
    CambiaCursor(ENCENDIDO, NORMAL); // Activa el cursor y establece su apariencia normal
    do
    {
        gotoxy(1,1);
        borrador();
        std::string nombre; // Variable para almacenar el nombre ingresado por el usuario
        int matricula; // Variable para almacenar la matrícula ingresada por el usuario

        gotoxy(1,2);
        CambiaCursor(ENCENDIDO);
        cout << "  Ingrese el nombre: "; // Solicita al usuario ingresar el nombre
        std::getline(std::cin, nombre); // Lee el nombre ingresado por el usuario
        CambiaCursor(APAGADO);
        gotoxy(1,1);
        borrador();


        matricula = CapturaUnsignedInt("  Ingrese la matr\241cula: "); // Solicita al usuario ingresar la matrícula


        Elemento elemento = {nombre, matricula}; // Crea un objeto de tipo Elemento con el nombre y la matrícula ingresados
        tabla.InsertarElemento(elemento); // Inserta el elemento en la tabla hash

        do
        {
            gotoxy(1,4);
            cout <<"  \250Desea agregar otro elemento? (S/N): "; // Pregunta al usuario si desea agregar otro elemento
            std::string entrada;
            std::getline(std::cin, entrada); // Lee la opción ingresada por el usuario

            if (entrada.length() != 1 || (entrada[0] != 'S' && entrada[0] != 's' && entrada[0] != 'N' && entrada[0] != 'n'))
            {
                cout << "  Opci\242n no v\240lida. Por favor, ingrese 'S' para agregar otro elemento o 'N' para salir." << endl << endl; // Verifica si la opción ingresada es válida y muestra un mensaje de error si no es el caso
                gotoxy(1,4);
                cout <<"                                                                                              ";
            }
            else
            {
                opcion = entrada[0]; // Almacena la opción ingresada por el usuario
                break; // Sale del ciclo do-while interno y continúa con el flujo del programa
            }
        }
        while (true); // Repite hasta que se ingrese una opción válida (S/N)

        cout << endl;
        continue; // Salta al comienzo del ciclo do-while externo

        // Limpiar el búfer de entrada
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    while (opcion == 'S' || opcion == 's'); // Repite hasta que la opción ingresada sea 'N' o 'n'
    CambiaCursor(APAGADO);
    gotoxy(1,1);
    borrador();
}
void EliminarElementos(TablaHashDC& tabla)
{
    // Se llama a la función CambiaCursor con los argumentos ENCENDIDO y NORMAL para cambiar la apariencia del cursor.
    CambiaCursor(ENCENDIDO, NORMAL);
    char opcion;
    do
    {
        gotoxy(1,1);
        // Se llama a la función borrador para borrar la pantalla.
        borrador();
        gotoxy(1,2);
        // Si la tabla está vacía, se muestra un mensaje indicando que no hay elementos en la tabla y se pausa el programa.
        if (tabla.EstaVacia())
        {
            cout << "  La tabla est\240 vac\241a. No se puede eliminar elementos.                                    " << endl;
            CambiaCursor(APAGADO);
            Sleep(2500);
            // Se rompe el bucle do-while y se sale de la función.
            break;
        }
        int matricula;
        // Se solicita al usuario que ingrese la matrícula del elemento que desea eliminar.

        matricula = CapturaUnsignedInt("  Ingrese la matr\241cula del elemento que desea eliminar: ");
        // Se llama a la función EliminarElemento de la tabla para eliminar el elemento con la matrícula especificada.
        tabla.EliminarElemento(matricula);
        // Si la tabla no está vacía, se muestra un mensaje preguntando si se desea eliminar otro elemento.
        if (!tabla.EstaVacia())
        {
            do
            {
                gotoxy(1,4);
                cout <<"  \250Desea eliminar otro elemento? (S/N): ";
                std::string input;
                // Se lee la entrada del usuario.
                std::getline(std::cin, input);
                // Se verifica si la entrada es válida (una sola letra 'S', 's', 'N' o 'n').
                if (input.length() != 1 || (input[0] != 'S' && input[0] != 's' && input[0] != 'N' && input[0] != 'n'))
                {
                    cout << "  Opci\242n no v\240lida. Por favor, ingrese 'S' para eliminar otro elemento o 'N' para salir." << endl;
                    gotoxy(1,4);
                    cout <<"                                                                                              ";
                }
                else
                {
                    // Se asigna la opción seleccionada por el usuario a la variable "opcion".
                    opcion = input[0];
                    break;
                }
            }
            while (true);
        }
        else
        {
            // Si la tabla está vacía después de eliminar un elemento, se muestra un mensaje indicando que la tabla se ha quedado sin elementos y se pausa el programa.
            CambiaCursor(APAGADO);
            cout << endl << "  La tabla se ha quedado sin elementos." << endl;
            Sleep(3500);
            gotoxy(1,1);
            borrador();
            return;
        }
        cout << endl;
        // Se utiliza "continue" para volver al inicio del bucle do-while.
        continue;
        // Limpiar el búfer de entrada
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    while (opcion == 'S' || opcion == 's');
    gotoxy(1,1);
    // Se llama a la función borrador para borrar la pantalla.
    borrador();
}

void BuscarElementos(TablaHashDC& tabla)
{
    // Se llama a la función CambiaCursor con los argumentos ENCENDIDO y NORMAL para cambiar la apariencia del cursor.
    CambiaCursor(ENCENDIDO, NORMAL);
    char opcion;
    do
    {
        gotoxy(1,1);
        // Se llama a la función borrador para borrar la pantalla.
        borrador();

        gotoxy(1,2);
        // Si la tabla está vacía, se muestra un mensaje indicando que no hay elementos en la tabla y se pausa el programa.
        if (tabla.EstaVacia())
        {
            gotoxy(1,2);
            CambiaCursor(APAGADO);
            cout << "  La tabla no tiene elementos para buscar.                                                  " << endl;
            gotoxy(5,3);
            Sleep(2500);
            // Se rompe el bucle do-while y se sale de la función.
            break;
        }
        int matricula;
        // Se solicita al usuario que ingrese la matrícula del elemento que desea buscar.
        matricula = CapturaUnsignedInt("  Ingrese la matr\241cula del elemento que desea buscar: ");
        // Se llama a la función Buscar de la tabla para buscar el elemento con la matrícula especificada.
        if (tabla.Buscar(matricula))
        {
            gotoxy(1,2);
            cout << "  Elemento encontrado: [" << tabla.ObtenerNombreElemento(matricula) << ']' << endl;
        }
        else
        {
            gotoxy(1,2);
            cout << "  El elemento con matr\241cula [" << matricula << "] no se encuentra en la tabla." << endl;
        }
        // Si la tabla no está vacía, se muestra un mensaje preguntando si se desea buscar otro elemento.
        if (!tabla.EstaVacia())
        {
            do
            {
                gotoxy(1,4);
                cout << "  \250Desea buscar otro elemento? (S/N): ";
                std::string entrada;
                // Se lee la entrada del usuario.
                std::getline(std::cin, entrada);
                // Se verifica si la entrada es válida (una sola letra 'S', 's', 'N' o 'n').
                if (entrada.length() != 1 || (entrada[0] != 'S' && entrada[0] != 's' && entrada[0] != 'N' && entrada[0] != 'n'))
                {
                    cout << "  Opci\242n no v\240lida. Por favor, ingrese 'S' para buscar otro elemento o 'N' para salir." << endl << endl;
                    gotoxy(1,4);
                    cout <<"                                                                                              ";
                }
                else
                {
                    // Se asigna la opción seleccionada por el usuario a la variable "opcion".
                    opcion = entrada[0];
                    break;
                }
            }
            while (true);
            cout << endl;
            // Se utiliza "continue" para volver al inicio del bucle do-while.
            continue;
        }
    }
    while (opcion == 'S' || opcion == 's');

    gotoxy(1,1);
    // Se llama a la función borrador para borrar la pantalla.
    borrador();
}

void ImprimirTabla(TablaHashDC& tabla)
{
    gotoxy(1,1);
    // Se llama a la función borrador para borrar la pantalla.
    borrador();

    gotoxy(1,15);
    cout << " ***Tabla Hash con Direccionamiento Cerrado***";

    gotoxy(1,17);
    // Se llama a la función ImprimirTabla de la tabla para mostrar la tabla en la consola.
    tabla.ImprimirTabla();
}
void ImprimirEstadisticas(const TablaHashDC& tabla)
{
    gotoxy(50,3);
    cout << "Estad\241sticas de la tabla original" << endl;
    gotoxy(50,4);
    cout << "-----------------------------" << endl;
    // Se posiciona el cursor en la coordenada (50,5) en la consola y se muestra la capacidad de la tabla.
    gotoxy(50,5);
    cout << "*Capacidad: " << tabla.ObtenerCapacidad() << endl;
    // Se posiciona el cursor en la coordenada (50,6) en la consola y se muestra el número de elementos en la tabla.
    gotoxy(50,6);
    cout << "*N\243mero de Elementos: " << tabla.ObtenerNumeroDeElementos() << endl;
    // Se posiciona el cursor en la coordenada (50,7) en la consola y se muestra si la tabla está vacía o no.
    gotoxy(50,7);
    cout << "*\250Est\240 vac\241a?: " << (tabla.EstaVacia() ? "S\241" : "No") << endl;

    int totalColisiones = 0;
    for (int i = 0; i < tabla.ObtenerCapacidad(); i++)
    {
        int colisiones;
        // Si la lista enlazada en la posición "i" tiene un tamaño de 0, no hay colisiones.
        if(tabla.ObtenerListaEnlazada(i).ObtenerTam() == 0)
        {
            colisiones = 0;
        }
        else
        {
            // Si el tamaño de la lista enlazada en la posición "i" es mayor a 0, se resta 1 para obtener el número de colisiones.
            colisiones = tabla.ObtenerListaEnlazada(i).ObtenerTam() - 1;
        }
        // Se suman las colisiones al total.
        totalColisiones += colisiones;
    }
    // Se posiciona el cursor en la coordenada (50,8) en la consola y se muestra el número total de colisiones.
    gotoxy(50,8);
    cout << "*Colisiones totales: " << totalColisiones << endl;

    int longitudMaxima = 0;
    for (int i = 0; i < tabla.ObtenerCapacidad(); i++)
    {
        int longitudLista = tabla.ObtenerListaEnlazada(i).ObtenerTam();
        if (longitudLista > longitudMaxima)
        {
            longitudMaxima = longitudLista;
        }
    }
    // Se posiciona el cursor en la coordenada (50,9) en la consola y se muestra la longitud máxima de lista.
    gotoxy(50,9);
    cout << "*Longitud m\240xima de lista: " << longitudMaxima << endl;
}

void CopiarTabla(TablaHashDC& tablaA, TablaHashDC& tablaB)
{
    // Verifica si la tabla A está vacía. Si es así, muestra un mensaje de error y detiene la copia.
    if (tablaA.EstaVacia())
    {
        gotoxy(1,14);
        cout << "  La tabla est\240 vac\241a. No se puede realizar la copia.                        " << endl;
        return;
    }

    // Realiza la copia de la tabla A en la tabla B.
    tablaB = tablaA;

    // Verifica si la copia fue exitosa comparando el número de elementos de ambas tablas.
    if (tablaB.ObtenerNumeroDeElementos() == tablaA.ObtenerNumeroDeElementos())
    {
        gotoxy(1,14);
        cout << "  Copia exitosa. Se ha guardado una copia de la tabla actual.                              " << endl;
        return;
    }
}

void RestaurarUltimaCopia(TablaHashDC& tablaA, TablaHashDC& tablaB)
{

    gotoxy(1,14);

    // Verifica si la tabla B está vacía. Si es así, muestra un mensaje de error y detiene la restauración.
    if (tablaB.EstaVacia())
    {
        gotoxy(1,14);
        cout << "  No hay ninguna copia guardada.                               " << endl;
        return;
    }

    // Restaura la última copia guardada, copiando la tabla B en la tabla A.
    tablaA = tablaB;

    // Verifica si la restauración fue exitosa comparando el número de elementos de ambas tablas.
    if (tablaA.ObtenerNumeroDeElementos() == tablaB.ObtenerNumeroDeElementos())
    {
        // Borra la pantalla y mueve el cursor a la posición (1,14) en la consola.
        gotoxy(1,1);
        borrador();
        gotoxy(1,14);
        cout << "  Se ha restaurado la \243ltima versi\242n de la tabla guardada.                            " << endl;
    }
}

bool VaciarTabla(TablaHashDC& tabla)
{
    // Borra la pantalla y mueve el cursor a la posición (1,1) en la consola.
    gotoxy(1,1);
    borrador();

    // Verifica si la tabla está vacía. Si es así, devuelve false.
    if (tabla.EstaVacia())
    {
        return false;
    }

    // Vacía la tabla llamando al método VaciarTabla().
    tabla.VaciarTabla();

    // Devuelve true para indicar que la tabla se ha vaciado correctamente.
    return true;
}
