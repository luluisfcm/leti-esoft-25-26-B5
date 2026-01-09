#pragma once

#include "../thirdparty/httplib.h"
#include <string>

inline bool hasAuth(const httplib::Request &req) {
    return req.has_header("Authorization") && !req.get_header_value("Authorization").empty();
}

inline void replyJson(httplib::Response &res, int status, const std::string &jsonBody) {
    res.status = status;
    res.set_content(jsonBody, "application/json");
}

inline void replyMessage(httplib::Response &res, int status, const std::string &msg) {
    std::string body = std::string("{\"message\":\"") + msg + "\"}";
    replyJson(res, status, body);
}

