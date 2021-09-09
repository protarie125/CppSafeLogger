#pragma once

namespace ahs {
    class App
    {
    public:
        App();

        virtual ~App();

    private:
        int a_{ 0 };
        int b_{ 0 };

    public:
        virtual const int& getA() const noexcept;

        virtual void setA(const int& value) noexcept;

        virtual const int& getB() const noexcept;

        virtual void setB(const int& value) noexcept;

        virtual int run();
    };
}