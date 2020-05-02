//
// Created by Alejandro  Otero on 2020-04-24.
//

#pragma once

#include "Node.h"

namespace Dlist {

    template<typename T>
    class Iterator {
    protected:
        typedef DoublyListNode<T> node_t;

        node_t *pointer;
    public:

        Iterator() : pointer(nullptr) {}

        Iterator(node_t *_pointer) : pointer(_pointer) {}

        ~Iterator(void) {}

        virtual bool operator!=(Iterator<T> it) {
            return this->pointer != it.pointer;
        }

        T &operator*(void) {
            return this->pointer->value;
        }

        void operator++(void) {
            this->pointer = this->pointer->next;
        }

        bool operator==(const Iterator &it) {
            return this->pointer == it.pointer;
        }

        bool operator<=(const Iterator &it) {
            return this->pointer <= it.pointer;
        }

        bool operator>=(const Iterator &it) {
            return this->pointer >= it.pointer;
        }

        bool operator<(const Iterator &it) {
            return this->pointer < it.pointer;
        }

        bool operator>(const Iterator &it) {
            return this->pointer > it.pointer;
        }

    };

    template<typename T>
    class Dlist {
    protected:
        //typedef Node<T> node;
        typedef DoublyListNode<T> Dnode;
        Dnode *head;
        Dnode *tail;
    public:
        Dlist(Dlist &ptr) {
            head = ptr.head;
            tail = ptr.tail;
        }

        Dlist(T *arr, size_t size) {
            for (int i = 0; i < size; i++) {
                push_front(arr[i]);
            }
        }

        Dlist(Dnode *temp) {
            head = tail = temp;
        }

        Dlist(int n) {
            for (int i = 0; i < n; i++) {
                push_front(rand() % 100 + 1);
            }
        }

        Dlist(void) : head(nullptr), tail(nullptr) {}

        ~Dlist(void) {}

        T &front(void) {
            return head->value;
        }

        T &back(void) {
            return tail->value;
        }

        void push_back(const T &element) {
            Dnode *current= new Dnode{element};
            if(head== nullptr){
                head=tail=current;
            }else {
                tail->next = current;
                current->prev = tail;
                tail = current;
            }
        }

        void push_front(const T &element){
            Dnode *current= new Dnode{element};
            if(head== nullptr){
                head=tail=current;
            }else{
                current->next=head;
                head->prev=current;
                head=current;
            }
        }

        void pop_back(void){
            Dnode* temp=tail;
            tail=temp->prev;
            tail->next= nullptr;
            delete temp;
        }

        void pop_front(void){
            Dnode* temp=head;
            head=head->next;
            head->prev= nullptr;
            delete temp;
        }

        T &operator[](const int & element){
            Dnode* current=head;
            for(int i=0; i<element; i++){
                current=current->next;
            }
            return current->value;
        }

        bool empty(void){
            return head== nullptr;
        }

        unsigned int size(void){
            int cont=0;
            if(empty())
                return cont;
            else{
                Dnode* current=head;
                while(current!= nullptr){
                    current=current->next;
                    cont++;
                }
                return cont;
            }
        }

        void clear(void){
            while (head!= nullptr){
                pop_front();
            }

        }

        // Elimina un elemento en base a un puntero
        void erase(Node<T> * ptr){
            if(head==ptr)
                pop_front();
            else if(tail==ptr)
                pop_back();
            else{


            }

        }

        // Inserta un elemento  en base a un puntero
        void insert(Node<T> *ptr, const T & element){
            if(head==ptr)
                push_front(element);
            else if(tail==ptr)
                push_back(element);
            else{


            }
        }

        // Elimina todos los elementos por similitud
        void remove(const T & element){
            if(head->value==element)
                push_front(element);
            else if(tail->value==element)
                push_back(element);
            else{
                Dnode* current=head;
                Dnode* temp=current;
                while(current!= nullptr){
                    current=current->next;
                    if(current->value==element){
                        temp->next=current->next;
                        current=current->next;
                        current->prev=temp;
                        delete current;
                        current=temp->next;
                    }else
                        current=current->next;
                    temp=current;
                }
            }
        }

        // ordena la lista
        Dlist &sort(void){

        }

        // invierte la lista
        void reverse(void){

        }

        //iterators
        Iterator<T> begin() {
            return Iterator(head);
        }

        Iterator<T> end() {
            return Iterator(tail->next);
        }

        template<typename __T>
        inline friend ostream &operator<<(std::ostream &out, const Dlist<__T> &ptr) {
            Dnode *temp = ptr.head;
            while (temp != nullptr) {
                out << temp->value << " ";
                temp = temp->next;
            }
            return out;
        }

        Dlist &operator<<(const T &_value) {
            this->push_back(_value);
            return *this;
        }

        Dlist &operator>>(const T &_value) {
            this->push_front(_value);
            return *this;
        }
    };

}