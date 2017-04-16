# Copyright (c) 2017, Kai Wolf. All rights reserved.
# Use of this source code is governed by a Apache license that can be
# found in the LICENSE file in the top directory.

set(DISPLAY_SOURCE_FILES
    surface.h
    surface.cc)

add_library(rpixel_display OBJECT ${DISPLAY_SOURCE_FILES})
add_library(rpixel::display ALIAS rpixel_display)

target_include_directories(rpixel_display PRIVATE
    ${CMAKE_SOURCE_DIR}/src)

set_target_properties(rpixel_display PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON)