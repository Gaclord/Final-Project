#pragma
#ifndef USER_H
#define USER_H
#include <string>

class User {
public:
    User(const std::string& login, const std::string& password, const std::string& name);

    const std::string& GetLogin() const;
    const std::string& GetPassword() const;
    const std::string& GetName() const;
    bool IsLoggedIn() const;
    void SetLoggedIn(bool logged_in);

private:
    std::string login_;
    std::string password_;
    std::string name_;
    bool logged_in_;
};

#endif  // USER_H