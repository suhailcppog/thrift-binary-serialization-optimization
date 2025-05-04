#
# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements. See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership. The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License. You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied. See the License for the
# specific language governing permissions and limitations
# under the License.
#

cmake_minimum_required(VERSION 3.14)
project(TestBinaryProtocol)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Boost
find_package(Boost REQUIRED COMPONENTS filesystem thread unit_test_framework chrono)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    message(STATUS "Boost found: ${Boost_INCLUDE_DIRS}")
else()
    message(FATAL_ERROR "Boost not found. Install Boost or set BOOST_ROOT.")
endif()

# Find Thrift
find_package(Thrift REQUIRED)
include_directories(${THRIFT_INCLUDE_DIR})

# Auto-generate C++ from Thrift IDL
find_program(THRIFT_COMPILER thrift)
if (NOT THRIFT_COMPILER)
    message(FATAL_ERROR "Thrift compiler not found. Please install Apache Thrift.")
endif()

set(THRIFT_FILE ${CMAKE_SOURCE_DIR}/benchmark.thrift)
set(GEN_CPP_DIR ${CMAKE_BINARY_DIR}/gen-cpp)

add_custom_command(
    OUTPUT ${GEN_CPP_DIR}/Benchmark_types.cpp ${GEN_CPP_DIR}/Benchmark_types.h
    COMMAND ${THRIFT_COMPILER} --gen cpp -o ${CMAKE_BINARY_DIR} ${THRIFT_FILE}
    DEPENDS ${THRIFT_FILE}
    COMMENT "Generating C++ code from Thrift definitions"
)

include_directories(${GEN_CPP_DIR})

# Create a library for generated Thrift code
add_library(thrift_gen STATIC
    ${GEN_CPP_DIR}/Benchmark_types.cpp
)

# Benchmark executable
add_executable(Benchmark test/Benchmark.cpp)
target_link_libraries(Benchmark thrift_gen thrift ${Boost_LIBRARIES})

# Unit test executable (optional - add sources as needed)
add_executable(UnitTests
    test/UnitTestMain.cpp
    # Add other test sources here
)
target_link_libraries(UnitTests thrift_gen thrift ${Boost_LIBRARIES})

# Testing
enable_testing()
add_test(NAME Benchmark COMMAND Benchmark)
add_test(NAME UnitTests COMMAND UnitTests)
