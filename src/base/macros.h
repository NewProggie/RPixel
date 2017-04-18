// Copyright (c) 2017, Kai Wolf. All rights reserved.
// Use of this source code is governed by a Apache license that can be
// found in the LICENSE file in the top directory.

#ifndef RPIXEL_MACROS_H
#define RPIXEL_MACROS_H

#include <memory>

#if __cplusplus >= 201402L
usig std::make_unique;
#else
template<typename T, typename... Args>
typename std::enable_if<!std::is_array<T>::value, std::unique_ptr<T>>::type
make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

/// Allows 'make_unique<T[]>(10)'. (N3690 s20.9.1.4 p3-4)
template<typename T>
typename std::enable_if<std::is_array<T>::value, std::unique_ptr<T>>::type
make_unique(const size_t n) {
    return std::unique_ptr<T>(new typename std::remove_extent<T>::type[n]());
}

/// Disallows 'make_unique<T[10]>()'. (N3690 s20.9.1.4 p5)
template<typename T, typename... Args>
typename std::enable_if<
    std::extent<T>::value != 0, std::unique_ptr<T>>::type
make_unique(Args&&...) = delete;
#endif

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName&) = delete;    \
    TypeName& operator=(const TypeName&) = delete

#define DISALLOW_IMPLICIT_CONSTRUCTOR(TypeName) \
    TypeName() = delete;                        \
    DISALLOW_COPY_AND_ASSIGN(TypeName)

/// Verify an expression during compile-time
#undef COMPILE_ASSERT
#define COMPILE_ASSERT(expr, msg) static_assert(expr, #msg)

/// Give branch indication hints to the (GCC) compiler: whether the if
/// condition is likely to be true or false
#undef LIKELY
#undef UNLIKELY
#if defined(__GNUC__) && __GNUC__ >= 4
#define LIKELY(x) (__builtin_expect((x), 1))
#define UNLIKELY(x) (__builtin_expect((x), 0))
#else
#define LIKELY(x) (x)
#define UNLIKELY(x) (x)
#endif

/// Determine host os system
#if defined(_WIN32)
#define OS_WINDOWS 1
#define __func__ __FUNCTION__
#elif defined(__APPLE__)
#define OS_MACOSX 1
#elif defined(__FreeBSD__)
#define OS_FREEBSD 1
#elif defined(__linux__)
#define OS_LINUX 1
#elif defined(__arm__)
#define OS_RASPBIAN 1
#endif

/// determine used compiler
#if defined(__clang__)
#define COMPILER_CLANG
#elif defined(_MSC_VER)
#define COMPILER_MSVC
#elif defined(__GNUC__)
#define COMPILER_GCC
#endif

#endif // RPIXEL_MACROS_H
