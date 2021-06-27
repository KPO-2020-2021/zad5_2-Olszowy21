
#include "../inc/scene.hpp"
#include "../inc/plaskowyz.hpp"
#include "../inc/gora_ze_szczytem.hpp"
#include "../inc/gora_z_grania.hpp"


Scene::Scene(){

  Numer_aktywnego_drona = 0;
    
}

Scene::~Scene(){

  for(std::list<objects_scene>::iterator iter = get_liste().begin(); iter != get_liste().end(); ++iter){
    if(iter->zwroc_typ_obiektu() != "Dron"){
      remove(iter->get_filename_anime().c_str());
    }
  }
    
}



void Scene::Dodaj_drona(Drone droniszcze){

  Pudlo_z_dronami.push_back(droniszcze);
  Pudlo_z_obstrukcjami.push_back(droniszcze);

}

void Scene::Dodaj_obstrukcje(std::string *File_oryginal, Vector3D &skala, Vector3D &polozenie, int index, PzG::LaczeDoGNUPlota &Lacze){
    
  std::string file_name_anime = "../datasets/obiekt" + std::to_string(Pudlo_z_obstrukcjami.size() - Pudlo_z_dronami.size()) + ".dat";
  std::cout << file_name_anime << std::endl;

  objects_scene obstrukt;
  
  switch(index){

  case 1:
    obstrukt = Mount1(File_oryginal[0], file_name_anime, skala, polozenie);
    Pudlo_z_obstrukcjami.push_back(obstrukt);
    Lacze.DodajNazwePliku(file_name_anime.c_str());
    Lacze.Rysuj();
    break;

  case 2:
    obstrukt = Mount2(File_oryginal[1], file_name_anime, skala , polozenie);
    Pudlo_z_obstrukcjami.push_back(obstrukt);
    Lacze.DodajNazwePliku(file_name_anime.c_str());
    Lacze.Rysuj();
    break;

  case 3:
    obstrukt = Mount3(File_oryginal[2], file_name_anime, skala , polozenie);
    Pudlo_z_obstrukcjami.push_back(obstrukt);
    Lacze.DodajNazwePliku(file_name_anime.c_str());
    Lacze.Rysuj();
  
    break;

  default:
    break;
  }

}

void Scene::Usun_obstrukt(int index, PzG::LaczeDoGNUPlota &Lacze){
  std::ofstream FILE;
  
  std::list<objects_scene>::iterator it = Pudlo_z_obstrukcjami.begin();
  std::advance(it, index + Pudlo_z_dronami.size() - 1);

  std::string file_name = it->get_filename_anime();
  FILE.open(file_name.c_str() , std::ios::trunc );
  FILE.close();

  Pudlo_z_obstrukcjami.erase(it);
  Lacze.Rysuj();

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
