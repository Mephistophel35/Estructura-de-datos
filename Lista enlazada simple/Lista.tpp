template <typename T>
Lista<T>::Lista() : tam(0), primero(nullptr), ultimo(nullptr){}

template <typename T>
Lista<T>::Lista(const Lista<T> &L) : tam(0), primero(nullptr), ultimo(nullptr)
{
    //Como todo constructor de copias hacemos que a lo que
    //apunte "this" lo igualamos con la lista proporcionada
    //como parámetro.
    *this = L;
}

template <typename T>
Lista<T> & Lista<T>::operator=(const Lista<T> &L)
{
    //Si la lista de esta instancia es diferente a la se recibe
    //como parámetro se procede a vaciarla
    if(this != &L){
        this->Vaciar();
    }
    //Si la lista NO está vacía...
    if(!L.ListaVacia()){
        //Creamos un puntero tipo elemento y hacemos que
        //apunte a donde apunte el puntero al primer elemento
        //de la lista.
        Elemento * lOtro = L.primero;
        //Creamos otro puntero tipo elemento que contenga el primer dato
        //de la lista recibida como parámetro.
        Elemento * lNuevo = new Elemento(lOtro->dato);
        //Hacemos que el puntero al primer elemento de ESTA instancia
        //apunte al nuevo elemento creado.
        primero = lNuevo;
        //Lo mismo con el puntero al último elemento de ESTA instancia.
        ultimo = lNuevo;
        //Incrementamos el contador de datos de la lista de ESTA instancia.
        ++tam;

        //Mientras la lista tenga más elementos se hace lo sig...
        while(lOtro->siguiente != nullptr){
            //Recorremos el puntero al siguiente elemento.
            lOtro = lOtro->siguiente;
            //Hacemos que el puntero al siguiente elemento del nuevo
            //elemento ahora contenga un elemento, en este caso
            //al dato que apunte "lOtro" porque recuerda
            //que el puntero se recorrió al siguiente elemento.
            lNuevo->siguiente = new Elemento(lOtro->dato);
            //Recorremos el puntero del nuevo elemento a su siguiente elemento.
            lNuevo = lNuevo->siguiente;
            //Ahora que el puntero al último elemento de la lista recibida
            //apunte a donde apunta "lNuevo".
            L.ultimo = lNuevo;
            //incrementamos en uno el tamaño de la lista de ESTA instancia.
            ++tam;
        }
    }
    //Regresamos la lista.
    return *this;
}

template <typename T>
Lista<T>::~Lista()
{
    //Solo vacía la lista.
    Vaciar();
}

template <typename T>
void Lista<T>::AgregarInicio(const T &v)
{
    //Creamos un puntero que contenga un nuevo elemento...
    //Si la lista está vacia pues su siguiente elemento apuntará
    //a null, en el caso de que no, apuntará a donde esté apuntando
    //el puntero al primer elemento de la lista.
    Elemento * nuevo = new Elemento(v, ListaVacia()? nullptr : primero);

    //Si la lista está vacia...
    if(ListaVacia()){
        //El puntero al primer elemento de la lista hacemos que
        //apunte al nuevo elemento
        primero = nuevo;
        //El puntero al ultimo elemento de la lista hacemos que
        //apunte al nuevo elemento
        ultimo = nuevo;
    }
    //Si la lista NO está vacía...
    else{
        //Hacemos que el puntero al primer elemento de la lista apunte ahora al nuevo.
        primero = nuevo;
    }
    //Incrementamos el contador de datos.
    ++tam;
}

template <typename T>
void Lista<T>::AgregarFinal(const T &v)
{
    //Creamos un nuevo contenedor donde estará nuestro dato.
    Elemento * nuevo = new Elemento(v);
    //Si la lista está vacia...
    if(ListaVacia())
    {
        //Hacemos que el puntero al primer elemento apunte al nuevo.
        primero = nuevo;
        //Hacemos que el puntero al ultimo elemento apunte al nuevo.
        ultimo = nuevo;
    }
    //Si la lista NO está vacia...
    else
    {
        //Agregamos el nuevo elemento al FINAL de la lista.
        ultimo->siguiente = nuevo;
        //Ahora que el puntero al último elemento apunte al nuevo.
        ultimo = nuevo;
    }
    //Incrementamos el tamaño
    ++tam;
}

template <typename T>
void Lista<T>::AgregarEnPos(const T &v, int ind)
{
    //Si el indice proporcionado se encuentra fuera del rango
    // 0 - tamaño actual de la lista...
    //Tiramos un error bien kamikaze
    if(ind < 0 || ind > tam) throw FueraDeRango();
    //Si el índice proporcionado es 0 pues mandamos a agregar al principio.
    if(ind == 0)
    {
        AgregarInicio(v);
    }
    //Si el índice es igual al tamaño -1 datos mandamos a
    //agregar al final.
    else if(ind == tam-1) AgregarFinal(v);
    else //Si ninguno de los casos anteriores se cumple se hace lo siguiente...
    {
        //Creamos un puntero que apunte al primer elemento de la lista.
        Elemento * ant = primero;

        //vamos a recorrer el puntero hasta encontrar la posición deseada.
        for(int i = 1; i < ind; ++i) ant = ant->siguiente;

        //Creamos un puntero que contenga el nuevo dato
        //Y que su siguiente sea el siguiente elemento del elemento
        //donde nos encontramos.
        Elemento * nuevo = new Elemento(v, ant->siguiente);

        //Ahora hacemos que el siguiente elemento del puntero
        //"ant" apunte al nuevo elemento.
        ant->siguiente = nuevo;

        //Incrementamos el tamaño
        ++tam;
    }
}

