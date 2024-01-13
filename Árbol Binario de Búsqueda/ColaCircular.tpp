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
    //Si la cola de esta instancia es diferente a la cola recibida como par�metro se hace lo siguiente...
    if (this != &C)
    {
        //Vaciamos la cola de esta instancia.
        VaciarCola();

        //Si la cola recibida por par�metro NO est� vacia se hace lo siguiente.
        if (!C.estaVacia())
        {
            //Declaramos un puntero tipo Elemento que apunte al �ltimo elemento que la cola recibida por par�mtro posee.
            Elemento* ptrOtra = C.ultimo;
            //Declaramos otro puntero igualandolo a un nuevo elemento que contenga el dato al que el puntero declarado
            //anteriormente est� apuntando.
            Elemento* ptrNuevo = new Elemento(ptrOtra->dato);
            //El puntero ultimo de esta instancia le decimos que sea igual al nuevo puntero (ptrNuevo).
            ultimo = ptrNuevo;
            //Incrementamos en uno el n�mero de elementos de la cola de esta instancia.
            NumElem++;

            //Mientras el puntero que apunta al siguiente del �ltimo elemento de la cola recibida como par�metro
            //Sea diferente de null se hace lo siguiente;
            while (ptrOtra->siguiente != nullptr)
            {
                //Este puntero que estamos comparando lo hacemos que apunte al siguiente elemento.
                ptrOtra = ptrOtra->siguiente;
                //Ahora en el siguiente elemento del puntero "ptrNuevo" creamos otro nuevo elemento que
                //contenga el dato al que el puntero "ptrOtra" est� apuntando.
                ptrNuevo->siguiente = new Elemento(ptrOtra->dato);
                //Ahora recorremos el puntero al siguiente elemento.
                ptrNuevo = ptrNuevo->siguiente;
                //Incrementamos en uno el n�mero de elementos
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
    //Declaramos un puntero tipo Elemento que igualar�mos a un nuevo Elemento que contenga el valor recibido
    //como par�metro y en la cuesti�n del puntero..
    /*
        *Recordar el constructor de la estructura elemento*
        Elemento(T d, Elemento * sig)
    */
    //Le decimos que el elemento al que el siguiente apunta del nuevo elemento creado sea dependiendo si
    //la cola est� vacia le decimos que apunte a null, de lo contrario que apunte al siguiente del �ltimo
    Elemento * nuevo = new Elemento(v, ColaVacia()? nullptr : ultimo->siguiente);
    //Si la cola est� vacia hacemos que el siguiente del nuevo sea el nuevo elemento, es decir, que apunte
    //a si mismo, de lo contrario que el siguiente del �ltimo apunte al nuevo.
    (ColaVacia() ? nuevo -> siguiente : ultimo -> siguiente) = nuevo;
    //Le decimos que el �ltimo dato ahora apunte al nuevo.
    ultimo = nuevo;
    //Incrementamos el contador de elementos.
    ++NumElem;
}

template <typename T>
void Cola<T>::Eliminar()
{
    //Si la cola no est� vacia hacemos lo siguiente...
    if(!ColaVacia()){

        //Si el ultimo elemento apunta a s� mismo hacemos...
        if(ultimo -> siguiente == ultimo){
            //Borramos a lo que apunta el �ltimo.
            delete ultimo;
            //Ahora que el �ltimo sea null
            ultimo = nullptr;
        //Si el ultimo elemento NO apunta a s� mismo hacemos...
        }else{
            //Declaramos un puntero tipo elemento auxiliar llamado "porBorrar" que apunte
            //Al siguiente del �ltimo elemento.
            Elemento * porBorrar = ultimo -> siguiente;
            //Ahora le conectamos el siguiente del �ltimo con el siguiente del puntero auxiliar.
            ultimo -> siguiente = porBorrar -> siguiente;
            //Borramos el nodo auxiliar.
            delete porBorrar;
        }
        //Decrementamos el contador de elementos en uno.
        --NumElem;
    //Si la cola est� vac�a solo tira excepci�n.
    }else{
        // *IMPORTANTE*
        //No es necesario que sea una excepci�n.
        //basta con que sea algo como esto:

        /*
            cout << "La pila est� vacia << endl;
            return;
        */
        throw ColaVaciaExc();
    }
}

template <typename T>
const T & Cola<T>::Primero() const
{
    //Si la cola est� vacia tiramos excepci�n
    // *REPITO* no es necesario que sea excepci�n.
    if(ColaVacia()) throw ColaVaciaExc();
    //Si la cola NO est� vac�a, regresamos el dato al que el siguiente del �ltimo elemento est� apuntando.
    else return ultimo->siguiente->dato;
}

template <typename T>
const T & Cola<T>::Ultimo() const
{
    //Si la cola est� vacia tiramos excepci�n
    // *REPITO* no es necesario que sea excepci�n.
    if(ColaVacia()) throw ColaVaciaExc();
    //Si la cola NO est� vac�a, regresamos el dato al que el puntero al �ltimo dato est� apuntando.
    else return ultimo->dato;
}

template <typename T>
bool Cola<T>::ColaVacia() const
{
    //Evaluamos si el puntero "�ltimo" apunta a null, es decir, si no apunta a nada.
    //Tambi�n se puede hacer lo siguiente:
    /*
        return NumElem == 0;
    */
    return ultimo == nullptr;
}

template <typename T>
void Cola<T>::VaciarCola()
{
    //Mientras la cola NO est� vac�a que vaya eliminando datos.
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
    //Si la cola est� vac�a regresamos excepci�n.
    //*NO NECESARIAMENTE PUEDE SER EXXCEPCI�N*
    if(ColaVacia()) throw ColaVaciaExc();

    //Declaramos un puntero tipo elemento auxiliar que apunte al siguiente del �ltimo elemento.
    Elemento * aux = ultimo->siguiente;
    cout << "[";
    //Mientras el puntero auxiliar no apunte a donde apunta el �ltimo empieza el ciclo...
    while(aux != ultimo){
        //Imprimimos el dato al que el puntero auxiliar apunte.
        cout << aux->dato << "|";
        //Recorremos el puntero auxiliar al siguiente elemento.
        aux = aux -> siguiente;
    }
    //Imprimir el �ltimo dato
    //*Recordar la concici�n que le pusimos para que vaya recorriendo.
    cout << aux->dato << "]";
}

template <typename T>
const char * Cola<T>::ColaVaciaExc::what() const throw()
{
    //Devolver mensajito de error.
    return "La cola est\240 vacia";
}

// ~Mephisto
