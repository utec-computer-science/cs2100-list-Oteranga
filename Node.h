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
    Node<T> * next;

    Node(T _value,Node<T>* _next):value(_value),next(_next){}

    ~Node(void){
    }
};
