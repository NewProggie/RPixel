# Copyright (c) 2017, Kai Wolf. All rights reserved.
# Use of this source code is governed by a Apache license that can be
# found in the LICENSE file in the top directory.

cmake_minimum_required(VERSION 3.6 FATAL_ERROR)
project(rpixel VERSION 0.1 LANGUAGES C CXX)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

option(WITH_CLANG_TIDY_CHECKS "Use clang-tidy checks" OFF)
if(WITH_CLANG_TIDY_CHECKS)
  find_program(CLANG_TIDY_EXECUTABLE clang-tidy DOC "Path to clang-tidy")
  if(CLANG_TIDY_EXECUTABLE)
    set(CMAKE_CXX_CLANG_TIDY ${CLANG_TIDY_EXECUTABLE} -fix)
  else()
    message(WARNING "WITH_CLANG_TIDY_CHECKS enabled but no clang-tidy \
                     executable found")
  endif()
endif()


add_subdirectory(src)
