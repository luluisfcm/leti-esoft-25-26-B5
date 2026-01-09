#include "../headers/RestApiServer.h"

#include "../headers/VaccineRouter.h"
#include "../headers/VaccineTypeRouter.h"
#include "../headers/HttpHelpers.h"

#include <iostream>

void RestApiServer::run(const std::string &host, int port) {
    httplib::Server svr;

    // In-memory services (process lifetime)
    static VaccineTypeService typeSvc;
    static VaccineService vaccSvc;

    // --- Bootstrap sample data ---
    {
        VaccineTypeDto mrna{"mrna", "covid", "mRNA"};
        VaccineTypeDto viral{"viral", "covid", "Viral vector"};
        typeSvc.create(mrna);
        typeSvc.create(viral);

        VaccineDto pf{"pf", "Comirnaty", "Pfizer", "mRNA", "mrna"};
        VaccineDto az{"az", "Vaxzevria", "AstraZeneca", "Viral vector", "viral"};
        vaccSvc.create(pf);
        vaccSvc.create(az);
    }

    // health endpoint
    svr.Get("/status(\\/?)", [&](const httplib::Request & /*req*/, httplib::Response &res) {
        replyJson(res, 200, "{\"status\":\"ok\"}");
    });

    configureVaccineTypeRoutes(svr, typeSvc, vaccSvc);
    configureVaccineRoutes(svr, typeSvc, vaccSvc);

    std::cout << "RestAPI listening on http://" << host << ":" << port << std::endl;
    svr.listen(host.c_str(), port);
}
