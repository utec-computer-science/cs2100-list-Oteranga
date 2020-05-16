//
// Created by Alejandro  Otero on 2020-05-12.
//

#pragma once

#define DEFAULT_NODE 0
#define FOWARD_NODE 1
#define DOUBLE_NODE 2
#define CIRCULAR_NODE 3
#define DOUBLE_CIRCULAR_NODE 4

#include<iostream>
using namespace std;

template <typename T>
class Node {
public:
    typedef T value_t;
    typedef unsigned int size_t;

public:
    value_t value;

public:
    Node(const value_t& _value):value(_value){
    }

    size_t size(){
        return 0;
    }

    ~Node(void){
    }

    value_t& operator*(void){
        return value;
    }

    template <typename _T>
    inline friend ostream& operator<< (ostream& _out, const Node<_T>& _node){
        _out << "Nodo: " <<  _node.value;
        return _out;
    }
};


template <typename T>
class ForwardListNode : public Node<T> {
public:
    typedef typename Node<T>::value_t value_t;

public:
    ForwardListNode<T>* next;

public:
    ForwardListNode(const T& _value):Node<T>(_value),next(nullptr){
    }

    ~ForwardListNode(void){
    }

    template <typename _T>
    inline friend ostream& operator<< (ostream& _out, const ForwardListNode<_T>& _node){
        _out << "Nodo: [v: " <<  _node.value << ", p: " << _node.next << "]";
        return _out;
    }
};

template <typename T>
class DoubleListNode : public Node<T> {
public:
    typedef typename Node<T>::value_t value_t;

public:
    DoubleListNode<T>* next;
    DoubleListNode<T>* prev;

public:
    DoubleListNode(const T& _value):Node<T>(_value),next(nullptr),prev(nullptr){
    }

    ~DoubleListNode(void){
    }

    template <typename _T>
    inline friend ostream& operator<< (ostream& _out, const DoubleListNode<_T>& _node){
        _out << "Nodo: [v: " <<  _node.value << ", p_next: " << _node.next << ", p_prev: " << _node.next << "]";
        return _out;
    }
};

template <typename T>
class CircularListNode : public Node<T> {
public:
    typedef typename Node<T>::value_t value_t;

public:
    CircularListNode<T>* next;

public:
    CircularListNode(const T& _value):Node<T>(_value),next(nullptr){
    }

    ~CircularListNode(void){
    }

    template <typename _T>
    inline friend ostream& operator<< (ostream& _out, const CircularListNode<_T>& _node){
        _out << "Nodo: [v: " <<  _node.value << ", p_next: " << _node.next << ", p_prev: " << _node.next << "]";
        return _out;
    }
};

template <typename T>
class DoublyCircularListNode : public Node<T> {
public:
    typedef typename Node<T>::value_t value_t;

public:
    DoublyCircularListNode<T>* next;
    DoublyCircularListNode<T>* prev;

public:
    DoublyCircularListNode(const T& _value):Node<T>(_value),next(nullptr),prev(nullptr){
    }

    ~DoublyCircularListNode(void){
    }

    template <typename _T>
    inline friend ostream& operator<< (ostream& _out, const DoublyCircularListNode<_T>& _node){
        _out << "Nodo: [v: " <<  _node.value << ", p_next: " << _node.next << ", p_prev: " << _node.next << "]";
        return _out;
    }
};

template <typename T, typename NT>
struct NodeTraits{
    static const int nodeType = DEFAULT_NODE;
};

template <typename NT>
struct NodeTraits< ForwardListNode<NT>, NT >{
    static const int nodeType = FOWARD_NODE;
};

template <typename NT>
struct NodeTraits< DoubleListNode<NT>, NT >{
    static const int nodeType = DOUBLE_NODE;
};

template <typename NT>
struct NodeTraits< CircularListNode<NT>, NT >{
    static const int nodeType = CIRCULAR_NODE;
};

template <typename NT>
struct NodeTraits< DoublyCircularListNode<NT>, NT >{
    static const int nodeType = DOUBLE_CIRCULAR_NODE;
};


template <typename Node>
class Iterator{
public:
    typedef Node node_t;
    typedef typename node_t::value_t value_t;

protected:
    node_t * pointer;
public:

    Iterator(node_t* _pointer = nullptr):pointer(_pointer){}

    ~Iterator(void){}

    bool operator!= (Iterator it){
        return pointer != it.pointer;
    }

    value_t& operator* (void) {
        return **pointer;
    }

    Iterator& operator++ (void){
        Iterator<node_t>::pointer = Iterator<node_t>::pointer->next;
        return *this;
    }
};


