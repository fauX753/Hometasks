#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>


int main()
{
	unsigned int num_lines = 0, num_points = 0;
	std::vector<std::pair<int, int>> lines;
	std::vector<std::pair<int, int>> points;
	std::cin >> num_lines >> num_points;
	while (num_lines-- >= 1) {
		int a = 0, b = 0;
		std::cin >> a >> b;
		lines.push_back(std::make_pair(a, b));
	}
	int counter = 0;
	while (counter < num_points) {
		int pt = 0;
		std::cin >> pt;
		points.push_back(std::make_pair(counter, pt));
		++counter;
	}
	std::stable_sort(points.begin(), points.end(), [](const std::pair<int, int> &e1, const std::pair<int, int> &e2) {return e1.second < e2.second;});
	std::stable_sort(lines.begin(), lines.end(), [](const std::pair<int, int> &e1, const std::pair<int, int> &e2) {return e1.first < e2.first;});
	std::vector<std::pair<int, int>> part;
	part.insert(part.begin(), lines.begin(), lines.end());
	std::stable_sort(part.begin(), part.end(), [](const std::pair<int, int> &e1, const std::pair<int, int> &e2) {return e1.second < e2.second;});
	std::vector<std::pair<int, int>> numbers;
	num_points = points.size();
	auto i_pt = points.begin();
	int prev_pt = (*i_pt).second;
	int prev_num = 0;
	bool is_prev = false;
	auto prev_iter_left = lines.begin();
	auto prev_iter_right = part.begin();
	while (num_points > numbers.size()) { // Пока пройдены не все точки
		if (is_prev && (*i_pt).second == prev_pt) {
			numbers.push_back(std::make_pair((*i_pt).first, prev_num));
			i_pt++;
			continue;
		}
		auto pos_left_line = std::find_first_of(prev_iter_left, lines.end(), i_pt, i_pt + 1, [](const std::pair<int, int> &e1, const std::pair<int, int> &e2) {return e1.first > e2.second;});
		if (pos_left_line == lines.begin()) { 
			numbers.push_back(std::make_pair((*i_pt).first, 0));
			is_prev = true;
			prev_pt = (*i_pt).second;
			prev_num = 0;
			i_pt++;
			continue;
		}
		prev_iter_left = lines.begin() == pos_left_line ? pos_left_line : pos_left_line - 1;
		auto pos_right_line = std::find_first_of(prev_iter_right, part.end(), i_pt, i_pt + 1, [](const std::pair<int, int> &e1, const std::pair<int, int> &e2) {return e1.second >= e2.second;});
		prev_iter_right = part.begin() == pos_right_line ? pos_right_line : pos_right_line - 1;
		numbers.push_back(std::make_pair((*i_pt).first, (pos_left_line - lines.begin()) - (pos_right_line - part.begin())));
		is_prev = true;
		prev_pt = (*i_pt).second;
		prev_num = (pos_left_line - lines.begin()) - (pos_right_line - part.begin());
		i_pt++;
	}
	std::ostringstream oss;
	std::stable_sort(numbers.begin(), numbers.end(), [](const std::pair<int, int> &e1, const std::pair<int, int> &e2) {return e1.first < e2.first;});
	for (auto elem : numbers) { oss << elem.second << " "; }
	std::cout << oss.str() << std::endl;

	return 0;
}