#include "ui/VaccineUI.h"

#include <iostream>
#include <limits>

#include "../../RestAPI/headers/Vaccine.h"   // VaccineDto + vaccineToJson

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

VaccineUI::VaccineUI(RestClient &client) : client(client) {}

void VaccineUI::list() {
    auto r = client.get("/vaccines");
    printHttp(r);
}

void VaccineUI::view() {
    std::string code;
    std::cout << "Vaccine code: ";
    std::cin >> code;

    auto r = client.get("/vaccines/" + code);
    printHttp(r);
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

    // cria JSON com o helper do RestAPI (evita erros de aspas/escape)
    auto body = vaccineToJson(v);

    auto r = client.post("/vaccines", body);
    printHttp(r);
}

void VaccineUI::update() {
    VaccineDto v;

    std::cout << "Code to update (URL): ";
    std::cin >> v.code; // vai no URL e no body

    clearLine();
    std::cout << "Commercial name: ";
    std::getline(std::cin, v.commercialName);

    std::cout << "Brand: ";
    std::getline(std::cin, v.brand);

    std::cout << "Technology used: ";
    std::getline(std::cin, v.technologyUsed);

    std::cout << "Vaccine type code: ";
    std::cin >> v.vaccineTypeCode;

    auto body = vaccineToJson(v);

    auto r = client.put("/vaccines/" + v.code, body);
    printHttp(r);
}

void VaccineUI::remove() {
    std::string code;
    std::cout << "Code to delete: ";
    std::cin >> code;

    auto r = client.del("/vaccines/" + code);
    printHttp(r);
}