//
// Created by Alejandro  Otero on 2020-04-13.
//
#pragma

#include "Node.h"

template <typename T>
class List {
protected:
    typedef Node<T> node;
    typedef ForwardListNode<T> Fnode;
    Fnode *head;
public:
    List(List& ptr){
        head=ptr.head;
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
    virtual T& front(void){
        return head->value;
    }

    // Retorna una referencia al ultimo elemento
    virtual T& back(void){
        Fnode *temp=head;
        while(head->next!= nullptr){
            temp=temp->next;
        }
        return temp->value;
    }

    virtual void push_back(const T& element){
        Fnode* temp= new Fnode(element);
        Fnode* tail=head;
        if(head== nullptr){
            head=temp;
        }
        while(temp->next!= nullptr){
            temp=temp->next;
            tail=tail->next;
        }
        tail->next=temp;
    }

    virtual void push_front(const T& element){
        Fnode* temp=new Fnode(element);
        if(head== nullptr){
            head=temp;
        }
        temp->next=head;
        head=temp;
    }

    virtual void popBack(void){
        Fnode* current=head;
        while(current->next!= nullptr){
            current=current->next;
        }
        delete current;
    }

    virtual void popFront(void){
        Fnode* current=head;
        head=head->next;
        current->next= nullptr;
        delete current;
    }

    virtual T& operator[] (const int& num){
        Fnode* current=head;
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
        Fnode *current=head;
        while(current!= nullptr){
            current=current->next;
            ++num;
        }
        return num;
    }

    void clear(void){
        while(head!= nullptr){
            popFront();
        }
    }

    void erase(node* ptr){
        Fnode* current=head;
        if(head==ptr){
            head=head->next;
            delete current;
        }
        Fnode* temp;
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
        Fnode* current=head;
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
        Fnode* temp;
        Fnode* current=head;
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
        Fnode* current=head;
        Fnode* temp;
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
        Fnode *current=head;
        push_front(head->value);
        popFront();
        while(current!= nullptr){
            current=current->next;
            push_front(current->value);
            popFront();
        }
    }

    template <typename A>
    inline friend ostream& operator<<(ostream& out, const List<A>& list){
        Fnode *ptr=list.head;
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

template <typename T>
class Iterator{
public:
    typedef T node_t;
    typedef typename node_t::value_t value_t;

protected:
    node_t * pointer;
public:

    Iterator(node_t* _pointer = nullptr):pointer(_pointer){}

    ~Iterator(void){}

    virtual bool operator!= (Iterator<T> it){
        return pointer != it.pointer;
    }

    virtual value_t& operator* (void) {
        return **pointer;
    }

/*virtual Iterator& operator++(void) const = 0;
virtual Iterator& operator++(int) const = 0;
virtual Iterator& operator--(void) const = 0;
virtual Iterator& operator--(int) const = 0;
*/
/*
virtual bool operator == (const Iterator&) const = 0;
virtual bool operator != (const Iterator&) const = 0;
virtual bool operator <= (const Iterator&) const = 0;
virtual bool operator >= (const Iterator&) const = 0;
virtual bool operator < (const Iterator&) const = 0;
virtual bool operator > (const Iterator&) const = 0;

virtual void operator=(const Iterator&) = 0;
*/
};

template <typename T>
class ForwardList : public List<T>{
public:
    typedef ForwardListNode<T> node_t;

    friend class ForwardIterator;
    class ForwardIterator: public Iterator<node_t> {
    public:
        typedef typename Iterator<node_t>::node_t node_t;
        typedef typename Iterator<node_t>::value_t value_t;

    public:
        ForwardIterator (node_t* pointer = nullptr)
                :Iterator<node_t>(pointer){
        }

        ~ForwardIterator (void){
        }

        ForwardIterator& operator++ (void){
            Iterator<node_t>::pointer = Iterator<node_t>::pointer->next;
            return *this;
        }

    };


protected:
    ForwardListNode<T> *head;
    ForwardListNode<T> *tail;

public:
    ForwardList(void)
            :List<T>(), head(nullptr), tail(nullptr){
    }

    ~ForwardList (void){
    }

    ForwardIterator begin(){
        return ForwardIterator(head);
    }

    ForwardIterator end(){
        return ForwardIterator(tail);
    }

    void push_back(const T& element){
        ForwardListNode<T> *new_node = new ForwardListNode<T>(element);
        if (!head){
            tail = head = new_node;
        } else {
            tail->next = new_node;
            tail = tail->next;
        }
    }

    void push_front(const T& element){
        ForwardListNode<T> *new_node = new ForwardListNode<T>(element);
        if (!head){
            tail = head = new_node;
        } else {
            ForwardListNode<T> * tmp = head;
            head = new_node;
            head->next = tmp;
        }
    }

    T& front(void){
        return head->value;
    };

    T& back(void){
        return tail->value;
    };

    Node<T>* pop_back(void){
        Node<T>* tmpRes = new Node<T>(tail->value);
        ForwardListNode<T> * tmpPointer = head;
        while(tmpPointer->next!=tail){
            tmpPointer = tmpPointer->next;
        }
        tail = tmpPointer;
        delete tail->next;
        tail->next = nullptr;
        return  tmpRes;
    };

    Node<T>* pop_front(void){
        Node<T>* tmpRes = new Node<T>(head->value);
        ForwardListNode<T> * tmpPointer = head;
        head = head->next;
        delete tmpPointer;
        return tmpRes;
    };

    T& operator[] (const int& _position){
        ForwardListNode<T> * tmp = head;
        for (int i = 0; i < _position; i++, tmp = tmp->next);
        return tmp->value;
    }

    bool empty(void){
        return head == nullptr;
    }

    unsigned int size(void){
        int i = 0;
        for (ForwardListNode<T> * tmp = head; tmp != nullptr; i++, tmp = tmp->next);
        return i;
    }

    template<typename _T>
    inline friend ostream& operator<< (ostream& out, ForwardList<_T>& _list){
        typename ForwardList<_T>::ForwardIterator it = _list.begin();
        for(; it != _list.end(); ++it){
            out << *it << " -> ";
        }
        out << *it << " -> ";
        /*
        if (!_list.head) return out;
        ForwardListNode<T> *tmp = _list.head;
        while(tmp){
            out << *tmp << " -> ";
            tmp = tmp->next;
        }
        */
        return out;
    }
};
