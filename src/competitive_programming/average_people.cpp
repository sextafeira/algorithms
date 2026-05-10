#include <iomanip>
#include <iostream>

int main() {
    double hotDogs = 0.0;
    double participants = 0.0;

    if (!(std::cin >> hotDogs >> participants) || participants == 0.0) {
        return 0;
    }

    std::cout << std::fixed << std::setprecision(2) << hotDogs / participants << '\n';
    return 0;
}
