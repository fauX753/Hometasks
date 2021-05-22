#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

int main()
{
	int num = 0;
	std::cin >> num;
	std::vector<int> arr;
	while (--num >= 0) {
		int val = 0;
		std::cin >> val;
		arr.push_back(val);
	}
	auto size = arr.size();
	std::vector<int> path_len(size + 1);
	std::vector<int> pos(size + 1);
	for (size_t i = 0; i < size + 1; ++i) pos[i] = -1;
	path_len[0] = std::numeric_limits<int>::max();
	for (size_t i = 1; i < size + 1; ++i) path_len[i] = std::numeric_limits<int>::min();

	for (size_t i = 0; i < size; ++i) {
		size_t j = static_cast<size_t>(std::upper_bound(path_len.begin(), path_len.end(), arr[i],
			[](int e1, int e2) { return e1 > e2;}) - path_len.begin());
		if ((path_len[j] < arr[i]) && (path_len[j - 1] >= arr[i])) {
			path_len[j] = arr[i];
			pos[j] = i;
		}
		else if (j == 0) {
			path_len[1] = arr[0];
			pos[1] = 0;
		}
	}
	auto res = std::count_if(path_len.begin(), path_len.end(), [](int e1) {return e1 > std::numeric_limits<int>::min() && e1 < std::numeric_limits<int>::max();});
	std::cout << res << std::endl;
	std::ostringstream oss;
	for (int i = 0; i < size + 1; ++i) {
		if (pos[i] >= 0) {
			oss << pos[i] + 1 << " ";
		}
	}
	std::cout << oss.str() << std::endl;

	return 0;
}