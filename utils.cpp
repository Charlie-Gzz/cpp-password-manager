#include "utils.h"

std::string encrypt(const std::string& data, char key) {
    std::string encrypted = data;
    for (char& c : encrypted) {
        c ^= key;
    }
    return encrypted;
}

std::string decrypt(const std::string& data, char key) {
    return encrypt(data, key); // XOR is symmetric
}
