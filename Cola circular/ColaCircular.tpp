#include <iostream>
using std::cout;
using std::endl;

template <typename T>
Cola<T>::Cola(): NumElem(0), ultimo(nullptr){}

template <typename T>
Cola<T>::Cola(const Cola<T> &C) : NumElem(0), ultimo(nullptr)
{
    *this = C;
}

template <typename T>
Cola<T> & Cola<T>::operator=(const Cola<T> &C)
{
    //Si la cola de esta instancia es diferente a la cola recibida como parámetro se hace lo siguiente...
    if (this != &C)
    {
        //Vaciamos la cola de esta instancia.
        VaciarCola();

        //Si la cola recibida por parámetro NO está vacia se hace lo siguiente.
        if (!C.estaVacia())
        {
            //Declaramos un puntero tipo Elemento que apunte al último elemento que la cola recibida por parámtro posee.
            Elemento* ptrOtra = C.ultimo;
            //Declaramos otro puntero igualandolo a un nuevo elemento que contenga el dato al que el puntero declarado
            //anteriormente esté apuntando.
            Elemento* ptrNuevo = new Elemento(ptrOtra->dato);
            //El puntero ultimo de esta instancia le decimos que sea igual al nuevo puntero (ptrNuevo).
            ultimo = ptrNuevo;
            //Incrementamos en uno el número de elementos de la cola de esta instancia.
            NumElem++;

            //Mientras el puntero que apunta al siguiente del último elemento de la cola recibida como parámetro
            //Sea diferente de null se hace lo siguiente;
            while (ptrOtra->siguiente != nullptr)
            {
                //Este puntero que estamos comparando lo hacemos que apunte al siguiente elemento.
                ptrOtra = ptrOtra->siguiente;
                //Ahora en el siguiente elemento del puntero "ptrNuevo" creamos otro nuevo elemento que
                //contenga el dato al que el puntero "ptrOtra" esté apuntando.
                ptrNuevo->siguiente = new Elemento(ptrOtra->dato);
                //Ahora recorremos el puntero al siguiente elemento.
                ptrNuevo = ptrNuevo->siguiente;
                //Incrementamos en uno el número de elementos
                NumElem++;
            }
        }
    }
    //Regresamos a lo que apunta "this", es decir, regramos una cola nueva o la misma.
    return *this;
}

template <typename T>
Cola<T>::~Cola()
{
    //Vaciamos la cola.
    VaciarCola();
}

template <typename T>
void Cola<T>::Agregar(const T &v)
{
    //Declaramos un puntero tipo Elemento que igualarémos a un nuevo Elemento que contenga el valor recibido
    //como parámetro y en la cuestión del puntero..
    /*
        *Recordar el constructor de la estructura elemento*
        Elemento(T d, Elemento * sig)
    */
    //Le decimos que el elemento al que el siguiente apunta del nuevo elemento creado sea dependiendo si
    //la cola está vacia le decimos que apunte a null, de lo contrario que apunte al siguiente del último
    Elemento * nuevo = new Elemento(v, ColaVacia()? nullptr : ultimo->siguiente);
    //Si la cola está vacia hacemos que el siguiente del nuevo sea el nuevo elemento, es decir, que apunte
    //a si mismo, de lo contrario que el siguiente del último apunte al nuevo.
    (ColaVacia() ? nuevo -> siguiente : ultimo -> siguiente) = nuevo;
    //Le decimos que el último dato ahora apunte al nuevo.
    ultimo = nuevo;
    //Incrementamos el contador de elementos.
    ++NumElem;
}

template <typename T>
void Cola<T>::Eliminar()
{
    //Si la cola no está vacia hacemos lo siguiente...
    if(!ColaVacia()){

        //Si el ultimo elemento apunta a sí mismo hacemos...
        if(ultimo -> siguiente == ultimo){
            //Borramos a lo que apunta el último.
            delete ultimo;
            //Ahora que el último sea null
            ultimo = nullptr;
        //Si el ultimo elemento NO apunta a sí mismo hacemos...
        }else{
            //Declaramos un puntero tipo elemento auxiliar llamado "porBorrar" que apunte
            //Al siguiente del último elemento.
            Elemento * porBorrar = ultimo -> siguiente;
            //Ahora le conectamos el siguiente del último con el siguiente del puntero auxiliar.
            ultimo -> siguiente = porBorrar -> siguiente;
            //Borramos el nodo auxiliar.
            delete porBorrar;
        }
        //Decrementamos el contador de elementos en uno.
        --NumElem;
    //Si la cola está vacía solo tira excepción.
    }else{
        // *IMPORTANTE*
        //No es necesario que sea una excepción.
        //basta con que sea algo como esto:

        /*
            cout << "La pila está vacia << endl;
            return;
        */
        throw ColaVaciaExc();
    }
}

template <typename T>
const T & Cola<T>::Primero() const
{
    //Si la cola está vacia tiramos excepción
    // *REPITO* no es necesario que sea excepción.
    if(ColaVacia()) throw ColaVaciaExc();
    //Si la cola NO está vacía, regresamos el dato al que el siguiente del último elemento esté apuntando.
    else return ultimo->siguiente->dato;
}

template <typename T>
const T & Cola<T>::Ultimo() const
{
    //Si la cola está vacia tiramos excepción
    // *REPITO* no es necesario que sea excepción.
    if(ColaVacia()) throw ColaVaciaExc();
    //Si la cola NO está vacía, regresamos el dato al que el puntero al último dato esté apuntando.
    else return ultimo->dato;
}

template <typename T>
bool Cola<T>::ColaVacia() const
{
    //Evaluamos si el puntero "último" apunta a null, es decir, si no apunta a nada.
    //También se puede hacer lo siguiente:
    /*
        return NumElem == 0;
    */
    return ultimo == nullptr;
}

template <typename T>
void Cola<T>::VaciarCola()
{
    //Mientras la cola NO esté vacía que vaya eliminando datos.
    while(!ColaVacia()) Eliminar();
}

template <typename T>
int Cola<T>::Tamanio() const
{
    //Regresamos la cantidad de elementos que el contador de elementos posee.
    return NumElem;
}

template <typename T>
void Cola<T>::Imprimir() const
{
    //Si la cola está vacía regresamos excepción.
    //*NO NECESARIAMENTE PUEDE SER EXXCEPCIÓN*
    if(ColaVacia()) throw ColaVaciaExc();

    //Declaramos un puntero tipo elemento auxiliar que apunte al siguiente del último elemento.
    Elemento * aux = ultimo->siguiente;
    cout << "[";
    //Mientras el puntero auxiliar no apunte a donde apunta el último empieza el ciclo...
    while(aux != ultimo){
        //Imprimimos el dato al que el puntero auxiliar apunte.
        cout << aux->dato << "|";
        //Recorremos el puntero auxiliar al siguiente elemento.
        aux = aux -> siguiente;
    }
    //Imprimir el último dato
    //*Recordar la concición que le pusimos para que vaya recorriendo.
    cout << aux->dato << "]";
}

template <typename T>
const char * Cola<T>::ColaVaciaExc::what() const throw()
{
    //Devolver mensajito de error.
    return "La cola est\240 vacia";
}

// ~Mephisto
