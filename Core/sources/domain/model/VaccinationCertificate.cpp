#include "../../../headers/domain/model/VaccinationCertificate.h"

namespace Core::Domain::Model {

    VaccinationCertificate::VaccinationCertificate(const std::string &issueDate)
            : m_issueDate(issueDate) {}

    const std::string &VaccinationCertificate::getIssueDate() const { return m_issueDate; }

}

