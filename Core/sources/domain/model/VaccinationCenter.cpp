#include "../../../headers/domain/model/VaccinationCenter.h"

namespace Core::Domain::Model {

    VaccinationCenter::VaccinationCenter(const std::string &name,
                                         const std::string &postalAddress,
                                         const std::string &phone,
                                         const std::string &email,
                                         const std::string &website,
                                         int maxVaccinesPerHour,
                                         const std::string &openingHours,
                                         const std::string &closingHours)
            : m_name(name), m_postalAddress(postalAddress), m_phone(phone), m_email(email),
              m_website(website), m_maxVaccinesPerHour(maxVaccinesPerHour),
              m_openingHours(openingHours), m_closingHours(closingHours) {}

    const std::string &VaccinationCenter::getName() const { return m_name; }
    const std::string &VaccinationCenter::getPostalAddress() const { return m_postalAddress; }
    const std::string &VaccinationCenter::getPhone() const { return m_phone; }
    const std::string &VaccinationCenter::getEmail() const { return m_email; }
    const std::string &VaccinationCenter::getWebsite() const { return m_website; }
    int VaccinationCenter::getMaxVaccinesPerHour() const { return m_maxVaccinesPerHour; }
    const std::string &VaccinationCenter::getOpeningHours() const { return m_openingHours; }
    const std::string &VaccinationCenter::getClosingHours() const { return m_closingHours; }

}

