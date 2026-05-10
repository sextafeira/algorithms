#include <iostream>
#include <string>

using namespace std;

struct Person {
    string name;
    string phone;
    int age;
};

struct Node {
    Person person;
    Node* next = nullptr;
};

void insertAtEnd(Node*& head, const Person& person) {
    Node* newNode = new Node{person, nullptr};
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next != nullptr) current = current->next;
    current->next = newNode;
}

void printList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    for (Node* current = head; current != nullptr; current = current->next) {
        cout << current->person.name << " | " << current->person.phone << " | " << current->person.age << '\n';
    }
}

Node* findByName(Node* head, const string& name) {
    for (Node* current = head; current != nullptr; current = current->next) {
        if (current->person.name == name) return current;
    }
    return nullptr;
}

Node* oldestPerson(Node* head) {
    if (head == nullptr) return nullptr;
    Node* oldest = head;
    for (Node* current = head->next; current != nullptr; current = current->next) {
        if (current->person.age > oldest->person.age) oldest = current;
    }
    return oldest;
}

void clear(Node*& head) {
    while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}

int main() {
    Node* list = nullptr;
    int option;
    do {
        cout << "\n1 - Insert person\n2 - Print list\n3 - Search by name\n4 - Show oldest person\n0 - Exit\nOption: ";
        cin >> option;
        if (option == 1) {
            Person person;
            cout << "Name: "; cin >> person.name;
            cout << "Phone: "; cin >> person.phone;
            cout << "Age: "; cin >> person.age;
            insertAtEnd(list, person);
        } else if (option == 2) {
            printList(list);
        } else if (option == 3) {
            string name;
            cout << "Name: "; cin >> name;
            cout << (findByName(list, name) ? "Found\n" : "Not found\n");
        } else if (option == 4) {
            Node* oldest = oldestPerson(list);
            if (oldest == nullptr) cout << "List is empty\n";
            else cout << "Oldest person: " << oldest->person.name << " (" << oldest->person.age << ")\n";
        }
    } while (option != 0);
    clear(list);
    return 0;
}
