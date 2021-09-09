#include "extern_methods.h"

#include <memory>

#include "../ahs/App.h"

using namespace std;

unique_ptr<ahs::App> gApp = nullptr;

ERROR_CODE CPPSAFELOGGER_API createApp()
{
    try
    {
        if (gApp != nullptr) return INSTANCE_ALREADY_EXISTS;

        gApp = make_unique<ahs::App>();

        return OK;
    }
    catch (...)
    {
        return FAIL;
    }
}

ERROR_CODE CPPSAFELOGGER_API appGetA(int* a)
{
    try
    {
        if (gApp == nullptr) return INSTANCE_NOT_CREATED;

        if (a == nullptr) return NULL_OUT_OBJECT;

        *a = gApp->getA();
    }
    catch (...)
    {
        return FAIL;
    }
}

ERROR_CODE CPPSAFELOGGER_API appSetA(int value)
{
    try
    {
        if (gApp == nullptr) return INSTANCE_NOT_CREATED;

        gApp->setA(value);
    }
    catch (...)
    {
        return FAIL;
    }
}

ERROR_CODE CPPSAFELOGGER_API appGetB(int* b)
{
    try
    {
        if (gApp == nullptr) return INSTANCE_NOT_CREATED;

        if (b == nullptr) return NULL_OUT_OBJECT;

        *b = gApp->getB();
    }
    catch (...)
    {
        return FAIL;
    }
}

ERROR_CODE CPPSAFELOGGER_API appSetB(int value)
{
    try
    {
        if (gApp == nullptr) return INSTANCE_NOT_CREATED;

        gApp->setB(value);
    }
    catch (...)
    {
        return FAIL;
    }
}

ERROR_CODE CPPSAFELOGGER_API appRun(int* result)
{
    try
    {
        if (gApp == nullptr) return INSTANCE_NOT_CREATED;

        if (result == nullptr) return NULL_OUT_OBJECT;

        *result = gApp->run();

        return OK;
    }
    catch (...)
    {
        return FAIL;
    }
}

ERROR_CODE CPPSAFELOGGER_API deleteApp()
{
    try
    {
        if (gApp != nullptr)
        {
            gApp = nullptr;
        }

        return OK;
    }
    catch (...)
    {
        return FAIL;
    }
}