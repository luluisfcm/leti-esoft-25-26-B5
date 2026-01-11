#pragma once
#include "http/RestClient.h"

class VaccineTypeUI {
    RestClient &client;

public:
    explicit VaccineTypeUI(RestClient &client);

    void list();     // GET /vaccine-types
    void view();     // GET /vaccine-types/{code}
    void create();   // POST /vaccine-types
    void update();   // PUT /vaccine-types/{code}
    void remove();   // DELETE /vaccine-types/{code}
};
