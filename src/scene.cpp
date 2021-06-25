#include "scene.hpp"

Scene::Scene(){

    Numer_aktywnego_drona = 0;
    
}

void Scene::Dodaj_drona(Drone droniszcze){

    Pudlo_z_dronami.push_back(droniszcze);

}

Drone *Scene::use_avtive_drone(){

    return &Pudlo_z_dronami[Numer_aktywnego_drona];

}

void Scene::avtive_drone(int index){

    Numer_aktywnego_drona = (index - 1);

}

int Scene::index_aktywnego_drona(){

    return Numer_aktywnego_drona;

}
