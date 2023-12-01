#include "ListaDoble.h"

//Este es el constructor por default.
template <typename T>
ListaDoble<T>::ListaDoble(): tam(0), primero(nullptr), ultimo(nullptr){}

//Este es el constructor de copias
template <typename T>
ListaDoble<T>::ListaDoble(const ListaDoble<T> &LD) : tam(0), primero(nullptr), ultimo(nullptr)
{
    //Tan sencillo como para igualar la instancia a la lista que le pasemos
    //Aquí estamos generando una copia.
    *this = LD;
}

//Sobrecargamos el operador de igualación "="
template <typename T>
ListaDoble<T> & ListaDoble<T>::operator=(const ListaDoble<T> &LD)
{
    //Checamos si la lista de la instancia es la misma que la del parámetro, en caso de que así pues la devolvemos
    //En caso de que no pues pasamos.
    if(this == &LD) return *this;

    //Vaciamos la lista (la de la instancia)
    VaciarLista();
    //Creamos un puntero tipo elemento auxiliar para ir paseando entre los elementos de la lista pasada como parámetro.
    Elemento * aux = LD.primero;
    //Esto se cliclará hasta que nuestro puntero llegue hasta lo último
    //Es decir, hasta cuando ya no haya nada.
    while(aux != nullptr){
        //Agregamos a la lista de la instancia el dato de la lista pasada como parámetro.
        AgregarFinal(aux->dato);
        //Recorremos el puntero para que tener la dirección de memoria del siguiente dato.
        aux = aux->siguiente;
    }
    //Una vez agregados los datos pues regresamos la lista de la instancia
    //Que es a la que le estábamos agregando los datos de la otra lista.
    return *this;
}

//Destructor. Esto nomas libera espacio en memoria para cuando a la hora de ejecución no se llene de basura nuestra memoria.
template <typename T>
ListaDoble<T>::~ListaDoble()
{
    //Aquí simplemente vaciamos la lista.
    VaciarLista();
}

//Agregar al principio de la lista.
template <typename T>
void ListaDoble<T>::AgregarPrincipio(const T &v)
{
    //Creamos un puntero que apunte un nuevo elemento, introduciremos en ese elemento el valor que nos pasaron.
    //Ahora, dependiendo de que si la lista está vacía o no es a donde apuntará al siguiente, como es el principio de la lista
    //pues su puntero "anterior" apuntará a null porque no hay nada que enlazarle ahí.
    Elemento * nuevo = new Elemento(v, listaVacia()? nullptr : primero, nullptr);
    //Si la lista está vacía conectamos el puntero del primero y último elemento al nuevo elemento creado.
    if(listaVacia()){
        primero = nuevo;
        ultimo = nuevo;
    }
    //Si la lista NO está vacía conectaremos el primero que se encuentre actualmente haciendo uso del puntero "anterior" de ese elemento
    //Y ahora como tenemos un nuevo "primer" dato pues conectamos el puntero "primero" al nuevo.
    else{
        primero->anterior = nuevo;
        primero = nuevo;
    }

    //Incrementamos el tamaño ya que agregamos un nuevo elemento a la lista.
    ++tam;
}

//Agregar al final de la lista.
template <typename T>
void ListaDoble<T>::AgregarFinal(const T &v)
{
    //Al igual que el anterior método en este es obvio que el siguiente elemento del último no existe, es decir, el siguiente del último apunta
    //a null, entonces ahora dependiendo si la lista está vacía o no, vamos a conectar el ANTERIOR del elemento nuevo al último que esté actualmente.
    //Si la lista no está vacía pues apuntará a null.
    Elemento * nuevo = new Elemento(v, nullptr, listaVacia()? nullptr : ultimo);
    //Si la lista está vacía conectamos el puntero del primero y último elemento al nuevo elemento creado.
    if(listaVacia()){
        ultimo = nuevo;
        primero = nuevo;
    }
    //Si la lista NO está vacía lo que se hará es que conectaremos el siguiente del último dato actual al nuevo
    //Y ahora conectaremos el puntero "último" al nuevo elemento.
    else{
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
    }

    //Incrementamos el tamaño porque agregamos un nuevo elemento a la lista.
    ++tam;
}

