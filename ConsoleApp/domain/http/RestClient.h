#pragma once
#include <string>
#include <map>
#include "httplib.h"


struct HttpResult {
    bool ok = false;          // request feita com sucesso (rede)
    int status = 0;           // status HTTP (200, 201, 404, ...)
    std::string body;         // body da resposta
    std::string error;        // erro de rede (se houver)
};

class RestClient {
    std::string host;
    int port;
    std::string authToken;

public:
    RestClient(std::string host = "localhost", int port = 8080, std::string authToken = "test");

    HttpResult get(const std::string &path);
    HttpResult post(const std::string &path, const std::string &jsonBody);
    HttpResult put(const std::string &path, const std::string &jsonBody);
    HttpResult del(const std::string &path);

private:
    httplib::Headers defaultHeaders(bool hasBody) const;
};