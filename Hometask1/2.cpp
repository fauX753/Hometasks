#include <cassert>
#include <iostream>

class Fibonacci {
 public:
  static int get_last_digit(int n) {
    assert(n >= 1);
    // put your code here
    int k=1,last=1,prelast=1;
    for(int i=2;i<n;i++){
        k=(last+prelast)%10;
        prelast=last;
        last=k;
    }
    
    return k;
  }
};

int main(void) {
  int n;
  std::cin >> n;
  std::cout << Fibonacci::get_last_digit(n) << std::endl;
  return 0;
}