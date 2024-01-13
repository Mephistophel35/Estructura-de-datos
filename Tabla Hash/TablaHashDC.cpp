#include "TablaHashDC.h"

// Incluye el archivo de encabezado "TablaHashDC.h"

// Métodos públicos de la clase TablaHashDC

// Constructor de la clase TablaHashDC
TablaHashDC::TablaHashDC(int capacidad) : Capacidad(capacidad), CapacidadMaxima(capacidad), NumeroDeElementos(0)
{
    // Crea un arreglo dinámico de ListasEnlazadasSimple de tamaño 'Capacidad'
    tabla = new ListaEnlazadaSimple<Elemento>[Capacidad];
}

// Constructor de copia de la clase TablaHashDC
TablaHashDC::TablaHashDC(const TablaHashDC& otraTabla) : Capacidad(otraTabla.Capacidad), CapacidadMaxima(otraTabla.CapacidadMaxima), NumeroDeElementos(otraTabla.NumeroDeElementos)
{
    // Crea un arreglo dinámico de ListasEnlazadasSimple de tamaño 'Capacidad'
    tabla = new ListaEnlazadaSimple<Elemento>[Capacidad];

    // Copia los elementos de 'otraTabla' a 'tabla'
    for (int i = 0; i < Capacidad; i++)
    {
        tabla[i] = otraTabla.tabla[i];
    }
}

// Sobrecarga del operador de asignación (=) de la clase TablaHashDC
TablaHashDC& TablaHashDC::operator=(const TablaHashDC& otraTabla)
{
    // Verifica si 'otraTabla' es la misma instancia que la actual
    if (this == &otraTabla)
    {
        // Si es la misma instancia, retorna la referencia a sí misma
        return *this;
    }

    // Libera la memoria ocupada por el arreglo 'tabla'
    delete[] tabla;

    // Asigna los valores de 'otraTabla' a la instancia actual
    Capacidad = otraTabla.Capacidad;
    CapacidadMaxima = otraTabla.CapacidadMaxima;
    NumeroDeElementos = otraTabla.NumeroDeElementos;

    // Crea un nuevo arreglo dinámico de ListasEnlazadasSimple de tamaño 'Capacidad'
    tabla = new ListaEnlazadaSimple<Elemento>[Capacidad];

    // Copia los elementos de 'otraTabla' a 'tabla'
    for (int i = 0; i < Capacidad; i++)
    {
        tabla[i] = otraTabla.tabla[i];
    }

    // Retorna la referencia a la instancia actual
    return *this;
}

// Destructor de la clase TablaHashDC
TablaHashDC::~TablaHashDC()
{
    // Libera la memoria ocupada por el arreglo 'tabla'
    delete[] tabla;
}

// Inserta un elemento en la tabla
void TablaHashDC::InsertarElemento(const Elemento& elemento)
{
    // Verifica si la tabla está vacía
    if (EstaVacia())
    {
        // Calcula el índice de inserción utilizando la función de hash
        int indice = FuncionHash(elemento.Id);
        // Agrega el elemento a la lista enlazada correspondiente al índice calculado
        tabla[indice].AgregarComoUltimo(elemento);
        // Incrementa el contador de elementos
        NumeroDeElementos++;
    }
    else
    {
        // Si la tabla no está vacía, verifica si el elemento ya existe en la tabla
        if (Buscar(elemento.Id))
        {
            // Si el elemento ya existe, muestra un mensaje y retorna
            gotoxy(1,2);
            std::cout << "  La matr\241cula ya est\240 en uso. No se puede agregar el elemento." << std::endl;
            return;
        }

        // Calcula el índice de inserción utilizando la función de hash
        int indice = FuncionHash(elemento.Id);
        // Agrega el elemento a la lista enlazada correspondiente al índice calculado
        tabla[indice].AgregarComoUltimo(elemento);
        // Incrementa el contador de elementos
        NumeroDeElementos++;

        // Verifica si la lista enlazada ha alcanzado el tamaño límite y se debe redimensionar la tabla
        if (tabla[indice].ObtenerTam() >= 5)
        {
            RedimensionarTabla();
        }
    }
}

// Elimina un elemento de la tabla dado su id
void TablaHashDC::EliminarElemento(int id)
{
    // Verifica si la tabla está vacía
    if (EstaVacia())
    {
        std::cout << "  La tabla est\240 vac\241a. No se puede eliminar elementos." << std::endl;
        return;
    }

    // Calcula el índice de búsqueda utilizando la función de hash
    int indice = FuncionHash(id);
    // Obtiene la lista enlazada correspondiente al índice calculado
    ListaEnlazadaSimple<Elemento>& lista = tabla[indice];

    // Recorre la lista enlazada en busca del elemento con el id dado
    for (unsigned int i = 0; i < lista.ObtenerTam(); i++)
    {
        // Si encuentra el elemento, lo elimina de la lista, decrementa el contador de elementos y muestra un mensaje
        if (lista[i].Id == id)
        {
            std::string ElementoEliminado = ObtenerNombreElemento(id);
            lista.EliminarEnPosicion(i);
            NumeroDeElementos--;
            gotoxy(1,2);
            std::cout << "  El elemento [" << ElementoEliminado << "] ha sido eliminado exitosamente." << std::endl;
            return;
        }
    }

    // Si no encuentra el elemento, muestra un mensaje indicando que no se encontró
    gotoxy(1,2);
    std::cout << "  Error: La matr\241cula no corresponde a ning\243n elemento." << std::endl;
}

