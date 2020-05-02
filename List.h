//
// Created by Alejandro  Otero on 2020-04-13.
//
#pragma

#include "Node.h"

namespace List {

    template<typename T>
    class Iterator {
    protected:
        typedef Node<T> node_t;

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
    class List {
    protected:
        typedef Node<T> node;
        node *head;
        node *tail;
    public:
        List(List &ptr) {
            head = ptr.head;
            tail = ptr.tail;
        }

        List(T *arr, size_t size) {
            head = nullptr;
            for (int i = 0; i < size; i++) {
                push_back(arr[i]);
            }
        }

        List(node *temp) {
            //Constructor por parametro,
            //retorna una lista con un nodo
            head = tail = temp;
        }

        List(int n) {
            for (int i = 0; i < n; i++) {
                push_back(rand() % 100 + 1);
            }
        }

        List(void) : head(nullptr) {}

        ~List(void) {
        }

        // Retorna una referencia al primer elemento
        T &front(void) {
            return head->value;
        }

        // Retorna una referencia al ultimo elemento
        T &back(void) {
            return tail->value;
        }

        void push_back(const T &element) {
            node *temp = new node(element, nullptr);
            if (head == nullptr) {
                head = tail = temp;
            }
            tail->next = temp;
            tail = temp;
        }

        void push_front(const T &element) {
            node *temp = new node(element, nullptr);
            if (head == nullptr) {
                head = tail = temp;
            }
            temp->next = head;
            head = temp;
        }

        void pop_back(void) {
            node *current = head;
            while (current->next != tail) {
                current = current->next;
            }
            tail = current;
            delete tail->next;
            tail->next = nullptr;
        }

        void pop_front(void) {
            node *current = head;
            head = head->next;
            delete current;
        }

        T &operator[](const int &num) {
            node *current = head;
            for (int i = 0; i < num; i++) {
                current = current->next;
            }
            return current->value;
        }

        virtual bool empty(void) {
            return head == nullptr;
        }

        virtual unsigned int size(void) {
            T num = 0;
            node *current = head;
            while (current != nullptr) {
                current = current->next;
                ++num;
            }
            return num;
        }

        void clear(void) {
            while (head != nullptr) {
                pop_front();
            }
        }

        void erase(node *ptr) {
            if (head == ptr) {
                pop_front();
            } else if(tail==ptr){
                pop_back();
            }else {
                node *current = head;
                node *temp;
                while (current != nullptr) {
                    if (current->next == ptr) {
                        temp = current->next;
                        ptr->next = temp->next;
                        delete temp;
                        break;
                    } else
                        current = current->next;
                }
            }
        }

        void insert(node *ptr, const T &element) {
            if(head==ptr)
                push_front(element);
            else if(tail==ptr)
                push_back(element);
            else {
                node *current = head;
                while (current != nullptr) {
                    if (current == ptr) {
                        current->value = element;
                        break;
                    } else
                        current = current->next;
                }
            }
        }

        void remove(const T &element) {
            if(head->value==element){
                pop_front();
            }else if( tail->value==element)
                pop_back();
            else {
                node *current = head;
                node *temp=current;
                while (current != nullptr) {
                    current = current->next;
                    if (current->value == element) {
                        temp->next = current->next;
                        delete current;
                        current = temp->next;
                    }
                    temp = current;
                }
            }
        }

        void sort(void) {
            node *current = head;
            node *temp;
            while (current != nullptr) {
                temp = current->next;
                while (temp != nullptr) {
                    if (current->value > temp->value) {
                        int num = temp->value;
                        temp->value = current->value;
                        current->value = num;
                    }
                    temp = temp->next;
                }
                current = current->next;
            }
        }

        // invierte la lista
        void reverse(void) {
            if(head!= nullptr) {
                node *current = head;
                node *sig = nullptr;
                node *ant = nullptr;
                while (current != nullptr) {
                    sig = current->next;
                    current->next = ant;
                    ant = current;
                    current = sig;
                }
                head = ant;
            }
        }

        //Iterator functions

        Iterator<T> begin() {
            return Iterator(head);
        }

        Iterator<T> end() {
            return Iterator(tail->next);
        }

        template<typename A>
        inline friend ostream &operator<<(ostream &out, const List<A> &list) {
            node *ptr = list.head;
            while (ptr != nullptr) {
                out << ptr->value << " ";
                ptr = ptr->next;
            }
            return out;
        }

        List &operator<<(const T &_value) {
            this->push_back(_value);
            return *this;
        }

        List &operator>>(const T &_value) {
            this->push_front(_value);
            return *this;
        }
    };
}