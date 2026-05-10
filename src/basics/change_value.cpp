#include <iostream>

using namespace std;

void changeByValue([[maybe_unused]] int value) {
    value = 100;
}

void changeByReference(int& value) {
    value = 100;
}

int main() {
    int value = 10;
    cout << "Original: " << value << '\n';
    changeByValue(value);
    cout << "After changeByValue: " << value << '\n';
    changeByReference(value);
    cout << "After changeByReference: " << value << '\n';
    return 0;
}
