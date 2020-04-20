//
// Created by Alejandro  Otero on 2020-04-13.
//
#pragma

#include <iostream>
#include "Node.h"

template <typename T>
class List {
protected:
    typedef Node<T> node;
    node *head;
public:
    List(List& ptr){
        head=ptr.head;
    }

    List(T* arr){
        //Constructor  parametro,
        //llena una lista a partir de un array
        head=arr;
    }

    List(node*){
        //Constructor por parametro,
        //retorna una lista con un nodo

    }

    List(int n){
        //Constructor por parametro,
        //retorna un lista de randoms de tamaño n

    }

    List(void):head(nullptr){}

    ~List(void){
    }

    // Retorna una referencia al primer elemento
    T front(void){
        return head;
    }

    // Retorna una referencia al ultimo elemento
    T back(void){
        node *current=head;
        while(current->next!= nullptr){
            current->next;
        }
        return current;
    }

    // Inserta un elemento al final
    void push_back(const T& element) = 0;

    // Inserta un elemento al inicio
    void push_front(const T& element) = 0;

    // Quita el ultimo elemento y retorna una referencia
    T& pop_back(void) = 0;

    // Quita el primer elemento y retorna una referencia
    T& pop_front(void) = 0;

    // Acceso aleatorio
    T& operator[] (const int&) = 0;

    // la lista esta vacia?
    bool empty(void){
        if(head!=nullptr){
            return false;
        }
        return true;
    }

    // retorna el tamaño de la lista
    unsigned int size(void){
        if(empty()== true){
            return 0;
        }
        T num=0;
        node *current=head;
        while(current->next!= nullptr){
            current=current->next;
            ++num;
        }
        return num;
    }

    // Elimina toda la lista
    void clear(void){
        node *current=head;
        for(int i=0;i<size();i++){
            head=head->next;
            delete current;
            current=head;
        }
    }

    // Elimina un elemento en base a un puntero
    void erase(node* element){
        node* current=head;
        node* enlace=head;
        if(head==element){
            head=head->next;
            delete current;
        }
        while(current->next!=element){
            current=current->next;
        }
        delete current;
    }

    // Inserta un elemento  en base a un puntero
    void insert(node*, const T&) = 0;

    // Elimina todos los elementos por similitud
    void remove(const T&) = 0;

    // ordena la lista
    List& sort(void) = 0;

    // invierte la lista
    List& reverse(void) = 0;

    // Imprime la lista con cout
    template<typename __T>
    inline friend ostream& operator<<(ostream& , const List<__T>& ){
        
    }
};
