#include "../headers/VaccineRouter.h"

#include "../headers/HttpHelpers.h"
#include "../headers/JsonUtils.h"
#include "../headers/Vaccine.h"

#include <algorithm>

static bool isBlank(const std::string &s) {
    return s.empty() || std::all_of(s.begin(), s.end(), [](unsigned char c) { return std::isspace(c) != 0; });
}

void configureVaccineRoutes(httplib::Server &svr, VaccineTypeService &typeSvc, VaccineService &vaccSvc) {
    const std::string base = "/vaccines";
    const std::string patternBase = base + "(\\/?)";
    const std::string patternByCode = base + "/(\\w+)";

    svr.Get(patternBase, [&](const httplib::Request &req, httplib::Response &res) {
        if (!hasAuth(req)) return replyMessage(res, 401, "Not authenticated");

        bool grouped = false;
        if (req.has_param("grouped")) grouped = req.get_param_value("grouped") == "true";

        if (grouped) {
            replyJson(res, 200, vaccSvc.getAllGroupedByTypeSortedByBrand(typeSvc));
            return;
        }

        std::string body = "[";
        bool first = true;
        for (const auto &v : vaccSvc.getAll()) {
            if (!first) body += ",";
            first = false;
            body += vaccineToJson(v);
        }
        body += "]";
        replyJson(res, 200, body);
    });

    svr.Get(patternByCode, [&](const httplib::Request &req, httplib::Response &res) {
        if (!hasAuth(req)) return replyMessage(res, 401, "Not authenticated");

        const std::string code = req.matches[1];
        auto v = vaccSvc.getByCode(code);
        if (!v.has_value()) return replyMessage(res, 404, "Vaccine not found");
        replyJson(res, 200, vaccineToJson(*v));
    });

    svr.Post(patternBase, [&](const httplib::Request &req, httplib::Response &res) {
        if (!hasAuth(req)) return replyMessage(res, 401, "Not authenticated");

        try {
            VaccineDto v;
            v.code = jsonGetString(req.body, "code");
            v.commercialName = jsonGetString(req.body, "commercialName");
            v.brand = jsonGetString(req.body, "brand");
            v.technologyUsed = jsonGetString(req.body, "technologyUsed");
            v.vaccineTypeCode = jsonGetString(req.body, "vaccineTypeCode");

            if (isBlank(v.code) || isBlank(v.commercialName) || isBlank(v.brand) || isBlank(v.technologyUsed) || isBlank(v.vaccineTypeCode))
                return replyMessage(res, 400, "code, commercialName, brand, technologyUsed and vaccineTypeCode are mandatory");

            if (!typeSvc.getByCode(v.vaccineTypeCode).has_value())
                return replyMessage(res, 400, "vaccineTypeCode does not exist");

            if (!vaccSvc.create(v)) return replyMessage(res, 409, "Vaccine code already exists");

            replyJson(res, 201, vaccineToJson(v));
        } catch (const std::exception &e) {
            replyMessage(res, 400, e.what());
        }
    });

    svr.Put(patternByCode, [&](const httplib::Request &req, httplib::Response &res) {
        if (!hasAuth(req)) return replyMessage(res, 401, "Not authenticated");

        const std::string codeUrl = req.matches[1];
        try {
            VaccineDto v;
            v.code = jsonGetString(req.body, "code");
            v.commercialName = jsonGetString(req.body, "commercialName");
            v.brand = jsonGetString(req.body, "brand");
            v.technologyUsed = jsonGetString(req.body, "technologyUsed");
            v.vaccineTypeCode = jsonGetString(req.body, "vaccineTypeCode");

            if (v.code != codeUrl) return replyMessage(res, 400, "Vaccine code on body does not match URL");
            if (isBlank(v.code) || isBlank(v.commercialName) || isBlank(v.brand) || isBlank(v.technologyUsed) || isBlank(v.vaccineTypeCode))
                return replyMessage(res, 400, "code, commercialName, brand, technologyUsed and vaccineTypeCode are mandatory");

            if (!typeSvc.getByCode(v.vaccineTypeCode).has_value())
                return replyMessage(res, 400, "vaccineTypeCode does not exist");

            if (!vaccSvc.update(codeUrl, v)) return replyMessage(res, 404, "Vaccine not found");

            replyJson(res, 200, vaccineToJson(v));
        } catch (const std::exception &e) {
            replyMessage(res, 400, e.what());
        }
    });

    svr.Delete(patternByCode, [&](const httplib::Request &req, httplib::Response &res) {
        if (!hasAuth(req)) return replyMessage(res, 401, "Not authenticated");

        const std::string code = req.matches[1];
        if (!vaccSvc.remove(code)) return replyMessage(res, 404, "Vaccine not found");
        replyJson(res, 204, "{}");
    });
}

