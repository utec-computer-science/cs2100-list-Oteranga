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

        bool operator!=(Iterator<T> it) {
            return this->pointer != it.pointer;
        }

        T &operator*(void) {
            return this->pointer->value;
        }

        void operator++(void) {
            this->pointer = this->pointer->next;
        }

        void operator--(void){
            this->pointer=this->pointer->prev;
        }

        bool operator==(const Iterator<T> &it) {
            return this->pointer == it.pointer;
        }

        bool operator<=(const Iterator<T> &it) {
            return this->pointer <= it.pointer;
        }

        bool operator>=(const Iterator<T> &it) {
            return this->pointer >= it.pointer;
        }

        bool operator<(const Iterator<T> &it) {
            return this->pointer < it.pointer;
        }

        bool operator>(const Iterator<T> &it) {
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
            if(tail== nullptr)
                return;
            else {
                Dnode *temp = tail;
                tail->prev->next = nullptr;
                tail = tail->prev;
                delete temp;
            }
        }

        void pop_front(void){
            if(head== nullptr)
                return;
            else {
                Dnode *temp = head;
                head = head->next;
                head->prev = nullptr;
                delete temp;
            }
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

        // Elimina toda la lista
        void clear(void){
            while (head!= nullptr){
                pop_back();
            }
        }

        void erase(Dnode * ptr){
            if(head==ptr)
                pop_front();
            else if(tail==ptr)
                pop_back();
            else{
                Dnode* current=head;
                Dnode* temp=current;
                while(current!= nullptr){
                    current=current->next;
                    if(current==ptr){
                        current=current->next;
                        temp->next=current;
                        current->prev=temp;
                        delete current;
                    }else
                        current=current->next;
                    temp=current;
                }
            }
        }

        void insert(Dnode *ptr, const T & element){
            if(head==ptr)
                push_front(element);
            else if(tail==ptr)
                push_back(element);
            else{
                Dnode* current=head;
                Dnode* prev_node=current;
                Dnode* new_node=new Dnode{element};
                while(current!= nullptr){
                    current=current->next;
                    if(current==ptr){
                        prev_node->next=new_node;
                        new_node->next=current;
                        new_node->prev=prev_node;
                        current->prev=new_node;
                    }
                    prev_node=current;
                }
            }
        }

        void remove(const T & element){
            Dnode* temp=head;
            while(temp!= nullptr){
                if(temp->value==element){
                    if(temp==head)
                        pop_front();
                    else if(temp== tail)
                        pop_back();
                    else{
                        Dnode* current=temp;
                        current->prev->next=current->next;
                        current->next->prev=current->prev;
                        delete current;
                    }
                }
                    temp=temp->next;
            }
        }

        void sort(void){
            Dnode* current=head;
            Dnode* temp;
            while (current!= nullptr){
                temp=current->next;
                while(temp!= nullptr){
                    if(current->value>temp->value){
                        int num = temp->value;
                        temp->value=current->value;
                        current->value=num;
                    }
                    temp=temp->next;
                }
                current=current->next;
            }
        }

        void reverse(void){
            if(head!= nullptr){
                Dnode* current=head;
                Dnode* next_node;
                while(current!= nullptr) {
                    next_node = current->next;
                    current->next = current->prev;
                    current->prev = next_node;
                    current=next_node;
                }
                current=head;
                head=tail;
                tail=current;
            }
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

    /*
    template <typename Node, typename ValueNode, int nodeType>
    class ListHelper{
    public:
        static void add(Node** head, Node** tail, ValueNode element){
            cout << "Hola no tengo trait definido" << endl;

        }
        static void remove(Node** head, Node** tail, ValueNode element){
            cout << "Hola no tengo trait definido" << endl;

        }
        static void print(Node** head, Node** tail, ValueNode element){
            cout << "Hola no tengo trait definido" << endl;

        }
    };

    template <typename Node, typename ValueNode>
    class ListHelper<Node,ValueNode,DOUBLE_NODE>{
    public:
        static void add(Node** head, Node** tail, ValueNode element){
            cout << "Hola soy el push_back para una double list." << endl;

        }
    };
     */

}