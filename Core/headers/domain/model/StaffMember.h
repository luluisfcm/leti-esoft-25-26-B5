#pragma once

#include <string>

namespace Core::Domain::Model {

    class StaffMember {
    public:
        StaffMember(const std::string &name,
                    const std::string &postalAddress,
                    const std::string &phone,
                    const std::string &email);
        virtual ~StaffMember() = default;

        const std::string &getName() const;
        const std::string &getPostalAddress() const;
        const std::string &getPhone() const;
        const std::string &getEmail() const;

        virtual std::string getRole() const = 0;

    protected:
        std::string m_name;
        std::string m_postalAddress;
        std::string m_phone;
        std::string m_email;
    };

}

