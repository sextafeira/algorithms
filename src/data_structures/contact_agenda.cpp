#include <algorithm>
#include <iostream>
#include <list>
#include <string>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

struct Contact {
    string name;
    Date birthDate;
    string phone;
};

void printContact(const Contact& contact) {
    cout << contact.name << " | "
         << contact.birthDate.day << '/' << contact.birthDate.month << '/' << contact.birthDate.year
         << " | " << contact.phone << '\n';
}

int main() {
    list<Contact> agenda;
    int option;
    do {
        cout << "\n1 - Is empty\n2 - Insert contact\n3 - Print agenda\n4 - Search by name\n5 - Count birthdays by month\n6 - List birthdays by month\n7 - Sort by name\n8 - Remove by name\n0 - Exit\nOption: ";
        cin >> option;

        if (option == 1) {
            cout << (agenda.empty() ? "Agenda is empty\n" : "Agenda is not empty\n");
        } else if (option == 2) {
            Contact contact;
            cout << "Name: "; cin >> contact.name;
            cout << "Birth day: "; cin >> contact.birthDate.day;
            cout << "Birth month: "; cin >> contact.birthDate.month;
            cout << "Birth year: "; cin >> contact.birthDate.year;
            cout << "Phone: "; cin >> contact.phone;
            agenda.push_back(contact);
        } else if (option == 3) {
            for (const Contact& contact : agenda) printContact(contact);
        } else if (option == 4) {
            string name;
            cout << "Name: "; cin >> name;
            auto it = find_if(agenda.begin(), agenda.end(), [&](const Contact& contact) { return contact.name == name; });
            if (it == agenda.end()) cout << "Contact not found\n";
            else printContact(*it);
        } else if (option == 5) {
            for (int month = 1; month <= 12; ++month) {
                int total = count_if(agenda.begin(), agenda.end(), [&](const Contact& contact) { return contact.birthDate.month == month; });
                cout << "Month " << month << ": " << total << '\n';
            }
        } else if (option == 6) {
            int month;
            cout << "Month: "; cin >> month;
            for (const Contact& contact : agenda) {
                if (contact.birthDate.month == month) printContact(contact);
            }
        } else if (option == 7) {
            agenda.sort([](const Contact& a, const Contact& b) { return a.name < b.name; });
        } else if (option == 8) {
            string name;
            cout << "Name: "; cin >> name;
            agenda.remove_if([&](const Contact& contact) { return contact.name == name; });
        }
    } while (option != 0);
    return 0;
}