template <typename T>
void Lista<T>::EliminarInicio()
{
    //Si la lista no está vacía procedemos a...
    if(!ListaVacia()){
            //Si el siguiente del primero es null, es decir, solo hay un dato.
        if(primero->siguiente == nullptr){
            //Eliminamos el dato.
            delete primero;
            //Ahora que a donde apunta el primero que sea null y de igual manera con el puntero al último.
            primero = nullptr;
            ultimo = nullptr;
        }
        //Si la lista tiene más de un dato...
        else{
            //Hacemos un puntero auxiliar que apunte a la dirección del elemento que queremos quitar de la lista
            //En este caso el primero.
            Elemento * porBorrar = primero;
            //Recorremos el el puntero del primero a su siguiente.
            primero = primero->siguiente;
            //Borramos la información del puntero auxiliar.
            delete porBorrar;
        }
        //Le quitamos uno al contador.
        --tam;
    }
    //Si la lista ESTÁ vacía lanzamos una excepción bien kamikaze.
    else throw listaVacia();
}

template <typename T>
void Lista<T>::EliminarFinal()
{
    //Si la lista está vacía lanzamos la excepción.
    if(ListaVacia()) throw listaVacia();
    //Si solo hay un dato en la lista, simplemente mandamos a eliminar al inicio,
    //ya que tenemos instrucciones en ese método que tiene este caso. (simplemente para no repetir código).
    if(tam == 1){
        EliminarInicio();
    }
    //Si la lista tiene más de un elemento.
    else{
        //Creamos un puntero auxiliar que se recorrerá hasta el penúltimo dato de la lista.
        Elemento * ant = primero;
        while(ant->siguiente != ultimo) ant = ant->siguiente;
        //Lo mismo de ahorita, creamos un puntero que apunte a la misma dirección del puntero "último".
        Elemento * porBorrar = ultimo;
        //Hacemos que el puntero "ultimo" ahora apunte al penúltimo dato.
        ultimo = ant;
        //Desconectamos el penúltimo dato del último.
        ultimo->siguiente = nullptr;
        //Eliminamos el puntero junto con la información a donde esté apuntando.
        delete porBorrar;
        //Restamos 1 al contador.
        --tam;
    }
}

template <typename T>
void Lista<T>::EliminarEnPos(int ind)
{
    //Si la lista está vacía lanzamos la excepción.
    if(ListaVacia()) throw listaVacia();
    //Si el índice proporcionado no es válido lanzamos la excepción
    //"Fuera de Rango"
    if(ind < 0 || ind > tam) throw FueraDeRango();
    //Si el índice proporcionado es el del primer dato mandamos a eliminar al inicio.
    if(ind == 0) EliminarInicio();
    //Si el índice proporcionado es el del último dato mandamos a eliminar al final.
    else if(ind == tam) EliminarFinal();
    //Si ninguno de los casos de arriba se cumple procedemos a...
    else
    {
        //Puntero auxiliar para recorrerlo hasta el dato de previo al que queremos eliminar.
        Elemento * ant = primero;
        for(int i = 0; i < ind-1; ++i) ant = ant->siguiente;

        //Puntero aux que contendrá el dato que querrémos eliminar.
        Elemento * porBorrar = ant->siguiente;
        //Conectamos el dato anterior al dato que queremos eliminar con el dato que está después del dato que queremos eliminar.
        ant->siguiente = porBorrar->siguiente;
        //Borramos el puntero que contiene la información del dato a eliminar.
        delete porBorrar;
        //Restamos 1 al tamaño
        --tam;
    }
}

template <typename T>
void Lista<T>::EliminarPrimeraOcurrencia(const T &v)
{
    //Si la lista está vacía pues lanzamos la excepción
    if(ListaVacia()) throw listaVacia();
    //Si el dato NO se encuentra en la lista lanzamos excepción de que el dato no se ha encontrado.
    if(!Buscar(v)) throw ValorNoEncontrado();

    int i = 0;
    Elemento * aux = primero;

    //Mientras el puntero aux no sea igual a null hacemos...
    while(aux != nullptr){

        //Si el dato a donde esté apuntando el auxiliar es el que andamos buscando para eliminarlo.
        if(aux->dato == v){
            //Mandamos el índice del dato encontrado para eliminarlo.
            EliminarEnPos(i);
            //Terminamos el método.
            return;
        }
        //Si el dato que contiene la dirección de memoria a donde el puntero auxiliar está apuntando no es el que queremos borrar...
        else{
            //incrementamos el índice y recorremos el puntero auxiliar.
            ++i;
            aux = aux->siguiente;
        }
    }
}

