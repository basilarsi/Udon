//
// Created by Basil on 8/6/2026.
//

#ifndef UDON_DEFS_HPP
#define UDON_DEFS_HPP

/* Platform Detection */
#define UDON_PLATFORM_WINDOWS (0)

#define UDON_PLATFORM_LINUX (1)

#define UDON_PLATFORM_MAC (2)

#define UDON_PLATFORM_UNKNOWN (3)

#if _WIN32
  #define UDON_CURRENT_PLATFORM UDON_PLATFORM_WINDOWS
#elif __linux__
  #define UDON_CURRENT_PLATFORM UDON_PLATFORM_LINUX

  #if !UDON_SUPPRESS_LINUX_PLATFORM_WARNING
    #warning "I make no promises that this code will be cross-platform, good luck!"
  #endif
#elif __APPLE__
  #define UDON_CURRENT_PLATFORM UDON_PLATFORM_MAC

  #if !UDON_SUPPRESS_MAC_PLATFORM_ERROR
    #error "Udon uses Vulkan, and I don't have time to wire up a compatability layer!"
  #endif
#else
  #define UDON_CURRENT_PLATFORM UDON_PLATFORM_UNKNOWN

  #if !UDON_SUPPRESS_UNKNOWN_PLATFORM_ERROR
    #error "Udon was unable to deduce your current platform!"
  #endif
#endif

/* Force 64-bit windows */
#if _WIN32 && !_WIN64
  #error "Only 64-bit versions of windows is supported!"
#endif

/* Exporting */
#if __GNUC__ || __clang__
  #if UDON_BUILD
    #define UDON_API __attribute__((visibility("default")))
  #else
    #define UDON_API
  #endif
#elif _MSC_VER
  #if UDON_BUILD
    #define UDON_API __declspec(dllexport)
  #else
    #define UDON_API __declspec(dllimport)
  #endif
#else
  #if !UDON_SUPPRESS_UNKNOWN_COMPILER_ERROR
    #error "Udon was unable to deduce your compiler! Symbols may not be exported properly."
  #endif
#endif

/* Numeric Types */
#if (__GNUC__ || __clang__) && !defined(UDON_FORCE_STANDARD_NUMERIC_TYPES)
  typedef signed int sbyte __attribute__((mode(QI)));
  typedef signed int int16 __attribute__((mode(HI)));
  typedef signed int int32 __attribute__((mode(SI)));
  typedef signed int int64 __attribute__((mode(DI)));

  typedef unsigned int byte __attribute__((mode(QI)));
  typedef unsigned int uint16 __attribute__((mode(HI)));
  typedef unsigned int uint32 __attribute__((mode(SI)));
  typedef unsigned int uint64 __attribute__((mode(DI)));

  typedef float float32 __attribute__((mode(SF)));
  typedef float float64 __attribute__((mode(DF)));
#else
  #include <cstdint>

  typedef std::int8_t  sbyte;
  typedef std::int16_t int16;
  typedef std::int32_t int32;
  typedef std::int64_t int64;

  typedef std::uint8_t  byte;
  typedef std::uint16_t uint16;
  typedef std::uint32_t uint32;
  typedef std::uint64_t uint64;

  typedef float  float32;
  typedef double float64;
#endif

static_assert(sizeof(sbyte) == 1, "The size of an sbyte must be exactly 1 byte!");
static_assert(sizeof(int16) == 2, "The size of an int16 must be exactly 2 bytes!");
static_assert(sizeof(int32) == 4, "The size of an int32 must be exactly 4 bytes!");
// ReSharper disable once CppStaticAssertFailure
static_assert(sizeof(int64) == 8, "The size of an int64 must be exactly 8 bytes!");

static_assert(sizeof(byte) == 1,   "The size of a byte must be exactly 1 byte!");
static_assert(sizeof(uint16) == 2, "The size of a uint16 must be exactly 2 bytes!");
static_assert(sizeof(uint32) == 4, "The size of a uint32 must be exactly 4 bytes!");
// ReSharper disable once CppStaticAssertFailure
static_assert(sizeof(uint64) == 8, "The size of a uint64 must be exactly 8 bytes!");

static_assert(sizeof(float32) == 4, "The size of a float32 must be exactly 4 bytes!");
static_assert(sizeof(float64) == 8, "The size of a float64 must be exactly 8 bytes!");

#endif //UDON_DEFS_HPP