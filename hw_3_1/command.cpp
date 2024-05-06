#include "command.h"

LogToFile::LogToFile(const std::string &path):path(path) {}

void LogToFile::print(const std::string &message) {
    std::ofstream file(path, std::ios::app);
    if (file.is_open()) {
        file << message << std::endl;
        file.close();
    }
}

void LogToCli::print(const std::string &message) {
    std::cout << message << std::endl;
}

void print(LogCommand &command, const std::string &message) {
    command.print(message);
}
