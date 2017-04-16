// Copyright (c) 2017, Kai Wolf. All rights reserved.
// Use of this source code is governed by a Apache license that can be
// found in the LICENSE file in the top directory.

#ifndef RPIXEL_UTILS_H
#define RPIXEL_UTILS_H

#define STRING_JOIN2(arg1, arg2) DO_STRING_JOIN2(arg1, arg2)
#define DO_STRING_JOIN2(arg1, arg2) arg1##arg2
#define SCOPE_EXIT(code)                       \
    auto STRING_JOIN2(scope_exit_, __LINE__) = \
        rpixel::base::MakeScopeExit([=]() { code; })

namespace rpixel {
namespace base {

template <typename F>
struct ScopeExit {
    ScopeExit(F f) : f_(f){};
    ~ScopeExit() {
        f_();
    }
    F f_;
};

template <typename F>
ScopeExit<F> MakeScopeExit(F f) {
    return ScopeExit<F>(f);
};
}
}

#endif // RPIXEL_UTILS_H
