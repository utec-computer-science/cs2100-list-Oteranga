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

        List(List &ptr) {
            head = ptr.head;
            tail = ptr.tail;
        }

        List(T *arr, size_t size) {
            head = tail=nullptr;
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

        List(void) : head(nullptr),tail(nullptr) {}

        ~List(void) {}


        T &front(void) {
            return head->value;
        }

        T &back(void) {
            return tail->value;
        }

        void push_back(const T &element) {
            //push_back_imp<NodeTraits<T, T>::nodeType>(&head, &tail, element);

            node *temp = new node(element, nullptr);
            if (head == nullptr) {
                head = tail = temp;
            }
            tail->next = temp;
            tail = temp;
        }

        void push_front(const T &element) {
            //push_front_imp<NodeTraits<T, T>::nodeType>(&head, &tail, element);
            node *temp = new node(element, nullptr);
            if (head == nullptr) {
                head = tail = temp;
            }
            temp->next = head;
            head = temp;
        }

        void pop_back(void) {
            //pop_back_imp<NodeTraits<T, T>::nodeType>(&head, &tail);
            node *current = head;
            while (current->next != tail) {
                current = current->next;
            }
            tail = current;
            delete tail->next;
            tail->next = nullptr;
        }

        void pop_front(void) {
            //pop_front_imp<NodeTraits<T, T>::nodeType>(&head, &tail);
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
                current=current->next;
                while (current != nullptr) {
                    temp=current;
                    if (current->next == ptr) {
                        current=current->next;
                        temp->next= current->next;
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
                ptr=new node(element, ptr);
                node *current = head;
                node *prev_node=current;
                current=current->next;
                while (current != nullptr) {
                    if (current == ptr) {
                        prev_node->next=ptr;
                        ptr->next=current;
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

        void reverse(void) {
            if(head!= nullptr) {
                node* current=head;
                node* next_node=head;
                node* prev= nullptr;
                while(next_node!= nullptr){
                    next_node=next_node->next;
                    current->next=prev;
                    prev=current;
                    current=next_node;
                }
                tail=head;
                head=prev;
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
            cout << "Hola soy el push_back" << endl;

            Node *new_node = new Node{element,nullptr};
            if (!head){
                tail = head = &new_node;
            } else {
                (*tail)->next = new_node;
                tail = &((*tail)->next);
            }
        }

        static void push_front_imp(Node** head, Node** tail, ValueNode element){
            cout<<"Hola soy el push_front "<<endl;

            Node *temp = new node(element, nullptr);
            if (head == nullptr) {
                head = tail = &temp;
            }
            temp->next = &(*head);
            head = &temp;

        }

        static void pop_back_imp(Node** head, Node** tail){
            cout<<"Hola soy el pop_back"<<endl;

            node *current = head;
            while (current->next != &(*tail)) {
                current = current->next;
            }
            tail = &current;
            delete (*tail)->next;
            (*tail)->next = nullptr;

        }

        static void pop_front_imp(Node** head, Node** tail){
            cout<<"Hola soy el pop_front"<<endl;

            node *current = &(*head);
            (*head) = (*head)->next;
            delete current;

        }
    };

    template< typename Node>  //template <int nodeType>
    void Node<Node>::push_back_imp(
            typename List<Node>::node_t ** head,
            typename List<Node>::node_t ** tail,
            typename List<Node>::value_t element){

        ListHelper<List<Node>::T,List<Node>::T,nodeType>::add(head,tail,element);
    }


    */
}