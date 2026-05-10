#include <iostream>
#include <limits>
#include <vector>

using namespace std;

const int NO_EDGE = 0;

class GraphMatrix {
private:
    vector<vector<int>> matrix;
    bool directed;

public:
    GraphMatrix(int vertices, bool directed) : matrix(vertices, vector<int>(vertices, NO_EDGE)), directed(directed) {}

    bool validVertex(int vertex) const {
        return vertex >= 0 && vertex < static_cast<int>(matrix.size());
    }

    void addEdge(int from, int to, int weight) {
        if (!validVertex(from) || !validVertex(to)) return;
        matrix[from][to] = weight;
        if (!directed) matrix[to][from] = weight;
    }

    bool areAdjacent(int from, int to) const {
        return validVertex(from) && validVertex(to) && matrix[from][to] != NO_EDGE;
    }

    void printAdjacent(int vertex) const {
        if (!validVertex(vertex)) return;
        cout << "Adjacent vertices of " << vertex << ": ";
        for (int to = 0; to < static_cast<int>(matrix.size()); ++to) {
            if (matrix[vertex][to] != NO_EDGE) cout << to << "(w=" << matrix[vertex][to] << ") ";
        }
        cout << '\n';
    }

    void print() const {
        for (const auto& row : matrix) {
            for (int value : row) cout << value << ' ';
            cout << '\n';
        }
    }

    void printSmallestEdge() const {
        int smallest = numeric_limits<int>::max();
        int bestFrom = -1, bestTo = -1;
        for (int from = 0; from < static_cast<int>(matrix.size()); ++from) {
            for (int to = 0; to < static_cast<int>(matrix.size()); ++to) {
                if (matrix[from][to] != NO_EDGE && matrix[from][to] < smallest) {
                    smallest = matrix[from][to];
                    bestFrom = from;
                    bestTo = to;
                }
            }
        }
        if (bestFrom == -1) cout << "Graph has no edges\n";
        else cout << "Smallest edge: " << bestFrom << " -> " << bestTo << " (w=" << smallest << ")\n";
    }
};

int main() {
    int vertices, directedOption;
    cout << "Number of vertices: ";
    cin >> vertices;
    cout << "Directed graph? 1=yes 0=no: ";
    cin >> directedOption;

    GraphMatrix graph(vertices, directedOption == 1);
    int option;
    do {
        cout << "\n1 - Add edge\n2 - Print matrix\n3 - Check adjacency\n4 - Print adjacent vertices\n5 - Smallest edge\n0 - Exit\nOption: ";
        cin >> option;
        if (option == 1) {
            int from, to, weight;
            cout << "From To Weight: "; cin >> from >> to >> weight;
            graph.addEdge(from, to, weight);
        } else if (option == 2) {
            graph.print();
        } else if (option == 3) {
            int from, to;
            cout << "From To: "; cin >> from >> to;
            cout << (graph.areAdjacent(from, to) ? "Adjacent\n" : "Not adjacent\n");
        } else if (option == 4) {
            int vertex;
            cout << "Vertex: "; cin >> vertex;
            graph.printAdjacent(vertex);
        } else if (option == 5) {
            graph.printSmallestEdge();
        }
    } while (option != 0);
    return 0;
}
