# Copyright (c) 2017, Kai Wolf. All rights reserved.
# Use of this source code is governed by a Apache license that can be
# found in the LICENSE file in the top directory.

set(RENDER_SOURCE_FILES
    painter.cc
    painter.h)

add_library(rpixel_render OBJECT ${RENDER_SOURCE_FILES})
add_library(rpixel::render ALIAS rpixel_render)

target_include_directories(rpixel_render PRIVATE
    ${CMAKE_SOURCE_DIR}/src)

set_target_properties(rpixel_render PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON)
