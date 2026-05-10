#include <iostream>
#include <vector>

using namespace std;

int main() {
    int rows, columns;
    cout << "Rows: ";
    cin >> rows;
    cout << "Columns: ";
    cin >> columns;

    vector<vector<int>> matrix(rows, vector<int>(columns));
    cout << "Enter matrix values:\n";
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            cin >> matrix[row][column];
        }
    }

    cout << "Matrix:\n";
    for (const auto& row : matrix) {
        for (int value : row) cout << value << ' ';
        cout << '\n';
    }
    return 0;
}
