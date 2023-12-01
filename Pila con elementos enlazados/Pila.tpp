#include <iostream>


template <typename T>
Pila<T>::Pila(){

    //Iniciar los atributos de la clase (debe de ser en orden en como están agregados).
    NumElem = 0;
    tope = nullptr;
}

template <typename T>
Pila<T>::Pila(const Pila<T> &P) : NumElem(0), tope(nullptr){

    //Igualamos la pila de esta instancia con la que recibimos como parámetro.
    *this = P;
}

template <typename T>
Pila<T> & Pila<T>::operator=(const Pila<T> &P)
{
    //Si la pila de esta instancia es igual a la que nos llegó como parámetro retornamos la pila de ESTA instancia.
    if(this == &P) return *this;

    //Vaciamos la pila de esta instancia
    this.VaciarPila();
    //Cremos una Pila auxiliar
    Pila aux;
    //Creamos un puntero tipo Elemento al tope de la pila recibida como parámetro.
    Elemento * pElemento = P.tope;

    //Mientras el puntero creado anteriormente sea diferente de null
    while(pElemento != nullptr){
        //Agregamos los elementos(datos) a los que el puntero que creamos esté apuntando.
        aux.Agregar(pElemento -> dato);
        //Hacemos que el puntero que estaba apuntando al tope apunte ahora al siguiente elemento
        pElemento = pElemento -> siguiente;
    }
    //Mientras la pila auxiliar NO esté vacia se hace lo siguiente.
    while(!aux.PilaVacia()){
        //A la pila de esta instancia mandamos a agregar el elemento que esté en el tope de la pila Auxiliar
        this->Agregar(aux.Tope());
        //Vamos eliminando los elementos de la pila auxiliar.
        aux.Eliminar();
    }
    return *this;
}

template <typename T>
Pila<T>::~Pila()
{
    //Solo mandamos a vaciar la pila
    VaciarPila();
}

template <typename T>
void Pila<T>::Agregar(const T &v)
{
    //Creamos un puntero tipo Elemento
    //Creamos un nuevo elemento con los siguiente parámetros, v que es el dato que deseamos agregar
    // y le decimos que este elemento debe ser el tope de la pila
    Elemento * nuevo = new Elemento(v, tope);
    //Hacemos que el tope ahora apunte al nuevo elemento.
    tope = nuevo;
    //Incrementamos el numero de elementos porque hemos agregado un nuevo elemento a la pila.
    ++NumElem;
}

template <typename T>
void Pila<T>::Eliminar()
{
    //Si la pila está vacia mandamos un error de que no se puede agregar nada
    //Esto del throw NO es necesario, basta con poner un mensaje con un cout
    //de que la pila está vacia y no regresamos nada, es decir, algo como:

    /*
        cout << "La pila se encuentra vacia" << endl;
        return;
    */

    if(PilaVacia()) throw pilaVacia();

    //Creamos un puntero tipo Elemento que nos diga cual vamos a quitar de la pila
    //Como queremos eliminar el tope hacemos que el puntero apunte TAMBIÉN a donde
    //esté apuntando el tope.
    Elemento * porBorrar = tope;
    //Hacemos que el tope apunte al siguiente del por borrar
    //El elemento del tope no se perderá porque recuerda que
    //el puntero porBorrar ya apunta al tope, es decir, no se perderá la dirección de memoria,
    //lo cual nos permitirá eliminar el elemento sin problema, ni dejar basura en el programa.
    tope = porBorrar -> siguiente;
    //Decrementamos en uno el contador de los elementos ya que acabamos de eliminar un elemento de la pila.
    --NumElem;
    //Borramos el puntero porBorrar.
    delete porBorrar;
}

template <typename T>
const T &Pila<T>::Tope() const
{
    //Si la pila está vacia mandamos un error de que no se puede agregar nada
    //Esto del throw NO es necesario, basta con poner un mensaje con un cout
    //de que la pila está vacia y no regresamos nada, es decir, algo como:

    /*
        cout << "La pila se encuentra vacia" << endl;
        return;
    */
    if(PilaVacia()) throw pilaVacia();

    //Retornamos el valor al que el tope esté apuntando.
    return tope->dato;
}

template <typename T>
bool Pila<T>::PilaVacia() const
{
    //Se evalua si el tope es igual a null

    //También se puede hacer algo como esto:

    /*

    return NumElem == 0;

    */

    //Ya que si el contador de elementos de la pila está en 0 pues significa que no hay nada en la pila.
    return tope == nullptr;
}

template <typename T>
void Pila<T>::VaciarPila()
{
    while(!PilaVacia()){
        Eliminar();
    }
}

template <typename T>
int Pila<T>::Tamanio() const
{
    //Regresamos el numero de elementos que contiene la pila
    return NumElem;
}

template <typename T>
void Pila<T>::Imprimir() const
{
    //Creamos un puntero auxiliar que apunte a donde el tope esté apuntando.
    //De la línea 145 a la 147 solo imprimo el tope
    Elemento * aux = tope;
    std::cout << "[";
    std::cout << aux->dato;
    std::cout << "]  <--- Tope" << std::endl;
    //Hacemos que el puntero auxiliar se recorra al siguiente elemento del tope.
    aux = aux -> siguiente;

    //Mientras el puntero aux sea diferente (!=) de null vamos imprimiendo y recorriendo el puntero auxiliar al siguiente elemento.
    while(aux != nullptr){
        std::cout << "[";
        std::cout << aux->dato;
        std::cout << "]" << std::endl;
        aux = aux->siguiente;
    }
}

template <typename T>
const char * Pila<T>::pilaVacia::what() const throw()
{
    //Esto solo imprime el mensajito que le queremos dar al usuario.
    return "Pila Vacia";
}




// ~Mephisto
