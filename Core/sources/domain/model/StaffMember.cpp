#include "../../../headers/domain/model/StaffMember.h"

namespace Core::Domain::Model {

    StaffMember::StaffMember(const std::string &name,
                             const std::string &postalAddress,
                             const std::string &phone,
                             const std::string &email)
            : m_name(name), m_postalAddress(postalAddress), m_phone(phone), m_email(email) {}

    const std::string &StaffMember::getName() const { return m_name; }
    const std::string &StaffMember::getPostalAddress() const { return m_postalAddress; }
    const std::string &StaffMember::getPhone() const { return m_phone; }
    const std::string &StaffMember::getEmail() const { return m_email; }

}

