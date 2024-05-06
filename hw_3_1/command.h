#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <string>
#include <fstream>


class LogCommand
{
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};


class LogToCli: public LogCommand
{
public:
    void print(const std::string& message);
};


class LogToFile: public LogCommand
{
public:
    LogToFile(const std::string& path);

    void print(const std::string& message);

private:
    std::string path;
};


void print(LogCommand& command, const std::string& message );

#endif // COMMAND_H
