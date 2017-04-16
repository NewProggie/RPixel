// Copyright (c) 2017, Kai Wolf. All rights reserved.
// Use of this source code is governed by a Apache license that can be
// found in the LICENSE file in the top directory.

#ifndef RPIXEL_MACROS_H
#define RPIXEL_MACROS_H

#include <memory>

#if __cplusplus < 201402L
namespace std {
template<class T> struct _Unique_if {
  typedef unique_ptr<T> _Single_object;
};

template<class T> struct _Unique_if<T[]> {
  typedef unique_ptr<T[]> _Unknown_bound;
};

template<class T, size_t N> struct _Unique_if<T[N]> {
  typedef void _Known_bound;
};

template<class T, class... Args>
typename _Unique_if<T>::_Single_object
make_unique(Args&&... args) {
    return unique_ptr<T>(new T(std::forward<Args>(args)...));
}

template<class T>
typename _Unique_if<T>::_Unknown_bound
make_unique(size_t n) {
    typedef typename remove_extent<T>::type U;
    return unique_ptr<T>(new U[n]());
}

template<class T, class... Args>
typename _Unique_if<T>::_Known_bound
make_unique(Args&&...) = delete;
}
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
