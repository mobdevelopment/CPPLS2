#ifndef UTILS_MEMLEAKDETECTION_HEADER_INCLUDED
#define UTILS_MEMLEAKDETECTION_HEADER_INCLUDED

#include "platformdefinitions.h"

#ifdef UTILS_PLATFORM_WINDOWS
#include "windows.h"
#define _CRTDBG_MAP_ALLOC
#define _CRTDBG_MAP_ALLOC_NEW
#include <stdlib.h>
#include <crtdbg.h>
#else
#error Memory leaks reporting is only supported in Windows for now.
#endif // #ifdef UTILS_PLATFORM_WINDOWS

namespace utils
{
  void EnableMemoryLeakDetection();
} // namespace utils

#endif // #ifndef UTILS_MEMLEAKDETECTION_HEADER_INCLUDED
