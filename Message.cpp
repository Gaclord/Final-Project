#include "message.h"
#include <iostream>

Message::Message(const User& sender, const User& receiver, const std::string& text)
    : sender_(sender), receiver_(receiver), text_(text), receiver_name_("")
{}

const User& Message::GetSender() const {
    return sender_;
}

const User& Message::GetReceiver() const {
    return receiver_;
}

const std::string& Message::GetText() const {
    return text_;
}

void Message::SetText(const std::string& text) {
    text_ = text;
}

void Message::SetReceiverName(const std::string& receiver_name) {
    receiver_name_ = receiver_name;
}

std::ostream& operator<<(std::ostream& os, const Message& message) {
    os << "From: " << message.GetSender().GetName() << std::endl
        << "To: " << message.GetReceiver().GetName() << std::endl
        << "Text: " << message.GetText() << std::endl;
    return os;
}