#include <iostream>
#include <string>
#include <vector>

using namespace std;

void selectionSort(vector<string>& names) {
    for (size_t i = 0; i + 1 < names.size(); ++i) {
        size_t smallest = i;
        for (size_t j = i + 1; j < names.size(); ++j) {
            if (names[j] < names[smallest]) smallest = j;
        }
        swap(names[i], names[smallest]);
    }
}

int sequentialSearch(const vector<string>& names, const string& target) {
    for (size_t i = 0; i < names.size(); ++i) {
        if (names[i] == target) return static_cast<int>(i);
    }
    return -1;
}

int main() {
    int size;
    string target;
    cout << "Enter number of names: ";
    cin >> size;
    vector<string> names(size);
    cout << "Enter names: ";
    for (string& name : names) cin >> name;
    cout << "Enter name to search: ";
    cin >> target;

    selectionSort(names);
    cout << "Sorted names: ";
    for (const string& name : names) cout << name << ' ';
    cout << '\n';

    int position = sequentialSearch(names, target);
    if (position == -1) cout << "Name not found\n";
    else cout << "Name found at index " << position << '\n';
    return 0;
}
