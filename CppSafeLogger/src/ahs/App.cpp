#include "App.h"

#include <exception>

#include "logging/Logger.h"

ahs::App::App() = default;

ahs::App::~App() = default;

const int& ahs::App::getA() const noexcept
{
    return a_;
}

void ahs::App::setA(const int& value) noexcept
{
    a_ = value;
}

const int& ahs::App::getB() const noexcept
{
    return b_;
}

void ahs::App::setB(const int& value) noexcept
{
    b_ = value;
}

int ahs::App::run()
{
    try
    {
        auto result = getA() + getB();

        throw std::exception{ "Test Exception" };

        return result;
    }
    catch (const std::exception& exc)
    {
        const auto& logger = ahs::logging::Logger::getInstance();
        logger->push(exc.what(), __LINE__, __FILE__);
    }
}