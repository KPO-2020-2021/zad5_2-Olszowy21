#include "scene.hpp"


Scene::Scene(){

  Numer_aktywnego_drona = 0;
    
}



void Scene::Dodaj_drona(Drone droniszcze){

  Pudlo_z_dronami.push_back(droniszcze);
  Pudlo_z_obstrukcjami.push_back(droniszcze);

}

void Scene::Dodaj_obstrukcje( Vector3D &skala, Vector3D &polozenie, int index, PzG::LaczeDoGNUPlota &Lacze){
    
  std::string file_name = "obiekt" + std::to_string(Pudlo_z_obstrukcjami.size() - Pudlo_z_dronami.size()) + ".dat";

  
  objects_scene obstrukt;
  
  switch(index){

  case 1:
    obstrukt = Mount1(file_name, skala, polozenie);

    break;

  case 2:
    obstrukt = Mount2(file_name, skala , polozenie);
  
    break;

  case 3:
    obstrukt = Mount3(file_name, skala , polozenie);
  
    break;

  default:
    break;
  }

  Pudlo_z_obstrukcjami.push_back(obstrukt);
    
}

void Scene::Usun_obstrukt(int index, PzG::LaczeDoGNUPlota &Lacze){
  std::ofstream FILE;
  
  std::list<objects_scene>::iterator it = Pudlo_z_obstrukcjami.begin();
  std::advance(it, index + Pudlo_z_dronami.size() - 1);

  std::string file_name = it->get_filename_anime();
  FILE.open(file_name.c_str() , std::ios::trunc );
  FILE.close();

  Pudlo_z_obstrukcjami.erase(it);

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
