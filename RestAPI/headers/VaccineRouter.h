#pragma once

#include "../thirdparty/httplib.h"
#include "VaccineService.h"

// Binds /vaccines endpoints to the server.
void configureVaccineRoutes(httplib::Server &svr, VaccineTypeService &typeSvc, VaccineService &vaccSvc);
