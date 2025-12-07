#pragma once

#include <string>

namespace Core::Domain::Model {

    class VaccineType;

    class Vaccine {
    public:
        Vaccine(VaccineType *type, const std::string &commercialName, const std::string &brand,
                const std::string &technologyUsed);

        VaccineType *getType() const;
        const std::string &getCommercialName() const;
        const std::string &getBrand() const;
        const std::string &getTechnologyUsed() const;

    private:
        VaccineType *m_type;
        std::string m_commercialName;
        std::string m_brand;
        std::string m_technologyUsed;
    };

}

