#include <iostream>
#include "Deque.cpp"

using namespace std;

int main() {
    Deque deq(0);
    deq.push_back(1);
    deq.push_back(2);
    deq.push_back(10);
    deq.push_back(4);
    deq.push_back(0);
    deq.print_deque();
    cout<<deq[0]<<deq[1]<<deq[2]<<deq[3]<<deq[4]<<endl;
    deq.print_deque();
    return 0;
}
