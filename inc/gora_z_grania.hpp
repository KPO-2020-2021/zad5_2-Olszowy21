#pragma once

#include "obiekt_sceny.hpp"



class Mount2: public objects_scene{ // grora z grania
protected:

    // std::string Plik_BrylaAnimowana;

    // Vector3D skala;

    // Vector3D Polozenie;

    // Matrix3D Macierz;

    // kat_do_globalnego

    Vector3D top[10]; // wiechrzołki z lokalnymi wartościami. top[0] i top[9] reprezentują wiechrzołki koperty. ( Już przeskalowane )
    
    
public:

// Konstruktory 

    Mount2(std::string Filename_oryginal, Vector3D skala, Vector3D polozenie);
    
    
// Metody

    void inicjuj_Mount2(std::string Filename_oryginal, Vector3D &skala, Vector3D &Polozenie );

    const Vector<double, SIZE> &operator [] (unsigned int index) const;

    Vector<double, SIZE> &operator [] (unsigned int index);

// Metody dziedziczone

    // Vector3D Skrobanie_do_ojca(const Vector3D & top) const;

    // void set_skala(Vector3D &tmp) { skala = tmp; };
    // Vector3D skaluj( const Vector3D top);

    // std::string set_filename_anime(std::string Filename_anime) { Plik_BrylaAnimowana = Filename_anime;};

    // const std::string get_filename_anime() const {return Plik_BrylaAnimowana ;};
    
    // bool Otworz_Plik_animowany(std::ofstream &out, std::string File_name);

    // void Zamknij_Plik_animowany(std::ofstream &out);

    // void set_kat(double kat) { kat_do_globalnego = kat;};
};