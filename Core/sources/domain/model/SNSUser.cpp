#include "../../../headers/domain/model/SNSUser.h"

namespace Core::Domain::Model {

    SNSUser::SNSUser(const std::string &name,
                     const std::string &dateOfBirth,
                     const std::string &sex,
                     const std::string &postalAddress,
                     const std::string &phone,
                     const std::string &email,
                     const std::string &citizenCardNumber)
            : m_name(name), m_dateOfBirth(dateOfBirth), m_sex(sex), m_postalAddress(postalAddress),
              m_phone(phone), m_email(email), m_citizenCardNumber(citizenCardNumber) {}

    const std::string &SNSUser::getName() const { return m_name; }
    const std::string &SNSUser::getDateOfBirth() const { return m_dateOfBirth; }
    const std::string &SNSUser::getSex() const { return m_sex; }
    const std::string &SNSUser::getPostalAddress() const { return m_postalAddress; }
    const std::string &SNSUser::getPhone() const { return m_phone; }
    const std::string &SNSUser::getEmail() const { return m_email; }
    const std::string &SNSUser::getCitizenCardNumber() const { return m_citizenCardNumber; }

}

