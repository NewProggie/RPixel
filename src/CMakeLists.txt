# Copyright (c) 2017, Kai Wolf. All rights reserved.
# Use of this source code is governed by a Apache license that can be
# found in the LICENSE file in the top directory.

add_executable(rpixel
  render/logos.h
  main.cc)

target_include_directories(rpixel
  PRIVATE ${CAIRO_INCLUDE_DIRS})

target_link_libraries(rpixel ${CAIRO_LIBRARIES})

set_target_properties(rpixel PROPERTIES
  CXX_STANDARD 11
  CXX_STANDARD_REQUIRED ON)
