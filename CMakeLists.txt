cmake_policy(SET CMP0048 NEW)

project(temporal VERSION 1.0.0)
cmake_minimum_required(VERSION 3.24.3)

# Common Config

set(CMAKE_CXX_STANDARD 20)

if(MSVC)
    add_compile_options(
        $<$<CONFIG:>:/MT> #---------|
        $<$<CONFIG:Debug>:/MTd> #---|-- Statically link the runtime libraries
        $<$<CONFIG:Release>:/MT> #--|
    )
endif()

# Dependencies

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        97459e54ec4f1882d219c413c929f719d9741ada
  FIND_PACKAGE_ARGS NAMES GTest
)

FetchContent_Declare(
  doxygen
  GIT_REPOSITORY https://github.com/doxygen/doxygen.git
  GIT_TAG        b1329dd1232c6c192c8aa9052396681abbc97f14
  FIND_PACKAGE_ARGS NAMES Doxygen
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Target: Library

add_library(temporal STATIC)
target_sources(temporal
    PRIVATE
        src/duration.cpp
        src/temporal-unit/temporal-unit.cpp
    PUBLIC
        src/duration.h
        src/instant.h
        src/period.h
        src/temporal-amount.h
        src/temporal-unit/temporal-unit.h
        src/chrono-unit.h
)

# Target: Tests

enable_testing()

find_package(GTest)

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

# Target: Documentation

# find_package( Doxygen )
# 
# if ( DOXYGEN_FOUND )
#     set( DOXYGEN_OUTPUT_DIRECTORY doxygen )
#     set( DOXYGEN_COLLABORATION_GRAPH YES )
#     set( DOXYGEN_EXTRACT_ALL YES )
#     set( DOXYGEN_CLASS_DIAGRAMS YES )
#     set( DOXYGEN_HIDE_UNDOC_RELATIONS NO )
#     set( DOXYGEN_HAVE_DOT YES )
#     set( DOXYGEN_CLASS_GRAPH YES )
#     set( DOXYGEN_CALL_GRAPH YES )
#     set( DOXYGEN_CALLER_GRAPH YES )
#     set( DOXYGEN_COLLABORATION_GRAPH YES )
#     set( DOXYGEN_BUILTIN_STL_SUPPORT YES )
#     set( DOXYGEN_EXTRACT_PRIVATE YES )
#     set( DOXYGEN_EXTRACT_PACKAGE YES )
#     set( DOXYGEN_EXTRACT_STATIC YES )
#     set( DOXYGEN_EXTRACT_LOCALMETHODS YES )
#     set( DOXYGEN_UML_LOOK YES )
#     set( DOXYGEN_UML_LIMIT_NUM_FIELDS 50 )
#     set( DOXYGEN_TEMPLATE_RELATIONS YES )
#     set( DOXYGEN_DOT_GRAPH_MAX_NODES 100 )
#     set( DOXYGEN_MAX_DOT_GRAPH_DEPTH 0 )
#     set( DOXYGEN_DOT_TRANSPARENT YES )
# 
#     doxygen_add_docs(documentation src)
# else()
#     message( "Doxygen needs to be installed to generate the doxygen documentation" )
# endif()
