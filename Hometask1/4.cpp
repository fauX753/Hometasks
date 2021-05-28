#include <cassert>
#include <iostream>

template <class Int>
Int gcd(Int a, Int b) {
  assert(a > 0 && b > 0);
  // optimize this function
    while (a != b) {
        if (a > b) {
            long tmp = a;
            a = b;
            b = tmp;
        }
        b = b - a;
    }
    return a;
}

int main(void) {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd(a, b) << std::endl;
  return 0;
}