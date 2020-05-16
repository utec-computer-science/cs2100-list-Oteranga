//
// Created by Alejandro  Otero on 2020-05-02.
//

#pragma once

#include "Node.h"

namespace Clist {

    template <typename T>
    class Iterator{
    private:
        typedef Iterator<T> iterator;
        typedef Node<T> node;
        node* ptr;
    public:
        Iterator(node* _ptr):ptr(_ptr){}
        Iterator(){}
        ~Iterator(){}

        virtual bool operator!=(iterator it) {
            return this->ptr != it.ptr;
        }

        void operator ++() {
            this->ptr = this->ptr->next;
        }

        T &operator*(void) {
            return this->ptr->value;
        }

        bool operator==(const iterator &it) {
            return this->ptr == it.ptr;
        }

        bool operator<=(const iterator &it) {
            return this->ptr <= it.ptr;
        }

        bool operator>=(const iterator &it) {
            return this->ptr >= it.ptr;
        }

        bool operator<(const iterator &it) {
            return this->ptr < it.ptr;
        }

        bool operator>(const iterator &it) {
            return this->ptr > it.ptr;
        }


    };

    template<typename T>
    class Circular_List {
    private:
        typedef Node<T> node;

        node* head;
        node* tail;
        int length;

    /*
    protected:
        template<int nodeType>
        void push_back_imp(node**, node**, T);

        template <int nodeType>
        void push_front_imp(node**, node**, T);

        template <int nodeType>
        void pop_back_imp(node**, node**);

        template <int nodeType>
        void pop_front_imp(node**, node**);
    */

    public:
        Circular_List(Circular_List & ptr){
                head=ptr.head;
                tail=ptr.tail;
        }

        Circular_List(T* arr, size_t size){
            head= tail= nullptr;
            for(int i=0; i<size; i++){
                push_back(arr[i]);
                length++;
            }
        }

        Circular_List(Node<T>* temp){
            head =  tail = temp;
            length++;
        }

        Circular_List(int n){
            for(int i=0; i<n; i++){
                push_back(rand()%100+1);
                length++;
            }
        }

        Circular_List(void):head(nullptr),tail(nullptr),length(0){}

        ~Circular_List(void){}

        T front(void){
            return head->value;
        }

        T back(void){
            return tail->value;
        }

        void push_back(const T& element) {
            //push_back_imp<NodeTraits<T, T>::nodeType>(&head, &tail, element);
            node* temp=new node{element, nullptr};
            if(head== nullptr) {
                head = tail = temp;
                head->next=tail;
                tail->next=head;
            }
            else{
                tail->next=temp;
                tail=temp;
                temp->next=head;
            }
            length++;
        }

        void push_front(const T& element){
            //push_front_imp<NodeTraits<T, T>::nodeType>(&head, &tail, element);
            node* temp=new node{element, nullptr};
            if(head== nullptr) {
                head = tail = temp;
                head->next = tail;
                tail->next = head;
            }
            else{
                tail->next=temp;
                temp->next=head;
                head=temp;
            }
            length++;
        }

        void pop_back(void){
            //pop_back_imp<NodeTraits<T, T>::nodeType>(&head, &tail);
            node* current=head;
            while(current->next!=tail){
                current=current->next;
            }
            tail=current;
            tail->next=head;
            delete current;
            length--;
        }

        void pop_front(void){
            //pop_front_imp<NodeTraits<T, T>::nodeType>(&head, &tail);
            if(head!= nullptr) {
                node* temp=head;
                head=head->next;
                tail->next=head;
                delete temp;
                length--;
            }
        }

        T& operator[] (const int& n){
            node* current=head;
            for(int i=0; i<n; i++){
                current=current->next;
            }
            return current->value;
        }

        bool empty(void){
            return head== nullptr;
        }

        unsigned int size(void){
            return length;
        }

        // Elimina toda la lista
        void clear(void){
            while(head!= nullptr){
                pop_back();
            }
        }

        void erase(node* ptr){
            if(head==ptr)
                pop_front();
            else if(tail==ptr)
                pop_back();
            else{
                node* current=head;
                node* prev_node=current;
                current=current->next;
                while (current!=head){
                    if(current==ptr){
                        prev_node->next=current->next;
                        delete current;
                        break;
                    }
                    prev_node=current;
                    current=current->next;
                }
            }
        }

