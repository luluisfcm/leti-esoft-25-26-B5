#pragma once

#include <string>

namespace Core::Domain::Model {

class SNSUser {
public:
    SNSUser(const std::string &name,
            const std::string &dateOfBirth,
            const std::string &sex,
            const std::string &postalAddress,
            const std::string &phone,
            const std::string &email,
            const std::string &citizenCardNumber);

    const std::string &getName() const;
    const std::string &getDateOfBirth() const;
    const std::string &getSex() const;
    const std::string &getPostalAddress() const;
    const std::string &getPhone() const;
    const std::string &getEmail() const;
    const std::string &getCitizenCardNumber() const;

private:
    std::string m_citizenCardNumber;
    std::string m_email;
    std::string m_phone;
    std::string m_postalAddress;
    std::string m_sex;
    std::string m_dateOfBirth;
    std::string m_name;
};

} // namespace Core::Domain::Model
