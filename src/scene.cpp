
#include "../inc/scene.hpp"
#include "../inc/plaskowyz.hpp"
#include "../inc/gora_ze_szczytem.hpp"
#include "../inc/gora_z_grania.hpp"

class objects_scene;


Scene::Scene(){

  Numer_aktywnego_drona = 0;
    
}

Scene::~Scene(){

  for(std::list<std::shared_ptr<objects_scene>>::iterator iter = Pudlo_z_obstrukcjami.begin(); iter != Pudlo_z_obstrukcjami.end(); ++iter){
    if(iter->get()->zwroc_typ_obiektu() != "cuś"){
      remove(iter->get()->get_filename_anime().c_str());
    }
  }
    
}



void Scene::Dodaj_drona(Drone droniszcze){

  Pudlo_z_dronami.push_back(droniszcze);
  Pudlo_z_obstrukcjami.push_back(std::shared_ptr<Drone>(&droniszcze));

}

void Scene::Dodaj_obstrukcje(std::string *File_oryginal, Vector3D &skala, Vector3D &polozenie, int index, PzG::LaczeDoGNUPlota &Lacze){
    
  std::string file_name_anime = "../datasets/obiekt" + std::to_string(Pudlo_z_obstrukcjami.size() - Pudlo_z_dronami.size()) + ".dat";
  std::cout << file_name_anime << std::endl;

  std::shared_ptr<objects_scene> obstrukt;
  
  switch(index){

  case 1:{
    obstrukt = std::make_shared<Mount1>(Mount1(File_oryginal[0], file_name_anime, skala, polozenie));
    Pudlo_z_obstrukcjami.push_back(obstrukt);
    Lacze.DodajNazwePliku(file_name_anime.c_str());
    Lacze.Rysuj();
  }
    break;

  case 2:{
    obstrukt = std::make_shared<Mount2>(Mount2(File_oryginal[1], file_name_anime, skala , polozenie));
    Pudlo_z_obstrukcjami.push_back(obstrukt);
    Lacze.DodajNazwePliku(file_name_anime.c_str());
    Lacze.Rysuj();
    }
    break;

  case 3:{
    obstrukt = std::make_shared<Mount3>(Mount3(File_oryginal[2], file_name_anime, skala , polozenie));
    Pudlo_z_obstrukcjami.push_back(obstrukt);
    Lacze.DodajNazwePliku(file_name_anime.c_str());
    Lacze.Rysuj();
  }
    break;

  default:
    break;
  }

}

bool Scene::Usun_obstrukt(PzG::LaczeDoGNUPlota &Lacze){
  int index = 1;
  std::ofstream FILE;

  std::cout << "\nWybierz element powierzchni do usuniecia: " << std::endl;

  std::list<std::shared_ptr<objects_scene>>::iterator iter1;

  for(iter1 = Pudlo_z_obstrukcjami.begin(); iter1 != Pudlo_z_obstrukcjami.end(); ++iter1){
    if(iter1->get()->zwroc_typ_obiektu() != "cuś"){
      std::cout << index << " - Polozenie: " << iter1->get()->get_pozycje_x() << " " << iter1->get()->get_pozycje_x() << "\t Typ: " << iter1->get()->zwroc_typ_obiektu() << std::endl;
      ++index;
    }
  }

  std::cout << "\nPodaj numer elementu> " << std::endl;
  
  std::cin >> index;

  std::list<std::shared_ptr<objects_scene>>::iterator iter2 = Pudlo_z_obstrukcjami.begin();
  std::advance(iter2, index + 1);          // zakładam posiadanie tylko 2 dronów.
  
  std::string anime = iter2->get()->get_filename_anime();
  FILE.open(anime , std::ios::trunc );
  if(FILE.is_open()){

    FILE.close();
    Pudlo_z_obstrukcjami.erase(iter2);
    Lacze.Rysuj();

    FILE.close();
    return true;
  }
  else return false;

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
