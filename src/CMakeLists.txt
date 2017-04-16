# Copyright (c) 2017, Kai Wolf. All rights reserved.
# Use of this source code is governed by a Apache license that can be
# found in the LICENSE file in the top directory.

find_package(Cairo)

add_subdirectory(base)
add_subdirectory(display)

add_library(rpixel
    $<TARGET_OBJECTS:rpixel::base>
    $<TARGET_OBJECTS:rpixel::display>)

set_target_properties(rpixel PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})

# Expose public/private API
target_include_directories(rpixel
    PUBLIC
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
      $<INSTALL_INTERFACE:include>
      ${CAIRO_INCLUDE_DIRS})

target_link_libraries(rpixel PUBLIC ${CAIRO_LIBRARIES})

add_executable(run_pixel
  render/logos.h
  main.cc)

set_target_properties(run_pixel PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON)

target_link_libraries(run_pixel rpixel)

