#include <iostream>
#include "Doubly_List.h"
#include "List.h"
#include "Node.h"

using namespace std;

int main(){

    cout<<"Linked list:"<<'\n';
    List::List<int> list;
    List::Iterator<int> it;
    list<< 5 << 6 >> 7 >>1 << 3 >>5;
    //list.reverse();
    list.remove(5);
    list[2]=0;
    list.sort();
    if(list[1]>list[4]){
        cout<<list[4]<<endl;
    }else cout<<list[1]<<endl;
    for(it=list.begin();it!=list.end();++it){
        cout<<*it<<" ";
    }
    cout<<'\n';
    list.pop_back();list.pop_front();
    for(it=list.begin();it!=list.end();++it){
        cout<<*it<<" ";
    }
    cout<<endl<<endl;

    cout<<"Doubly linked list:"<<endl;
    Dlist::Dlist<int> dlist;
    dlist<< 6 >> 2 >>3 << 9 << 6<<12;
    dlist.pop_back();dlist.pop_front();
    cout<<dlist<<'\n';
    cout<<"Elemento de la posición uno: "<<dlist[1]<<endl;
    cout<<"Lista vacía: "<<dlist.empty()<<'\n';
    dlist.clear();
    cout<<"Size de la lista: "<<dlist.size();


    return 0;
}
