//
// Created by luis on 09/01/2026.
//

#ifndef LETI_ESOFT_25_26_B5_VACCINE_H
#define LETI_ESOFT_25_26_B5_VACCINE_H

#include <string>
#include <sstream>

#include "JsonUtils.h"

// REST-layer DTOs (independent from Core domain pointers)
struct VaccineTypeDto {
    std::string code;
    std::string disease;
    std::string shortDescription;
};

struct VaccineDto {
    std::string code;
    std::string commercialName;
    std::string brand;
    std::string technologyUsed;
    std::string vaccineTypeCode;
};

inline std::string vaccineTypeToJson(const VaccineTypeDto &vt) {
    std::ostringstream os;
    os << "{";
    os << "\"code\":\"" << jsonEscape(vt.code) << "\",";
    os << "\"disease\":\"" << jsonEscape(vt.disease) << "\",";
    os << "\"shortDescription\":\"" << jsonEscape(vt.shortDescription) << "\"";
    os << "}";
    return os.str();
}

inline std::string vaccineToJson(const VaccineDto &v) {
    std::ostringstream os;
    os << "{";
    os << "\"code\":\"" << jsonEscape(v.code) << "\",";
    os << "\"commercialName\":\"" << jsonEscape(v.commercialName) << "\",";
    os << "\"brand\":\"" << jsonEscape(v.brand) << "\",";
    os << "\"technologyUsed\":\"" << jsonEscape(v.technologyUsed) << "\",";
    os << "\"vaccineTypeCode\":\"" << jsonEscape(v.vaccineTypeCode) << "\"";
    os << "}";
    return os.str();
}

#endif //LETI_ESOFT_25_26_B5_VACCINE_H