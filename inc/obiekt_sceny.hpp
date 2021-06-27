#pragma once

/*!
* \file
* \brief Definicja klasy objects_scene
*
* 
*/

#include "cuboid.hpp"


class objects_scene: public Cuboid {

  public:

  virtual std::string zwroc_typ_obiektu() {return "cuś";};

  void ze_wzora_do_animatora();

};