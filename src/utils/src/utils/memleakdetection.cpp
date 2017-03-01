#include "utils/memleakdetection.h"

void utils::EnableMemoryLeakDetection()
{
  #ifdef UTILS_PLATFORM_WINDOWS
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
  #endif // #ifdef UTILS_PLATFORM_WINDOWS
}
