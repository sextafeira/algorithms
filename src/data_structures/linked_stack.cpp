#include <iostream>
#include <memory>
#include <stdexcept>

class LinkedStack {
private:
    struct Node {
        int value;
        std::unique_ptr<Node> next;

        explicit Node(int newValue) : value(newValue), next(nullptr) {}
    };

    std::unique_ptr<Node> topNode;

public:
    bool empty() const {
        return topNode == nullptr;
    }

    void push(int value) {
        auto newNode = std::make_unique<Node>(value);
        newNode->next = std::move(topNode);
        topNode = std::move(newNode);
    }

    int pop() {
        if (empty()) {
            throw std::runtime_error("Stack is empty");
        }
        int value = topNode->value;
        topNode = std::move(topNode->next);
        return value;
    }

    void print() const {
        const Node* current = topNode.get();
        while (current != nullptr) {
            std::cout << current->value << ' ';
            current = current->next.get();
        }
        std::cout << '\n';
    }
};

int main() {
    LinkedStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Stack: ";
    stack.print();
    std::cout << "Removed: " << stack.pop() << '\n';
    std::cout << "Stack after pop: ";
    stack.print();

    return 0;
}
