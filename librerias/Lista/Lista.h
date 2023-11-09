#ifndef U02_LISTAS_LISTA_LISTA_H_
#define U02_LISTAS_LISTA_LISTA_H_
#include "nodo.h"
#include <iostream>
#include <cmath>

/**
 * Clase que implementa una Lista Enlasada generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template <class T> class Lista {
private:
  Nodo<T> *inicio;

public:
  Lista();

  Lista(const Lista<T> &li);

  ~Lista();

  bool esVacia();

  int getTamanio();

  void insertar(int pos, T dato);

  void insertarPrimero(T dato);

  void insertarUltimo(T dato);

  void remover(int pos);

  T getDato(int pos);

  void reemplazar(int pos, T dato);

  void vaciar();

  void print();

  int pos_max( int n);

  int pos_min(int n);

  void quickSort(int o_inicio, int fin, Lista<T>* l1, Lista<std::string>* l2);

  void intercambiar(int a, int b);

  int particion(int o_inicio, int fin, Lista<T>* l1, Lista<std::string>* l2);

  void print_min(int n,Lista<std::string>*,Lista<int>*);

  void print_max(int n,Lista<std::string>*,Lista<int>*);
};


/**
 * Constructor de la clase Lista
 * @tparam T
 */
template <class T> Lista<T>::Lista() { inicio = nullptr; }

/**
 * Constructor por copia de la clase Lista
 * @tparam T
 * @param li
 */
template <class T> Lista<T>::Lista(const Lista<T> &li) { inicio = li.inicio; }

/**
 * Destructor de la clase Lista, se encarga de liberar la memoria de todos los
 * nodos utilizados en la lista
 * @tparam T
 */
template <class T> Lista<T>::~Lista() { vaciar(); }

/**
 * Metodo para saber si la lista esta vacia
 * @tparam T
 * @return true si la lista esta vacia, sino false
 */
template <class T> bool Lista<T>::esVacia() { return inicio == nullptr; }

/**
 * Metodo para obtener la cantidad de nodos de la lista
 * @tparam T
 * @return la cantidad de nodos de la lista
 */
template <class T> int Lista<T>::getTamanio() {
  Nodo<T> *aux = inicio;
  int size = 0;

  while (aux != nullptr) {
    aux = aux->getSiguiente();
    size++;
  }

  return size;
}

/**
 * Inserta un nodo con el dato en la posicion pos
 * @tparam T
 * @param pos lugar donde será insertado el dato
 * @param dato  dato a insertar
 */
template <class T> void Lista<T>::insertar(int pos, T dato) {
  int posActual = 0;
  Nodo<T> *aux = inicio, *nuevo;
  nuevo = new Nodo<T>;
  nuevo->setDato(dato);

  if (pos == 0) {
    nuevo->setSiguiente(inicio);
    inicio = nuevo;
    return;
  }

  while (aux != nullptr && posActual < pos - 1) {
    aux = aux->getSiguiente();
    posActual++;
  }

  if (aux == nullptr) {
    throw "insert";
  }

  nuevo->setSiguiente(aux->getSiguiente());
  aux->setSiguiente(nuevo);
}

/**
 * Inserta un nodo con el dato en la primera posicion
 * @tparam T
 * @param dato dato a insertar
 */
template <class T> void Lista<T>::insertarPrimero(T dato) { insertar(0, dato); }

/**
 * Inserta un nodo con el dato en la ultima posicion
 * @tparam T
 * @param dato dato a insertar
 */
template <class T> void Lista<T>::insertarUltimo(T dato) {
  Nodo<T> *aux = inicio, *nuevo;
  nuevo = new Nodo<T>;
  nuevo->setDato(dato);

  if (aux == nullptr) {
    nuevo->setSiguiente(inicio);
    inicio = nuevo;
    return;
  }

  while (aux->getSiguiente() != nullptr) {
    aux = aux->getSiguiente();
  }

  nuevo->setSiguiente(aux->getSiguiente());
  aux->setSiguiente(nuevo);
}

/**
 * Elimina el nodo en la posicion 'pos' de la lista enlasada
 * @tparam T
 * @param pos posicion del nodo a eliminar
 */
template <class T> void Lista<T>::remover(int pos) {
  Nodo<T> *aux = inicio, *aBorrar;
  int posActual = 0;

  if (pos == 0) {
    inicio = inicio->getSiguiente();
    delete aux;
    return;
  }

  while (aux != nullptr && posActual < pos - 1) {
    aux = aux->getSiguiente();
    posActual++;
  }

  if (aux == nullptr) {
    throw "remove";
  }

  aBorrar = aux->getSiguiente();
  aux->setSiguiente(aBorrar->getSiguiente());

  delete aBorrar;
}

/**
 * Obtener el dato del nodo en la posicion pos
 * @tparam T
 * @param pos posicion del dato
 * @return dato almacenado en el nodo
 */
template <class T> T Lista<T>::getDato(int pos) {
  Nodo<T> *aux = inicio;
  int posActual = 0;

  while (aux != nullptr && posActual < pos) {
    aux = aux->getSiguiente();
    posActual++;
  }

  if (aux == nullptr) {
    throw "getDato";
  }

  return aux->getDato();
}

