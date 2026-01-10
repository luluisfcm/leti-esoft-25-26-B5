#pragma once

#include <string>
#include "VaccineService.h"
//#include "VaccineTypeService.h"

class VaccineUI {
    VaccineService &vaccSvc;
    VaccineTypeService &typeSvc;

public:
    VaccineUI(VaccineService &vaccSvc, VaccineTypeService &typeSvc);

    void list();     // GET all
    void view();     // GET by code
    void create();   // POST
    void update();   // PUT
    void remove();   // DELETE
};
