#include <iostream>
#include "ColaCircular.h"

//Bueno ya se la saben, celulares y carteras
//Ya en serio, este es el último código, que subiré porque lo demás está más cabrón
//o sea, lo tengo, pero lo chilo es echarle coco a los otros.
//Ya saben como funciona estos 4 métodos, son los que "garantizan el correcto funcionamiento de nuestra clase"
template <typename T>
ArbolBB<T>::ArbolBB() : numNodos(0), raiz(nullptr){}

template <typename T>
ArbolBB<T>::ArbolBB(const ArbolBB<T> &ABB)
{
    *this = ABB;
}

template <typename T>
ArbolBB<T> & ArbolBB<T>::operator=(const ArbolBB<T> &ABB)
{
    if(this == &ABB) return *this;

    vaciarArbol();

    copiarPreorden(ABB.raiz);

    return *this;
}

template <typename T>
ArbolBB<T>::~ArbolBB()
{
    vaciarArbol();
}

//**********************************************************************
//Esto pues poco más, lo chilo son los métodos privados, agárrense de su silla
//porque se van a ir para atrás.

template <typename T>
void ArbolBB<T>::agregar(T v)
{
    agregarPriv(raiz, v);
}

template <typename T>
void ArbolBB<T>::eliminar(T v)
{
    eliminarPriv(raiz, v);
}

template <typename T>
bool ArbolBB<T>::buscar(T v)
{
    return buscarPriv(raiz, v);
}

template <typename T>
void ArbolBB<T>::podarSubArbol(T v)
{
    if(!buscar(v)){
        std::cout << "El elemento no se encuentra en el \xA0rbol" << std::endl;
        return;
    }

    podarPriv(encontrar(raiz,v));
}

template <typename T>
bool ArbolBB<T>::arbolVacio() const
{
    return (numNodos == 0);
}

template <typename T>
void ArbolBB<T>::imprimirAscendente() const
{
    imprimirInorden(raiz);
}

template <typename T>
void ArbolBB<T>::imprimirDescendente() const
{
    imprimirInordenInv(raiz);
}

template <typename T>
void ArbolBB<T>::imprimirPorNiveles() const
{
    imprimirPorNivel(raiz);
}


//*******************************************************

//Método para agregar nodos, lesfakingooo
template <typename T>
void ArbolBB<T>::agregarPriv(Nodo * &r, T v)
{
    //checamos si nuestro árbol está vacío
    if(r == nullptr){
        //Si sí está vacío entonces agregamos un nuevo nodo y conectamos el puntero raíz con el nuevo dato.
        r = new Nodo(v);
        //Incrementamos el número de nodos
        ++numNodos;
    }else{

        //recursividad linda y bonita, si el valor que nos pasan es más pequeño que el dato a donde raíz apunte pues mandamos
        //como hijo izquierdo, si no pues al lado derecho, ya se imaginan el arbolito?
        if(v < r->nodo) agregarPriv(r->hijoIzq, v);
        else if (v > r->nodo) agregarPriv(r->hijoDer, v);
    }

}

template <typename T>
bool ArbolBB<T>::eliminarPriv(Nodo * &r, T v)
{

    //Si nuestra árbol no tiene nada pues le tiramos un false diciendo que no eliminamos nada.
    if(r == nullptr) return false;

    //Si encontramos el nodo que queremos borrar...
    if(r->nodo == v){

        //Nodo por borrar que ya se la saben
        Nodo * porBorrar = r;

        //si a donde apunte r es una hoja pues no hay problema, solamente eliminamos el nodo, facilito.
        if(r->EsHoja()){

            r = nullptr;

        //Si el nodo de la raiz tiene solo hijo izquierdo pues hacemos que nuestra
        //r apunte a él para poder eliminar al que queremos y que no se pierda el nodo.
        }else if(r->soloHI()){

            r = porBorrar->hijoIzq;

        //Misma historia solo que con el hijo derecho.
        }else if(r->soloHD()){

            r = porBorrar->hijoDer;

        //aquí es cuando tiene ambos hijos, en este caso irémos a buscar al
        //mayor del subarbol del hijo izquierdo
        }else{
            //Aquí mandamos a doxear al mayor
            Nodo * &dirMax = obtenerMayor(r->hijoIzq);
            //ya que lo encontremos hacemos que ahora el mayor lo sustituya por el que
            //estaba apuntando r, porque ya se saben el algoritmo, sino se lo saben
            //pues a chambiar.
            r->nodo = dirMax->nodo;
            //y lo mandamos a levantar que no,
            return eliminarPriv(dirMax, dirMax->nodo);

        }
        //baneamos al puntero porBorrar
        delete porBorrar;
        //disminuimos la cantidad de nodos en el árbol
        --numNodos;
        //Avisamos que si eliminamos algo.
        return true;
    //Ahora bien, estas dos últimas consideraciones es para buscar el nodo, si el valor
    //es menor al que andamos buscando pues nos vamos pa la izquierda, sino, pa la derecha.
    }else if(v < r->nodo){

        return eliminarPriv(r->hijoIzq, v);

    }else{

        return eliminarPriv(r->hijoDer, v);

    }
}

