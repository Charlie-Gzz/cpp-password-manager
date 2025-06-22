#ifndef UTILS_H
#define UTILS_H

#include <string>

std::string encrypt(const std::string& data, char key = 'K');
std::string decrypt(const std::string& data, char key = 'K');

#endif
