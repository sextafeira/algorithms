#include <iostream>
#include <string>

using namespace std;

int ceilingDivision(int dividend, int divisor) {
    return (dividend + divisor - 1) / divisor;
}

string buildPoodleLogo(int documents, int resultsPerPage) {
    int pages = ceilingDivision(documents, resultsPerPage);
    int logoLength = max(6, min(20, pages));
    int numberOfOs = logoLength - 4; // P + dle = 4 fixed letters.
    return "P" + string(numberOfOs, 'o') + "dle";
}

int main() {
    int documents, resultsPerPage;
    while (cin >> documents >> resultsPerPage && !(documents == 0 && resultsPerPage == 0)) {
        cout << buildPoodleLogo(documents, resultsPerPage) << '\n';
    }
    return 0;
}
