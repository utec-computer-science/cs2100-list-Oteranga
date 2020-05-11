#include <iostream>
#include "Circular_List.h"
#include "Doubly_Circular_List.h"
#include "Doubly_List.h"
#include "List.h"
#include "Node.h"

using namespace std;

int main(){

    cout<<"Linked list:"<<'\n';
    List::List<int> list;
    List::Iterator<int> it;
    list<< 5 << 6 >> 7 >>1 << 3 >>5;

    list.reverse();
    list.remove(5);
    list[2]=0;
    //list.sort();
    if(list[1]>list[4]){
        cout<<"Probando los operadores de mayor menor: "<<list[4]<<endl;
    }else cout<<"Probando los operadores de mayor menor: "<<list[1]<<endl;
    cout<<"Elementos de la lista: ";
    for(it=list.begin();it!=list.end();++it){
        cout<<*it<<" ";
    }
    cout<<'\n';
    list.pop_back();list.pop_front();
    for(it=list.begin();it!=list.end();++it){
        cout<<*it<<" ";
    }
    cout<<endl;
    cout<<"Tamaño de la lista: "<<list.size();
    cout<<endl<<endl;

    /*
    cout<<"Doubly linked list:"<<endl;
    Dlist::Dlist<int> dlist;
    dlist<< 6 >> 2 >>3 << 9 << 6 << 12;
    dlist.pop_back();
    //dlist.sort();
    //dlist.remove(3);
    dlist.reverse();
    cout<<dlist<<'\n';
    cout<<"Elemento de la posición uno: "<<dlist[0]<<endl;
    cout<<"Lista vacía: "<<dlist.empty()<<'\n';
    cout<<"Size de la lista: "<<dlist.size();
    cout<<endl<<endl;


    cout<<"Circular linked list: "<<endl;
    Clist::Circular_List<int> Clist;
    Clist::Iterator<int> i;
    Clist.push_back(5);Clist.push_front(2);
    Clist<<6 >> 1 >>7 >> 2 << 2 >>0;
    Clist.pop_front();Clist.pop_back();
    Clist.sort();
    //Clist.remove(2);
    //Clist.reverse();
    for(i=Clist.begin(); i!=Clist.end();++i){
        cout<<*i<<" ";
    }
    cout<<Clist[Clist.size()-1];
    cout<<endl;
    //Clist.clear();
    cout<<"Tamaño de la lista: "<<Clist.size()<<endl;
    cout<<"Elemento de la posición dos: "<<Clist[1];

    cout<<endl<<endl;




    cout<<"Doubly circular linked list: "<<'\n';
    DCircular_List::Doubly_Circular_List<int> DCircular_list;
    DCircular_List::Iterator<int> e;
    DCircular_list >> 4 << 2 >> 3 >> 7 << 9 >> 2 >> 1;
    DCircular_list.pop_front();DCircular_list.pop_back();
    DCircular_list.sort();
    DCircular_list.reverse();
    DCircular_list.remove(2);
    for(e=DCircular_list.begin(); e!=DCircular_list.end(); ++e){
        cout<<*e<<" ";
    }
    cout<<DCircular_list[DCircular_list.size()-1];
    cout<<endl;
    cout<<"Tamaño de la lista: "<<DCircular_list.size();
*/

    return 0;
}
