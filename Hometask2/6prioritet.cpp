#include <iostream>
#include <vector>
#include <string>

std::vector<int> Lift_Up(std::vector<int> numbers, int index) {
    if (index > 0) {
        if (((index == 1) || (index == 2)) && (numbers.size() > 2)) {
            if (std::max(numbers[1], numbers[2]) > numbers[0]) {
                if (numbers[1] > numbers[2]) {
                    std::swap(numbers[1], numbers[0]);
                }
                else {
                    std::swap(numbers[2], numbers[0]);
                }
            }
            return numbers;
        }
        int parent_index = (index - 1) / 2;
        if (numbers[index] > numbers[parent_index]) {
            std::swap(numbers[index], numbers[parent_index]);
            Lift_Up(numbers, parent_index);
        }
    }
    return numbers;
}

std::vector<int> Get_Down(std::vector<int> numbers, int index) {
    int child_index = index * 2 + 1;
    if (child_index < numbers.size()) {
        if (child_index + 1 != numbers.size()) {
            if (numbers[child_index] < numbers[child_index + 1]) {
                child_index++;
            }
        }
        if (numbers[index] < numbers[child_index]) {
            std::swap(numbers[index], numbers[child_index]);
            Get_Down(numbers, child_index);
        }
    }
    return numbers;
}

int main() {
    int number_of_requests;
    std::cin >> number_of_requests;
    std::vector<int> numbers;
    for (size_t request_number = 0; request_number < number_of_requests; request_number++) {
        int value;
        std::string command;
        std::cin >> command;
        if (command == "ExtractMax") {
            std::swap(numbers[0], numbers[numbers.size() - 1]);
            std::cout << numbers.back() << std::endl;
            numbers.pop_back();
            numbers = Get_Down(numbers, 0);
        }
        else {
            std::cin >> value;
            numbers.push_back(value);
            numbers = Lift_Up(numbers, numbers.size() - 1);
        }
    }
}