cmake_minimum_required(VERSION 3.30)
project(ConsoleApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ConsoleApp
        ConsoleApp.cpp
        sources/domain/shared/Result.cpp
        sources/domain/shared/StringUtils.cpp

        # HTTP client + UI
        sources/domain/http/RestClient.cpp
        sources/domain/ui/VaccineUI.cpp
)

target_include_directories(ConsoleApp PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/domain

        # para poderes fazer: #include "../../RestAPI/thirdparty/httplib.h"
        ${CMAKE_CURRENT_SOURCE_DIR}/../RestAPI/thirdparty
        ${CMAKE_CURRENT_SOURCE_DIR}/../RestAPI/headers
)

# Se estiveres no Windows, precisas disto para sockets (igual ao RestAPI)
if (WIN32)
    target_link_libraries(ConsoleApp ws2_32)
endif()

target_link_libraries(ConsoleApp Core)