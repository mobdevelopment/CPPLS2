#ifndef UTILS_PLATFORMDEFINITIONS_HEADER_INCLUDED
#define UTILS_PLATFORMDEFINITIONS_HEADER_INCLUDED

// Apple.
#ifdef __APPLE__
#define UTILS_PLATFORM_APPLE
#endif // #ifdef __APPLE__

// Windows.
#if defined(__MINGW32__) || defined(_WIN32)
#define UTILS_PLATFORM_WINDOWS
#if defined(_WIN64)
#define UTILS_PLATFORM_WINDOWS64
#endif // #if defined(_WIN64)
#endif // #if defined(__MINGW32__) || defined(_WIN32)

// Linux.
#if defined(__linux__)
#define UTILS_PLATFORM_LINUX
#endif // #if defined(__linux__)

#endif // #ifndef UTILS_PLATFORMDEFINITIONS_HEADER_INCLUDED
