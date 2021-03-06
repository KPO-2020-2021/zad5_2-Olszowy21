#pragma once

#include "drone.hpp"
#include <list>
#include <memory>

class Scene{
protected:

    std::vector<Drone> Pudlo_z_dronami; 

    std::list<std::shared_ptr<objects_scene>> Pudlo_z_obstrukcjami;

    PzG::LaczeDoGNUPlota Lacze;

    unsigned int Numer_aktywnego_drona;

public:

    Scene();

    ~Scene();

    void Dodaj_drona(Drone droniszcze);

    void Dodaj_obstrukcje(std::string *File_oryginal, Vector3D &skala, Vector3D &polozenie, int index, PzG::LaczeDoGNUPlota &Lacze);

    bool Usun_obstrukt(PzG::LaczeDoGNUPlota &Lacze);

    void avtive_drone(int index);

    Drone *use_avtive_drone();

    int index_aktywnego_drona();


};