template <typename T>
void ArbolBB<T>::podarPriv(Nodo * &r)
{
    //Si no hay nada en el arbol pues GG
    if(arbolVacio()) std::cout << "El \xA0rbol est\xA0 vacio" << std::endl;

    //vamos a usar la maravillosa recursividad para ir rebanando el árbol nodo x nodo.
    //durísimo.
    if(r != nullptr){

        if(r->tieneHI()) podarPriv(r->hijoIzq);
        if(r->tieneHD()) podarPriv(r->hijoDer);
        delete r;
        r = nullptr;
        --numNodos;
    }
}

template <typename T>
bool ArbolBB<T>::buscarPriv(Nodo * &r, T v)
{
    //Si el árbol está vacío GG, gana el Atlas.
    if(arbolVacio()){

        std::cout << "El \xA0rbol est\xA0 vacio." << std::endl;

    //Si encontramos el valor pues le decimos que shi está
    }else if(r->nodo ==  v){

        return true;

    //Si tiene hijo izquierdo y el valor es menor a donde se encuentre r pues
    //recurseamos y mandamos a doxear pa la izquierda.
    }else if(r->tieneHI() && v < r->nodo){

        return buscarPriv(r->hijoIzq, v);

    //Misma historia para el lado derecho, solo que ahora vemos si el valor es mayor a donde
    //esté r en ese momento.
    }else if(r->tieneHD() && v > r->nodo){

        return buscarPriv(r->hijoDer, v);

    }
    //Si de plano no está pues GG. Pierde el Atlas
    return false;
}

template <typename T>
unsigned int ArbolBB<T>::tamanio() const
{
    //Regresamos el número de nodos que el árbol posee.
    return numNodos;
}

template <typename T>
void ArbolBB<T>::imprimirInorden(Nodo * r) const
{

    //si el árbol está vacío pues no se chambea
    if(arbolVacio()){
        std::cout << "El \xA0rbol est\xA0 vacio...";
        return;
    }

    //Pues imprimimos si si hay nodos que imprimir.
    //Ya se saben el inorden, primero revisan al hijo izquierdo
    //luego el nodo raíz y después al derecho.
    if(r != nullptr){

        imprimirInorden(r->hijoIzq);
        std::cout << "[" << r->nodo << "]";
        imprimirInorden(r->hijoDer);

    }
}

template <typename T>
void ArbolBB<T>::imprimirInordenInv(Nodo * r) const
{
    //jejeje
    if(arbolVacio()){
        std::cout << "El \xA0rbol est\xA0 vacio...";
        return;
    }

    //Misma historia pero ahora revisamos al hijo derecho primero
    //luego el nodo raíz y luego pal izquierdo
    if(r != nullptr){

        imprimirInordenInv(r->hijoDer);
        std::cout << "[" << r->nodo << "]";
        imprimirInordenInv(r->hijoIzq);

    }
}