//Agregar en una posición específica.
template <typename T>
void ListaDoble<T>::AgregarEnPos(const T &v, int ind)
{
    //Si el índice que nos dieron es menor a 0 o el índice que nos dieron es mayor al tamaño de la lista pues truena KABOOM.
    if(ind < 0 || ind > tam) IndiceInvalido();
    //Si el índice es 0, significa que irá al frente de la lista.
    //Pero como ya tenemos un método que agrega al principio pues hacemos uso de este, ¿te late?
    if(ind == 0){
        AgregarPrincipio(v);
    }
    //Si el índice es igual al tamaño de la lista significa que irá al final de la lista,
    //pero ya tenemos un método que agrega al final, entonces nomas lo mandamos a llamar pasándole el valor, ¿cómo te quedó el ojo?
    else if(ind == tam){
        AgregarFinal(v);
    }
    //Si indice está entre 0 y el tamaño de la lista se hace lo siguiente.
    else{
        //Declaramos un puntero para recorrer
        Elemento * aux = primero;

        //Recorremos ese puntero tantas veces como diga el índice que nos pasaron
        for(int i = 1; i < ind; ++i) aux = aux->siguiente;

        //Una vez encontrado el lugar
        //Creamos un nuevo elemento, con su valorsito
        Elemento * nuevo = new Elemento(v, aux->siguiente, aux);

        //Hacemos que el siguiente del anterior del puntero auxiliar apunte al nuevo elemento.
        aux->siguiente->anterior = nuevo;
        //Ahora que el siguiente del auxiliar apunte a nuestro nuevo elemento.
        aux->siguiente = nuevo;
        //Incrementamos el tamaño de la lista porque agregamos un nuevo elemento.
        ++tam;
    }
}

//Eliminar primer elemento de la lista.
template <typename T>
void ListaDoble<T>::EliminarPrincipio()
{
    //Si la lista está vacía... oh oh...
    if(listaVacia()) throw ListaVacia();
    //Creamos un puntero auxiliar.
    Elemento * aux = primero;
    //Hacemos que el puntero "primero" de la clase apunte al siguiente elemento del primer elemento.
    //para desconectarlo y eliminarlo agusto pues.
    primero = aux->siguiente;
    //Si el puntero "primero" de nuestra clase apunta a null entonces también lo debe de hacer el último.
    //Así que hacemos que "ultimo" apunte a null
    if(primero == nullptr) ultimo = nullptr;
    //Si no es el caso hacemos que el anterior del primer elemento apunte a null para descontectarlo
    //100% machín y ahora sí como está desconectado pues GG, se va ese elemento.
    else primero->anterior = nullptr;
    //Le restamos 1 al tamaño de la lista porque sacamos un elemento de ella.
    --tam;
}

//Eliminar último elemento de la lista.
template <typename T>
void ListaDoble<T>::EliminarFinal()
{
    //Si la lista está vacía.. oh oh...
    if(listaVacia()) throw ListaVacia();
    //Si primero y ultimo apuntan a donde mismo pues solo le hacemos un delete
    //Y hacemos que tanto el primero como el último apunten a null.
    if(primero == ultimo){
        delete primero;
        primero = ultimo = nullptr;
    }
    //Si no es caso pues...
    else{
        //Creamos puntero auxiliar que apunte al anterior elemento del último elemento.
        Elemento * aux = ultimo->anterior;
        //Hacemos que el siguiente elemento de donde esté el auxiliar valga null
        //así desconectaríamos ese elemento de la lista más no al 100%
        aux->siguiente = nullptr;
        //Eliminamos a lo que apunte "ultimo".
        delete ultimo;
        //Ahora hacemos que "último" apunte a nuestro nuevo "ultimo".
        ultimo = aux;
    }
    --tam;
}

//Eliminar en una posición específica.
template <typename T>
void ListaDoble<T>::EliminarEnPos(int ind)
{
    //Si la lista está vacía GG.
    if(listaVacia()) throw ListaVacia();
    //Si el índice no corresponde o no cae entre 0 y el tamaño de la lista GG.
    if(ind < 0 || ind >= tam) throw IndiceInvalido();
    //Si el índice es 0 pues mandamos a eliminar al principio. Joya.
    if(ind == 0)
    {
        EliminarPrincipio();
    }
    //Si el índice es igual a tamaño-1, porque el conteo empieza en 0, por eso tam-1
    //Pues peladamente mandamos a eliminar al final.
    else if(ind == tam-1)
    {
        EliminarFinal();
    }
    //Si el índice no ni el principio ni el final pues...
    else{
        //Here we go again...
        Elemento * aux = primero;
        //Recorremos.
        for(int i = 1; i < ind; ++i) aux = aux->siguiente;

        //Otro puntero auxiliar que apuntará al elemento que deseamos borrar.
        //Lo hacemos que apunte al siguiente del auxiliar.
        Elemento * porBorrar = aux->siguiente;
        //Ahora que el siguiente del auxiliar apunte al siguiente del puntero del elemento
        //que queremos borrar.
        aux->siguiente = porBorrar->siguiente;
        //Hacemos que el siguiente del anterior del elemento que queremos borrar apunte ahora
        //al elemento anterior del elemento que queremos borrar.
        porBorrar->siguiente->anterior = aux;
        //eliminamos el puntero que contenía la información que queríamos sacar.
        delete porBorrar;
        //Le quitamos 1 al tamaño de la lista porque eliminamos un elemento.
        --tam;

    }
}

