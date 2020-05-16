#include <iostream>
/*
#include "Circular_List.h"
#include "Doubly_Circular_List.h"
#include "Doubly_List.h"
#include "List.h"
#include "Node.h"
 */
#include "List_Types.h"

using namespace std;

int main(){

    typedef ForwardListNode<int> forward_node_t;
    typedef List<forward_node_t> list_t;
    typedef Iterator<int> iterator_t;

    typedef DoubleListNode<int> double_node_t;
    typedef List<double_node_t> dlist_t;

    typedef CircularListNode<int> circular_node_t;
    typedef List<circular_node_t> circularList_t;

    typedef DoublyCircularListNode<int> dcircular_node_t;
    typedef List<dcircular_node_t> dcircularList_t;

    list_t list;
    dlist_t dlist;
    circularList_t clist;
    dcircularList_t Dclist;

    cout<<"Linked list con type traits"<<endl;
    list<<10>>11>>2<<4<<2>>5<<1;
    list.pop_back();list.remove(2);list.pop_front();
    list.sort();
    list.reverse();
    list.size();
    //cout<<list[0];
    list.print();
    cout<<endl;

    cout<<"Doubly linked list con type traits"<<endl;
    dlist<<1>>0<<9>>1<<4;
    dlist.pop_front();
    dlist.sort();
    dlist.reverse();
    dlist.print();
    cout<<endl;

    cout<<"Circular linked list con type traits"<<endl;
    clist>>1>>3>>9<<4<<5;
    clist.pop_front();clist.pop_back();
    clist.sort();
    clist.reverse();
    clist.print();
    clist.size();
    cout<<endl;

    cout<<"Doubly circular linked list con type traits"<<endl;
    Dclist<<4>>3<<9>>1<<2<<9<<3;
    Dclist.pop_front();
    Dclist.pop_back();
    Dclist.remove(3);
    Dclist.sort();
    Dclist.reverse();
    //cout<<Dclist[0];
    Dclist.print();


    return 0;
}
