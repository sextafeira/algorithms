#include <iostream>

void changeValue(int* value) {
    if (value != nullptr) {
        *value = 42;
    }
}

int main() {
    int number = 10;
    int* pointer = &number;

    std::cout << "Value before change: " << number << '\n';
    std::cout << "Address stored in pointer: " << pointer << '\n';

    changeValue(pointer);

    std::cout << "Value after change: " << number << '\n';
    return 0;
}
