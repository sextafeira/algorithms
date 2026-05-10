#include <iostream>
#include <stdexcept>
#include <vector>

class Stack {
public:
    bool empty() const {
        return items.empty();
    }

    void push(int value) {
        items.push_back(value);
    }

    int pop() {
        if (empty()) {
            throw std::runtime_error("Stack is empty");
        }
        int value = items.back();
        items.pop_back();
        return value;
    }

    int top() const {
        if (empty()) {
            throw std::runtime_error("Stack is empty");
        }
        return items.back();
    }

    void print() const {
        for (auto it = items.rbegin(); it != items.rend(); ++it) {
            std::cout << *it << ' ';
        }
        std::cout << '\n';
    }

private:
    std::vector<int> items;
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Stack: ";
    stack.print();
    std::cout << "Top: " << stack.top() << '\n';
    std::cout << "Removed: " << stack.pop() << '\n';
    std::cout << "Stack after pop: ";
    stack.print();

    return 0;
}
