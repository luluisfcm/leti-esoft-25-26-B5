#pragma once

#include "StaffMember.h"

namespace Core::Domain::Model {

    class DGSAdministrator : public StaffMember {
    public:
        using StaffMember::StaffMember;

        std::string getRole() const override { return "DGSAdministrator"; }
    };

}

