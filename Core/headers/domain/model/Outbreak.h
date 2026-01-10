#pragma once

#include <string>

namespace Core::Domain::Model {

    class Outbreak {
    public:
        Outbreak(const std::string &name,
                 const std::string &startDate,
                 bool current);

        const std::string &getName() const;
        const std::string &getStartDate() const;
        bool isCurrent() const;

    private:
        std::string m_name;
        std::string m_startDate;
        bool m_current;
    };

}

