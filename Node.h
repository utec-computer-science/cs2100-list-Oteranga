//
// Created by Alejandro  Otero on 2020-04-13.
//
#pragma once

#include <iostream>

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
    DoublyListNode<A> *next;
    DoublyListNode<A> *prev;

    DoublyListNode():DoublyListNode<A>(0),next(nullptr),prev(nullptr){}

    ~DoublyListNode(void){}

    template <typename _T>
    inline friend ostream& operator<< (ostream& _out, const DoublyListNode<_T>& _node){
        _out << "Nodo: [v: " <<  _node.value << ", p: " << _node.next << "]";
        return _out;
    }
};
