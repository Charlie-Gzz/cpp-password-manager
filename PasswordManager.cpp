#include "PasswordManager.h"
#include "utils.h"
#include <fstream>
#include <iostream>
#include <sstream>

PasswordManager::PasswordManager() {
    load();
}

void PasswordManager::load() {
    std::ifstream file("passwords.dat", std::ios::in | std::ios::binary);
    std::string line;

    if (!file.is_open()) {
        std::cout << "[DEBUG] Could not open passwords.dat\n";
        return;
    }

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::string decrypted = decrypt(line);
        std::istringstream iss(decrypted);
        std::string svc, user, pass;

        if (std::getline(iss, svc, ',') &&
            std::getline(iss, user, ',') &&
            std::getline(iss, pass)) {

            credentials.emplace_back(svc, user, pass);
            std::cout << "[DEBUG] Loaded: " << svc << ", " << user << "\n";
        } else {
            std::cout << "[DEBUG] Failed to parse line: " << decrypted << "\n";
        }
    }

    file.close();
}

void PasswordManager::save() {
    std::ofstream file("passwords.dat", std::ios::out | std::ios::binary);
    for (const auto& cred : credentials) {
        std::string line = encrypt(cred.to_string()) + "\n";
        file << line;
    }
    file.close();
}

void PasswordManager::add_credential() {
    std::string svc, user, pass;
    std::cout << "Enter service name: ";
    std::cin >> svc;
    std::cout << "Enter username: ";
    std::cin >> user;
    std::cout << "Enter password: ";
    std::cin >> pass;

    credentials.emplace_back(svc, user, pass);
    save();
    std::cout << "Credential saved successfully.\n";
}

void PasswordManager::view_credentials() {
    for (const auto& cred : credentials) {
        std::cout << "Service: " << cred.service
                  << ", Username: " << cred.username
                  << ", Password: " << cred.password << "\n";
    }
}

void PasswordManager::search_credentials() {
    std::string query;
    std::cout << "Enter service or username to search: ";
    std::cin >> query;

    for (const auto& cred : credentials) {
        if (cred.service == query || cred.username == query) {
            std::cout << "Found: " << cred.to_string() << "\n";
        }
    }
}
