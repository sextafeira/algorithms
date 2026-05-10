#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<int>& values) {
    for (int value : values) cout << value << ' ';
    cout << '\n';
}

int countMultiplesOfFive(const vector<int>& values, int index) {
    if (index < 0) return 0;
    return (values[index] % 5 == 0 ? 1 : 0) + countMultiplesOfFive(values, index - 1);
}

bool areEqual(const vector<int>& first, const vector<int>& second, int index) {
    if (first.size() != second.size()) return false;
    if (index < 0) return true;
    if (first[index] != second[index]) return false;
    return areEqual(first, second, index - 1);
}

void sumArrays(const vector<int>& first, const vector<int>& second, vector<int>& result, int index) {
    if (index < 0) return;
    result[index] = first[index] + second[index];
    sumArrays(first, second, result, index - 1);
}

int main() {
    int size;
    cout << "Enter vector size: ";
    cin >> size;

    vector<int> first(size), second(size), result(size);
    cout << "Enter first vector values: ";
    for (int& value : first) cin >> value;
    cout << "Enter second vector values: ";
    for (int& value : second) cin >> value;

    cout << "Multiples of five in first vector: " << countMultiplesOfFive(first, size - 1) << '\n';
    cout << "Vectors are equal: " << (areEqual(first, second, size - 1) ? "yes" : "no") << '\n';
    sumArrays(first, second, result, size - 1);
    cout << "Sum vector: ";
    printVector(result);
    return 0;
}
