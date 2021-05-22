#include <iostream>
#include <sstream>
#include <vector>


int main()
{
	int n = 0;
	std::cin >> n;
	std::vector<unsigned int> b(11);
	while (--n >= 0) {
		unsigned int value = 0;
		std::cin >> value;
		b[value] += 1;
	}
	std::ostringstream oss;
	for (unsigned int i = 0; i < 11; ++i)
		for (unsigned int j = 0; j < b[i]; ++j) oss << i << " ";
	std::cout << oss.str() << std::endl;
	return 0;
}