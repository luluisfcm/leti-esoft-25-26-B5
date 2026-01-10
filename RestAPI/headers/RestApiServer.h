#pragma once

// Disable mmap and exceptions in cpp-httplib so that MinGW doesn't require
// Windows-specific APIs like CreateFile2 and CreateFileMappingFromApp.
#ifndef CPPHTTPLIB_NO_MMAP
#define CPPHTTPLIB_NO_MMAP
#endif

#ifndef CPPHTTPLIB_NO_EXCEPTIONS
#define CPPHTTPLIB_NO_EXCEPTIONS
#endif

// Tell our patched httplib to avoid using the Windows-specific mmap
// implementation entirely on this target. This makes it fall back to
// a no-op mmap wrapper and removes the dependency on CreateFile2.
#ifndef HTTPLIB_DISABLE_WIN_MMAP
#define HTTPLIB_DISABLE_WIN_MMAP
#endif

#include "../thirdparty/httplib.h"

class RestApiServer {
public:
    // Blocks the current thread.
    void run(const std::string &host, int port);
};
