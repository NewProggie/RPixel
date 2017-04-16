# Copyright (c) 2017, Kai Wolf. All rights reserved.
# Use of this source code is governed by a Apache license that can be
# found in the LICENSE file in the top directory.

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(BASE_SOURCE_FILES
    macros.h
    environment.cc
    environment.h utils.h)

add_library(rpixel_base OBJECT ${BASE_SOURCE_FILES})
add_library(rpixel::base ALIAS rpixel_base)

set_target_properties(rpixel_base PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON)