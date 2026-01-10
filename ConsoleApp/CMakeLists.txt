cmake_minimum_required(VERSION 3.30)
project(ConsoleApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ConsoleApp
        ConsoleApp.cpp

        # shared utils
        sources/domain/shared/Result.cpp
        sources/domain/shared/StringUtils.cpp

        # UI (vais acrescentar depois)
        sources/domain/ui/VaccineUI.cpp
)

target_include_directories(ConsoleApp PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/domain
)

target_link_libraries(ConsoleApp Core)
