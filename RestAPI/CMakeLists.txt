cmake_minimum_required(VERSION 3.10)
project(RestAPI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(RESTAPI_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source)
set(RESTAPI_HDR_DIR ${CMAKE_CURRENT_SOURCE_DIR}/headers)

# Collect sources and headers
file(GLOB_RECURSE RESTAPI_SOURCES
    "${RESTAPI_SRC_DIR}/*.cpp"
)

file(GLOB_RECURSE RESTAPI_HEADERS
    "${RESTAPI_HDR_DIR}/*.h" "${RESTAPI_HDR_DIR}/*.hpp"
)

# Exclude the entry point from the library if picked up (accept both slash styles)
list(REMOVE_ITEM RESTAPI_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/RestAPI.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}\\RestAPI.cpp"
)

# If there are implementation sources, build a static library; otherwise create an INTERFACE library
if(RESTAPI_SOURCES)
    add_library(RestAPI_Lib STATIC ${RESTAPI_SOURCES} ${RESTAPI_HEADERS})
    target_include_directories(RestAPI_Lib PUBLIC ${RESTAPI_HDR_DIR})
else()
    add_library(RestAPI_Lib INTERFACE)
    target_include_directories(RestAPI_Lib INTERFACE ${RESTAPI_HDR_DIR})
endif()

# On MinGW/Windows, disable exceptions in cpp-httplib and link Winsock library
if(MINGW)
    if(TARGET RestAPI_Lib)
        if(NOT RESTAPI_SOURCES)
            target_compile_definitions(RestAPI_Lib INTERFACE CPPHTTPLIB_NO_EXCEPTIONS HTTPLIB_DISABLE_WIN_MMAP)
        else()
            target_compile_definitions(RestAPI_Lib PUBLIC CPPHTTPLIB_NO_EXCEPTIONS HTTPLIB_DISABLE_WIN_MMAP)
        endif()
    endif()

    # Require RestAPI.cpp at project root as the executable entrypoint
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/RestAPI.cpp")
        add_executable(RestAPI_Server "${CMAKE_CURRENT_SOURCE_DIR}/RestAPI.cpp")
        target_include_directories(RestAPI_Server PRIVATE ${RESTAPI_HDR_DIR})
        target_link_libraries(RestAPI_Server PRIVATE RestAPI_Lib)

        # Link against Winsock2 for cpp-httplib networking symbols
        target_link_libraries(RestAPI_Server PRIVATE ws2_32)
        target_compile_definitions(RestAPI_Server PRIVATE CPPHTTPLIB_NO_EXCEPTIONS HTTPLIB_DISABLE_WIN_MMAP)
    else()
        message(FATAL_ERROR "RestAPI.cpp not found in ${CMAKE_CURRENT_SOURCE_DIR}. Please add the project entry file or update CMakeLists.")
    endif()
else()
    # Require RestAPI.cpp at project root as the executable entrypoint
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/RestAPI.cpp")
        add_executable(RestAPI_Server "${CMAKE_CURRENT_SOURCE_DIR}/RestAPI.cpp")
        target_include_directories(RestAPI_Server PRIVATE ${RESTAPI_HDR_DIR})
        target_link_libraries(RestAPI_Server PRIVATE RestAPI_Lib)
    else()
        message(FATAL_ERROR "RestAPI.cpp not found in ${CMAKE_CURRENT_SOURCE_DIR}. Please add the project entry file or update CMakeLists.")
    endif()
endif()

if (WIN32)
    target_link_libraries(RestAPI_Lib PRIVATE ws2_32)
    target_link_libraries(RestAPI_Server PRIVATE ws2_32)
endif()
