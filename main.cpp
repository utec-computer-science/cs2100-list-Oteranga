#include <iostream>
#include "List.h"
#include "Node.h"

using namespace std;

int main(){
    List<int> list;
    list.push_back(6);list.push_back(7);list.push_back(8);list.push_front(5);
    list.pop_back();
    cout<<list;

    return 0;
}
