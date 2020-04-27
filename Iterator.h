//
// Created by Alejandro  Otero on 2020-04-26.
//

#pragma once

#include "Node.h"

template <typename T>
class Iterator{
protected:
    typedef Node<T> node_t;

    node_t * pointer;
public:

    Iterator():pointer(nullptr){}
    Iterator(node_t* _pointer):pointer(_pointer){}

    ~Iterator(void){}

    virtual bool operator!= (Iterator<T> it){
        return this->pointer != it.pointer;
    }

    T& operator* (void) {
        return this->pointer->value;
    }

    void operator++(void){
        this->pointer=this->pointer->next;
    }

    bool operator == (const Iterator& it){
        return this->pointer==it.pointer;
    }

    bool operator <= (const Iterator& it){
        return this->pointer<=it.pointer;
    }

    bool operator >= (const Iterator& it){
        return this->pointer>=it.pointer;
    }

    bool operator < (const Iterator& it){
        return this->pointer<it.pointer;
    }

    bool operator > (const Iterator&it ){
        return this->pointer>it.pointer;
    }

};

template <typename T>
class iterator: public Iterator<T>{
private:
    typedef DoublyListNode<T> Dnode;
    Dnode* ptr;
public:
    iterator(Dnode* _ptr):Iterator<T>(),ptr(_ptr){}

    ~iterator(void){}

    void operator --(){
        this->ptr=this->ptr->prev;
    }
};
