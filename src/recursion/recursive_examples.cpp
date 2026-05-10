#include <algorithm>
#include <iostream>
#include <vector>

void printRecursive(const std::vector<int>& values, std::size_t index = 0) {
    if (index == values.size()) {
        std::cout << '\n';
        return;
    }
    std::cout << values[index] << ' ';
    printRecursive(values, index + 1);
}

bool recursiveLinearSearch(const std::vector<int>& values, int target, std::size_t index = 0) {
    if (index == values.size()) {
        return false;
    }
    if (values[index] == target) {
        return true;
    }
    return recursiveLinearSearch(values, target, index + 1);
}

bool recursiveBinarySearch(const std::vector<int>& values, int target, int left, int right) {
    if (left > right) {
        return false;
    }

    int middle = left + (right - left) / 2;
    if (values[middle] == target) {
        return true;
    }
    if (target < values[middle]) {
        return recursiveBinarySearch(values, target, left, middle - 1);
    }
    return recursiveBinarySearch(values, target, middle + 1, right);
}

int recursiveSum(const std::vector<int>& values, std::size_t index = 0) {
    if (index == values.size()) {
        return 0;
    }
    return values[index] + recursiveSum(values, index + 1);
}

int recursiveFactorial(int number) {
    if (number <= 1) {
        return 1;
    }
    return number * recursiveFactorial(number - 1);
}

int main() {
    std::vector<int> values {2, 4, 6, 8, 10, 12};
    int target = 8;

    std::cout << "Values: ";
    printRecursive(values);

    std::cout << "Recursive sum: " << recursiveSum(values) << '\n';
    std::cout << "Factorial of 5: " << recursiveFactorial(5) << '\n';
    std::cout << "Linear search for " << target << ": "
              << (recursiveLinearSearch(values, target) ? "found" : "not found") << '\n';
    std::cout << "Binary search for " << target << ": "
              << (recursiveBinarySearch(values, target, 0, static_cast<int>(values.size()) - 1) ? "found" : "not found") << '\n';

    return 0;
}
