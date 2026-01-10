#pragma once

namespace Core::Domain::Model {

    enum class AppointmentStatus {
        Scheduled,
        Arrived,
        Ready,
        InProgress,
        Vaccinated,
        Cancelled,
        NoShow
    };

}

