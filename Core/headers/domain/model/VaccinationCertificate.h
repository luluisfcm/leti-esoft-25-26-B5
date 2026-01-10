#pragma once

#include <string>

namespace Core::Domain::Model {

    class VaccinationCertificate {
    public:
        explicit VaccinationCertificate(const std::string &issueDate);

        const std::string &getIssueDate() const;

    private:
        std::string m_issueDate;
    };

}

