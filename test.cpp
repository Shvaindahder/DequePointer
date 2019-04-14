#include <iostream>
#include <deque>

using namespace std;

int main(int argc, char const *argv[]) {
  deque<int> dec;
  dec.push_front(1);
  dec.push_back(2);
  dec.push_front(0);
  dec.push_back(3);
  cout<<dec[2];
  return 0;
}
