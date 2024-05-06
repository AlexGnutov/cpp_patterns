#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>


class Observer {
public:
    virtual void onWarning(const std::string& message) {}
    virtual void onError(const std::string& message) {}
    virtual void onFatalError(const std::string& message) {}
};


class Observable
{
public:
    Observable();

    void warning(const std::string& message) const {
        for (auto o : observers_) {
            if (auto p = o.lock()) {
                p->onWarning(message);
            }
        }
    }

    void error(const std::string& message) const {
        for (auto o : observers_) {
            if (auto p = o.lock()) {
                p->onError(message);
            }
        }
    }

    void fatalError(const std::string& message) const {
        for (auto o : observers_) {
            if (auto p = o.lock()) {
                p->onFatalError(message);
            }
        }
    }

    void addObserver(std::weak_ptr<Observer> observable) {
        observers_.push_back(observable);
    }

private:
    std::vector<std::weak_ptr<Observer>> observers_ = {};
};



class WarningObserver: public Observer {
public:
    void onWarning(const std::string& message) override {
        std::cout << "warning observer: " << message << std::endl;
    }
};


class ErrorObserver: public Observer {
public:
    ErrorObserver(const std::string& path):path(path) {}

    void onError(const std::string& message) override {
        std::ofstream file(path, std::ios::app);
        if (file.is_open()) {
            file << "error observer: " << message << std::endl;
        }
    }

private:
    std::string path;
};


class FatalErrorObserver: public Observer {
public:
    FatalErrorObserver(const std::string& path):path(path) {}

    void onFatalError(const std::string& message) override {
        std::cout << "fatal error observer: " << message << std::endl;
        std::ofstream file(path, std::ios::app);
        if (file.is_open()) {
            file << "fatal error observer: " << message << std::endl;
        }
    }

private:
    std::string path;
};

#endif // OBSERVABLE_H