        // Inserta un elemento  en base a un puntero
        void insert(node* ptr, const T& element){
            if(head==ptr)
                push_front(element);
            else if(tail==ptr)
                push_back(element);
            else{
                node* current=head;
                node* prev_node=current;
                current=current->next;
                node* new_node=new node{element};
                while(current!=head){
                    if(ptr==current){
                        prev_node->next=new_node;
                        new_node->next=current;
                    }
                    current=current->next;
                }
            }
        }

        // Elimina todos los elementos por similitud
        void remove(const T& element){
            node* current=head;
            node* prev_node=current;
            current=current->next;
            while(current!=head) {
                if(prev_node->value==element) {
                    if (head->value == element)
                        pop_front();
                    else if (tail->value == element)
                        pop_back();
                    else {
                        node* temp=head;
                        while (temp->next!=prev_node){
                            temp=temp->next;
                        }
                        temp->next = current;
                        delete prev_node;
                        length--;
                    }
                }
                prev_node = current;
                current = current->next;
            }
            if(prev_node->value==tail->value)
                pop_back();
        }


        void sort(void){
            node* current=head;
            node* index;
            int temp;
            while(current!=tail){
                index=current->next;
                while(index!=head){
                    if(current->value>index->value){
                        temp=current->value;
                        current->value=index->value;
                        index->value=temp;
                    }
                    index=index->next;
                }
                current=current->next;
            }

        }

        void reverse(void){
            if(head!= nullptr){
                node* current=head;
                node* prev_node;
                node* next_node;
                next_node=current->next;
                while(current!=tail){
                    prev_node=current;
                    current=next_node;
                    next_node=current->next;
                    current->next=prev_node;
                }
                head->next=tail;
                current=head;
                head=tail;
                tail=current;
            }
        }

        //iterators

        Iterator<T> begin(){
            return Iterator<T>(head);
        }

        Iterator<T> end(){
            return Iterator<T>(tail);
        }


        Circular_List &operator<<(const T &_value) {
            this->push_back(_value);
            return *this;
        }

        Circular_List &operator>>(const T &_value) {
            this->push_front(_value);
            return *this;
        }

    };

    /*
    template <typename Node, typename ValueNode, int nodeType>
    class ListHelper{
    public:
        static void push_front_imp(Node** head, Node** tail, ValueNode element){
            cout << "Hola no tengo trait definido" << endl;
        }
        static void push_back_imp(Node** head, Node** tail, ValueNode element){
            cout << "Hola no tengo trait definido" << endl;
        }
        static void pop_back_imp(Node** head, Node** tail){
            cout << "Hola no tengo trait definido" << endl;
        }
        static void pop_front_imp(Node** head, Node** tail){
            cout << "Hola no tengo trait definido" << endl;
        }
        static void print(Node** head, Node** tail, ValueNode element){
            cout << "Hola no tengo trait definido" << endl;

        }
    };

    template <typename Node, typename ValueNode>
    class ListHelper<Node,ValueNode,FOWARD_NODE>{
    public:
        static void push_back_imp(Node** head, Node** tail, ValueNode element){
            cout << "Hola soy el push_back para una forward list." << endl;
            /*
            Node* temp=new Node{element, nullptr};
            if(head== nullptr) {
                head = tail = &temp;
                (*head)->next=&(*tail);
                (*tail)->next=&(*head);
            }
            else{
                (*tail)->next=temp;
                tail=&temp;
                temp->next=&(*head);
            }
            */
        }

        static void push_front_imp(Node** head, Node** tail, ValueNode element){
            cout<<"Hola soy el push_front "<<endl;

            /*
            Node* temp=new Node{element, nullptr};
            if(head== nullptr) {
                head = tail = &temp;
                (*head)->next = tail;
                (*tail)->next = head;
            }
            else{
                (*tail)->next=&temp;
                temp->next=&(*head);
                head=&temp;
            }
             */
        }

        static void pop_back_imp(Node** head, Node** tail){
            cout<<"Hola soy el pop_back"<<endl;
            /*
            Node* current=head;
            while(current->next!=&(*tail)){
                current=current->next;
            }
            tail=&current;
            (*tail)->next=&(*head);
            delete current;
             */
        }

        static void pop_front_imp(Node** head, Node** tail){
            cout<<"Hola soy el pop_front"<<endl;
            /*
            if(head!= nullptr) {
                Node* temp=&(*head);
                (*head)=(*head)->next;
                (*tail)->next=&(*head);
                delete temp;
            }
             */
        }
    };

    */

}