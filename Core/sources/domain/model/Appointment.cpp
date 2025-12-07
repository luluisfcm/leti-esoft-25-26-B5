#include "../../../headers/domain/model/Appointment.h"

namespace Core::Domain::Model {

    Appointment::Appointment(const std::string &date,
                             const std::string &time,
                             AppointmentStatus status,
                             const std::string &arrivalDateTime)
            : m_date(date), m_time(time), m_status(status), m_arrivalDateTime(arrivalDateTime) {}

    const std::string &Appointment::getDate() const { return m_date; }
    const std::string &Appointment::getTime() const { return m_time; }
    AppointmentStatus Appointment::getStatus() const { return m_status; }
    const std::string &Appointment::getArrivalDateTime() const { return m_arrivalDateTime; }

}

