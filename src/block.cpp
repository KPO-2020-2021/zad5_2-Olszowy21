#include "block.hpp"

bool Block::Otworz_Plik_animowany(std::ofstream &out) const{

       std::string File_name = get_filename_anime();

       out.open(File_name, std::ios::trunc);

       if (!out.is_open())  {
              std::cerr << ":(  Operacja otwarcia do zapisu" << std::endl
              << ":(  nie powiodla sie." << std::endl;
              return false;
       }
       else{
           return true;
       }
}

void Block::Zamknij_Plik_animowany(std::ofstream &out) const{

    out.close();

}

Vector3D Block::Skrobanie_do_rodzica(const Vector3D & top) const{
    
    Vector3D Wynik;
    Matrix3D macierz;

    macierz.obrot_z(kat_do_globalnego);

    Wynik = macierz * top;
    Wynik = Wynik + Polozenie;

    return Wynik;
}