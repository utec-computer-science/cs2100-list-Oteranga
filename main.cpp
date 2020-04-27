#include <iostream>
#include "Doubly_List.h"
#include "List.h"
#include "Node.h"
#include "Iterator.h"

using namespace std;

int main(){

    List<int> list;
    Iterator<int> it;
    list<< 5 << 6 >> 7 >>1 << 3;
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

    return 0;
}
