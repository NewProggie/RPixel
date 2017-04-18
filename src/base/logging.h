// Copyright (c) 2017, Kai Wolf. All rights reserved.
// Use of this source code is governed by a Apache license that can be
// found in the LICENSE file in the top directory.

#ifndef RPIXEL_LOGGING_H
#define RPIXEL_LOGGING_H

#include "macros.h"

#ifdef OS_WINDOWS
#undef ERROR
#endif
#include <ostream>

namespace rpixel {
namespace base {

enum LogSeverity { FATAL, ERROR, WARNING, INFO };

namespace internal {
int GetLoggingLevel();
void SetLoggingLevel(int value);

std::ostream& GetNullLoggingInstance();
std::ostream& GetErrorLoggingInstance();

inline std::ostream& GetLoggingInstanceForLevel(int level) {
    if (level <= GetLoggingLevel()) { return GetErrorLoggingInstance(); }
    return GetNullLoggingInstance();
}
} // namespace internal
} // namespace base

#define LOGGING(x)                                           \
    (::rpixel::base::internal::GetLoggingInstanceForLevel(x) \
     << "-- rpixel LOG(" << (x) << "): ")
} // namespace rpixel
#endif // RPIXEL_LOGGING_H
