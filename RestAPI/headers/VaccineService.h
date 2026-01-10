//
// Created by luis on 09/01/2026.
//

#ifndef LETI_ESOFT_25_26_B5_VACCINESERVICE_H
#define LETI_ESOFT_25_26_B5_VACCINESERVICE_H

#include <mutex>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

#include "Vaccine.h"

class VaccineTypeService {
private:
    std::unordered_map<std::string, VaccineTypeDto> store;
    mutable std::mutex mtx;

public:
    std::vector<VaccineTypeDto> getAll() const;
    std::optional<VaccineTypeDto> getByCode(const std::string &code) const;

    // returns false on duplicate
    bool create(const VaccineTypeDto &vt);

    // returns false if missing
    bool update(const std::string &code, const VaccineTypeDto &vt);

    // returns false if missing
    bool remove(const std::string &code);
};

class VaccineService {
private:
    std::unordered_map<std::string, VaccineDto> store;
    mutable std::mutex mtx;

public:
    std::vector<VaccineDto> getAll() const;
    std::optional<VaccineDto> getByCode(const std::string &code) const;

    // returns false on duplicate
    bool create(const VaccineDto &v);

    // returns false if missing
    bool update(const std::string &code, const VaccineDto &v);

    // returns false if missing
    bool remove(const std::string &code);

    bool anyVaccineWithTypeCode(const std::string &vaccineTypeCode) const;

    // US12 ordering helper: grouped by typeCode, and within each group by brand (A-Z)
    // Returning a JSON string keeps the REST response straightforward.
    std::string getAllGroupedByTypeSortedByBrand(const VaccineTypeService &typeSvc) const;
};

#endif //LETI_ESOFT_25_26_B5_VACCINESERVICE_H