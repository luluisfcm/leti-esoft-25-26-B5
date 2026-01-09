#pragma once

#include <string>

namespace Core::Domain::Model {

class VaccineType {
public:
    VaccineType(const std::string &disease, const std::string &shortDescription);

    const std::string &getDisease() const;
    const std::string &getShortDescription() const;

private:
    std::string m_disease;
    std::string m_shortDescription;
};

}
