#pragma once
#include <string>

namespace ahs {
    namespace logging {
        class LogObject final
        {
        public:
            LogObject(const std::string& message, int line, const std::string& file);

            ~LogObject();

        private:
            std::string message_{};

            int line_{ 0 };

            std::string file_{};

        public:
            const std::string& getMessage() const noexcept;

            const int& getLine() const noexcept;

            const std::string& getFile() const noexcept;
        };
    }
}