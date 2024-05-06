#ifndef CHAIN_H
#define CHAIN_H

#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>


enum class Type {
    fatalerror,
    error,
    warning,
    unknown
};


class Message {
public:
    Type type() const { return message_type; }
    const std::string& message() const { return message_text; }
protected:
    Type message_type;
    std::string message_text;
};

class FatalErrorMessage: public Message {
public:
    FatalErrorMessage(const std::string& message);
};

class ErrorMessage: public Message {
public:
    ErrorMessage(const std::string& message);
};

class WarningMessage: public Message {
public:
    WarningMessage(const std::string& message);
};

class UnknownMessage: public Message {
public:
    UnknownMessage(const std::string& message);
};


class AbstractHandler
{
public:
    virtual void set_next_handler(AbstractHandler* handler);
    virtual void handle_request(const Message& message) = 0;

protected:
    AbstractHandler* next_handler = nullptr;
};


//! Throws an exception.
class FatalErrorHandler: public AbstractHandler
{
public:
    void handle_request(const Message& message);
};


//! Writes error to file
class ErrorHandler: public AbstractHandler
{
public:
    ErrorHandler(const std::string& path):path(path) {}

    void handle_request(const Message& message);
private:
    std::string path;
};


//! Writes warning to CLI
class WarningHandler: public AbstractHandler
{
public:
    void handle_request(const Message& message);
};


//! Throws unknown exception.
class UnknownMessageHandler: public AbstractHandler
{
public:
    void handle_request(const Message& message);
};

#endif // CHAIN_H
