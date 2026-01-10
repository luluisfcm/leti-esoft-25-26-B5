#include <iostream>

#include "http/RestClient.h"
#include "ui/VaccineTypeUI.h"
#include "ui/VaccineUI.h"

int main() {
    RestClient client("localhost", 8080, "test");

    VaccineTypeUI vaccineTypeUI(client);
    VaccineUI vaccineUI(client);

    int op = -1;
    while (op != 0) {
        std::cout << "\n== PVMS Console (REST client) ==\n";
        std::cout << "=== Vaccine Types ===\n";
        std::cout << "1  - List vaccine types\n";
        std::cout << "2  - View vaccine type\n";
        std::cout << "3  - Create vaccine type\n";
        std::cout << "4  - Update vaccine type\n";
        std::cout << "5  - Delete vaccine type\n";
        std::cout << "=== Vaccines ===\n";
        std::cout << "6  - List vaccines\n";
        std::cout << "7  - View vaccine\n";
        std::cout << "8  - Create vaccine\n";
        std::cout << "9  - Update vaccine\n";
        std::cout << "10 - Delete vaccine\n";
        std::cout << "0  - Exit\n";
        std::cout << "Option: ";

        std::cin >> op;

        switch (op) {
            case 1:  vaccineTypeUI.list();   break;
            case 2:  vaccineTypeUI.view();   break;
            case 3:  vaccineTypeUI.create(); break;
            case 4:  vaccineTypeUI.update(); break;
            case 5:  vaccineTypeUI.remove(); break;

            case 6:  vaccineUI.list();       break;
            case 7:  vaccineUI.view();       break;
            case 8:  vaccineUI.create();     break;
            case 9:  vaccineUI.update();     break;
            case 10: vaccineUI.remove();     break;

            case 0: break;
            default: std::cout << "Invalid option\n";
        }
    }

    return 0;
}
