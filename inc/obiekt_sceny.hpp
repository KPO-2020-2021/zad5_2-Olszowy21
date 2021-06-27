#pragma once

/*!
* \file
* \brief Definicja klasy objects_scene
*
* 
*/

#include "cuboid.hpp"
#include "plaskowyz.hpp"
#include "gora_z_grania.hpp"
#include "gora_ze_szczytem.hpp"


class objects_scene: public Block {

  public:

    virtual void Inicjuj_obiekt(Vector3D &tmp) override;

  
};