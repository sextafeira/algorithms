#include <iostream>
#include <memory>

using namespace std;

struct Node {
    int value;
    unique_ptr<Node> next;
    explicit Node(int value) : value(value), next(nullptr) {}
};

class Queue {
private:
    unique_ptr<Node> frontNode;
    Node* rearNode = nullptr;

public:
    bool empty() const { return frontNode == nullptr; }

    void enqueue(int value) {
        auto newNode = make_unique<Node>(value);
        Node* rawNode = newNode.get();
        if (empty()) frontNode = move(newNode);
        else rearNode->next = move(newNode);
        rearNode = rawNode;
    }

    bool dequeue(int& value) {
        if (empty()) return false;
        value = frontNode->value;
        frontNode = move(frontNode->next);
        if (empty()) rearNode = nullptr;
        return true;
    }
};

int main() {
    Queue queue;
    int option;
    do {
        cout << "\n1 - Enqueue\n2 - Dequeue\n0 - Exit\nOption: ";
        cin >> option;
        if (option == 1) {
            int value;
            cout << "Value: ";
            cin >> value;
            queue.enqueue(value);
        } else if (option == 2) {
            int value;
            if (queue.dequeue(value)) cout << "Removed: " << value << '\n';
            else cout << "Queue is empty\n";
        }
    } while (option != 0);
    return 0;
}
