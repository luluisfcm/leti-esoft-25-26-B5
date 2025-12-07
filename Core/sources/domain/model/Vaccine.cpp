#include "../../../headers/domain/model/Vaccine.h"
#include "../../../headers/domain/model/VaccineType.h"

namespace Core::Domain::Model {

    Vaccine::Vaccine(VaccineType *type, const std::string &commercialName, const std::string &brand,
                     const std::string &technologyUsed)
            : m_type(type), m_commercialName(commercialName), m_brand(brand), m_technologyUsed(technologyUsed) {}

    VaccineType *Vaccine::getType() const {
        return m_type;
    }

    const std::string &Vaccine::getCommercialName() const {
        return m_commercialName;
    }

    const std::string &Vaccine::getBrand() const {
        return m_brand;
    }

    const std::string &Vaccine::getTechnologyUsed() const {
        return m_technologyUsed;
    }

}

