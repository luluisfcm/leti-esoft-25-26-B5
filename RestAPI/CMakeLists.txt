cmake_minimum_required(VERSION 3.30)

project(RestAPI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(RestAPI_Lib
        source/RestApiServer.cpp
        source/VaccineService.cpp
        source/VaccineTypeRouter.cpp
        source/VaccineRouter.cpp
)

target_include_directories(RestAPI_Lib
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/headers
        ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty
)

target_link_libraries(RestAPI_Lib PUBLIC Core ws2_32)

target_compile_definitions(RestAPI_Lib PUBLIC
        _WIN32_WINNT=0x0A00
        CPPHTTPLIB_USE_POLL
        CPPHTTPLIB_NO_FILE_SYSTEM
)

add_executable(RestAPI_Server
        RestAPI.cpp
)

target_link_libraries(RestAPI_Server PRIVATE RestAPI_Lib ws2_32)

set_target_properties(RestAPI_Server PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)
