#include <iostream>
#include <memory>
#include <queue>

class BinarySearchTree {
private:
    struct Node {
        int value;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;

        explicit Node(int newValue) : value(newValue), left(nullptr), right(nullptr) {}
    };

    std::unique_ptr<Node> root;

    void insert(std::unique_ptr<Node>& node, int value) {
        if (node == nullptr) {
            node = std::make_unique<Node>(value);
            return;
        }

        if (value < node->value) {
            insert(node->left, value);
        } else if (value > node->value) {
            insert(node->right, value);
        }
    }

    void printInOrder(const Node* node) const {
        if (node == nullptr) {
            return;
        }
        printInOrder(node->left.get());
        std::cout << node->value << ' ';
        printInOrder(node->right.get());
    }

    int countNodes(const Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        return 1 + countNodes(node->left.get()) + countNodes(node->right.get());
    }

    int sumNodes(const Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        return node->value + sumNodes(node->left.get()) + sumNodes(node->right.get());
    }

public:
    void insert(int value) {
        insert(root, value);
    }

    void printInOrder() const {
        printInOrder(root.get());
        std::cout << '\n';
    }

    void printBreadthFirst() const {
        if (root == nullptr) {
            std::cout << '\n';
            return;
        }

        std::queue<const Node*> queue;
        queue.push(root.get());

        while (!queue.empty()) {
            const Node* current = queue.front();
            queue.pop();

            std::cout << current->value << ' ';

            if (current->left != nullptr) {
                queue.push(current->left.get());
            }
            if (current->right != nullptr) {
                queue.push(current->right.get());
            }
        }
        std::cout << '\n';
    }

    int countNodes() const {
        return countNodes(root.get());
    }

    int sumNodes() const {
        return sumNodes(root.get());
    }
};

int main() {
    BinarySearchTree tree;

    for (int value : {8, 3, 10, 1, 6, 14, 4, 7, 13}) {
        tree.insert(value);
    }

    std::cout << "In-order traversal: ";
    tree.printInOrder();

    std::cout << "Breadth-first traversal: ";
    tree.printBreadthFirst();

    std::cout << "Node count: " << tree.countNodes() << '\n';
    std::cout << "Node sum: " << tree.sumNodes() << '\n';

    return 0;
}
