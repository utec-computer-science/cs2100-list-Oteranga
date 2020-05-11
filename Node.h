//
// Created by Alejandro  Otero on 2020-04-13.
//
#pragma once

#include <iostream>

#define DEFAULT_NODE 0
#define FOWARD_NODE 1
#define DOUBLE_NODE 2

using namespace std;

template <typename T>
class Node {
public:
    T value;
    Node<T> *next;

    Node(T _value, Node<T>* _next):value(_value),next(_next){}

    ~Node(void){}

    template <typename _T>
    inline friend ostream& operator<< (ostream& _out, const Node<_T>& _node){
        _out << "Nodo: " <<  _node.value;
        return _out;
    }
};

template <typename A>
class DoublyListNode{
public:
    A value;
    DoublyListNode<A> *next;
    DoublyListNode<A> *prev;
    typedef DoublyListNode<A> Dnode;

    DoublyListNode(A _value):value(_value),next(nullptr),prev(nullptr){}

    ~DoublyListNode(void){}

    template <typename _T>
    inline friend ostream& operator<< (ostream& _out, const DoublyListNode<_T>& _node){
        _out << "Nodo: [v: " <<  _node.value << ", p: " << _node.next << "]";
        return _out;
    }
};


template <typename T, typename NT>
struct NodeTraits{
    static const int nodeType = DEFAULT_NODE;
};

template <typename NT>
struct NodeTraits< Node<NT>, NT >{
    static const int nodeType = FOWARD_NODE;
};

template <typename NT>
struct NodeTraits< DoublyListNode<NT>, NT >{
    static const int nodeType = DOUBLE_NODE;
};
