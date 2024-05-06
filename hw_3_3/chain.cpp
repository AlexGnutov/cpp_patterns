#include "chain.h"


FatalErrorMessage::FatalErrorMessage(const std::string &message) {
    message_type = Type::fatalerror;
    message_text = message;
}

ErrorMessage::ErrorMessage(const std::string &message) {
    message_type = Type::error;
    message_text = message;
}

WarningMessage::WarningMessage(const std::string &message) {
    message_type = Type::warning;
    message_text = message;
}

UnknownMessage::UnknownMessage(const std::string &message) {
    message_type = Type::unknown;
    message_text = message;
}

void AbstractHandler::set_next_handler(AbstractHandler *handler) {
    next_handler = handler;
}

void FatalErrorHandler::handle_request(const Message &message) {
    if (message.type() == Type::fatalerror) {
        throw std::runtime_error("Fatal error: " + message.message());
    } else {
        if (next_handler != nullptr) {
            next_handler->handle_request(message);
        }
    }
}

void ErrorHandler::handle_request(const Message &message) {
    if (message.type() == Type::error) {
        std::ofstream file(path, std::ios::app);
        if (file.is_open()) {
            file << message.message() << std::endl;
            file.close();
        }
    } else {
        if (next_handler != nullptr) {
            next_handler->handle_request(message);
        }
    }
}

void WarningHandler::handle_request(const Message &message) {
    if (message.type() == Type::warning) {
        std::cout << message.message() << std::endl;
    } else {
        if (next_handler != nullptr) {
            next_handler->handle_request(message);
        }
    }
}

void UnknownMessageHandler::handle_request(const Message &message) {
    if (message.type() == Type::unknown) {
        throw std::runtime_error("Unknow message: " + message.message());
    } else {
        if (next_handler != nullptr) {
            next_handler->handle_request(message);
        }
    }
}
