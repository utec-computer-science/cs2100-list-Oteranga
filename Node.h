//
// Created by Alejandro  Otero on 2020-04-13.
//

#pragma

#include <iostream>

using namespace std;

template <typename T>
class Node {
protected:
    T value;
    Node<T> * next;

public:
    Node(void){
    }

    ~Node(void){
    }
};