//Buscar elemento
template <typename T>
bool ListaDoble<T>::Buscar(const T &v) const
{
    //Si la lista está vacía pues GG.
    if(listaVacia()) throw ListaVacia();

    //YAAA NO QUIERO MÁS AUXILIARESSS
    Elemento * aux = primero;
    //Iremos recorriendo el puntero hasta encontrar el dato que estamos buscando
    //Si lo encontramos regresamos True (#t) si no está el wason pues un false de chill (#t)
    while(aux != nullptr){
        if(aux->dato == v){
            return true;
        }
        aux = aux->siguiente;
    }
    return false;

}

//Posición del valor.
template <typename T>
int ListaDoble<T>::PosicionDelValor(const T &v) const
{
    //Si la lista está vacía mandamos un -1. o sea, no está GG pues, porque tenemos que regresar un entero a fuerza.
    if(listaVacia()) return -1;
    //Si la lista tiene cositas...
    else{
        //...
        Elemento * aux = primero;
        for(int i = 0; i < Tamanio(); ++i){
            //Si encontramos el valor pues le regresamos el i donde estaba el canijo.
            if(aux->dato == v) return i;
            //Si no pues simplemente vamos recordando.
            aux = aux->siguiente;
        }
        //Si el dato no está pues GG, regresamos un -1, como que no lo encontramos. Ni pedo.
        return -1;
    }
}

//La lista está vacía?
template <typename T>
bool ListaDoble<T>::listaVacia() const
{
    //Regresa simplemente si el primero apunta a null, es decir, si el primero no apunta a un elemento
    //Quiere decir que no hay elementos pues, pero si si hay elementos y primero apunta a null
    //pues GG para ti, así que ten cuidado.
    return primero == nullptr;
}

//Primer valor
template <typename T>
const T & ListaDoble<T>::PrimerValor() const
{
    //Si la lista está vacía GG.
    if(listaVacia()) throw ListaVacia();
    //Mandamos el valor donde este apuntando "primero". Papita.
    return primero->dato;
}

//Ultimo valor
template <typename T>
const T & ListaDoble<T>::UltimoValor() const
{
    //Si la lista está vacía GG.
    if(listaVacia()) throw ListaVacia();
    //Regresamos el valor donde esté apuntando "ultimo". Papita.
    return ultimo->dato;
}

//Valor en posición
template <typename T>
const T & ListaDoble<T>::ValorEnPos(int ind) const
{
    //Si la lista está vacía GG.
    if(listaVacia()) throw ListaVacia();
    //Si el índice no corresponde con nuestra lista GG.
    if(ind < 0 || ind > tam) throw IndiceInvalido();
    //Si el índice es 0 pues mandamos el primero.
    if(ind == 0) return PrimerValor();
    //Si el índice es igual al tamaño-1 de la lista pues le mandamos el último elemento.
    else if(ind == tam-1) return UltimoValor();
    //Si nada de aquello entonces esto...
    else{
        //quiero morir...
        Elemento * aux = primero;
        for(int i = 0; i < ind; ++i) aux = aux->siguiente;
        //Regresamos el valor a donde "aux" apunte.
        return aux->dato;
    }
}

//Modificar valor
template <typename T>
void ListaDoble<T>::ModificarValor(int ind, const T &v)
{
    //Si el índice que nos da no corresponde GG.
    if(ind < 0 || ind > tam) throw IndiceInvalido();
    // ToT
    Elemento * aux = primero;
    for(int i = 0; i < ind; ++i) aux = aux->siguiente;
    //Ahora hacemos que el dato a donde apunte aux sea igual al valor que nos pasaron.
    aux->dato = v;
}

//Tamaño (dice Tamanio pq no jala la ñ)
template <typename T>
int ListaDoble<T>::Tamanio() const
{
    //Solo regresamos lo que tenga nuestro contador pue.
    return tam;
}

//Vaciar lista.
template <typename T>
void ListaDoble<T>::VaciarLista()
{
    //Esto pues papita, si la lista no está vacía pues vamos a ir eliminando cositas.
    while(!listaVacia()) EliminarPrincipio();
}

