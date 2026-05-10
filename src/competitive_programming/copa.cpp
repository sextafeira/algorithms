#include <iostream>
#include <string>

int main() {
    int teams = 0;
    int gamesPerTeam = 0;

    while (std::cin >> teams >> gamesPerTeam && (teams != 0 || gamesPerTeam != 0)) {
        int maximumPoints = teams * gamesPerTeam * 3;
        int totalPoints = 0;

        for (int i = 0; i < teams; ++i) {
            std::string teamName;
            int points = 0;
            std::cin >> teamName >> points;
            totalPoints += points;
        }

        std::cout << maximumPoints - totalPoints << '\n';
    }

    return 0;
}
