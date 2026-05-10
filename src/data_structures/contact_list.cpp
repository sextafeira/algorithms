#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Date {
    int day;
    int month;
    int year;
};

struct Contact {
    std::string name;
    Date birthDate;
    std::string phone;
};

void printContact(const Contact& contact) {
    std::cout << contact.name << " - "
              << contact.birthDate.day << '/'
              << contact.birthDate.month << '/'
              << contact.birthDate.year << " - "
              << contact.phone << '\n';
}

int main() {
    std::vector<Contact> contacts {
        {"Maria", {10, 5, 1995}, "1111-1111"},
        {"Ana", {20, 3, 1998}, "2222-2222"},
        {"Joao", {1, 5, 1990}, "3333-3333"}
    };

    std::sort(contacts.begin(), contacts.end(), [](const Contact& first, const Contact& second) {
        return first.name < second.name;
    });

    std::cout << "Contacts sorted by name:\n";
    for (const Contact& contact : contacts) {
        printContact(contact);
    }

    int month = 5;
    std::cout << "\nBirthdays in month " << month << ":\n";
    for (const Contact& contact : contacts) {
        if (contact.birthDate.month == month) {
            printContact(contact);
        }
    }

    return 0;
}
