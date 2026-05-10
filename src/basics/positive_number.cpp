#include <iostream>

using namespace std;

int main() {
    int value;
    cout << "Enter a number: ";
    cin >> value;
    if (value > 0) cout << "The number is greater than zero\n";
    else if (value == 0) cout << "The number is zero\n";
    else cout << "The number is less than zero\n";
    return 0;
}
