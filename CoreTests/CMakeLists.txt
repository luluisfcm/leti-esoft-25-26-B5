cmake_minimum_required(VERSION 3.30)
project(CoreTests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

# GoogleTest vendorizado (avoid extra targets)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
add_subdirectory(lib)

add_executable(CoreTests
        domain/shared/StringUtilsTests.cpp
)

target_link_libraries(CoreTests
        PRIVATE
        Core
        gtest
        gtest_main
)

add_test(NAME CoreTests COMMAND CoreTests)
