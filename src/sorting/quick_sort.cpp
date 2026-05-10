#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<int>& values) {
    for (int value : values) cout << value << ' ';
    cout << '\n';
}

int partition(vector<int>& values, int low, int high) {
    int pivot = values[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (values[j] <= pivot) {
            ++i;
            swap(values[i], values[j]);
        }
    }
    swap(values[i + 1], values[high]);
    return i + 1;
}

void quickSort(vector<int>& values, int low, int high) {
    if (low >= high) return;
    int pivotIndex = partition(values, low, high);
    quickSort(values, low, pivotIndex - 1);
    quickSort(values, pivotIndex + 1, high);
}

int main() {
    int size;
    cout << "Enter vector size: ";
    cin >> size;

    vector<int> values(size);
    cout << "Enter " << size << " values: ";
    for (int& value : values) cin >> value;

    quickSort(values, 0, static_cast<int>(values.size()) - 1);
    cout << "Sorted vector: ";
    printVector(values);
    return 0;
}
