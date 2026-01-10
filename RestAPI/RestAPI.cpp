#include "RestApiServer.h"

// Entry point for the RestAPI executable.
int main() {
    RestApiServer server;
    server.run("0.0.0.0", 8080);
    return 0;
}

