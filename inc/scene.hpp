#pragma once

#include "drone.hpp"

class Scene{
protected:

    std::vector<Drone> Pudlo_z_dronami;

    PzG::LaczeDoGNUPlota Lacze;

    unsigned int Numer_aktywnego_drona;

public:

    Scene();

    void Dodaj_drona(Drone droniszcze);

    void avtive_drone(int index);

    Drone *use_avtive_drone();

    int index_aktywnego_drona();

};