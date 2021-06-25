#pragma once


#include "matrix3d.hpp"

/*!
 * \file  block.hpp
 *  
 *  Plik zawiera klasę bryla oraz
 *  jest ojcem dla wszystkich bibliotek wbudowanych.
 *  
 */

class Block{
protected:

    std::string Plik_BrylaAnimowana;

    Vector3D skala;

    Vector3D Polozenie;

    Matrix3D Macierz;

    double kat_do_globalnego;


public:

    Vector3D Skrobanie_do_rodzica(const Vector3D & top) const;

    void set_skala(Vector3D &tmp) { skala = tmp; };

    Vector3D skaluj(const Vector3D &top ) const {return skala * top;};

    void set_pozycje( Vector3D &Pozycja) { Polozenie = Pozycja;};

    void set_filename_anime(std::string Filename_anime) { Plik_BrylaAnimowana = Filename_anime;};

    const std::string get_filename_anime() const {return Plik_BrylaAnimowana ;};
    
    bool Otworz_Plik_animowany(std::ofstream &out) const;

    void Zamknij_Plik_animowany(std::ofstream &out) const;

    void set_kat(double kat) { kat_do_globalnego = kat;};

};