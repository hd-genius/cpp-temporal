cmake_policy(SET CMP0048 NEW)

project(temporal VERSION 1.0.0)
cmake_minimum_required(VERSION 3.24.3)

set(CMAKE_CXX_STANDARD 20)

# Target: Library

add_library(temporal STATIC)
target_sources(temporal
    PRIVATE
        src/duration.cpp
        src/temporal-unit/temporal-unit.cpp
        src/temporal-unit/second-unit.h
        src/temporal-unit/second-unit.cpp
    PUBLIC
        src/duration.h
        src/instant.h
        src/period.h
        src/temporal-amount.h
        src/temporal-unit/temporal-unit.h
        src/chrono-unit.h
)

# Target: Tests

set(INSTALL_GTEST OFF)
add_subdirectory(src/dependencies/googletest)

enable_testing()

add_executable(
    temporal-test
    src/test.cpp
    src/duration.test.h
    src/temporal-unit/temporal-unit.test.h
)
target_link_libraries(
    temporal-test
    GTest::gtest_main
    temporal
)
# include(GoogleTest)
# gtest_discover_tests(temporal-test)
add_test(NAME temporal-test COMMAND temporal-test)

# Target: Benchmarks

# set (BENCHMARK_ENABLE_INSTALL OFF)
# set (BENCHMARK_ENABLE_TESTING OFF)
# add_subdirectory(dependencies/benchmark)

# add_executable(hellobench hellobench.cpp)
# target_link_libraries(hellobench benchmark)
