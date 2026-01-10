#include "/domain/http/RestClient.h"

RestClient::RestClient(std::string host, int port, std::string authToken)
    : host(std::move(host)), port(port), authToken(std::move(authToken)) {}

httplib::Headers RestClient::defaultHeaders(bool hasBody) const {
    httplib::Headers h;
    h.emplace("Authorization", authToken);
    if (hasBody) h.emplace("Content-Type", "application/json");
    h.emplace("Accept", "application/json");
    return h;
}

static HttpResult toResult(const httplib::Result &res) {
    HttpResult r;

    if (!res) {
        r.ok = false;
        r.error = "No response (connection failed)";
        return r;
    }

    r.ok = true;
    r.status = res->status;
    r.body = res->body;
    return r;
}

HttpResult RestClient::get(const std::string &path) {
    httplib::Client cli(host, port);
    auto res = cli.Get(path.c_str(), defaultHeaders(false));
    return toResult(res);
}

HttpResult RestClient::post(const std::string &path, const std::string &jsonBody) {
    httplib::Client cli(host, port);
    auto res = cli.Post(path.c_str(), defaultHeaders(true), jsonBody, "application/json");
    return toResult(res);
}

HttpResult RestClient::put(const std::string &path, const std::string &jsonBody) {
    httplib::Client cli(host, port);
    auto res = cli.Put(path.c_str(), defaultHeaders(true), jsonBody, "application/json");
    return toResult(res);
}

HttpResult RestClient::del(const std::string &path) {
    httplib::Client cli(host, port);
    auto res = cli.Delete(path.c_str(), defaultHeaders(false));
    return toResult(res);
}