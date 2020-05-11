//
// Created by Alejandro  Otero on 2020-05-04.
//

#pragma once

#include "Node.h"

namespace DCircular_List{
    template <typename T>
    class Iterator{
    private:
        typedef DoublyListNode<T> Dnode;
        Dnode* pointer;

    public:
        Iterator():pointer(nullptr){}

        Iterator(Dnode *_pointer):pointer(_pointer){}

        ~Iterator(){}

        bool operator !=(Iterator<T> it){
            return this->pointer!=it.pointer;
        }

        bool operator ==(Iterator<T> it){
            return this->pointer==it.pointer;
        }

        T &operator*(void){
            return this->pointer->value;
        }

        void operator++(void){
            this->pointer=this->pointer->next;
        }

        void operator --(void){
            this->pointer=this->pointer->prev;
        }

        bool operator <(const Iterator<T> &it){
            return this->pointer=it.pointer;
        }

        bool operator>(const Iterator<T> &it){
            return this->pointer=it-pointer;
        }

        bool operator >=(const Iterator<T> &it){
            return this->pointer=it.pointer;
        }

        bool operator <=(const Iterator<T> &it){
            return this->pointer=it.pointer;
        }
    };

    template <typename T>
    class Doubly_Circular_List{
    private:
        typedef DoublyListNode<T> Dnode;
        Dnode* head;
        size_t length;
    public:
        Doubly_Circular_List(Doubly_Circular_List &ptr){
            head=ptr.head;
        }

        Doubly_Circular_List(T* arr, size_t size){
            for(int i=0; i<size; i++){
                push_back(arr[i]);
            }
        }

        Doubly_Circular_List(Dnode* *temp){
            head=temp;
        }

        Doubly_Circular_List(int n){
            for(int i=0;i<n; i++){
                push_front(rand()%100+1);
            }
        }

        Doubly_Circular_List(void):head(nullptr),length(0){}

        ~Doubly_Circular_List(void){}

        T front(void){
            head->value;
        }

        T back(void){
            head->prev->value;
        }

        void push_back(const T& element){
            Dnode* temp=new Dnode{element};
            if(head== nullptr){
                temp->next=temp;
                temp->prev=temp;
                head=temp;
            } else{
                Dnode* tail=head->prev;
                temp->prev=tail;
                tail->next=temp;
                temp->next=head;
                head->prev=temp;
            }
            length++;
        }

        void push_front(const T& element){
            Dnode* temp=new Dnode{element};
            if(head== nullptr){
                head=temp;
                temp->next=head;
                temp->prev=head;
            }else{
                Dnode* tail=head->prev;
                temp->next=head;
                head->prev=temp;
                temp->prev=tail;
                tail->next=temp;
                head=temp;
            }
            length++;
        }

        void pop_back(void){
            Dnode* current=head;
            if(head->prev== nullptr)
                return;
            else if(head->next==head){
                head= nullptr;
                delete current;
                length--;
            }
            current=head->prev;
            Dnode* temp=current->prev;
            temp->next=head;
            head->prev=temp;
            delete current;
            length--;
        }

        void pop_front(void){
            Dnode* current=head;
            if(head== nullptr)
                return;
            else if(head->next==head){
                head= nullptr;
                delete current;
                length--;
            }else {
                Dnode* tail=head->prev;
                head=head->next;
                head->prev=tail;
                tail->next=head;
                delete current;
                length--;
            }
        }

        // Acceso aleatorio
        T& operator[] (const int& element){
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
            return length;
        }

        // Elimina toda la lista
        void clear(void){
            while(head!= nullptr){
                pop_front();
            }
        }

        void erase(Dnode* ptr){
            if(head==ptr)
                pop_front();
            else if(head->prev==ptr)
                pop_back();
            else{
                Dnode* current=head;
                current=current->next;
                while (current!=head){
                    if(current==ptr){
                        current->prev->next=current->next;
                        current->next->prev=current->prev;
                        delete current;
                        break;
                    }
                    current=current->next;
                }
            }
        }

        // Inserta un elemento  en base a un puntero
        void insert(Dnode* ptr, const T& element){
            if(head==ptr)
                push_front(element);
            else if(head->prev==ptr)
                push_back(element);
            else{
                Dnode* current=head;
                current=current->next;
                Dnode* new_node=new Dnode{element};
                while(current!=head){
                    if(ptr==current){
                        current->prev->next=new_node;
                        new_node->prev=current->prev;
                        current->prev=new_node;
                        new_node->next=current;
                    }
                    current=current->next;
                }
            }
        }

        void remove(const T& element){
            Dnode* temp=head;
            while(temp!= head->prev){
                if(temp->value==element){
                    if(temp==head)
                        pop_front();
                    else if(temp== head->prev)
                        pop_back();
                    else{
                        Dnode* current=temp;
                        current->prev->next=current->next;
                        current->next->prev=current->prev;
                        delete current;
                        length--;
                    }
                }
                temp=temp->next;
            }
            if(temp->value==head->prev->value)
                pop_back();
        }

        void sort(void){
            Dnode* current=head;
            Dnode* index;
            int temp;
            while(current!=head->prev){
                index=current->next;
                while (index!=head){
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
                Dnode* current=head;
                Dnode* temp=current->next;
                current->prev=temp;
                while(temp!=head){
                    temp->prev=temp->next;
                    temp->next=current;
                    current=temp;
                    temp=temp->prev;
                }
                head=current;
            }
        }

        //iterators

        Iterator<T> begin(){
            return Iterator(head);
        }

        Iterator<T> end(){
            return Iterator(head->prev);
        }

        Doubly_Circular_List &operator<<(const T &_value) {
            this->push_back(_value);
            return *this;
        }

        Doubly_Circular_List &operator>>(const T &_value) {
            this->push_front(_value);
            return *this;
        }
    };

}
