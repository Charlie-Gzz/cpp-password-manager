#include "PasswordManager.h"
#include <iostream>

int main() {
    PasswordManager pm;
    int choice;

    while (true) {
        std::cout << "\n==== Password Manager ====\n";
        std::cout << "1. Add New Credential\n";
        std::cout << "2. View All Credentials\n";
        std::cout << "3. Search Credentials\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                pm.add_credential();
                break;
            case 2:
                pm.view_credentials();
                break;
            case 3:
                pm.search_credentials();
                break;
            case 4:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice.\n";
        }
    }

    return 0;
}
