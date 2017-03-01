#ifndef MACHIAVELLI_MAIN_HEADER_INCLUDED
#define MACHIAVELLI_MAIN_HEADER_INCLUDED

#include <system_error>
#include <string>

#include <utils/definitions.h>

#ifdef UTILS_PLATFORM_WINDOWS
#include <Windows.h>
#endif // #ifdef UTILS_PLATFORM_WINDOWS

#ifdef UTILS_DEBUG
#include <utils/memleakdetection.h>
#endif // #ifdef UTILS_DEBUG

#include <netw.h>

#include "ui/context.h"
#include "ui/cnsl/userinterface.h"

#endif // #ifndef MACHIAVELLI_MAIN_HEADER_INCLUDED
