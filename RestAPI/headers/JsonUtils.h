#pragma once

#include <regex>
#include <stdexcept>
#include <string>

// Minimal JSON helpers for this educational project.
// Supports extracting string values from flat JSON objects like:
// {"code":"VT1","disease":"COVID","shortDescription":"..."}
// Does NOT support nested objects/arrays.

inline std::string jsonGetString(const std::string &body, const std::string &key) {
    // Match "key" : "value" with basic escaping support (" and \\).
    std::regex re("\\\"" + key + "\\\"\\s*:\\s*\\\"((?:\\\\.|[^\\\"])*)\\\"");
    std::smatch m;
    if (!std::regex_search(body, m, re) || m.size() < 2) {
        throw std::invalid_argument("Missing or invalid field: " + key);
    }

    std::string raw = m[1].str();
    // Unescape common sequences
    std::string out;
    out.reserve(raw.size());
    for (size_t i = 0; i < raw.size(); ++i) {
        char c = raw[i];
        if (c == '\\' && i + 1 < raw.size()) {
            char n = raw[i + 1];
            switch (n) {
                case '\\': out += '\\'; break;
                case '"': out += '"'; break;
                case 'n': out += '\n'; break;
                case 'r': out += '\r'; break;
                case 't': out += '\t'; break;
                default: out += n; break;
            }
            ++i;
        } else {
            out += c;
        }
    }
    return out;
}

inline std::string jsonEscape(const std::string &s) {
    std::string out;
    out.reserve(s.size());
    for (char c : s) {
        switch (c) {
            case '"': out += "\\\""; break;
            case '\\': out += "\\\\"; break;
            case '\n': out += "\\n"; break;
            case '\r': out += "\\r"; break;
            case '\t': out += "\\t"; break;
            default: out += c; break;
        }
    }
    return out;
}

