#include "ui/VaccineTypeUI.h"

#include <iostream>
#include <limits>

#include "../../RestAPI/headers/Vaccine.h" // traz VaccineTypeDto + vaccineTypeToJson()

static void clearLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

static void printHttp(const HttpResult &r) {
    if (!r.ok) {
        std::cout << "HTTP ERROR: " << r.error << "\n";
        return;
    }
    std::cout << "Status: " << r.status << "\n";
    if (!r.body.empty()) std::cout << r.body << "\n";
}

VaccineTypeUI::VaccineTypeUI(RestClient &client) : client(client) {}

void VaccineTypeUI::list() {
    auto r = client.get("/vaccine-types");
    printHttp(r);
}

void VaccineTypeUI::view() {
    std::string code;
    std::cout << "Vaccine type code: ";
    std::cin >> code;

    auto r = client.get("/vaccine-types/" + code);
    printHttp(r);
}

void VaccineTypeUI::create() {
    VaccineTypeDto vt;

    std::cout << "Code: ";
    std::cin >> vt.code;

    clearLine();
    std::cout << "Disease: ";
    std::getline(std::cin, vt.disease);

    std::cout << "Short description: ";
    std::getline(std::cin, vt.shortDescription);

    auto body = vaccineTypeToJson(vt);
    auto r = client.post("/vaccine-types", body);
    printHttp(r);
}

void VaccineTypeUI::update() {
    VaccineTypeDto vt;

    std::cout << "Code to update (URL): ";
    std::cin >> vt.code; // tem de bater com URL

    clearLine();
    std::cout << "Disease: ";
    std::getline(std::cin, vt.disease);

    std::cout << "Short description: ";
    std::getline(std::cin, vt.shortDescription);

    auto body = vaccineTypeToJson(vt);
    auto r = client.put("/vaccine-types/" + vt.code, body);
    printHttp(r);
}

void VaccineTypeUI::remove() {
    std::string code;
    std::cout << "Code to delete: ";
    std::cin >> code;

    auto r = client.del("/vaccine-types/" + code);
    printHttp(r);
}
