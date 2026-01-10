#include "../../../headers/domain/model/VaccinationEvent.h"

namespace Core::Domain::Model {

    VaccinationEvent::VaccinationEvent(const std::string &lotNumber,
                                       const std::string &administrationDateTime,
                                       Vaccine *vaccine)
            : m_lotNumber(lotNumber), m_administrationDateTime(administrationDateTime), m_vaccine(vaccine) {}

    const std::string &VaccinationEvent::getLotNumber() const { return m_lotNumber; }
    const std::string &VaccinationEvent::getAdministrationDateTime() const { return m_administrationDateTime; }
    Vaccine *VaccinationEvent::getVaccine() const { return m_vaccine; }

}

