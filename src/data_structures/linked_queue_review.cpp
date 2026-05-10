#include <iostream>
#include <memory>
#include <stdexcept>

class LinkedQueue {
private:
    struct Node {
        int value;
        std::unique_ptr<Node> next;

        explicit Node(int newValue) : value(newValue), next(nullptr) {}
    };

    std::unique_ptr<Node> frontNode;
    Node* backNode = nullptr;

public:
    bool empty() const {
        return frontNode == nullptr;
    }

    void enqueue(int value) {
        auto newNode = std::make_unique<Node>(value);
        Node* rawNode = newNode.get();

        if (empty()) {
            frontNode = std::move(newNode);
        } else {
            backNode->next = std::move(newNode);
        }
        backNode = rawNode;
    }

    int dequeue() {
        if (empty()) {
            throw std::runtime_error("Queue is empty");
        }

        int value = frontNode->value;
        frontNode = std::move(frontNode->next);
        if (frontNode == nullptr) {
            backNode = nullptr;
        }
        return value;
    }

    void print() const {
        const Node* current = frontNode.get();
        while (current != nullptr) {
            std::cout << current->value << ' ';
            current = current->next.get();
        }
        std::cout << '\n';
    }
};

int main() {
    LinkedQueue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << "Queue: ";
    queue.print();
    std::cout << "Removed: " << queue.dequeue() << '\n';
    std::cout << "Queue after dequeue: ";
    queue.print();

    return 0;
}
