#include "chat.h"
#include <iostream>

void Chat::AddUser(const User& user) {
    users_.push_back(user);
}

bool Chat::Login(const std::string& login, const std::string& password) {
    for (User& user : users_) {
        if (user.GetLogin() == login && user.GetPassword() == password) {
            user.SetLoggedIn(true);
            return true;
        }
    }
    return false;
}

void Chat::SendMessage(const Message& message) {
    if (message.GetSender().IsLoggedIn()) {
        messages_.push_back(message);
    }
    else {
        std::cout << "Error: sender not logged in" << std::endl;
    }
}

void Chat::SendMessageToAllUsers(const Message& message) {
    for (User& user : users_) {
        if (user.IsLoggedIn()) {
            Message copy = message;
            copy.SetReceiverName(user.GetLogin());
            SendMessage(copy);
        }
    }
}

void Chat::SendMessageToUser(const Message& message, const std::string& recipient_login) {
    for (User& user : users_) {
        if (user.GetLogin() == recipient_login) {
            if (user.IsLoggedIn()) {
                Message copy = message;
                copy.SetReceiverName(recipient_login);
                SendMessage(copy);
                return;
            }
            else {
                std::cout << "Error: recipient not logged in" << std::endl;
                return;
            }
        }
    }
    std::cout << "Error: recipient not found" << std::endl;
}

void Chat::DisplayAllMessages() const {
    for (const Message& message : messages_) {
        std::cout << message << std::endl;
    }
}

void Chat::Logout() {
    for (User& user : users_) {
        if (user.IsLoggedIn()) {
            user.SetLoggedIn(false);
        }
    }
}

const std::vector<User>& Chat::GetUsers() const {
    return users_;
}

const std::vector<Message>& Chat::GetMessages() const {
    return messages_;
}