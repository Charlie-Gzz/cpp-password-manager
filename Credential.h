#ifndef CREDENTIAL_H
#define CREDENTIAL_H

#include <string>

class Credential {
public:
    std::string service;
    std::string username;
    std::string password;

    Credential(std::string svc, std::string user, std::string pass);
    std::string to_string() const;
};

#endif