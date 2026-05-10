#include <iostream>
#include <vector>
#include <algorithm>

bool isSortedAscending(const std::vector<int>& values) {
    for (std::size_t i = 1; i < values.size(); ++i) {
        if (values[i - 1] > values[i]) {
            return false;
        }
    }
    return true;
}

void bubbleSort(std::vector<int>& values) {
    for (std::size_t i = 0; i < values.size(); ++i) {
        for (std::size_t j = 1; j < values.size() - i; ++j) {
            if (values[j - 1] > values[j]) {
                std::swap(values[j - 1], values[j]);
            }
        }
    }
}

void insertionSort(std::vector<int>& values) {
    for (std::size_t i = 1; i < values.size(); ++i) {
        int key = values[i];
        std::size_t j = i;
        while (j > 0 && values[j - 1] > key) {
            values[j] = values[j - 1];
            --j;
        }
        values[j] = key;
    }
}

void selectionSort(std::vector<int>& values) {
    for (std::size_t i = 0; i < values.size(); ++i) {
        std::size_t minimumIndex = i;
        for (std::size_t j = i + 1; j < values.size(); ++j) {
            if (values[j] < values[minimumIndex]) {
                minimumIndex = j;
            }
        }
        std::swap(values[i], values[minimumIndex]);
    }
}

void printVector(const std::vector<int>& values) {
    for (int value : values) {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> values {9, 5, 1, 7, 3, 2};
    int method = 1;

    std::cout << "Original values: ";
    printVector(values);

    if (isSortedAscending(values)) {
        std::cout << "The vector is already sorted.\n";
    } else {
        std::cout << "The vector is not sorted. Sorting now...\n";
        switch (method) {
            case 1:
                selectionSort(values);
                break;
            case 2:
                insertionSort(values);
                break;
            case 3:
                bubbleSort(values);
                break;
            default:
                std::cout << "Invalid sorting method.\n";
                return 1;
        }
    }

    std::cout << "Sorted values: ";
    printVector(values);
    return 0;
}
