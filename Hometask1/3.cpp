#include <cassert>
#include <iostream>
#include <vector>

class Fibonacci {
 public:
  static int get_remainder(long long n, int m) {
    assert(n >= 1);
    assert(m >= 2);
    std::vector<long long> fib(2);
	fib[0] = 0;
	fib[1] = 1;
	long long t = 0;
    
    for (long long j = 2; j < m*m+1; ++j) {	
		fib.push_back((fib[j - 1] + fib[j - 2]) % m);
		++t;
		if ((fib[j] == 1) && (fib[j - 1] == 0)) break;
	}
      
    return fib[(n % t)] ;
  }
};

int main(void) {
  long long n;
  int m;
  std::cin >> n >> m;
  std::cout << Fibonacci::get_remainder(n, m) << std::endl;
  return 0;
}