#pragma once

#include <stdexcept>
#include <string>

// Minimal auth gate to keep the existing router structure working.
// Current project doesn't have real auth wired yet, so we treat any non-empty
// Authorization header as acceptable.
inline void ensureAuthenticated(const std::wstring &bearerToken) {
    if (bearerToken.empty()) {
        throw std::invalid_argument("Missing Authorization header");
    }
}

