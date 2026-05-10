#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void printNames(const std::vector<std::string>& names) {
    for (const std::string& name : names) {
        std::cout << name << ' ';
    }
    std::cout << '\n';
}

bool binarySearchName(std::vector<std::string> names, const std::string& target) {
    std::sort(names.begin(), names.end());
    return std::binary_search(names.begin(), names.end(), target);
}

int main() {
    std::vector<std::string> names {"Luciano", "Weddly", "Ana", "Maria", "Joao"};
    std::string target = "Ana";

    std::cout << "Original names: ";
    printNames(names);

    std::sort(names.begin(), names.end());
    std::cout << "Sorted names: ";
    printNames(names);

    std::cout << "Searching for " << target << ": "
              << (binarySearchName(names, target) ? "found" : "not found") << '\n';

    return 0;
}
