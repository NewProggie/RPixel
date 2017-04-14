# Copyright (c) 2017, Kai Wolf. All rights reserved.
# Use of this source code is governed by a Apache license that can be
# found in the LICENSE file in the top directory.

cmake_minimum_required(VERSION 3.6 FATAL_ERROR)
project(rpixel VERSION 0.1 LANGUAGES C CXX)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
find_package(Cairo)

add_subdirectory(src)