template <typename T>
void Lista<T>::EliminarTodaOcurrencia(const T &v)
{
    //Nos aseguramos de las cosas básicas.
    if(ListaVacia()) throw listaVacia();
    if(!Buscar(v)) throw ValorNoEncontrado();

    //Mientras siga habiendo un dato igual al que recibimos como parámetro...
    while(Buscar(v)){
        //Eliminamos ese dato.
        EliminarPrimeraOcurrencia(v);
    }
}

template <typename T>
bool Lista<T>::Buscar(const T &v) const
{
    //Si la lista está vacía, lanzamos la amazing excepción.
    if(ListaVacia()) throw listaVacia();

    //Puntero que usaremos para recorrelo por toda la lista.
    Elemento * aux = primero;

    //Mientras el puntero no apunte a null
    while(aux != nullptr){

        //Si el dato que se encuentra en la dirección de memoria en la que el puntero auxiliar sea igual al que recibimos
        //como parámetro, retornamos True, ya que si está ese dato en la lista.
        if(aux->dato == v){
            return true;
        }
        //Recorremos el puntero en caso de que no se cumpla lo anterior.
        aux = aux->siguiente;
    }

    //Si no se regresa ningún True pues lanzamos un False, diciendo que no enctramos el dato.
    return false;
}

template <typename T>
int * Lista<T>::BuscarPosicion(const T &v) const
{
    if(ListaVacia()) throw listaVacia();
    if(!Buscar(v)) throw ValorNoEncontrado();

    //Variables que se usarán en el proceso de búsqueda de la posición del valor que queremos encontrar.
    int i = 0;

    Elemento * aux = primero;

    while(aux != nullptr){

        //Si encontramos el dato lo agregamos al array donde
        //estarán la información de las posiciones de uno o más datos. (siempre y cuando sean iguales).
        if(aux->dato == v){
            return i;
        }
            //Recorremos.
        aux = aux->siguiente;
        ++i;
    }
}


template <typename T>
bool Lista<T>::ListaVacia() const
{
    //Evaluamos si el puntero al primer elemento de la lista
    //apunta a null, encontes significa que no hay elementos
    //en la lista.
    return primero == nullptr;
}

template <typename T>
const T &Lista<T>::Primero() const
{
    //Si la lista está vacía lanzamos la excepción.
    if(ListaVacia()) throw listaVacia();

    //Regresamos el dato que está al principio de la lista.
    return primero->dato;
}

template <typename T>
const T &Lista<T>::Ultimo() const
{
    //Si la lista está vacía, lanzamos excepción.
    if(ListaVacia()) throw listaVacia();

    //Regresamos el dato que está hasta el final de la lista.
    return ultimo->dato;
}

template <typename T>
const T &Lista<T>::ValorEnPosicion(int ind) const
{
    if(ListaVacia()) throw listaVacia();

    //Recorreremos el puntero hasta donde queremos y después regresamos el dato.
    Elemento * ant = primero;
    for(int i = 1; i < ind; ++i) ant = ant->siguiente;
    return ant->dato;
}

template <typename T>
void Lista<T>::ModificarElem(const int ind, const T &v)
{
    (*this)[ind] = v;
}

template <typename T>
int Lista<T>::Tamanio() const
{
    return tam;
}

template <typename T>
void Lista<T>::Vaciar()
{
    //Mientras la lista NO esté vacía eliminamos desde el inicio.
    //todas las veces que sean necesarias.
    while(!ListaVacia()){
        EliminarInicio();
    }
}

template <typename T>
void Lista<T>::Imprimir() const
{
    if(ListaVacia()) throw listaVacia();
    Elemento * aux = primero;
    while(aux != nullptr){
        std::cout << "[" << aux->dato << "]";
        aux = aux->siguiente;
    }
}

//*********************************************************************
// Sobrecarga de operaciones //

template <typename T>
const T &Lista<T>::operator[](const int ind) const
{
    if(ListaVacia()) throw listaVacia();
    if(ind < 0 || ind >= tam) throw FueraDeRango();
    Elemento * actual = primero;
    for(int i = 1; i <= ind; ++i){
        actual = actual->siguiente;
    }
    return actual->dato;
}

template <typename T>
T & Lista<T>::operator[](const int ind)
{
    if(ListaVacia()) throw listaVacia();
    if(ind < 0 || ind >= tam) throw FueraDeRango();
    Elemento * actual = primero;
    for(int i = 1; i <= ind; ++i){
        actual = actual->siguiente;
    }
    return actual->dato;
}

//*********************************************************************//
// Excepciones //

template <typename T>
const char * Lista<T>::listaVacia::what() const throw()
{
    return "La lista est\240 vacia";
}

template <typename T>
const char * Lista<T>::FueraDeRango::what() const throw()
{
    return "Valor fuera de rango.";
}

template <typename T>
const char * Lista<T>::ValorNoEncontrado::what() const throw()
{
    return "Valor no encontrado.";
}





// ~Mephisto
