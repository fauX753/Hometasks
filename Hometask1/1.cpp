#include <cassert>
#include <iostream>

class Fibonacci {
 public:
  static int get(int n) {
    assert(n >= 0);
    int k=0;
    if(n>1){
        k=Fibonacci::get(n-1);
        k+=Fibonacci::get(n-2);
    }else if(n==1){
        k=1;
    }else if(n==0){
        k=0;
    }
    return k;
  }
};

int main(void) {
  int n;
  std::cin >> n;
  std::cout << Fibonacci::get(n) << std::endl;
  return 0;
}