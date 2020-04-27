//
// Created by Alejandro  Otero on 2020-04-13.
//
#pragma

#include "Node.h"
#include "Iterator.h"

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
        head=nullptr;
        for(int i=0; i<size; i++){
            push_back(arr[i]);
        }
    }

    List(node* temp){
        //Constructor por parametro,
        //retorna una lista con un nodo
        head=tail=temp;
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
    T& front(void){
        return head->value;
    }

    // Retorna una referencia al ultimo elemento
    T& back(void){
        return tail->value;
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
        node* temp=new node(element, nullptr);
        if(head== nullptr){
            head=tail=temp;
        }
        temp->next=head;
        head=temp;
    }

     void pop_back(void){
        node* current=head;
        while(current->next!= tail){
            current=current->next;
        }
        tail=current;
        delete tail->next;
        tail->next= nullptr;
    }

     void pop_front(void){
        node* current=head;
        head=head->next;
        delete current;
    }

     T& operator[] (const int& num){
        node* current=head;
        for(int i=0; i<num;i++){
            current=current->next;
        }
        return current->value;
    }

    virtual bool empty(void){
        return head==nullptr;
    }

    virtual unsigned int size(void){
        T num=0;
        node *current=head;
        while(current!= nullptr){
            current=current->next;
            ++num;
        }
        return num;
    }

    void clear(void){
        while(head!= nullptr){
            pop_front();
        }
    }

    void erase(node* ptr){
        node* current=head;
        if(head==ptr){
            head=head->next;
            delete current;
        }
        node* temp;
        while(current!= nullptr){
            if(current->next==ptr){
                temp=current->next;
                ptr->next=temp->next;
                delete temp;
            }else
            current=current->next;
        }

    }

    // Inserta un elemento  en base a un puntero
    void insert(node* ptr, const T& element){
        node* current=head;
        while(current!= nullptr){
            if(current->next==ptr){
                current=current->next;
                current->value=element;
            } else
                current=current->next;
        }
    }

    // Elimina todos los elementos por similitud
    void remove(const T& element){
        node* temp;
        node* current=head;
        while(current!= nullptr){
            current=current->next;
            if(current->value==element){
                temp=current->next;
                delete current;
                current=temp;
            }
        }
    }

    void sort(void){
        node* current=head;
        node* temp;
        while(current!=nullptr){
            temp=current->next;
            while(temp!= nullptr){
                if(current->value>temp->value){
                    int num=temp->value;
                    temp->value=current->value;
                    current->value=num;
                }
                temp=temp->next;
            }
            current=current->next;
        }
    }

    // invierte la lista
    void reverse(void){
        node *current=head;
        push_front(head->value);
        pop_front();
        while(current!= nullptr){
            current=current->next;
            push_front(current->value);
            pop_front();
        }
    }

    //Iterator functions

    Iterator<T> begin(){
        return Iterator(head);
    }

    Iterator<T> end(){
        return Iterator(tail->next);
    }

    template <typename A>
    inline friend ostream& operator<<(ostream& out, const List<A>& list){
        node *ptr=list.head;
        while(ptr!= nullptr){
            out<<ptr->value<<" ";
            ptr=ptr->next;
        }
        return out;
    }

    List& operator<< (const T& _value){
        this->push_back(_value);
        return *this;
    }

    List& operator>> (const T& _value){
        this->push_front(_value);
        return *this;
    }
};
