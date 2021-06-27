#include "../inc/plaskowyz.hpp"



/*!
 * Konstruktor dla prostopadłościanu z przypadkowymi wartościami.
 *
 * 
 * 
 */
Mount3::Mount3(std::string Filename_oryginal, std::string File_name_anime, Vector3D &skala, Vector3D &polozenie){

    kat_do_globalnego = 0;

    set_skala(skala);

    Polozenie = polozenie;

    set_filename_anime(File_name_anime);

    inicjuj_Mount3( Filename_oryginal );

    ze_wzora_do_animatora();

}


/*!
 * Przeciazenie operatora [] dla danych chronionych prostokata.
 * \param[in] index - pomocniczy unsigned int ktory zwroci odpowiedni dla
 *                      liczby czesc tablicy wiechrzolkow.
 * 
 */
Vector<double, SIZE>& Mount3::operator [] (unsigned int index){
    return top[index];
}

/*!
 * Przeciazenie operatora [] const dla danych chronionych prostokata.
 * \param[in] index - pomocniczy unsidned int ktory zwroci odpowiedni dla
 *                      liczby czesc tablicy wiechrzolkow.
 * 
 */
const Vector<double, SIZE>& Mount3::operator [] (unsigned int index) const{
    return top[index];
}


void Mount3::inicjuj_Mount3(std::string Filename_oryginal){
    
    Vector3D broker;

    std::ifstream oryginal;

    oryginal.open(Filename_oryginal.c_str(), std::ios::in );

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


void Mount3::ze_wzora_do_animatora(){
    
    Vector3D broker;

    std::ofstream anime;
    
    int Licznik = 1;
    
    if(Otworz_Plik_animowany(anime)){
        
        for(int i = 0; i < 4; ++i){
            broker = top[0];
            broker = Skrobanie_do_rodzica(broker);
            anime << broker;
            anime << std::endl;
            for(int j = 1; j < 3; ++j){
                broker = top[Licznik];
                broker = Skrobanie_do_rodzica(broker);
                anime << broker;
                anime << std::endl;
                ++Licznik;
            }
            broker = top[9];
            broker = Skrobanie_do_rodzica(broker);
            anime << broker;
            anime << std::endl;
            anime << std::endl;
        }
        broker = top[0];
        broker = Skrobanie_do_rodzica(broker);
        anime << broker;
        anime << std::endl;
        broker = top[1];
        broker = Skrobanie_do_rodzica(broker);
        anime << broker;
        anime << std::endl;
        broker = top[2];
        broker = Skrobanie_do_rodzica(broker);
        anime << broker;
        anime << std::endl;
        broker = top[9];
        broker = Skrobanie_do_rodzica(broker);
        anime << broker;
        anime << std::endl;
        anime << std::endl;

        Zamknij_Plik_animowany(anime);

    }
    else{
        throw std::runtime_error("PLik nie istnieje / błąd pliku1");
    }
}