cmake_minimum_required(VERSION 3.30)
project(ConsoleApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ConsoleApp
        ConsoleApp.cpp
        sources/domain/shared/Result.cpp
        sources/domain/shared/StringUtils.cpp
        sources/domain/http/RestClient.cpp
        sources/domain/ui/VaccineUI.cpp
        sources/domain/ui/VaccineTypeUI.cpp

)

# Resolve o problema do CreateFile2 no Windows headers (MinGW)
target_compile_definitions(ConsoleApp PRIVATE
        CPPHTTPLIB_NO_MMAP
        _WIN32_WINNT=0x0602
        WINVER=0x0602
)

# Diretório raiz do repo (um nível acima de ConsoleApp/)
get_filename_component(REPO_ROOT "${CMAKE_CURRENT_LIST_DIR}/.." ABSOLUTE)

target_include_directories(ConsoleApp PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/domain"
        "${REPO_ROOT}/RestAPI/thirdparty"
        "${REPO_ROOT}/RestAPI/headers"
)

target_link_libraries(ConsoleApp PRIVATE
        Core
        $<$<BOOL:${WIN32}>:ws2_32>
)
