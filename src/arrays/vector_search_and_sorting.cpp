#include <algorithm>
#include <iostream>
#include <vector>

int getLargestValue(const std::vector<int>& values) {
    return *std::max_element(values.begin(), values.end());
}

int countOccurrences(const std::vector<int>& values, int target) {
    return static_cast<int>(std::count(values.begin(), values.end(), target));
}

void countEvenAndOdd(const std::vector<int>& values, int& evenCount, int& oddCount) {
    evenCount = 0;
    oddCount = 0;
    for (int value : values) {
        if (value % 2 == 0) {
            ++evenCount;
        } else {
            ++oddCount;
        }
    }
}

bool linearSearch(const std::vector<int>& values, int target) {
    return std::find(values.begin(), values.end(), target) != values.end();
}

void printVector(const std::vector<int>& values) {
    for (int value : values) {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> values {12, 5, 8, 12, 3, 9, 4, 12};
    int target = 12;
    int evenCount = 0;
    int oddCount = 0;

    std::cout << "Values: ";
    printVector(values);

    countEvenAndOdd(values, evenCount, oddCount);

    std::cout << "Largest value: " << getLargestValue(values) << '\n';
    std::cout << "Occurrences of " << target << ": " << countOccurrences(values, target) << '\n';
    std::cout << "Even values: " << evenCount << '\n';
    std::cout << "Odd values: " << oddCount << '\n';
    std::cout << "Linear search result: " << (linearSearch(values, target) ? "found" : "not found") << '\n';

    std::sort(values.begin(), values.end());
    std::cout << "Ascending order: ";
    printVector(values);

    std::sort(values.rbegin(), values.rend());
    std::cout << "Descending order: ";
    printVector(values);

    return 0;
}