template <typename Node>
class List {
protected:
    typedef Node node_t;
    typedef typename node_t::value_t value_t;
    typedef Iterator<Node> Iterator;

protected:
    node_t* head;
    node_t* tail;

    template<int nodeType>
    void push_back_imp(Node**,Node**,value_t);

    template<int nodeType>
    void push_front_imp(Node**,Node**,value_t);

    template<int nodeType>
    void pop_back_imp(Node**,Node**);

    template<int nodeType>
    void pop_front_imp(Node**,Node**);

    template<int nodeType>
    void remove_imp(Node**,Node**,value_t);

    template <int nodeType>
    void reverse_imp(Node**,Node**);

    template <int nodeType>
    void sort_imp(Node**,Node**);

    template <int nodeType>
    void print_imp(Node**,Node**);

    template <int nodeType>
    unsigned int size_imp(Node**,Node**);

public:
    List(const List& ptr){
        head = ptr.head;
        tail = ptr.tail;
    }

    List(value_t* arr, size_t size):head(nullptr),tail(nullptr){
        head=tail= nullptr;
        for(int i=0; i<size; i++){
            push_back(arr[i]);
        }
    }

    List(node_t* temp){
        head=tail=temp;
    }

    List(int n){
        for(int i=0; i<n; i++){
            push_back(rand()%100+1);
        }
    }

    List(void):head(nullptr),tail(nullptr){
    }

    ~List(void){}


    void push_back(const value_t& element){
        push_back_imp<NodeTraits<node_t,value_t>::nodeType>(&head,&tail,element);
    }

    void push_front(const value_t& element){
        push_front_imp<NodeTraits<node_t,value_t>::nodeType>(&head,&tail,element);
    }

    value_t& front(void){
        return head->value;
    }
    value_t& back(void){
        return tail->value;
    }

    void pop_back(void){
        pop_back_imp<NodeTraits<node_t,value_t>::nodeType>(&head,&tail);
    }
    void pop_front(void){
        pop_front_imp<NodeTraits<node_t,value_t>::nodeType>(&head,&tail);
    }

    value_t& operator[] (const int& value){
        node_t* current=head;
        for(size_t i=0; i<value; i++){
            current=current->next;
        }
        return current->value;
    }

    bool empty(void){
        return head == nullptr;
    };

    unsigned int size(void){
        size_imp<NodeTraits<node_t ,value_t>::nodeType>(&head,&tail);
    }

    void reverse(){
        reverse_imp<NodeTraits<node_t,value_t>::nodeType>(&head,&tail);
    }

    void remove(const value_t& element){
        remove_imp<NodeTraits<node_t, value_t>::nodeType>(&head,&tail,element);
    }

    void sort(){
        sort_imp<NodeTraits<node_t ,value_t>::nodeType>(&head,&tail);
    }

    //iterators
    Iterator begin(){
        return Iterator(head);
    }

    Iterator end(){
        return Iterator(tail);
    }


    void print(){
        print_imp<NodeTraits<node_t,value_t>::nodeType>(&head,&tail);
    }

    /*
    template<typename _T>
    inline friend ostream& operator<< (ostream& out, const List<_T>& _list){


        typename List<_T>::Iterator it = _list.begin();
        for(; it != _list.end(); ++it){
            out << *it << " -> ";
        }
        out << *it << " -> ";

        if (!_list.head) return out;
        ForwardListNode<T> *tmp = _list.head;
        while(tmp){
            out << *tmp << " -> ";
            tmp = tmp->next;
        }

        return out;
    }
     */


    List& operator<< (const value_t& _value){
        this->push_back(_value);
        return *this;
    }

    List& operator>> (const value_t& _value){
        this->push_front(_value);
        return *this;
    }
};

template <typename Node, typename ValueNode, int nodeType>
class ListHelper{
public:
    static void push_back_imp(Node** &head, Node** &tail, ValueNode element){

    }
    static void push_front_imp(Node** &head, Node** &tail, ValueNode element){

    }

    static void pop_back_imp(Node** &head, Node** &tail){

    }

    static void pop_front_imp(Node** &head, Node** &tail){

    }
    static void remove_imp(Node** &head, Node** &tail, ValueNode element){

    }

    static void reverse_imp(Node** &head, Node** &tail){

    }

    static void sort_imp(Node** &head, Node** &tail){

    }

    static void print_imp(Node** &head, Node** &tail){

    }

    static unsigned int size_imp(Node** &head, Node** &tail){

    }
};

