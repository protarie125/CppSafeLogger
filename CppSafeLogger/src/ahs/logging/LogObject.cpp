#include "LogObject.h"

ahs::logging::LogObject::LogObject(const std::string& message, int line, const std::string& file)
    : message_{ message }
    , line_{ line }
    , file_{ file }
{
}

ahs::logging::LogObject::~LogObject() = default;

const std::string& ahs::logging::LogObject::getMessage() const noexcept
{
    return message_;
}

const int& ahs::logging::LogObject::getLine() const noexcept
{
    return line_;
}

const std::string& ahs::logging::LogObject::getFile() const noexcept
{
    return file_;
}