#pragma once

#include "../thirdparty/httplib.h"
#include "VaccineService.h"

// Binds /vaccine-types endpoints to the server.
void configureVaccineTypeRoutes(httplib::Server &svr, VaccineTypeService &typeSvc, VaccineService &vaccSvc);