//Imprimir ascendente
template <typename T>
void ListaDoble<T>::ImprimirAscendente() const
{
    //Si la lista está vacía pues imprimimos "()".
    std::cout << "(";
    if(listaVacia()){
        std::cout << ")";
    }
    //Si la lista no está vacía pues al merequetengue.
    else{
        //._.
        Elemento * aux = primero;
        while(aux != nullptr){
            //Vamos imprimiendo un dato de esta forma "dato, ", recorremos el auxiliar y así hasta que se nos acaben los datos.
            std::cout << aux->dato << ", ";
            aux = aux->siguiente;
        }
        //Al final nos quedaría algo así (..., ), así que usamos la mágica \b para quitar ese espacio y "coma"
        //Y pues su paréntesis al final. wonito.
        std::cout << "\b\b)";
    }
}

//Imprimir Descendente.
template <typename T>
void ListaDoble<T>::ImprimirDescendente() const
{
    //Lo mismo de lo anterior
    std::cout << "(";
    if(listaVacia()){
        std::cout << ")";
    }
    else{
        //Esto si cambia porque como queremos imprimir desde el último al primero pues ahora
        //empezamos desde el último elemento y así.
        Elemento * aux = ultimo;
        while(aux != nullptr){
            std::cout << aux->dato << ", ";
            aux = aux->anterior;
        }
        std::cout << "\b\b)";
    }
}

//Sobrecarga del operador "[]" LECTURA
template <typename T>
const T & ListaDoble<T>::operator[](const int ind) const
{
    //Aquí solo regresamos el valor en la posición que nos dijeron. fa-ci-li-to ~ Kay/O.
    return ValorEnPos(ind);
}

//Sobrecarga del operador "[]" ESCRITURA
template <typename T>
T& ListaDoble<T>::operator[](const int ind)
{
    //Lo mismo de la anterior sobrecarga.
    return ValorEnPos(ind);
}

//Eliminar toda ocurrencia.
template <typename T>
void ListaDoble<T>::EliminarTodaOcurrencia(const T &v)
{
    //Si la lista está vacía GG.
    if(listaVacia()) throw ListaVacia();
    //Si el desgraciado valor sigue en la lista lo mandamos a levantar.
    while(Buscar(v)) EliminarEnPos(PosicionDelValor(v));
}

//Eliminar por condición.
template <typename T>
void ListaDoble<T>::EliminarPorCondicion(bool (*condicion) (T))
{
    //Este está chilo.

    //Si la lista está vacía GG.
    if(listaVacia()) throw ListaVacia();
    //Mismo puntero y otro además que necesitaremos que no apunte a nada de momento.
    Elemento * aux = primero;
    Elemento * borrar;
    //Mientras el auxiliar no apunte a null todo bien.
    while(aux != nullptr){
        //Ahora, dependiendo de la condición que nos pasen con respecto al dato donde apunte el auxiliar...
        if(condicion(aux->dato)){
            //borraremos ese dato.
            borrar = aux;
            //recorremos el auxiliar.
            aux = aux->siguiente;
            //Y mandamos a borrar ese valor.
            EliminarEnPos(PosicionDelValor(borrar->dato));
        }
        //Si la condición no se cumple pues simplemente recorremos el puntero.
        else{
            aux = aux->siguiente;
        }
    }
}

//Elimminar repeticiones.
template <typename T>
void ListaDoble<T>::EliminarRepeticiones()
{
    //Mismo puntero aaaaa
    Elemento * aux = primero;
    //Mientras nuestro puntero aux no apunte a null
    while(aux != nullptr){
        //Otro puntero aux que apunte al mismo sitio que el primer auxiliar
        Elemento * aux2 = aux;
        //Mientras el siguiente del aux2 no apunte a null.
        while(aux2->siguiente != nullptr){
            //Si el dato del siguiente del auxiliar 2 es igual dato al que auxiliar 1 apunta
            if(aux2->siguiente->dato == aux->dato){
                //Creamos un puntero temporal (también pude llamarle "porBorrar").
                //que apunte al siguiente del auxiliar.
                Elemento * temp = aux2->siguiente;
                //Hacemos que el siguiente del auxiliar 2 apunte al
                //siguiente del siguiente de ese auxiliar.
                aux2->siguiente = aux2->siguiente->siguiente;
                //Lanzamos el puntero temp a la basura.
                delete temp;
                //Reducimos el tamaño de la lista porque quitamos un elemento.
                --tam;
            }
            //Si no, recorremos el puntero al siguiente elemento.
            else{
                aux2 = aux2->siguiente;
            }
        }
        //Recorremos el puntero al siguiente elemento.
        aux = aux->siguiente;
    }
}

