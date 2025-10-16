project(CoreTests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(CoreTests domain/shared/StringUtilsTests.cpp)

target_link_libraries(CoreTests Core)
target_link_libraries(CoreTests gtest gtest_main)