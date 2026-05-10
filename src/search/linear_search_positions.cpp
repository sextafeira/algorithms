#include <iostream>
#include <vector>

std::vector<int> findAllPositions(const std::vector<int>& values, int target) {
    std::vector<int> positions;
    for (std::size_t i = 0; i < values.size(); ++i) {
        if (values[i] == target) {
            positions.push_back(static_cast<int>(i));
        }
    }
    return positions;
}

void printVector(const std::vector<int>& values) {
    for (int value : values) {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> values {4, 7, 4, 1, 9, 4, 2};
    int target = 4;

    std::cout << "Values: ";
    printVector(values);

    std::vector<int> positions = findAllPositions(values, target);

    std::cout << "Target: " << target << '\n';
    std::cout << "Positions: ";
    printVector(positions);
    std::cout << "Occurrences: " << positions.size() << '\n';

    return 0;
}