//Ordenar
template <typename T>
void ListaDoble<T>::Ordenar()
{
    //Esto está aún más chilo.

    //Necesitamos una lista auxiliar que será la que ordenaremos.
    ListaDoble<T> LisOrdenada;
    //Mismo puntero...............
    Elemento * aux = primero;
    //Mientras el puntero no apunte a null
    while(aux != nullptr){
        //Vamos agregando el valor a la lista aux pero espera...
        //Un nuevo agregar?
        //Está en la última parte!
        //Es un Ordenar Secreto... sh...
        LisOrdenada.AgregarOrdenado(aux->dato);
        //Recorremos el puntero auxiliar.
        aux = aux->siguiente;
    }
    //Igualamos la lista de la instancia con la lista ordenada.
    //Esto haciendo que nuestra lista ahora esté ordenada. JOYA
    *this = LisOrdenada;
}

//Cambiar.
template <typename T>
void ListaDoble<T>::Cambiar(ListaDoble<T> &L)
{
    //Tomamos una lista auxiliar que sea idéntica a la lista que nos pasen como parámetro.
    ListaDoble<T> LisAux = L;
    //Igualamos esa lista que nos pasaron con la de la instancia.
    L = *this;
    //Ahora la lista de la instancia la igualamos a la auxiliar.
    //De esta manera hemos intercambiado las listas!!! WOWOWOWOWOWO UwU
    *this = LisAux;
}

//Transferir 1
template <typename T>
void ListaDoble<T>::Transferir(ListaDoble<T> &L, int ini, int fin)
{
    //Si los índices no concuerdan con la lista GG.
    if(ini > fin || ini < 0 || fin > L.Tamanio()) throw IndiceInvalido();
    //Usarémos un for que empiece en el inicio hasta que sea igual al índice del final
    for(int i = ini; i < fin; ++i){
        //Vamos agregando al final los valores que empiecen del índice ini hasta el índice fin
        AgregarFinal(L.ValorEnPos(ini));
        //vamos a ir eliminando los valores de la lista del parámetro.
        L.EliminarEnPos(ini);
    }
}

//Transferir 2
template <typename T>
void ListaDoble<T>::Transferir(ListaDoble<T> &L, int ini)
{
    //Mandamos a llamar el transferir 1 pero solo desde el indice ini hasta el último elemento.
    Transferir(L, ini, L.Tamanio());
}

//Transferir 3
template <typename T>
void ListaDoble<T>::Transferir(ListaDoble<T> &L)
{
    //Mandamos a llamar el Transferir 1 para que transfiera TODOS los elementos de la lista que nos pasen
    //a la lista de la instancia.
    Transferir(L, 0, L.Tamanio());
}

//AGREGAR ORDENADO ****
template <typename T>
void ListaDoble<T>::AgregarOrdenado(const T &v)
{
    //Tomamos varios casos
    //si el primer apunta a null pues lo agregamos al principio.
    //Si el valor es menor o igual al dato que está al frente lo colocamos a su izquierda.
    //Si el valor es mayor o igual al dato que está al final lo colocamos a su derecha.
    //Si no es ninguno de los casos...
    Elemento * nuevo = new Elemento(v);
    if(primero == nullptr){
        primero = nuevo;
        ultimo = nuevo;
    }else if(v <= primero->dato){
        nuevo->siguiente = primero;
        primero->anterior = nuevo;
        primero = nuevo;
    }else if(v >= ultimo->dato){
        nuevo->anterior = ultimo;
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
    }else{
        //Puntero aux que apunte al siguiente del primero.
        Elemento * aux = primero->siguiente;
        //Vamos recorriendo hasta que el dato al que apunta el auxiliar sea mayor o igual que el valor
        //que queremos agregar
        while(aux->dato < v){
            aux = aux->siguiente;
        }
        //Una vez encontremos donde debe de ir lo colocamos con las siguientes instrucciones.
        //El anterior del nuevo que apunte al anterior del auxiliar.
        nuevo->anterior = aux->anterior;
        //Que el siguiente del nuevo apunte a donde apunte el auxiliar,
        nuevo->siguiente = aux;
        //Que el siguiente del anterior del auxiliar apunte al nuevo.
        aux->anterior->siguiente = nuevo;
        //Que el anterior del auxiliar apunte al nuevo.
        aux->anterior = nuevo;
    }
}

//Método para error Lista vacía.
template <typename T>
const char * ListaDoble<T>::ListaVacia::what() const throw()
{
    return "La lista se encuentra vacia.";
}

//Método para error de Índice inválido.
template <typename T>
const char * ListaDoble<T>::IndiceInvalido::what() const throw()
{
    return "Indice invalido.";
}








// ~Mephisto
