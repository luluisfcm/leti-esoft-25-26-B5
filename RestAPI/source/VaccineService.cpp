#include "../headers/VaccineService.h"

#include <algorithm>
#include <sstream>
#include <cctype>

std::vector<VaccineTypeDto> VaccineTypeService::getAll() const {
    std::lock_guard<std::mutex> lock(mtx);
    std::vector<VaccineTypeDto> out;
    out.reserve(store.size());
    for (const auto &kv : store) out.push_back(kv.second);
    std::sort(out.begin(), out.end(), [](const auto &a, const auto &b) { return a.code < b.code; });
    return out;
}

std::optional<VaccineTypeDto> VaccineTypeService::getByCode(const std::string &code) const {
    std::lock_guard<std::mutex> lock(mtx);
    auto it = store.find(code);
    if (it == store.end()) return std::nullopt;
    return it->second;
}

bool VaccineTypeService::create(const VaccineTypeDto &vt) {
    std::lock_guard<std::mutex> lock(mtx);
    if (store.find(vt.code) != store.end()) return false;
    store.emplace(vt.code, vt);
    return true;
}

bool VaccineTypeService::update(const std::string &code, const VaccineTypeDto &vt) {
    std::lock_guard<std::mutex> lock(mtx);
    auto it = store.find(code);
    if (it == store.end()) return false;
    it->second = vt;
    return true;
}

bool VaccineTypeService::remove(const std::string &code) {
    std::lock_guard<std::mutex> lock(mtx);
    return store.erase(code) > 0;
}

std::vector<VaccineDto> VaccineService::getAll() const {
    std::lock_guard<std::mutex> lock(mtx);
    std::vector<VaccineDto> out;
    out.reserve(store.size());
    for (const auto &kv : store) out.push_back(kv.second);
    std::sort(out.begin(), out.end(), [](const auto &a, const auto &b) { return a.code < b.code; });
    return out;
}

std::optional<VaccineDto> VaccineService::getByCode(const std::string &code) const {
    std::lock_guard<std::mutex> lock(mtx);
    auto it = store.find(code);
    if (it == store.end()) return std::nullopt;
    return it->second;
}

bool VaccineService::create(const VaccineDto &v) {
    std::lock_guard<std::mutex> lock(mtx);
    if (store.find(v.code) != store.end()) return false;
    store.emplace(v.code, v);
    return true;
}

bool VaccineService::update(const std::string &code, const VaccineDto &v) {
    std::lock_guard<std::mutex> lock(mtx);
    auto it = store.find(code);
    if (it == store.end()) return false;
    it->second = v;
    return true;
}

bool VaccineService::remove(const std::string &code) {
    std::lock_guard<std::mutex> lock(mtx);
    return store.erase(code) > 0;
}

bool VaccineService::anyVaccineWithTypeCode(const std::string &vaccineTypeCode) const {
    std::lock_guard<std::mutex> lock(mtx);
    for (const auto &kv : store) {
        if (kv.second.vaccineTypeCode == vaccineTypeCode) return true;
    }
    return false;
}

std::string VaccineService::getAllGroupedByTypeSortedByBrand(const VaccineTypeService &typeSvc) const {
    std::vector<VaccineDto> vaccines = getAll();

    std::unordered_map<std::string, std::vector<VaccineDto>> groups;
    for (const auto &v : vaccines) {
        groups[v.vaccineTypeCode].push_back(v);
    }

    for (auto &kv : groups) {
        auto &vec = kv.second;
        std::sort(vec.begin(), vec.end(), [](const VaccineDto &a, const VaccineDto &b) {
            if (a.brand == b.brand) return a.commercialName < b.commercialName;
            return a.brand < b.brand;
        });
    }

    std::vector<std::string> typeCodes;
    typeCodes.reserve(groups.size());
    for (const auto &kv : groups) typeCodes.push_back(kv.first);
    std::sort(typeCodes.begin(), typeCodes.end());

    std::ostringstream os;
    os << "{\"groups\":[";

    bool firstGroup = true;
    for (const auto &code : typeCodes) {
        if (!firstGroup) os << ',';
        firstGroup = false;

        os << '{';

        auto vt = typeSvc.getByCode(code);
        if (vt.has_value()) {
            os << "\"vaccineType\":" << vaccineTypeToJson(*vt);
        } else {
            os << "\"vaccineType\":{\"code\":\"" << jsonEscape(code) << "\"}";
        }

        os << ",\"vaccines\":[";
        bool firstV = true;
        for (const auto &v : groups[code]) {
            if (!firstV) os << ',';
            firstV = false;
            os << vaccineToJson(v);
        }
        os << "]";

        os << '}';
    }

    os << "]}";
    return os.str();
}

