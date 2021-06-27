#include "gora_z_grania.hpp"


/*!
 * Konstruktor dla gory z grania
 *
 * 
 * 
 */
Mount2::Mount2(std::string Filename_oryginal, Vector3D skala, Vector3D polozenie){

    kat_do_globalnego = 0;

    inicjuj_Mount2( Filename_oryginal, skala, Polozenie);

}

/*!
 * Przeciazenie operatora [] dla danych chronionych prostokata.
 * \param[in] index - pomocniczy unsigned int ktory zwroci odpowiedni dla
 *                      liczby czesc tablicy wiechrzolkow.
 * 
 */
Vector<double, SIZE>& Mount2::operator [] (unsigned int index){
    return top[index];
}

/*!
 * Przeciazenie operatora [] const dla danych chronionych prostokata.
 * \param[in] index - pomocniczy unsidned int ktory zwroci odpowiedni dla
 *                      liczby czesc tablicy wiechrzolkow.
 * 
 */
const Vector<double, SIZE>& Mount2::operator [] (unsigned int index) const{
    return top[index];
}


void Mount2::inicjuj_Mount2(std::string Filename_oryginal , Vector3D &skala, Vector3D &Polozenie ){
    
    Vector3D broker;

    std::ifstream oryginal;

    this->Polozenie = Polozenie;

    set_skala(skala);

    oryginal.open(Filename_oryginal, std::ios::in );

    if(oryginal.is_open()){
        int licznik = 1;                        // zmienna pomagająca poprawnie dodać dane do wiechrzołków
        for(int j = 0; j < 4; ++j){
            oryginal >> broker;
            if (oryginal.eof()) return;
            broker = skaluj(broker);
            top[0] = broker;

            for(int i = 0; i < 2; ++i){
                oryginal >> broker;
                broker = skaluj(broker);
                top[licznik] = broker;
                ++licznik;
            }

            oryginal >> broker;
            broker = skaluj(broker);
            top[9] = broker;
        }
    }

    oryginal.close();

}