template <typename T>
void ArbolBB<T>::imprimirPorNivel(Nodo * r) const
{
    //jijijiji
    if(arbolVacio()){
        std::cout << "El \xA0rbol est\xA0 vacio...";
        return;
    }

    //a este está chilo, aquí vamos a usar una cola que ya hemos hecho
    //para guardar PUNTEROS, ojo piojo, puntero tipo nodo
    //Para simplemente ir imprimiendo desde la raíz nivel por nivel hasta abajo
    //está durísimo no?


    Nodo * aux;

    Cola<Nodo *> si;

    si.Agregar(r);

    //mientras haya punteros en la cola...
    while(!si.ColaVacia()){

        //nuestro auxiliar tendrá la información del primer puntero en la cola.
        aux = si.Cima();
        //eliminamos uno de la cola para después en la siguiente iteración pues tomamos
        //otra dirección de memoria, ta chilo no?
        si.Eliminar();
        //imprimimos el dato
        std::cout << "[" << aux->nodo << "]";

        //Si tiene hijo derecho pues lo agregamos a la cola y luego si tiene hijo derecho
        //pues también pa la cola.
        if(aux->TieneHI())si.Agregar(aux->hijoIzq);
        if(aux->TieneHD())si.Agregar(aux->hijoDer);
    }


}

template <typename T>
void ArbolBB<T>::copiarPreorden(Nodo * r)
{
    if(arbolVacio()){
        std::cout << "El \xA0rbol est\xA0 vacio mi loco";
        return;
    }

    //Si la raiz tiene cositas...
    if(raiz != nullptr){

        //solo vamos copiando el arbol, en preorden específicamente
        //porque es el método correcto.
        //Ya se la saben, primero el nodo raíz, después el hijo izquierdo
        //y luego el derecho.
        agregar(r->nodo);
        copiarPreorden(r->hijoIzq);
        copiarPreorden(r->hijoDer);

    }
}

template <typename T>
typename ArbolBB<T>::Nodo *& ArbolBB<T>::obtenerMenor(ArbolBB<T>::Nodo * &r) const
{
    //si nuestra raiz no tiene hijo izquierdo pues devolvemos r
    if(r->hijoIzq== nullptr) return r;

    //Regresamos el dato más chiquito.
    return obtenerMenor(r->hijoIzq);
}

template <typename T>
typename ArbolBB<T>::Nodo *& ArbolBB<T>::obtenerMayor(ArbolBB<T>::Nodo * &r) const
{
    //Misma historia de ahorita pero ahora con el hijo derecho.
    if(r->hijoDer== nullptr) return r;

    //regresamos el valor más grande a partir de una r que nos den.
    return obtenerMayor(r->hijoDer);
}

template <typename T>
typename ArbolBB<T>::Nodo *& ArbolBB<T>::encontrar(Nodo * &r, T v)
{
    //Si r apunta a null pues devolvemos r
    if(r == nullptr) return r;
    //Si el dato del nodo es más chiquito pues mandamos a buscar para la izquierda
    //si es más grande pues para la derecha, y si nada de esto se da pues devolvemos simplemente r.
    else if(r->nodo < v) return encontrar(r->hijoIzq, v);
    else if(r->nodo > v) return encontrar(r->hijoDer, v);
    else return r;
}

//*******************************************************

//Verificar si la raiz en la que estemos hoja
template <typename T>
bool ArbolBB<T>::Nodo::esHoja() const
{
    return (hijoIzq == nullptr && hijoDer == nullptr);
}

//Verificamos si la raiz en la que estemos SOLO tiene hijo izquierdo
template <typename T>
bool ArbolBB<T>::Nodo::soloHI() const
{
    return (hijoIzq != nullptr && hijoDer == nullptr);
}

//Verificamos si la raiz en la que estemos SOLO tiene hijo derecho
template <typename T>
bool ArbolBB<T>::Nodo::soloHD() const
{
    return (hijoIzq == nullptr && hijoDer != nullptr);
}

//Verificamos si la raiz en la que estemos tiene ambos hijos
template <typename T>
bool ArbolBB<T>::Nodo::tieneHIHD() const
{
    return (hijoIzq != nullptr && hijoDer != nullptr);
}

//Verificamos si la raiz en la estemos tiene hijo izquierdo
template <typename T>
bool ArbolBB<T>::Nodo::tieneHI() const
{
    return (hijoIzq != nullptr);
}

//Verificamos si la raiz en la estemos tiene hijo izquierdo
template <typename T>
bool ArbolBB<T>::Nodo::tieneHD() const
{
    return (hijoDer != nullptr);
}






















// ~Mephisto
