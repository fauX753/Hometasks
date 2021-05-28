#include <iostream>
#include <vector>
#include <climits>

int main() {
  int N;
  std::cin >> N;
  std::vector<int> steps(N + 1, INT_MAX);
  steps[N] = 0;
  std::vector<int> next_num(N + 1, -1);

  for (int i = N; i > 1; --i) {
    int s = steps[i] + 1;
    // 3 * x
    if (!(i % 3) && steps[i / 3] > s) {
      steps[i / 3] = s;
      next_num[i / 3] = i;
    }
    // 2 * x
    if (!(i % 2) && steps[i / 2] > s) {
      steps[i / 2] = s;
      next_num[i / 2] = i;
    }
    // x + 1
    if (steps[i - 1] > s) {
      steps[i - 1] = s;
      next_num[i - 1] = i;
    }
  }

  std::cout << steps[1] << std::endl;
  for (int i = 1; i != -1; i = next_num[i])
    std::cout << i << ' ';
  std::cout << std::endl;
}
