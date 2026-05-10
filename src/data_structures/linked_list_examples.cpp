#include <iostream>
#include <list>

void printList(const std::list<int>& values) {
    for (int value : values) {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::list<int> values;

    values.push_back(10);
    values.push_back(30);
    values.push_front(5);

    auto iterator = values.begin();
    std::advance(iterator, 2);
    values.insert(iterator, 20);

    std::cout << "List: ";
    printList(values);

    values.remove(30);
    std::cout << "After removing 30: ";
    printList(values);

    values.sort();
    std::cout << "Sorted list: ";
    printList(values);

    return 0;
}
