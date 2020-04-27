//
// Created by Alejandro  Otero on 2020-04-13.
//
#pragma once

#include <iostream>

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

    ForwardListNode<T>* next;

    ForwardListNode(const T& _value):Node<T>(_value),next(nullptr){}

    ~ForwardListNode(void){}

    template <typename _T>
    inline friend ostream& operator<< (ostream& _out, const ForwardListNode<_T>& _node){
        _out << "Nodo: [v: " <<  _node.value << ", p: " << _node.next << "]";
        return _out;
    }
};

template <typename A>
class DoublyListNode: public Node<A>{
public:
    DoublyListNode<A> *next;
    DoublyListNode<A> *prev;

    DoublyListNode(const A& _value):Node<A>(_value),next(nullptr),prev(nullptr){}

    ~DoublyListNode(void){}

    template <typename _T>
    inline friend ostream& operator<< (ostream& _out, const DoublyListNode<_T>& _node){
        _out << "Nodo: [v: " <<  _node.value << ", p: " << _node.next << "]";
        return _out;
    }
};
