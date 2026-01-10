#include "../headers/VaccineTypeRouter.h"

#include "../headers/HttpHelpers.h"
#include "../headers/JsonUtils.h"
#include "../headers/Vaccine.h"

#include <algorithm>

static bool isBlank(const std::string &s) {
    return s.empty() || std::all_of(s.begin(), s.end(), [](unsigned char c) { return std::isspace(c) != 0; });
}

void configureVaccineTypeRoutes(httplib::Server &svr, VaccineTypeService &typeSvc, VaccineService &vaccSvc) {
    const std::string base = "/vaccine-types";
    const std::string patternBase = base + "(\\/?)";
    const std::string patternByCode = base + "/(\\w+)";

    svr.Get(patternBase, [&](const httplib::Request &req, httplib::Response &res) {
        if (!hasAuth(req)) return replyMessage(res, 401, "Not authenticated");

        std::string body = "[";
        bool first = true;
        for (const auto &vt : typeSvc.getAll()) {
            if (!first) body += ",";
            first = false;
            body += vaccineTypeToJson(vt);
        }
        body += "]";
        replyJson(res, 200, body);
    });

    svr.Get(patternByCode, [&](const httplib::Request &req, httplib::Response &res) {
        if (!hasAuth(req)) return replyMessage(res, 401, "Not authenticated");

        const std::string code = req.matches[1];
        auto vt = typeSvc.getByCode(code);
        if (!vt.has_value()) return replyMessage(res, 404, "Vaccine type not found");
        replyJson(res, 200, vaccineTypeToJson(*vt));
    });

    svr.Post(patternBase, [&](const httplib::Request &req, httplib::Response &res) {
        if (!hasAuth(req)) return replyMessage(res, 401, "Not authenticated");

        try {
            VaccineTypeDto vt;
            vt.code = jsonGetString(req.body, "code");
            vt.disease = jsonGetString(req.body, "disease");
            vt.shortDescription = jsonGetString(req.body, "shortDescription");

            if (isBlank(vt.code) || isBlank(vt.disease) || isBlank(vt.shortDescription))
                return replyMessage(res, 400, "code, disease and shortDescription are mandatory");

            if (!typeSvc.create(vt)) return replyMessage(res, 409, "Vaccine type code already exists");

            replyJson(res, 201, vaccineTypeToJson(vt));
        } catch (const std::exception &e) {
            replyMessage(res, 400, e.what());
        }
    });

    svr.Put(patternByCode, [&](const httplib::Request &req, httplib::Response &res) {
        if (!hasAuth(req)) return replyMessage(res, 401, "Not authenticated");

        const std::string codeUrl = req.matches[1];
        try {
            VaccineTypeDto vt;
            vt.code = jsonGetString(req.body, "code");
            vt.disease = jsonGetString(req.body, "disease");
            vt.shortDescription = jsonGetString(req.body, "shortDescription");

            if (vt.code != codeUrl) return replyMessage(res, 400, "Vaccine type code on body does not match URL");
            if (isBlank(vt.code) || isBlank(vt.disease) || isBlank(vt.shortDescription))
                return replyMessage(res, 400, "code, disease and shortDescription are mandatory");

            if (!typeSvc.update(codeUrl, vt)) return replyMessage(res, 404, "Vaccine type not found");

            replyJson(res, 200, vaccineTypeToJson(vt));
        } catch (const std::exception &e) {
            replyMessage(res, 400, e.what());
        }
    });

    svr.Delete(patternByCode, [&](const httplib::Request &req, httplib::Response &res) {
        if (!hasAuth(req)) return replyMessage(res, 401, "Not authenticated");

        const std::string code = req.matches[1];
        if (vaccSvc.anyVaccineWithTypeCode(code)) return replyMessage(res, 409, "Cannot delete vaccine type: vaccines reference it");
        if (!typeSvc.remove(code)) return replyMessage(res, 404, "Vaccine type not found");
        replyJson(res, 204, "{}");
    });
}

