#pragma once

#include "cuboid.hpp"

class Drone{
protected:

    Vector3D Polozenie;

    Cuboid Korpus;

    Prism Rotor[4];

    Matrix3D Macierz;

    double kat_do_globalnego;
    
public:

    void inicjalizuj_drona(std::string anime_files[], std::string name_oryginal_cuboid, std::string name_oryginal_prism , Vector3D &polozenie, double kat, PzG::LaczeDoGNUPlota &Lacze);

    Cuboid get_cuboid() const {return *&Korpus;};
    
    Prism get_prism(unsigned int index) const {return Rotor[index];};

    double Get_polozeniex() { return Polozenie[0]; };

    double Get_polozeniey() { return Polozenie[1]; };

    void zmlucenie_drona_do_animacji();

    void ze_wzora_rotora_do_animatora( const Prism &rotorek );

    void ze_wzora_cuboida_do_animatora();

    Vector3D Skrobanie_do_rodzica(const Vector3D & top) const;

    Vector3D Trans_do_rodzica(const Vector3D & top) const;

    bool up_down(double wysokosc_lotu, PzG::LaczeDoGNUPlota &Lacze);

    void forward_backward(double kat_obrotu, double dlugosc_lotu, PzG::LaczeDoGNUPlota &Lacze);

    void Maluj_rozklad_lotu(Vector3D sciezka_lotu[], std::string nazwa_pliku[], double kat_obrotu, double dlugosc_lotu, PzG::LaczeDoGNUPlota &Lacze);

    
};
