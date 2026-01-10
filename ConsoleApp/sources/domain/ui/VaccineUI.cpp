#include "/domain/ui/VaccineUI.h"
#include <iostream>
#include <limits>

static void clearLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

VaccineUI::VaccineUI(VaccineService &vaccSvc, VaccineTypeService &typeSvc)
        : vaccSvc(vaccSvc), typeSvc(typeSvc) {}

void VaccineUI::list() {
    auto list = vaccSvc.getAll();
    if (list.empty()) {
        std::cout << "No vaccines found.\n";
        return;
    }

    for (const auto &v : list) {
        std::cout << v.code << " | "
                  << v.commercialName << " | "
                  << v.brand << " | "
                  << v.technologyUsed << " | "
                  << v.vaccineTypeCode << "\n";
    }
}

void VaccineUI::view() {
    std::string code;
    std::cout << "Vaccine code: ";
    std::cin >> code;

    auto v = vaccSvc.getByCode(code);
    if (!v.has_value()) {
        std::cout << "Vaccine not found.\n";
        return;
    }

    std::cout << "Code: " << v->code << "\n"
              << "Commercial name: " << v->commercialName << "\n"
              << "Brand: " << v->brand << "\n"
              << "Technology used: " << v->technologyUsed << "\n"
              << "Vaccine type code: " << v->vaccineTypeCode << "\n";
}

void VaccineUI::create() {
    VaccineDto v;

    std::cout << "Code: ";
    std::cin >> v.code;

    clearLine();
    std::cout << "Commercial name: ";
    std::getline(std::cin, v.commercialName);

    std::cout << "Brand: ";
    std::getline(std::cin, v.brand);

    std::cout << "Technology used: ";
    std::getline(std::cin, v.technologyUsed);

    std::cout << "Vaccine type code: ";
    std::cin >> v.vaccineTypeCode;

    // valida se o tipo existe (igual ao que a REST faz)
    if (!typeSvc.getByCode(v.vaccineTypeCode).has_value()) {
        std::cout << "Invalid vaccine type code (does not exist).\n";
        return;
    }

    if (!vaccSvc.create(v)) {
        std::cout << "Vaccine already exists (duplicate code).\n";
        return;
    }

    std::cout << "Vaccine created successfully.\n";
}

void VaccineUI::update() {
    VaccineDto v;

    std::cout << "Code to update: ";
    std::cin >> v.code;

    if (!vaccSvc.getByCode(v.code).has_value()) {
        std::cout << "Vaccine not found.\n";
        return;
    }

    clearLine();
    std::cout << "Commercial name: ";
    std::getline(std::cin, v.commercialName);

    std::cout << "Brand: ";
    std::getline(std::cin, v.brand);

    std::cout << "Technology used: ";
    std::getline(std::cin, v.technologyUsed);

    std::cout << "Vaccine type code: ";
    std::cin >> v.vaccineTypeCode;

    if (!typeSvc.getByCode(v.vaccineTypeCode).has_value()) {
        std::cout << "Invalid vaccine type code (does not exist).\n";
        return;
    }

    // update deve devolver bool no teu service; se não devolver, mantém como void e assume sucesso.
    if (!vaccSvc.update(v.code, v)) {
        std::cout << "Update failed.\n";
        return;
    }

    std::cout << "Vaccine updated successfully.\n";
}

void VaccineUI::remove() {
    std::string code;
    std::cout << "Code to delete: ";
    std::cin >> code;

    if (!vaccSvc.remove(code)) {
        std::cout << "Vaccine not found.\n";
        return;
    }

    std::cout << "Vaccine deleted successfully.\n";
}
