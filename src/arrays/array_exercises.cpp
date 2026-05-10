#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maxValue(const vector<int>& values) {
    return *max_element(values.begin(), values.end());
}

void printEvenAndOdd(const vector<int>& values) {
    cout << "Even values: ";
    for (int value : values) if (value % 2 == 0) cout << value << ' ';
    cout << "\nOdd values: ";
    for (int value : values) if (value % 2 != 0) cout << value << ' ';
    cout << '\n';
}

int countOccurrences(const vector<int>& values, int target) {
    return static_cast<int>(count(values.begin(), values.end(), target));
}

int main() {
    int size, target;
    cout << "Enter vector size: ";
    cin >> size;
    vector<int> values(size);
    cout << "Enter " << size << " values: ";
    for (int& value : values) cin >> value;
    cout << "Enter value to count: ";
    cin >> target;

    cout << "Max value: " << maxValue(values) << '\n';
    printEvenAndOdd(values);
    cout << "Occurrences of " << target << ": " << countOccurrences(values, target) << '\n';
    return 0;
}
