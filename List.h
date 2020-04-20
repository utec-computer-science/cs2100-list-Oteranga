//
// Created by Alejandro  Otero on 2020-04-13.
//
#pragma

#include "Node.h"

template <typename T>
class List {
protected:
    typedef Node<T> node;
    node *head;
    node *tail;
public:
    List(List& ptr){
        head=ptr.head;
        tail=ptr.tail;
    }

    List(T* arr, size_t size){
        head=tail= nullptr;
        for(int i=0; i<size; i++){
            push_back(arr[i]);
        }
    }

    List(node* temp){
        //Constructor por parametro,
        //retorna una lista con un nodo
        head=temp;
    }

    List(int n){
        for(int i=0; i<n; i++){
            push_back(rand()%100+1);
        }
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
        return tail;
    }

    void push_back(const T& element){
        node* temp= new node(element, nullptr);
        if(head== nullptr){
            head=tail=temp;
        }
        tail->next=temp;
        tail=temp;
    }

    void push_front(const T& element){
        node* temp=new node{element, nullptr};
        if(head== nullptr){
            head=tail=temp;
        }
        temp->next=head;
        head=temp;
    }

    // Quita el ultimo elemento y retorna una referencia
    T& pop_back(void){

    }

    // Quita el primer elemento y retorna una referencia
    T& pop_front(void){

    }

    // Acceso aleatorio
    T& operator[] (const int& num){
        node* current=head;
        for(int i=0; i<num;i++){
            current=current->next;
        }
        return *current;
    }

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
        if(head==element){
            head=head->next;
            delete current;
        }
        while(current->next!=element){
            current=current->next;
        }
        node* temp=current->next;
        current=temp->next;
        delete temp;
    }

    // Inserta un elemento  en base a un puntero
    void insert(node*, const T&){

    }

    // Elimina todos los elementos por similitud
    void remove(const T&){

    }

    // ordena la lista
    List& sort(void){

    }

    // invierte la lista
    List& reverse(void){
        
    }

    // Imprime la lista con cout
    template <typename A>
    inline friend ostream& operator<<(ostream& out, const List<A>& list){
        node *ptr=list.head;
        while(ptr!= nullptr){
            out<<ptr->value<<" ";
            ptr=ptr->next;
        }
        return out;
    }
};
