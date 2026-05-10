#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& values, int target) {
    int left = 0;
    int right = static_cast<int>(values.size()) - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (values[middle] == target) return middle;
        if (values[middle] < target) left = middle + 1;
        else right = middle - 1;
    }
    return -1;
}

int main() {
    int size, target;
    cout << "Enter vector size: ";
    cin >> size;
    vector<int> values(size);
    cout << "Enter " << size << " values: ";
    for (int& value : values) cin >> value;
    cout << "Enter value to search: ";
    cin >> target;

    sort(values.begin(), values.end());
    int position = binarySearch(values, target);
    if (position == -1) cout << "Value not found\n";
    else cout << "Value found at sorted index " << position << '\n';
    return 0;
}