/**
 * Reemplaza el dato almacenado en un nodo por este otro
 * @tparam T
 * @param pos posicion donde se desea reemplazar
 * @param dato nuevo dato a almacenar
 */
template <class T> void Lista<T>::reemplazar(int pos, T dato) {
  Nodo<T> *aux = inicio;
  int posActual = 0;

  while (aux != nullptr && posActual < pos) {
    aux = aux->getSiguiente();
    posActual++;
  }

  if (aux == nullptr) {
    throw "reemplazar";
  }

  aux->setDato( dato );
}

/**
 * Función que vacia la lista enlazada
 * @tparam T
 */
template <class T> void Lista<T>::vaciar() {
	Nodo<T> *aux = inicio, *aBorrar;

	while( aux != nullptr ){
		aBorrar = aux;
		aux = aux->getSiguiente();
		delete aBorrar;
	}

	inicio = nullptr;

}

template<class T>
void Lista<T>::print() {
    Nodo<T> *auxNodo= inicio;
    while(auxNodo!= nullptr){
        std::cout<<auxNodo->getDato()<<"\n";
        auxNodo=auxNodo->getSiguiente();
    }
    std::cout<<"\n";
}

template<class T>
int Lista<T>::pos_max( int n) {
    int parte1=ceil((getTamanio()-1)/4);
    int parte2=parte1*2;
    int parte3=parte1*3;
    int caso[4]={-1,-1,-1,-1};

    if(n<= getDato(0)){return 0;}

    if(n> getDato(getTamanio()-1)){return -1;}


    //nos fijamos si esta en el primer cuarto
    if(n>=getDato(0) && n<=getDato(parte1)){
        caso[0]=1;
    }

    //nos fijamos en el segundo cuarto
    if(n>=getDato(parte1) && n<=getDato(parte2)){
        caso[1]=1;
    }

    //nos fijamos en el tercer cuarto
    if(n>=getDato(parte2) && n<=getDato(parte3)){
        caso[2]=1;
    }

    //nos fijamos en el ultimo cuarto
    if(n>=getDato(parte3) && n<=getDato(getTamanio()-1)){
        caso[3]=1;
    }
    int aux;
    if(caso[0]==1){
        for(int i=0;i<parte1;i++){
            if(getDato(i)==n){
                return i;
            }

        }
    }

    if(caso[1]==1){
        for(int i=parte1;i<parte2;i++){
            if(getDato(i)==n){
                return i;
            }

        }
    }

    if(caso[2]==1){
        for(int i=parte2;i<parte3;i++){
            if(getDato(i)==n){
                return i;
            }
        }
    }

    if(caso[3]==1){
        for(int i=parte3; i < getTamanio()-1; i++){

            if(getDato(i)<n){
                aux=i;
            }
        }
    }
    return (aux+1);
}

template<class T>
void Lista<T>::quickSort(int o_inicio, int fin, Lista<T>* l1, Lista<std::string>* l2) {
    if (o_inicio < fin) {
        int pivot = particion(o_inicio, fin, l1, l2);

        quickSort(o_inicio, pivot - 1, l1, l2);
        quickSort(pivot + 1, fin, l1, l2);
    }
}

template<class T>
int Lista<T>::particion(int o_inicio, int fin, Lista<T>* l1, Lista<std::string>* l2) {
    T pivot = l1->getDato(fin); // Usamos l1 para obtener el dato pivot
    int i = o_inicio - 1;

    for (int j = o_inicio; j < fin; j++) {
        if (l1->getDato(j) < pivot) { // Usamos l1 para comparar
            i++;
            l1->intercambiar(i, j);
            l2->intercambiar(i, j); // Intercambia en la segunda lista
        }
    }

    l1->intercambiar(i + 1, fin);
    l2->intercambiar(i + 1, fin); // Intercambia en la segunda lista
    return i + 1;
}


template<class T>
void Lista<T>::intercambiar(int a, int b) {
    T temp = getDato(a);
    reemplazar(a, getDato(b));
    reemplazar(b, temp);
}

template<class T>
int Lista<T>::pos_min(int n) {

    if(n>= getDato(getTamanio()-1)){
        return (getTamanio()-1);
    }
    if(n<getDato(0)){
        return -1;
    }

    int x= pos_max(n+1);
    if(getDato(x)!=n){
        return(x-1);
    }
    if(getDato(x)==n){
        return x;
    }
    return 0;
}

template<class T>
void Lista<T>::print_min(int n,Lista<std::string> *name,Lista<int> *stock) {
    for (int i=0;i<n;i++){
        std::cout<<name->getDato(i)<<"----"<< stock->getDato(i)<<"\n";
    }
}

template<class T>
void Lista<T>::print_max(int n, Lista<std::string> *name, Lista<int> *stock) {
    for (int i=n;i<(getTamanio());i++){
        std::cout<<name->getDato(i)<<"----"<<stock->getDato(i)<<"\n";
    }
}

#endif // U02_LISTAS_LISTA_LISTA_H_
