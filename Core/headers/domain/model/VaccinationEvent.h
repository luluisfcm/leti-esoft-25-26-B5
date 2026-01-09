#pragma once

#include <string>

namespace Core::Domain::Model {

class Vaccine;
class AdverseReaction;

class VaccinationEvent {
public:
    VaccinationEvent(const std::string &lotNumber,
                     const std::string &administrationDateTime,
                     Vaccine *vaccine);

    const std::string &getLotNumber() const;
    const std::string &getAdministrationDateTime() const;
    Vaccine *getVaccine() const;

private:
    Vaccine *m_vaccine;
    std::string m_administrationDateTime;
    std::string m_lotNumber;
};

} // namespace Core::Domain::Model
