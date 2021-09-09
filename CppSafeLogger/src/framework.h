#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#ifdef CPPSAFELOGGER_EXPORTS
#define CPPSAFELOGGER_API __declspec(dllexport)
#else
#define CPPSAFELOGGER_API __declspec(dllimport)
#endif