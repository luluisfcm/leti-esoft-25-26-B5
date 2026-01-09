#pragma once

#include "HttpStatus.h"
#include <string>

class HttpResult {
public:
    HttpResult() : m_status(HttpStatus::HTTP_OK), m_body("{}") {}

    int getHttpStatus() const { return static_cast<int>(m_status); }
    HttpStatus getStatus() const { return m_status; }

    const std::string &getBody() const { return m_body; }

    void setHttpStatus(HttpStatus status) { m_status = status; }

    // The provided string should be a valid JSON string.
    void setBodyJson(const std::string &jsonBody) { m_body = jsonBody; }

    // Convenience method for error messages
    void setMessage(const std::string &message) {
        m_body = std::string("{\"message\":\"") + escapeJson(message) + "\"}";
    }

private:
    static std::string escapeJson(const std::string &s) {
        std::string out;
        out.reserve(s.size());
        for (char c : s) {
            switch (c) {
                case '"': out += "\\\""; break;
                case '\\': out += "\\\\"; break;
                case '\b': out += "\\b"; break;
                case '\f': out += "\\f"; break;
                case '\n': out += "\\n"; break;
                case '\r': out += "\\r"; break;
                case '\t': out += "\\t"; break;
                default:
                    if (static_cast<unsigned char>(c) < 0x20) {
                        // control characters -> replace
                        out += ' ';
                    } else {
                        out += c;
                    }
            }
        }
        return out;
    }

    HttpStatus m_status;
    std::string m_body;
};
