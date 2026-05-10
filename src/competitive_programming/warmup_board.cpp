#include <iostream>

int main() {
    int boardSize = 0;
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;

    if (!(std::cin >> boardSize >> x1 >> y1 >> x2 >> y2)) {
        return 0;
    }

    int maximumSum = 3 * boardSize / 2;
    int minimumSum = boardSize / 2 + 2;

    bool isValid = (x1 + x2 <= maximumSum) &&
                   (y1 + y2 <= maximumSum) &&
                   (x1 + x2 >= minimumSum) &&
                   (y1 + y2 >= minimumSum);

    std::cout << (isValid ? 'S' : 'N') << '\n';
    return 0;
}
