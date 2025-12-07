#pragma once

#include <string>

namespace Core::Domain::Model {

    class AdverseReaction {
    public:
        AdverseReaction(const std::string &description,
                        const std::string &severity,
                        const std::string &observedAt,
                        const std::string &notes);

        const std::string &getDescription() const;
        const std::string &getSeverity() const;
        const std::string &getObservedAt() const;
        const std::string &getNotes() const;

    private:
        std::string m_description;
        std::string m_severity;
        std::string m_observedAt;
        std::string m_notes;
    };

}

