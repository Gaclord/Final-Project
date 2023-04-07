#include <iostream>
#include <string>
#include "user.h"
#include "message.h"
#include "chat.h"

using namespace std;

void registerUser(Chat& chat) {
    string login, password, name;
    cout << "Enter login: ";
    getline(cin, login);
    cout << "Enter password: ";
    getline(cin, password);
    cout << "Enter name: ";
    getline(cin, name);
    User user(login, password, name);
    chat.AddUser(user);
    cout << "User registered." << endl;
}

void loginUser(Chat& chat, User*& user) {
    string login, password;
    cout << "Enter login: ";
    getline(cin, login);
    cout << "Enter password: ";
    getline(cin, password);
    if (chat.Login(login, password)) {
        for (User u : chat.GetUsers()) {
            if (u.GetLogin() == login) {
                user = &u;
                break;
            }
        }
        cout << "User logged in." << endl;
    }
    else {
        cout << "Invalid login or password." << endl;
    }
}

void sendMessage(Chat& chat, User& user) {
    string recipient_login, text;
    cout << "Enter recipient login: ";
    getline(cin, recipient_login);
    cout << "Enter message text: ";
    getline(cin, text);
    Message message(user, chat.GetUsers()[0], text);
    if (recipient_login == "all") {
        chat.SendMessageToAllUsers(message);
    }
    else {
        chat.SendMessageToUser(message, recipient_login);
    }
    cout << "Message sent." << endl;
}

void displayMessages(const Chat& chat) {
    for (const Message& message : chat.GetMessages()) {
        cout << message;
    }
}

int main() {
    Chat chat;
    User* user = nullptr;
    while (true) {
        cout << "Enter command (register, login, send, messages, exit): ";
        string command;
        getline(cin, command);
        if (command == "register") {
            registerUser(chat);
        }
        else if (command == "login") {
            loginUser(chat, user);
        }
        else if (command == "send") {
            if (user) {
                sendMessage(chat, *user);
            }
            else {
                cout << "You must be logged in to send messages." << endl;
            }
        }
        else if (command == "messages") {
            displayMessages(chat);
        }
        else if (command == "exit") {
            break;
        }
        else {
            cout << "Invalid command." << endl;
        }
    }
    if (user) {
        user->SetLoggedIn(false);
    }
    return 0;
}