#include "Logger.h"

std::shared_ptr<ahs::logging::Logger> ahs::logging::Logger::getInstance() noexcept
{
    if (singleton_ == nullptr) singleton_ = std::make_shared<ahs::logging::Logger>();

    return singleton_;
}

ahs::logging::Logger::Logger() = default;

ahs::logging::Logger::~Logger() = default;

void ahs::logging::Logger::push(const std::string& message, int line, const std::string& file) noexcept
{
    ahs::logging::LogObject obj{ message, line, file };
    messageQueue_.push(obj);
}

void ahs::logging::Logger::beginWrite(const std::string& filename)
{
    ofs_ = std::ofstream{ filename, std::ofstream::app };
    if (!ofs_.is_open()) return;

    if (ofs_.good())
    {
        while (!messageQueue_.empty())
        {
            const auto& msg = messageQueue_.front();
            ofs_ << msg.getMessage() << "\t" << msg.getFile() << " (line:" << msg.getLine() << ")\n";
            messageQueue_.pop();
        }
    }
    ofs_.close();
}