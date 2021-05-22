#include <iostream>
#include <vector>

std::vector<unsigned int> merge(std::vector<unsigned int> a1, std::vector<unsigned int> a2, long& count) {
	std::vector<unsigned int> result;
	auto p1 = a1.begin();
	auto p2 = a2.begin();
	bool isP2 = false, isP1 = false;
	while (true) {
		if (*p1 <= *p2) {
			result.push_back(*p1);
			p1++;
			if (p1 == a1.end()) {
				isP1 = true;
				break;
			}
		}
		else {
			size_t c = (a1.end() - p1);
			count += c;
			result.push_back(*p2);
			p2++;
			if (p2 == a2.end()) {
				isP2 = true;
				break;
			}
		}
	}
	if (isP1) result.insert(result.end(), p2, a2.end());
	else result.insert(result.end(), p1, a1.end());
	return result;
}

std::vector<unsigned int> merge_sort(std::vector<unsigned int>& a, size_t l, size_t r, long& count) {
	if (r == l) {
		std::vector<unsigned int> vec;
		vec.push_back(a[r]);
		return vec;
	}
	size_t m = l + (r - l) / 2;
	return merge(merge_sort(a, l, m, count), merge_sort(a, m + 1, r, count), count);

}

int main()
{
	unsigned int size = 0;
	std::vector<unsigned int> mas;
	std::cin >> size;
	while (size-- >= 1) {
		unsigned int val = 0;
		std::cin >> val;
		mas.push_back(val);
	}
	long count = 0;
	auto a = merge_sort(mas, 0, mas.size() - 1, count);
	std::cout << count << std::endl;
	return 0;
}
