#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct Edge {
    int to;
    int weight;
};

class GraphList {
private:
    vector<list<Edge>> adjacency;
    bool directed;

public:
    GraphList(int vertices, bool directed) : adjacency(vertices), directed(directed) {}

    bool validVertex(int vertex) const {
        return vertex >= 0 && vertex < static_cast<int>(adjacency.size());
    }

    void addEdge(int from, int to, int weight) {
        if (!validVertex(from) || !validVertex(to)) return;
        adjacency[from].push_back({to, weight});
        if (!directed) adjacency[to].push_back({from, weight});
    }

    void removeEdge(int from, int to) {
        if (!validVertex(from) || !validVertex(to)) return;
        adjacency[from].remove_if([&](const Edge& edge) { return edge.to == to; });
        if (!directed) adjacency[to].remove_if([&](const Edge& edge) { return edge.to == from; });
    }

    bool areAdjacent(int from, int to) const {
        if (!validVertex(from) || !validVertex(to)) return false;
        return any_of(adjacency[from].begin(), adjacency[from].end(), [&](const Edge& edge) { return edge.to == to; });
    }

    void printAdjacent(int vertex) const {
        if (!validVertex(vertex)) return;
        cout << "Adjacent vertices of " << vertex << ": ";
        for (const Edge& edge : adjacency[vertex]) cout << edge.to << "(w=" << edge.weight << ") ";
        cout << '\n';
    }

    void print() const {
        for (int from = 0; from < static_cast<int>(adjacency.size()); ++from) {
            cout << from << " -> ";
            for (const Edge& edge : adjacency[from]) cout << edge.to << "(w=" << edge.weight << ") ";
            cout << '\n';
        }
    }
};

int main() {
    int vertices, directedOption;
    cout << "Number of vertices: ";
    cin >> vertices;
    cout << "Directed graph? 1=yes 0=no: ";
    cin >> directedOption;

    GraphList graph(vertices, directedOption == 1);
    int option;
    do {
        cout << "\n1 - Add edge\n2 - Print graph\n3 - Check adjacency\n4 - Print adjacent vertices\n5 - Remove edge\n0 - Exit\nOption: ";
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
            int from, to;
            cout << "From To: "; cin >> from >> to;
            graph.removeEdge(from, to);
        }
    } while (option != 0);
    return 0;
}
