#include "../../../headers/domain/model/AdverseReaction.h"

namespace Core::Domain::Model {

    AdverseReaction::AdverseReaction(const std::string &description,
                                     const std::string &severity,
                                     const std::string &observedAt,
                                     const std::string &notes)
            : m_description(description), m_severity(severity), m_observedAt(observedAt), m_notes(notes) {}

    const std::string &AdverseReaction::getDescription() const { return m_description; }
    const std::string &AdverseReaction::getSeverity() const { return m_severity; }
    const std::string &AdverseReaction::getObservedAt() const { return m_observedAt; }
    const std::string &AdverseReaction::getNotes() const { return m_notes; }

}

