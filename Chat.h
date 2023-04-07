#pragma
#ifndef CHAT_H
#define CHAT_H
#include <vector>
#include "user.h"
#include "message.h"

class Chat {
public:
    void AddUser(const User& user);
    bool Login(const std::string& login, const std::string& password);
    void SendMessage(const Message& message);
    void SendMessageToAllUsers(const Message& message);
    void SendMessageToUser(const Message& message, const std::string& recipient_login);
    void DisplayAllMessages() const;
    void Logout();

    const std::vector<User>& GetUsers() const;
    const std::vector<Message>& GetMessages() const;

private:
    std::vector<User> users_;
    std::vector<Message> messages_;
};
#endif // CHAT_H