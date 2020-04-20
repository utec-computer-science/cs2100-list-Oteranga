#include <iostream>
#include "List.h"
#include "Node.h"

using namespace std;

int main(){
    List<int> list(5);
    list.push_front(6);
    cout<<list;

    return 0;
}