template <typename Node, typename ValueNode>
class ListHelper<Node,ValueNode,FOWARD_NODE>{
public:
    static void push_back_imp(Node** &head, Node** &tail, ValueNode element){
        Node *new_node = new Node{element};
        if (!*head){
            *tail = *head = new_node;
        } else {
            (*tail)->next = new_node;
            (*tail) = (*tail)->next;
        }
    }

    static void push_front_imp(Node** &head, Node** &tail, ValueNode element){
        Node *temp = new Node(element);
        if (*head == nullptr) {
            *head = *tail = temp;
        }
        temp->next = *head;
        *head = temp;
    }

    static void pop_back_imp(Node** &head, Node** &tail){
        Node *current = (*head);
        while (current->next != (*tail)) {
            current = current->next;
        }
        (*tail) = current;
        delete (*tail)->next;
        (*tail)->next = nullptr;
    }

    static void pop_front_imp(Node** &head, Node** &tail){
        Node *current = (*head);
        (*head) = (*head)->next;
        delete current;
    }

    static void remove_imp(Node** &head,Node** &tail,ValueNode element){
        Node *current = (*head);
        Node *temp=current;
        while (current != nullptr) {
        if((*head)->value==element){
            pop_front_imp(head,tail);
        }else if((*tail)->value==element)
            pop_back_imp(head,tail);
        else {
            if (current->value == element) {
                temp->next = current->next;
                delete current;
                current = temp->next;
            }
            temp = current;
        }
            current = current->next;
        }
    }

    static void reverse_imp(Node** &head, Node** &tail){
        if((*head)!= nullptr) {
            Node* current=(*head);
            Node* next_node=(*head);
            Node* prev= nullptr;
            while(next_node!= nullptr){
                next_node=next_node->next;
                current->next=prev;
                prev=current;
                current=next_node;
            }
            tail=head;
            *head=prev;
        }
    }

    static void sort_imp(Node** &head, Node** &tail){
        Node *current = (*head);
        Node *temp;
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

    static void print_imp(Node** &head, Node** &tail){
        Node* current=(*head);
        while(current){
            cout<<current->value<<" ";
            current=current->next;
        }
    }

    static unsigned int size_imp(Node** &head, Node** &tail){
        int num=0;
        Node* current=(*head);
        while(current!= nullptr){
            current=current->next;
            num++;
        }
        return num;
    }
};

template <typename Node, typename ValueNode>
class ListHelper<Node,ValueNode,DOUBLE_NODE>{
public:
    static void push_back_imp(Node** &head, Node** &tail, ValueNode element){
        Node *current= new Node(element);
        if((*head)== nullptr){
            *head=*tail=current;
        }else {
            (*tail)->next = current;
            current->prev = (*tail);
            (*tail) = current;
        }
    }

    static void push_front_imp(Node** &head, Node** &tail, ValueNode element){
        Node *current= new Node(element);
        if((*head)== nullptr){
            *head=*tail=current;
        }else{
            current->next=(*head);
            (*head)->prev=current;
            (*head)=current;
        }
    }

    static void pop_back_imp(Node** &head, Node** &tail){
        if((*tail)== nullptr)
            return;
        else {
            Node *temp = (*tail);
            (*tail)->prev->next = nullptr;
            *tail = (*tail)->prev;
            delete temp;
        }
    }

    static void pop_front_imp(Node** &head, Node** &tail){
        if((*head)== nullptr)
            return;
        else {
            Node *temp = (*head);
            *head = (*head)->next;
            (*head)->prev = nullptr;
            delete temp;
        }
    }

    static void remove_imp(Node** &head,Node** &tail,ValueNode element){
        Node* temp=(*head);
        while(temp!= nullptr){
            if(temp->value==element){
                if(temp==*head)
                    pop_front_imp();
                else if(temp== *tail)
                    pop_back_imp();
                else{
                    Node* current=temp;
                    current->prev->next=current->next;
                    current->next->prev=current->prev;
                    delete current;
                }
            }
            temp=temp->next;
        }
    }

    static void reverse_imp(Node** &head, Node** &tail){
        if((*head)!= nullptr){
            Node* current=(*head);
            Node* next_node;
            while(current!= nullptr) {
                next_node = current->next;
                current->next = current->prev;
                current->prev = next_node;
                current=next_node;
            }
            current=(*head);
            *head=*tail;
            *tail=current;
        }
    }

