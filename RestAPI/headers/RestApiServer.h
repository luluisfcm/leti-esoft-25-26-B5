#pragma once

#include "../thirdparty/httplib.h"

class RestApiServer {
public:
    // Blocks the current thread.
    void run(const std::string &host, int port);
};

