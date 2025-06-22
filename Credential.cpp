#include "Credential.h"

Credential::Credential(std::string svc, std::string user, std::string pass)
    : service(svc), username(user), password(pass) {}

std::string Credential::to_string() const {
    return service + "," + username + "," + password;
}