    static void sort_imp(Node** &head, Node** &tail){
        Node* current=(*head);
        Node* temp;
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

    static void print_imp(Node** &head, Node** &tail){
        Node* current=(*head);
        while(current){
            cout<<current->value<<" ";
            current=current->next;
        }
    }

    static unsigned int size_imp(Node** &head, Node** &tail){
        int num=0;
        Node* current=(*head);
        while(current!= nullptr){
            current=current->next;
            num++;
        }
        return num;
    }
};

template <typename Node, typename ValueNode>
class ListHelper<Node,ValueNode,CIRCULAR_NODE>{
public:
    static void push_back_imp(Node** &head, Node** &tail, ValueNode element){
        Node* temp=new Node(element);
        if((*head)== nullptr) {
            *head = *tail = temp;
            (*head)->next=(*tail);
            (*tail)->next=(*head);
        }
        else{
            (*tail)->next=temp;
            *tail=temp;
            temp->next=(*head);
        }
    }

    static void push_front_imp(Node** &head, Node** &tail, ValueNode element){
        Node* temp=new Node(element);
        if((*head)== nullptr) {
            *head = *tail = temp;
            (*head)->next = (*tail);
            (*tail)->next = (*head);
        }
        else{
            (*tail)->next=temp;
            temp->next=(*head);
            (*head)=temp;
        }
    }

    static void pop_back_imp(Node** &head, Node** &tail){
        Node* current=(*head);
        while(current->next!=(*tail)){
            current=current->next;
        }
        (*tail)=current;
        (*tail)->next=(*head);
        delete current;
    }

    static void pop_front_imp(Node** head, Node** tail){
        if(*head!= nullptr) {
            Node* temp=(*head);
            *head=(*head)->next;
            (*tail)->next=(*head);
            delete temp;
        }
    }

    static void remove_imp(Node** &head,Node** &tail,ValueNode element){
        Node* current=*head;
        Node* prev_node=current;
        current=current->next;
        while(current!=(*head)) {
            if(prev_node->value==element) {
                if ((*head)->value == element)
                    pop_front_imp(head,tail);
                else if ((*tail)->value == element)
                    pop_back_imp(head,tail);
                else {
                    Node* temp=(*head);
                    while (temp->next!=prev_node){
                        temp=temp->next;
                    }
                    temp->next = current;
                    delete prev_node;
                }
            }
            prev_node = current;
            current = current->next;
        }
        if(prev_node->value==(*tail)->value)
            pop_back_imp(head,tail);
    }

    static void reverse_imp(Node** &head, Node** &tail){
        if((*head)!= nullptr){
            Node* current=(*head);
            Node* prev_node;
            Node* next_node;
            next_node=current->next;
            while(current!=(*tail)){
                prev_node=current;
                current=next_node;
                next_node=current->next;
                current->next=prev_node;
            }
            (*head)->next=*tail;
            current=(*head);
            *head=*tail;
            *tail=current;
        }
    }

