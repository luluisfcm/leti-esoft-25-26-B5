#pragma once

#include <string>

namespace Core::Domain::Model {

    class VaccinationCenter {
    public:
        VaccinationCenter(const std::string &name,
                          const std::string &postalAddress,
                          const std::string &phone,
                          const std::string &email,
                          const std::string &website,
                          int maxVaccinesPerHour,
                          const std::string &openingHours,
                          const std::string &closingHours);
        virtual ~VaccinationCenter() = default;

        const std::string &getName() const;
        const std::string &getPostalAddress() const;
        const std::string &getPhone() const;
        const std::string &getEmail() const;
        const std::string &getWebsite() const;
        int getMaxVaccinesPerHour() const;
        const std::string &getOpeningHours() const;
        const std::string &getClosingHours() const;

    protected:
        std::string m_name;
        std::string m_postalAddress;
        std::string m_phone;
        std::string m_email;
        std::string m_website;
        int m_maxVaccinesPerHour;
        std::string m_openingHours;
        std::string m_closingHours;
    };

}

