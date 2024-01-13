#include <iostream>
#include "ColaCircular.h"

//Bueno ya se la saben, celulares y carteras
//Ya en serio, este es el �ltimo c�digo, que subir� porque lo dem�s est� m�s cabr�n
//o sea, lo tengo, pero lo chilo es echarle coco a los otros.
//Ya saben como funciona estos 4 m�todos, son los que "garantizan el correcto funcionamiento de nuestra clase"
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
//Esto pues poco m�s, lo chilo son los m�todos privados, ag�rrense de su silla
//porque se van a ir para atr�s.

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

//M�todo para agregar nodos, lesfakingooo
template <typename T>
void ArbolBB<T>::agregarPriv(Nodo * &r, T v)
{
    //checamos si nuestro �rbol est� vac�o
    if(r == nullptr){
        //Si s� est� vac�o entonces agregamos un nuevo nodo y conectamos el puntero ra�z con el nuevo dato.
        r = new Nodo(v);
        //Incrementamos el n�mero de nodos
        ++numNodos;
    }else{

        //recursividad linda y bonita, si el valor que nos pasan es m�s peque�o que el dato a donde ra�z apunte pues mandamos
        //como hijo izquierdo, si no pues al lado derecho, ya se imaginan el arbolito?
        if(v < r->nodo) agregarPriv(r->hijoIzq, v);
        else if (v > r->nodo) agregarPriv(r->hijoDer, v);
    }

}

template <typename T>
bool ArbolBB<T>::eliminarPriv(Nodo * &r, T v)
{

    //Si nuestra �rbol no tiene nada pues le tiramos un false diciendo que no eliminamos nada.
    if(r == nullptr) return false;

    //Si encontramos el nodo que queremos borrar...
    if(r->nodo == v){

        //Nodo por borrar que ya se la saben
        Nodo * porBorrar = r;

        //si a donde apunte r es una hoja pues no hay problema, solamente eliminamos el nodo, facilito.
        if(r->EsHoja()){

            r = nullptr;

        //Si el nodo de la raiz tiene solo hijo izquierdo pues hacemos que nuestra
        //r apunte a �l para poder eliminar al que queremos y que no se pierda el nodo.
        }else if(r->soloHI()){

            r = porBorrar->hijoIzq;

        //Misma historia solo que con el hijo derecho.
        }else if(r->soloHD()){

            r = porBorrar->hijoDer;

        //aqu� es cuando tiene ambos hijos, en este caso ir�mos a buscar al
        //mayor del subarbol del hijo izquierdo
        }else{
            //Aqu� mandamos a doxear al mayor
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
        //disminuimos la cantidad de nodos en el �rbol
        --numNodos;
        //Avisamos que si eliminamos algo.
        return true;
    //Ahora bien, estas dos �ltimas consideraciones es para buscar el nodo, si el valor
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

    //vamos a usar la maravillosa recursividad para ir rebanando el �rbol nodo x nodo.
    //dur�simo.
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
    //Si el �rbol est� vac�o GG, gana el Atlas.
    if(arbolVacio()){

        std::cout << "El \xA0rbol est\xA0 vacio." << std::endl;

    //Si encontramos el valor pues le decimos que shi est�
    }else if(r->nodo ==  v){

        return true;

    //Si tiene hijo izquierdo y el valor es menor a donde se encuentre r pues
    //recurseamos y mandamos a doxear pa la izquierda.
    }else if(r->tieneHI() && v < r->nodo){

        return buscarPriv(r->hijoIzq, v);

    //Misma historia para el lado derecho, solo que ahora vemos si el valor es mayor a donde
    //est� r en ese momento.
    }else if(r->tieneHD() && v > r->nodo){

        return buscarPriv(r->hijoDer, v);

    }
    //Si de plano no est� pues GG. Pierde el Atlas
    return false;
}

template <typename T>
unsigned int ArbolBB<T>::tamanio() const
{
    //Regresamos el n�mero de nodos que el �rbol posee.
    return numNodos;
}

template <typename T>
void ArbolBB<T>::imprimirInorden(Nodo * r) const
{

    //si el �rbol est� vac�o pues no se chambea
    if(arbolVacio()){
        std::cout << "El \xA0rbol est\xA0 vacio...";
        return;
    }

    //Pues imprimimos si si hay nodos que imprimir.
    //Ya se saben el inorden, primero revisan al hijo izquierdo
    //luego el nodo ra�z y despu�s al derecho.
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
    //luego el nodo ra�z y luego pal izquierdo
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

    //a este est� chilo, aqu� vamos a usar una cola que ya hemos hecho
    //para guardar PUNTEROS, ojo piojo, puntero tipo nodo
    //Para simplemente ir imprimiendo desde la ra�z nivel por nivel hasta abajo
    //est� dur�simo no?


    Nodo * aux;

    Cola<Nodo *> si;

    si.Agregar(r);

    //mientras haya punteros en la cola...
    while(!si.ColaVacia()){

        //nuestro auxiliar tendr� la informaci�n del primer puntero en la cola.
        aux = si.Cima();
        //eliminamos uno de la cola para despu�s en la siguiente iteraci�n pues tomamos
        //otra direcci�n de memoria, ta chilo no?
        si.Eliminar();
        //imprimimos el dato
        std::cout << "[" << aux->nodo << "]";

        //Si tiene hijo derecho pues lo agregamos a la cola y luego si tiene hijo derecho
        //pues tambi�n pa la cola.
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

        //solo vamos copiando el arbol, en preorden espec�ficamente
        //porque es el m�todo correcto.
        //Ya se la saben, primero el nodo ra�z, despu�s el hijo izquierdo
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

    //Regresamos el dato m�s chiquito.
    return obtenerMenor(r->hijoIzq);
}

template <typename T>
typename ArbolBB<T>::Nodo *& ArbolBB<T>::obtenerMayor(ArbolBB<T>::Nodo * &r) const
{
    //Misma historia de ahorita pero ahora con el hijo derecho.
    if(r->hijoDer== nullptr) return r;

    //regresamos el valor m�s grande a partir de una r que nos den.
    return obtenerMayor(r->hijoDer);
}

template <typename T>
typename ArbolBB<T>::Nodo *& ArbolBB<T>::encontrar(Nodo * &r, T v)
{
    //Si r apunta a null pues devolvemos r
    if(r == nullptr) return r;
    //Si el dato del nodo es m�s chiquito pues mandamos a buscar para la izquierda
    //si es m�s grande pues para la derecha, y si nada de esto se da pues devolvemos simplemente r.
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