    static void sort_imp(Node** &head, Node** &tail){
        Node* current=(*head);
        Node* index;
        int temp;
        while(current!=(*tail)){
            index=current->next;
            while(index!=(*head)){
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

    static void print_imp(Node** &head, Node** &tail){
        Node* current=(*head);
        while(current!=(*tail)){
            cout<<current->value<<" ";
            current=current->next;
        }
        cout<<current->value;
    }

    static unsigned int size_imp(Node** &head, Node** &tail){
        int num=1;
        Node* current=(*head);
        while(current!=(*tail)){
            current=current->next;
            num++;
        }
        return num;
    }
};

template <typename Node, typename ValueNode>
class ListHelper<Node,ValueNode,DOUBLE_CIRCULAR_NODE>{
public:
    static void push_back_imp(Node** &head, Node** &tail, ValueNode element){
        Node* temp=new Node(element);
        if(*head== nullptr){
            temp->next=temp;
            temp->prev=temp;
            *head=*tail=temp;
        } else{
            temp->prev=(*tail);
            (*tail)->next=temp;
            temp->next=(*head);
            (*head)->prev=temp;
            *tail=temp;
        }
    }

    static void push_front_imp(Node** &head, Node** &tail, ValueNode element){
        Node* temp=new Node(element);
        if(*head== nullptr){
            (*head)=temp;
            temp->next=(*head);
            temp->prev=(*head);
        }else{
            temp->next=(*head);
            (*head)->prev=temp;
            temp->prev=(*tail);
            (*tail)->next=temp;
            *head=temp;
        }
    }

    static void pop_back_imp(Node** &head, Node** &tail){
        Node* current=(*head);
        if((*head)->prev== nullptr)
            return;
        else if((*head)->next==(*head)){
            *head= *tail=nullptr;
            delete current;
        }
        Node* temp=(*tail)->prev;
        current=(*tail);
        temp->next=(*head);
        (*head)->prev=temp;
        *tail=temp;
        delete current;
    }

    static void pop_front_imp(Node** &head, Node** &tail){
        Node* current=(*head);
        if(*head== nullptr)
            return;
        else if((*head)->next==(*head)){
            *head= *tail=nullptr;
            delete current;
        }else {
            *head=(*head)->next;
            (*head)->prev=*tail;
            (*tail)->next=*head;
            delete current;
        }
    }

    static void remove_imp(Node** &head,Node** &tail,ValueNode element){
        Node* temp=(*head);
        while(temp!= (*head)->prev){
            if(temp->value==element){
                if(temp==(*head))
                    pop_front_imp(head,tail);
                else if(temp== (*head)->prev)
                    pop_back_imp(head,tail);
                else{
                    Node* current=temp;
                    current->prev->next=current->next;
                    current->next->prev=current->prev;
                    delete current;
                }
            }
            temp=temp->next;
        }
        if(temp->value==(*head)->prev->value)
            pop_back_imp(head,tail);
    }

    static void reverse_imp(Node** &head, Node** &tail){
        if((*head)!= nullptr){
            Node* current=(*head);
            Node* temp=current->next;
            current->prev=temp;
            while(temp!=(*head)){
                temp->prev=temp->next;
                temp->next=current;
                current=temp;
                temp=temp->prev;
            }
            *head=current;
            (*tail)=(*head)->prev;
        }
    }

    static void sort_imp(Node** &head, Node** &tail){
        Node* current=(*head);
        Node* index;
        int temp;
        while(current!=(*tail)){
            index=current->next;
            while (index!=(*head)){
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

    static void print_imp(Node** &head, Node** &tail){
        Node* current=(*head);
        while(current!=(*tail)){
            cout<<current->value<<" ";
            current=current->next;
        }
        cout<<current->value;
    }

    static unsigned int size_imp(Node** &head, Node** &tail){
        int num=1;
        Node* current=(*head);
        while(current!=(*tail)){
            current=current->next;
            num++;
        }
        return num;
    }
};

template< typename Node>  template <int nodeType>
void List<Node>::push_back_imp(
        typename List<Node>::node_t ** head,
        typename List<Node>::node_t ** tail,
        typename List<Node>::value_t element){

    ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::push_back_imp(head,tail,element);
}

template< typename Node>  template <int nodeType>
void List<Node>::push_front_imp(
        typename List<Node>::node_t ** head,
        typename List<Node>::node_t ** tail,
        typename List<Node>::value_t element){

    ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::push_front_imp(head,tail,element);
}

template< typename Node>  template <int nodeType>
void List<Node>::pop_front_imp(
        typename List<Node>::node_t ** head,
        typename List<Node>::node_t ** tail){

    ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::pop_front_imp(head,tail);
}

template< typename Node>  template <int nodeType>
void List<Node>::pop_back_imp(
        typename List<Node>::node_t ** head,
        typename List<Node>::node_t ** tail){

    ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::pop_back_imp(head,tail);
}

template< typename Node>  template <int nodeType>
void List<Node>::remove_imp(
        typename List<Node>::node_t ** head,
        typename List<Node>::node_t ** tail,
        typename List<Node>::value_t element){

    ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::remove_imp(head,tail,element);
}

template <typename Node> template <int nodeType>
void List<Node>::reverse_imp(
        typename List<Node>::node_t ** head,
        typename List<Node>::node_t ** tail){

    ListHelper<List<Node>::node_t ,List<Node>::value_t,nodeType>::reverse_imp(head,tail);
}

template <typename Node> template <int nodeType>
void List<Node>::sort_imp(
        typename List<Node>::node_t ** head,
        typename List<Node>::node_t ** tail){
    ListHelper<List<Node>::node_t, List<Node>::value_t,nodeType>::sort_imp(head,tail);
}

template <typename Node> template <int nodeType>
void List<Node>::print_imp(
        typename List<Node>::node_t ** head,
        typename List<Node>::node_t ** tail){
    ListHelper<List<Node>::node_t ,List<Node>::value_t,nodeType>::print_imp(head,tail);
}

template <typename Node> template <int nodeType>
unsigned int List<Node>::size_imp(
        typename List<Node>::node_t ** head,
        typename List<Node>::node_t ** tail){
    ListHelper<List<Node>::node_t ,List<Node>::value_t,nodeType>::size_imp(head,tail);
}


