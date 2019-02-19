#pragma once
#include <string>
#include <ostream>

//This is for part 1
class ILogger {
public:
    virtual ILogger& LogInfo(const std::string& str) = 0;
    virtual ILogger& LogError(const std::string& str) = 0;
    virtual const std::string& GetLastError() const = 0;
    virtual ~ILogger() = default;
};

// This is for Part 2/3
class StringLogger : public ILogger {
    std::ostream& stream;
    std::string lastError;
public:
    StringLogger(std::ostream& stream) : stream{stream} {}
    ILogger& LogInfo(const std::string& str) override {
        stream << "INFO: " << str;
        return *this;
    }
    ILogger& LogError(const std::string& str) override {
        stream << "ERROR: " << str;
        lastError = str;
        return *this;
    }
    const std::string& GetLastError() const override {
        return lastError;
    }
};
