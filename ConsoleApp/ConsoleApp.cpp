#include <iostream>
#include "domain/http/RestClient.h"
#include "domain/ui/VaccineUI.h"

int main() {
    RestClient client("localhost", 8080, "test");
    VaccineUI vaccineUI(client);

    int op = -1;
    while (op != 0) {
        std::cout << "\n== PVMS Console (REST client) ==\n";
        std::cout << "1 - List vaccines\n";
        std::cout << "2 - View vaccine\n";
        std::cout << "3 - Create vaccine\n";
        std::cout << "4 - Update vaccine\n";
        std::cout << "5 - Delete vaccine\n";
        std::cout << "0 - Exit\n";
        std::cout << "Option: ";
        std::cin >> op;

        switch (op) {
            case 1: vaccineUI.list(); break;
            case 2: vaccineUI.view(); break;
            case 3: vaccineUI.create(); break;
            case 4: vaccineUI.update(); break;
            case 5: vaccineUI.remove(); break;
            case 0: break;
            default: std::cout << "Invalid option\n";
        }
    }
    return 0;
}