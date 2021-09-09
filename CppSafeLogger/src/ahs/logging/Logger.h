#pragma once
#include <memory>
#include <queue>
#include <string>
#include <fstream>

#include "LogObject.h"

namespace ahs {
    namespace logging {
        class Logger final
        {
        public:
            static std::shared_ptr<ahs::logging::Logger> getInstance() noexcept;

        private:
            Logger();

            ~Logger();

            static std::shared_ptr<ahs::logging::Logger> singleton_;

            std::queue<ahs::logging::LogObject> messageQueue_{};

            std::ofstream ofs_{};

        public:
            void push(const std::string& message, int line, const std::string& file) noexcept;

            void beginWrite(const std::string& filename);
        };
    }
}
