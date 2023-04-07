#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
#include "user.h"

class Message {
public:
    Message(const User& sender, const User& receiver, const std::string& text);

    const User& GetSender() const;
    const User& GetReceiver() const;
    const std::string& GetText() const;
    void SetText(const std::string& text);
    void SetReceiverName(const std::string& receiver_name);
    friend std::ostream& operator<<(std::ostream& os, const Message& message);


private:
    const User& sender_;
    const User& receiver_;
    std::string text_;
    std::string receiver_name_;
};

#endif // MESSAGE_H