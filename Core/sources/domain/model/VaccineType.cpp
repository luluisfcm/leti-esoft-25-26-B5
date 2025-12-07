#include "../../../headers/domain/model/VaccineType.h"

namespace Core::Domain::Model {

    VaccineType::VaccineType(const std::string &disease, const std::string &shortDescription)
            : m_disease(disease), m_shortDescription(shortDescription) {}

    const std::string &VaccineType::getDisease() const {
        return m_disease;
    }

    const std::string &VaccineType::getShortDescription() const {
        return m_shortDescription;
    }

}

