#pragma once

// Unsigned int types
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

// Signed int types
typedef char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

// Floating point types
typedef float f32;
typedef double f64;

// Boolean types
typedef int b32;
typedef char b8;

// Properly define static assertions.
#if defined(__clang__) || defined(__gcc__)
#define STATIC_ASSERT _Static_assert
#else 
#define STATIC_ASSERT static_assert
#endif

// Ensure all types are of the correct size
STATIC_ASSERT(sizeof(u8) == 1, "Expect u8 to be 1 byte.");
STATIC_ASSERT(sizeof(u16) == 2, "Expect u16 to be 2 byte.");
STATIC_ASSERT(sizeof(u32) == 4, "Expect u32 to be 4 byte.");
STATIC_ASSERT(sizeof(u64) == 8, "Expect u64 to be 8 byte.");

STATIC_ASSERT(sizeof(i8) == 1, "Expect i8 to be 1 byte.");
STATIC_ASSERT(sizeof(i16) == 2, "Expect i16 to be 2 byte.");
STATIC_ASSERT(sizeof(i32) == 4, "Expect i32 to be 4 byte.");
STATIC_ASSERT(sizeof(i64) == 8, "Expect i64 to be 8 byte.");

STATIC_ASSERT(sizeof(f32) == 4, "Expect f32 to be 4 byte.");
STATIC_ASSERT(sizeof(f64) == 8, "Expect f64 to be 8 byte.");

#define TRUE 1
#define FALSE 0

// Platform detection
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) 
#define JPLATFORM_WINDOWS 1
#ifndef _WIN64
#error "64-bit is required on Windows!"
#endif
#elif defined(__linux__) || defined(__gnu_linux__)
// Linux OS
#define JPLATFORM_LINUX 1
#if defined(__ANDROID__)
#define JPLATFORM_ANDROID 1
#endif
#elif defined(__unix__)
// Catch anything not caught by the above.
#define JPLATFORM_UNIX 1
#elif defined(_POSIX_VERSION)
// Posix
#define JPLATFORM_POSIX 1
#elif __APPLE__
// Apple platforms
#define JPLATFORM_APPLE 1
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR
// iOS Simulator
#define JPLATFORM_IOS 1
#define JPLATFORM_IOS_SIMULATOR 1
#elif TARGET_OS_IPHONE
#define JPLATFORM_IOS 1
// iOS device
#elif TARGET_OS_MAC
// Other kinds of Mac OS
#else
#error "Unknown Apple platform"
#endif
#else
#error "Unknown platform!"
#endif

#ifdef JEXPORT
// Exports
#ifdef _MSC_VER
#define JAPI __declspec(dllexport)
#else
#define JAPI __attribute__((visibility("default")))
#endif
#else
// Imports
#ifdef _MSC_VER
#define JAPI __declspec(dllimport)
#else
#define JAPI
#endif
#endif