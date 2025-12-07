#pragma once

#include "VaccinationCenter.h"

namespace Core::Domain::Model {

    class CommunityMassVaccinationCenter : public VaccinationCenter {
    public:
        using VaccinationCenter::VaccinationCenter;
    };

}

