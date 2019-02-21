#include "EXERCISE.h"

#include <string>
#include <ostream>


StringLogger::StringLogger(std::ostream& stream) : stream{stream} {}

ILogger& StringLogger::LogInfo(const std::string& str) {
    stream << "INFO: " << str;
    return *this;
}

ILogger& StringLogger::LogError(const std::string& str) {
    stream << "ERROR: " << str;
    lastError = str;
    return *this;
}

const std::string& StringLogger::GetLastError() const {
    return lastError;
}
