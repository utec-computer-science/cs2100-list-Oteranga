//
// Created by Alejandro  Otero on 2020-04-13.
//
#pragma

#include <iostream>

using namespace std;

template <typename T>
class Node {
public:
    T value;
    Node<T> * next;

    Node(void){

    }

    ~Node(void){
    }
};
