#include <iostream>
#include "List.h"
#include "Node.h"

using namespace std;

int main(){
    List<int> list;
    list.push_back(4);list.push_back(2);list.push_back(4);list.push_front(9);
    list.sort();
    //list.reverse();
    list.remove(4);
    cout<<list;

    return 0;
}
