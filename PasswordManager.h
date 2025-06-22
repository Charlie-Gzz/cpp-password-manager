#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H

#include "Credential.h"
#include <vector>

class PasswordManager {
private:
    std::vector<Credential> credentials;
    void load();
    void save();

public:
    PasswordManager();
    void add_credential();
    void view_credentials();
    void search_credentials();
};

#endif
