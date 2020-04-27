//
// Created by Alejandro  Otero on 2020-04-24.
//

#pragma

#include "Node.h"
#include "Iterator.h"

/*
template<typename T>
class Dlist{
protected:
    typedef Node<T> node;
    typedef DoublyListNode<T> Dnode;
    Dnode *head;
public:
    Dlist(Dlist& ptr){
        head=ptr.head;
    }

    Dlist(T* arr, size_t size){
        for(int i=0; i<size; i++){
            push_front(arr[i]);
        }
    }

    Dlist(node* temp){
        head=temp;
    }

    Dlist(int n){
        for(int i=0; i<n; i++){
            push_front(rand()%100+1);
        }
    }

    Dlist(void):head(nullptr){}

    ~Dlist(void){}

    // Retorna una referencia al primer elemento
    T& front(void){
        return head->value;
    }

    // Retorna una referencia al ultimo elemento
    T& back(void){
        Dnode *current=head;
        while(current->next!= nullptr){
            current=current->next;
        }
        return current->value;
    }

    // Inserta un elemento al final
    void push_back(const T& element){

    }

    // Inserta un elemento al inicio
    void push_front(const T& element) = 0;

    // Quita el ultimo elemento y retorna una referencia
    T& pop_back(void) = 0;

    // Quita el primer elemento y retorna una referencia
    T& pop_front(void) = 0;

    // Acceso aleatorio
    T& operator[] (const int&) = 0;

    // la lista esta vacia?
    bool empty(void) = 0;

    // retorna el tamaño de la lista
    unsigned int size(void) = 0;

    // Elimina toda la lista
    void clear(void) = 0;

    // Elimina un elemento en base a un puntero
    void erase(Node<T>*) = 0;

    // Inserta un elemento  en base a un puntero
    void insert(Node<T>*, const T&) = 0;

    // Elimina todos los elementos por similitud
    void remove(const T&) = 0;

    // ordena la lista
    Dlist& sort(void) = 0;

    // invierte la lista
    Dlist& reverse(void) = 0;

    // Imprime la lista con cout
    template<typename __T>
    inline friend std::ostream& operator<<(std::ostream& out, const Dlist<__T>& ptr){
        Dnode *temp=ptr.head;
        while(temp!= nullptr){
            out<<temp->value<<" ";
            temp=temp->next;
        }
        return out;
    }

    Dlist& operator<< (const T& _value){
        this->push_back(_value);
        return *this;
    }

    Dlist& operator>> (const T& _value){
        this->push_front(_value);
        return *this;
    }
};

*/
