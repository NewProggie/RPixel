// Copyright (c) 2017, Kai Wolf. All rights reserved.
// Use of this source code is governed by a Apache license that can be
// found in the LICENSE file in the top directory.

#ifndef RPIXEL_ENVIRONMENT_H
#define RPIXEL_ENVIRONMENT_H

#include <string>

namespace rpixel {
namespace base {

/// Gets an environment variable and returns it in |result|.
/// Returns false, if the variable is not set
bool GetEnvVar(const std::string& var_name, std::string* result);

/// Returns true, if the environment variable is set
bool HasEnvVar(const std::string& var_name);

/// Sets an environment variable
/// Returns true on success, otherwise returns false
bool SetEnvVar(const std::string& var_name, const std::string& new_value);

/// Returns true on success, otherwise returns false
bool UnsetEnvVar(const std::string& var_name);

} // namespace base
} // namespace rpixel

#endif // RPIXEL_ENVIRONMENT_H
