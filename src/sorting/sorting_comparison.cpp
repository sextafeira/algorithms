#include <iostream>
#include <vector>

using namespace std;

struct SortStats {
    long long comparisons = 0;
    long long movements = 0;
};

void printVector(const vector<int>& values) {
    for (int value : values) cout << value << ' ';
    cout << '\n';
}

void selectionSort(vector<int>& values, SortStats& stats) {
    for (size_t i = 0; i + 1 < values.size(); ++i) {
        size_t smallest = i;
        for (size_t j = i + 1; j < values.size(); ++j) {
            ++stats.comparisons;
            if (values[j] < values[smallest]) smallest = j;
        }
        if (smallest != i) {
            swap(values[i], values[smallest]);
            stats.movements += 3;
        }
    }
}

void insertionSort(vector<int>& values, SortStats& stats) {
    for (size_t i = 1; i < values.size(); ++i) {
        int key = values[i];
        ++stats.movements;
        int j = static_cast<int>(i) - 1;
        while (j >= 0) {
            ++stats.comparisons;
            if (values[j] <= key) break;
            values[j + 1] = values[j];
            ++stats.movements;
            --j;
        }
        values[j + 1] = key;
        ++stats.movements;
    }
}

void bubbleSort(vector<int>& values, SortStats& stats) {
    bool swapped = true;
    for (size_t pass = 0; pass < values.size() && swapped; ++pass) {
        swapped = false;
        for (size_t j = 0; j + 1 < values.size() - pass; ++j) {
            ++stats.comparisons;
            if (values[j] > values[j + 1]) {
                swap(values[j], values[j + 1]);
                stats.movements += 3;
                swapped = true;
            }
        }
    }
}

int main() {
    int size;
    cout << "Enter vector size: ";
    cin >> size;

    vector<int> original(size);
    cout << "Enter " << size << " values: ";
    for (int& value : original) cin >> value;

    vector<int> selection = original, insertion = original, bubble = original;
    SortStats selectionStats, insertionStats, bubbleStats;

    selectionSort(selection, selectionStats);
    insertionSort(insertion, insertionStats);
    bubbleSort(bubble, bubbleStats);

    cout << "Selection sort: ";
    printVector(selection);
    cout << "Comparisons: " << selectionStats.comparisons << " | Movements: " << selectionStats.movements << "\n\n";

    cout << "Insertion sort: ";
    printVector(insertion);
    cout << "Comparisons: " << insertionStats.comparisons << " | Movements: " << insertionStats.movements << "\n\n";

    cout << "Bubble sort: ";
    printVector(bubble);
    cout << "Comparisons: " << bubbleStats.comparisons << " | Movements: " << bubbleStats.movements << '\n';
    return 0;
}
