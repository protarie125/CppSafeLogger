#pragma once
#include "../framework.h"

#define ERROR_CODE int
#define OK 0
#define FAIL -1
#define INSTANCE_ALREADY_EXISTS -2
#define INSTANCE_NOT_CREATED -3
#define NULL_OUT_OBJECT -4

EXTERN_C_START

ERROR_CODE CPPSAFELOGGER_API createApp();
ERROR_CODE CPPSAFELOGGER_API appGetA(int* a);
ERROR_CODE CPPSAFELOGGER_API appSetA(int value);
ERROR_CODE CPPSAFELOGGER_API appGetB(int* b);
ERROR_CODE CPPSAFELOGGER_API appSetB(int value);
ERROR_CODE CPPSAFELOGGER_API appRun(int* result);
ERROR_CODE CPPSAFELOGGER_API deleteApp();

EXTERN_C_END