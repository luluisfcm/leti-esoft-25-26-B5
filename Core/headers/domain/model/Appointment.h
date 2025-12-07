#pragma once

#include <string>
#include "AppointmentStatus.h"

namespace Core::Domain::Model {

    class SNSUser;
    class VaccinationCenter;
    class VaccineType;
    class VaccinationEvent;

    class Appointment {
    public:
        Appointment(const std::string &date,
                    const std::string &time,
                    AppointmentStatus status,
                    const std::string &arrivalDateTime = "");

        const std::string &getDate() const;
        const std::string &getTime() const;
        AppointmentStatus getStatus() const;
        const std::string &getArrivalDateTime() const;

    private:
        std::string m_date;
        std::string m_time;
        AppointmentStatus m_status;
        std::string m_arrivalDateTime;
    };

}

