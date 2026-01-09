cmake_minimum_required(VERSION 3.30)
project(leti_esoft_25_26_B5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

# Core library (used by CoreTests; can also be used by other modules)
add_subdirectory(Core)

# Rest API (library + server executable)
add_subdirectory(RestAPI)

# Unit tests
add_subdirectory(CoreTests)
