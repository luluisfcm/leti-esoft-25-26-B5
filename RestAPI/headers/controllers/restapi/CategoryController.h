#pragma once

#include "../restapi/HttpResult.h"
#include "../restapi/Auth.h"
#include <string>

// Minimal stub so the existing CategoryRouter compiles.
// TODO: Replace with real Category domain implementation when available.
class CategoryController {
public:
    explicit CategoryController(const std::wstring &bearerToken) {
        ensureAuthenticated(bearerToken);
    }

    HttpResult getAll() {
        HttpResult r;
        r.setHttpStatus(HttpStatus::HTTP_OK);
        r.setBodyJson("[]");
        return r;
    }

    HttpResult getById(const std::wstring & /*code*/) {
        HttpResult r;
        r.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_NOT_FOUND);
        r.setMessage("Category not implemented");
        return r;
    }

    HttpResult postCategory(const std::wstring & /*code*/, const std::wstring & /*description*/) {
        HttpResult r;
        r.setHttpStatus(HttpStatus::HTTP_CREATED);
        r.setMessage("Category not implemented");
        return r;
    }

    HttpResult putCategory(const std::wstring & /*code*/, const std::wstring & /*description*/) {
        HttpResult r;
        r.setHttpStatus(HttpStatus::HTTP_OK);
        r.setMessage("Category not implemented");
        return r;
    }

    HttpResult deleteCategory(const std::wstring & /*code*/) {
        HttpResult r;
        r.setHttpStatus(HttpStatus::HTTP_NO_CONTENT);
        r.setBodyJson("{}");
        return r;
    }
};
