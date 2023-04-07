#include "user.h"

User::User(const std::string& login, const std::string& password, const std::string& name)
    : login_(login), password_(password), name_(name), logged_in_(false) {}

const std::string& User::GetLogin() const {
    return login_;
}

const std::string& User::GetPassword() const {
    return password_;
}

const std::string& User::GetName() const {
    return name_;
}

bool User::IsLoggedIn() const {
    return logged_in_;
}

void User::SetLoggedIn(bool logged_in) {
    logged_in_ = logged_in;
}
