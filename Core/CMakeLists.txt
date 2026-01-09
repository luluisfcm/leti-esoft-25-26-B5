cmake_minimum_required(VERSION 3.30)
project(Core LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Core
        # shared (from ConsoleApp)
        ../ConsoleApp/domain/shared/Result.h
        ../ConsoleApp/domain/shared/StringUtils.h
        ../ConsoleApp/sources/domain/shared/Result.cpp
        ../ConsoleApp/sources/domain/shared/StringUtils.cpp

        # domain model
        headers/domain/model/VaccineType.h
        sources/domain/model/VaccineType.cpp
        headers/domain/model/Vaccine.h
        sources/domain/model/Vaccine.cpp
        headers/domain/model/SNSUser.h
        sources/domain/model/SNSUser.cpp
        headers/domain/model/StaffMember.h
        sources/domain/model/StaffMember.cpp
        headers/domain/model/Receptionist.h
        headers/domain/model/Nurse.h
        headers/domain/model/DGSAdministrator.h
        headers/domain/model/VaccinationCenter.h
        sources/domain/model/VaccinationCenter.cpp
        headers/domain/model/HealthcareCenter.h
        headers/domain/model/CommunityMassVaccinationCenter.h
        headers/domain/model/AppointmentStatus.h
        headers/domain/model/Appointment.h
        sources/domain/model/Appointment.cpp
        headers/domain/model/VaccinationEvent.h
        sources/domain/model/VaccinationEvent.cpp
        headers/domain/model/AdverseReaction.h
        sources/domain/model/AdverseReaction.cpp
        headers/domain/model/VaccinationCertificate.h
        sources/domain/model/VaccinationCertificate.cpp
        headers/domain/model/Outbreak.h
        sources/domain/model/Outbreak.cpp
)

# Expose headers/ for includes like "headers/domain/model/..." from within Core sources
# Expose repo-root so includes like <headers/...> work in other modules.
target_include_directories(Core
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/headers
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/ConsoleApp
)