// Vacía la tabla eliminando todos los elementos
void TablaHashDC::VaciarTabla()
{
    // Verifica si la tabla está vacía
    if (EstaVacia())
    {
        gotoxy(1,14);
        std::cout << "  La tabla no tiene elementos." << std::endl;
        return;
    }

    // Recorre todas las listas enlazadas del arreglo 'tabla' y las vacía
    for (int i = 0; i < Capacidad; i++)
    {
        tabla[i].Vaciar();
    }
    // Reinicia el contador de elementos
    NumeroDeElementos = 0;
    gotoxy(1,14);
    std::cout << "  Tabla vaciada exitosamente." << std::endl;
}

// Imprime la tabla en la consola
void TablaHashDC::ImprimirTabla() const
{
    // Verifica si la tabla está vacía
    if (EstaVacia())
    {
        std::cout << "  La tabla est\240 vac\241a." << std::endl;
        return;
    }

    // Recorre todas las listas enlazadas del arreglo 'tabla' y las imprime en la consola
    for (int i = 0; i < Capacidad; i++)
    {
        std::cout << "\t\t";
        ListaEnlazadaSimple<Elemento>& lista = tabla[i];
        for (unsigned int j = 0; j < lista.ObtenerTam(); j++)
        {
            Elemento& elemento = lista[j];
            std::cout << '[' << elemento.Nombre << "] --> ";
        }
        std::cout << "\b\b\b\b   ";
        std::cout << "\r\326ndice " << i << ": ";
        std::cout << std::endl;
    }
}

// Obtiene el nombre del elemento con el id dado
std::string TablaHashDC::ObtenerNombreElemento(int id) const
{
    // Verifica si la tabla está vacía
    if (EstaVacia())
    {
        std::cout << "  La tabla no tiene elementos." << std::endl;
        return "";
    }

    // Calcula el índice de búsqueda utilizando la función de hash
    int indice = FuncionHash(id);

    // Obtiene la lista enlazada correspondiente al índice calculado
    ListaEnlazadaSimple<Elemento>& lista = tabla[indice];

    // Recorre la lista enlazada en busca del elemento con el id dado
    for (unsigned int i = 0; i < lista.ObtenerTam(); i++)
    {
        // Si encuentra el elemento, retorna su nombre
        Elemento& elemento = lista[i];
        if (elemento.Id == id)
        {
            return elemento.Nombre;
        }
    }

    // Si no encuentra el elemento, muestra un mensaje indicando que no se encontró
    gotoxy(1,2);
    std::cout << "  Elemento no encontrado." << std::endl;
    return "";
}

// Obtiene el número de elementos en la tabla
int TablaHashDC::ObtenerNumeroDeElementos() const
{
    return NumeroDeElementos;
}

// Verifica si la tabla está vacía
bool TablaHashDC::EstaVacia() const
{
    return NumeroDeElementos == 0;
}

// Busca un elemento en la tabla dado su id
bool TablaHashDC::Buscar(int id) const
{
    // Verifica si la tabla está vacía
    if (EstaVacia())
    {
        std::cout << "  La tabla no tiene elementos." << std::endl;
        return false;
    }

    // Calcula el índice de búsqueda utilizando la función de hash
    int indice = FuncionHash(id);

    // Obtiene la lista enlazada correspondiente al índice calculado
    ListaEnlazadaSimple<Elemento>& lista = tabla[indice];

    // Recorre la lista enlazada en busca del elemento con el id dado
    for (unsigned int i = 0; i < lista.ObtenerTam(); i++)
    {
        // Si encuentra el elemento, retorna true
        Elemento& elemento = lista[i];
        if (elemento.Id == id)
        {
            return true;
        }
    }

    // Si no encuentra el elemento, retorna false
    return false;
}

// Obtiene la capacidad actual de la tabla
int TablaHashDC::ObtenerCapacidad() const
{
    return Capacidad;
}

// Obtiene la lista enlazada correspondiente a un índice dado
const ListaEnlazadaSimple<Elemento>& TablaHashDC::ObtenerListaEnlazada(int indice) const
{
    return tabla[indice];
}

// Métodos privados de la clase TablaHashDC

// Función de hash que devuelve el índice de inserción dado un id
int TablaHashDC::FuncionHash(int id) const
{
    return id % Capacidad;
}

// Redimensiona la tabla aumentando su capacidad en 2
void TablaHashDC::RedimensionarTabla()
{
    // Duplica la capacidad de la tabla
    Capacidad *= 2;

    // Crea un nuevo arreglo dinámico de ListasEnlazadasSimple de tamaño 'Capacidad'
    ListaEnlazadaSimple<Elemento>* nuevaTabla = new ListaEnlazadaSimple<Elemento>[Capacidad];

    // Recorre todas las listas enlazadas del arreglo 'tabla' y redistribuye los elementos en la nueva tabla
    for (int i = 0; i < Capacidad / 2; i++)
    {
        ListaEnlazadaSimple<Elemento>& lista = tabla[i];
        for (unsigned int j = 0; j < lista.ObtenerTam(); j++)
        {
            Elemento& elemento = lista[j];
            int nuevoIndice = FuncionHash(elemento.Id);
            nuevaTabla[nuevoIndice].AgregarComoUltimo(elemento);
        }
    }

    // Libera la memoria ocupada por el arreglo 'tabla'
    delete[] tabla;

    // Asigna el nuevo arreglo 'nuevaTabla' a 'tabla'
    tabla = nuevaTabla;
}
