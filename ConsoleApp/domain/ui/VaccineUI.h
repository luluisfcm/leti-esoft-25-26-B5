#pragma once
#include "http/RestClient.h"

class VaccineUI {
    RestClient &client;

public:
    explicit VaccineUI(RestClient &client);

    void list();
    void view();
    void create();
    void update();
    void remove();
};