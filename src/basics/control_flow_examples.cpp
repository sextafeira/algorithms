#include <iostream>

using namespace std;

void forExample(int limit) {
    cout << "For: ";
    for (int i = 1; i <= limit; ++i) cout << i << ' ';
    cout << '\n';
}

void whileExample(int limit) {
    cout << "While: ";
    int i = 1;
    while (i <= limit) cout << i++ << ' ';
    cout << '\n';
}

void switchExample(int option) {
    switch (option) {
        case 1: cout << "Option one\n"; break;
        case 2: cout << "Option two\n"; break;
        default: cout << "Unknown option\n"; break;
    }
}

int main() {
    int limit, option;
    cout << "Enter limit: ";
    cin >> limit;
    forExample(limit);
    whileExample(limit);

    cout << "Enter option for switch example: ";
    cin >> option;
    switchExample(option);
    return 0;
}
